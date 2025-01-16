package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
/*
* 임의의 노드에서 가장 긴 경로로 연결돼있는 노드는 트리의 지름에 해당하는 두 노드 중 하나다.
* */
public class Baekjoon_1167 {

  static ArrayList<Edge>[] arr;
  static boolean[] visited;
  static int[] distance;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int V = Integer.parseInt(st.nextToken());

    arr = new ArrayList[V + 1];
    visited = new boolean[V + 1];
    distance = new int[V + 1];

    for (int i = 0; i < V; i++) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      arr[a] = new ArrayList<>();

      while (true) {
        int e = Integer.parseInt(st.nextToken());
        if (e == -1) {
          break;
        }
        int w = Integer.parseInt(st.nextToken());
        arr[a].add(new Edge(e, w));
      }
    }

    bfs(1);
    int max = 1;
    for (int i = 2; i < V + 1; i++) {
      if (distance[max] < distance[i]) {
        max = i;
      }
    }
    visited = new boolean[V + 1];
    distance = new int[V + 1];
    bfs(max);
    System.out.println(Arrays.stream(distance).max().getAsInt());
  }

  static void bfs(int start) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    visited[start] = true;

    while (!queue.isEmpty()) {
      int v = queue.poll();
      for (Edge edge : arr[v]) {
        int v1 = edge.e;
        int w = edge.w;
        if (!visited[v1]) {
          visited[v1] = true;
          queue.add(v1);
          distance[v1] = distance[v] + w;
        }
      }
    }
  }

  static class Edge {
    int e;
    int w;

    public Edge(int e, int w) {
      this.e = e;
      this.w = w;
    }
  }

}