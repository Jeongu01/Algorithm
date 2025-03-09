package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Baekjoon_24480 {

  static ArrayList<Integer>[] graph;
  static int[] visited;
  static int count = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int R = Integer.parseInt(st.nextToken());

    graph = new ArrayList[N + 1];
    visited = new int[N + 1];
    for (int i = 0; i <= N; i++) {
      graph[i] = new ArrayList<>();
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(R);

    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= N; i++) {
      sb.append(visited[i]).append("\n");
    }
    System.out.println(sb);
  }

  static void dfs(int n) {
    if (visited[n] != 0) return;
    visited[n] = ++count;

    Collections.sort(graph[n], Collections.reverseOrder());

    for (int next : graph[n]) {
      dfs(next);
    }
  }

}
