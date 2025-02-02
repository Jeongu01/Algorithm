package sort.topology;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_2252 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    ArrayList<Integer>[] graph = new ArrayList[N + 1];

    for (int i = 0; i < N + 1; i++) {
      graph[i] = new ArrayList<>();
    }

    int[] indegree = new int[N + 1];

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      int A = Integer.parseInt(st.nextToken());
      int B = Integer.parseInt(st.nextToken());

      graph[A].add(B);
      indegree[B]++;
    }

    Queue<Integer> queue = new LinkedList<>();
    for (int i = 1; i < N + 1; i++) {
      if (indegree[i] == 0) {
        queue.offer(i);
      }
    }

    StringBuilder sb = new StringBuilder();

    while (!queue.isEmpty()) {
      int now = queue.poll();
      sb.append(now).append(" ");
      for (Integer i : graph[now]) {
        indegree[i]--;
        if (indegree[i] == 0) {
          queue.offer(i);
        }
      }
    }

    System.out.println(sb);

  }

}
