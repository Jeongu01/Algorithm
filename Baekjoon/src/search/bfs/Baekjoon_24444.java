package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_24444 {

  static ArrayList<Integer>[] graph;
  static int[] visited;

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

    bfs(R);
    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= N; i++) {
      sb.append(visited[i]).append("\n");
    }
    System.out.println(sb);
  }

  static void bfs(int n) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(n);
    int count = 1;
    visited[n] = count++;

    while (!queue.isEmpty()) {
      int now = queue.poll();

      Collections.sort(graph[now]);
      for (int next : graph[now]) {
        if (visited[next] == 0) {
          visited[next] = count++;
          queue.add(next);
        }
      }
    }
  }

}
