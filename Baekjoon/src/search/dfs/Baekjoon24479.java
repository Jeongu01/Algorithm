package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Baekjoon24479 {

  static ArrayList<Integer>[] graph;
  static int[] visited;
  static int N, M, count = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    int R = Integer.parseInt(st.nextToken());

    graph = new ArrayList[N + 1];
    for (int i = 1; i <= N; i++) {
      graph[i] = new ArrayList<>();
    }
    visited = new int[N + 1];

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
      sb.append(visited[i]).append("\n");
    }
    System.out.println(sb);
  }

  static void dfs(int n) {
    if (visited[n] != 0) return;
    visited[n] = ++count;

    Collections.sort(graph[n]);
    for (int next : graph[n]) {
      if (visited[next] == 0) {
        dfs(next);
      }
    }
  }

}
