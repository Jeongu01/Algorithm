package dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_1753 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int V = Integer.parseInt(st.nextToken()); // 정점의 개수
    int E = Integer.parseInt(st.nextToken()); // 간선의 개수
    ArrayList<Edge>[] graph = new ArrayList[V + 1];
    int[] distance = new int[V + 1];

    for (int i = 1; i < V + 1; i++) {
      graph[i] = new ArrayList<>();
    }

    for (int i = 1; i < V + 1; i++) {
      distance[i] = Integer.MAX_VALUE;
    }

    st = new StringTokenizer(br.readLine());
    int K = Integer.parseInt(st.nextToken()); // 시작 정점의 번호
    distance[K] = 0;

    for (int i = 0; i < E; i++) {
      st = new StringTokenizer(br.readLine());

      int u = Integer.parseInt(st.nextToken()); // 출발 정점
      int v = Integer.parseInt(st.nextToken()); // 도착 정점
      int w = Integer.parseInt(st.nextToken()); // 가중치

      graph[u].add(new Edge(v, w));
    }

    PriorityQueue<Edge> queue = new PriorityQueue<>();
    queue.offer(new Edge(K, 0));
    boolean[] visited = new boolean[V + 1];

    while (!queue.isEmpty()) {
      Edge now = queue.poll();

      if (visited[now.v]) continue;
      visited[now.v] = true;

      for (Edge e : graph[now.v]) {
        if (distance[e.v] > distance[now.v] + e.w) {
          distance[e.v] = distance[now.v] + e.w;
          queue.offer(new Edge(e.v, distance[e.v]));
        }
      }
    }

    for (int i = 1; i < V + 1; i++) {
      if (distance[i] == Integer.MAX_VALUE) {
        System.out.println("INF");
      } else {
        System.out.println(distance[i]);
      }
    }
  }

  static class Edge implements Comparable<Edge> {
    int v;
    int w;

    public Edge(int v, int w) {
      this.v = v;
      this.w = w;
    }

    @Override
    public int compareTo(Edge e) {
      return this.w - e.w;
    }
  }


}
