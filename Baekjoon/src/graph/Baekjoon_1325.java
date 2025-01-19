package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_1325 {

  static ArrayList<Integer>[] graph;
  static boolean[] visited;
  static int N, M, temp, num;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    graph = new ArrayList[N + 1];
    visited = new boolean[N + 1];

    for (int i = 1; i < N + 1; i++) {
      graph[i] = new ArrayList<>();
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int A = Integer.parseInt(st.nextToken());
      int B = Integer.parseInt(st.nextToken());

      graph[B].add(A);
    }

    StringBuilder answer = new StringBuilder();
    for (int i = 1; i < N + 1; i++) {
      visited = new boolean[N + 1];
      if (!visited[i]) {
        temp = 1;
        bfs(i);
        if (temp > num) {
          num = temp;
          answer = new StringBuilder();
          answer.append(i).append(" ");
        } else if (temp == num) {
          answer.append(i).append(" ");
        }
      }
    }

    System.out.println(answer.toString());

  }

  static void bfs(int node) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(node);
    visited[node] = true;

    while (!queue.isEmpty()) {
      int now = queue.poll();

      for (int e : graph[now]) {
        if (!visited[e]) {
          visited[e] = true;
          queue.add(e);
          temp++;
        }
      }
    }
  }

}
