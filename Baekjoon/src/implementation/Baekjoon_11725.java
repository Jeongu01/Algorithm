package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_11725 {

  static int N;
  static int[] parents;
  static ArrayList<Integer>[] tree;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());

    tree = new ArrayList[N + 1];
    for (int i = 0; i <= N; i++) {
      tree[i] = new ArrayList<>();
    }

    for (int i = 0; i < N - 1; i++) {
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      tree[a].add(b);
      tree[b].add(a);
    }

    parents = new int[N + 1];
    bfs(1);

    StringBuilder sb = new StringBuilder();
    for (int i = 2; i <= N; i++) {
      sb.append(parents[i]).append("\n");
    }
    System.out.println(sb);
  }

  static void bfs(int a) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(a);

    while (!queue.isEmpty()) {
      int now = queue.poll();

      for (int i = 0; i < tree[now].size(); i++) {
        int child = tree[now].get(i);

        if (parents[child] == 0) {
          parents[child] = now;
          queue.add(child);
        }
      }
    }
  }

}
