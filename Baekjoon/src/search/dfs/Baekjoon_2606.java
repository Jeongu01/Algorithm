package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_2606 {

  static int N, E, answer = 0;
  static ArrayList<Integer>[] networks;
  static boolean[] visited;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    E = Integer.parseInt(br.readLine());

    networks = new ArrayList[N + 1];
    visited = new boolean[N + 1];

    for (int i = 0; i <= N; i++) {
      networks[i] = new ArrayList<>();
    }

    for (int i = 0; i < E; i++) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      networks[a].add(b);
      networks[b].add(a);
    }

    dfs(1);
    System.out.println(answer - 1);
  }

  static void dfs(int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    answer++;
    for (Integer n : networks[node]) {
      dfs(n);
    }
  }

}
