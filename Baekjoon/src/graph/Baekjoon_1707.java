package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_1707 {

  static ArrayList<Integer>[] graph;
  static int[] visited; // 0: 방문 X, 1: A 그룹, 2: B 그룹
  static int V, E;
  static boolean answer;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int K = Integer.parseInt(st.nextToken());

    for (int i = 0; i < K; i++) {
      st = new StringTokenizer(br.readLine());
      V = Integer.parseInt(st.nextToken());
      E = Integer.parseInt(st.nextToken());

      graph = new ArrayList[V + 1];
      visited = new int[V + 1];
      answer = true;

      for (int j = 1; j < V + 1; j++) {
        graph[j] = new ArrayList<>();
      }

      for (int j = 0; j < E; j++) {
        st = new StringTokenizer(br.readLine());
        int u = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        graph[u].add(v);
        graph[v].add(u);
      }

      for (int j = 1; j < V + 1; j++) {
        if (!answer) {
          break;
        }
        if (visited[j] == 0){
          visited[j] = 1;
          dfs(j);
        }
      }
      System.out.println(answer ? "YES" : "NO");
    }
  }

  static void dfs(int node) {
    for (Integer n : graph[node]) {
      if (visited[n] == 0) { // 방문하지 않은 노드인 경우
        visited[n] = visited[node] == 1 ? 2 : 1;
        dfs(n);
      } else if (visited[n] == visited[node]) {  // 같은 집합의 노드인데 인접한 경우
        answer = false;
      }
    }
  }

}
