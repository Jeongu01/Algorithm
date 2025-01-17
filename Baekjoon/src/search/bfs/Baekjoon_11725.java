package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_11725 {

  static ArrayList<Integer>[] tree;
  static int[] parents;
  static boolean[] visited;
  static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());

    tree = new ArrayList[N + 1];
    parents = new int[N + 1];
    visited = new boolean[N + 1];

    for (int i = 1; i < N + 1; i++) {
      tree[i] = new ArrayList<>();
    }

    for (int i = 1; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      int node1 = Integer.parseInt(st.nextToken());
      int node2 = Integer.parseInt(st.nextToken());

      tree[node1].add(node2);
      tree[node2].add(node1);
    }

    bfs(1);

    for (int i = 2; i < N + 1; i++) {
      System.out.println(parents[i]);
    }
  }

  static void bfs(int n) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(n);
    visited[n] = true;

    while (!queue.isEmpty()) {
      int p = queue.poll();

      for (int t : tree[p]) {
        if (!visited[t]) {
          parents[t] = p;
          visited[t] = true;
          queue.add(t);
        }
      }
    }
  }
}
