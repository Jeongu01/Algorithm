package tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_1967 {

  static ArrayList<Edge>[] tree;
  static boolean[] visited;
  static int max = 0;
  static int p = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());

    tree = new ArrayList[n + 1];
    visited = new boolean[n + 1];
    for (int i = 0; i <= n; i++) {
      tree[i] = new ArrayList<>();
    }

    for (int i = 0; i < n - 1; i++) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());

      tree[u].add(new Edge(v, w));
      tree[v].add(new Edge(u, w));
    }

    visited = new boolean[n + 1];

    dfs(1, 0);
    dfs(p, 0);

    System.out.println(max);
  }

  static void dfs(int n, int w) {
    if (visited[n]) return;
    if (w > max) {
      max = w;
      p = n;
    }
    visited[n] = true;
    for (Edge next : tree[n]) {
      dfs(next.v, w + next.w);
    }
    visited[n] = false;
  }

  static class Edge implements Comparable<Edge> {
    int v;
    int w;

    public Edge(int v, int w) {
      this.v = v;
      this.w = w;
    }

    @Override
    public int compareTo(Edge edge) {
      return this.w - edge.w;
    }

  }

}
