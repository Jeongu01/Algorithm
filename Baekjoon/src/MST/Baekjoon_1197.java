package MST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_1197 {

  static int[] parent;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int V = Integer.parseInt(st.nextToken()); // 정점의 개수
    int E = Integer.parseInt(st.nextToken()); // 간선의 개수

    parent = new int[V + 1];
    for (int i = 0; i <= V; i++) {
      parent[i] = i;
    }

    PriorityQueue<Edge> queue = new PriorityQueue<>();

    for (int i = 0; i < E; i++) {
      st = new StringTokenizer(br.readLine());

      int A = Integer.parseInt(st.nextToken());
      int B = Integer.parseInt(st.nextToken());
      int C = Integer.parseInt(st.nextToken());

      queue.add(new Edge(A, B, C));
    }

    int edgeCount = 0;
    int answer = 0;
    while (edgeCount < V - 1) {
      Edge now = queue.poll();
      if (find(parent[now.s]) != find(parent[now.e])) {
        union(now.s, now.e);
        answer += now.weight;
        edgeCount++;
      }
    }

    System.out.println(answer);


  }

  static void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      parent[b] = a;
    }
  }

  static int find (int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
  }


  static class Edge implements Comparable<Edge>{
    int s;
    int e;
    int weight;

    public Edge(int s, int e, int weight) {
      this.s = s;
      this.e = e;
      this.weight = weight;
    }

    @Override
    public int compareTo(Edge edge) {
      return this.weight - edge.weight;
    }
  }
}
