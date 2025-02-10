package tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_11725 {

  static int N;
  static ArrayList<Integer>[] tree;
  static int[] answer;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());

    tree = new ArrayList[N + 1];
    answer = new int[N + 1];

    for (int i = 1; i <= N; i++) {
      tree[i] = new ArrayList<>();
    }

    for (int i = 0; i < N - 1; i++) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      tree[a].add(b);
      tree[b].add(a);
    }

    answer[1] = -1;
    dfs(1);

    for (int i = 2; i <= N; i++) {
      System.out.println(answer[i]);
    }
  }

  static void dfs(int n) {
    for (Integer c : tree[n]) {
      if (answer[c] == 0) {
        answer[c] = n;
        dfs(c);
      }
    }
  }

}
