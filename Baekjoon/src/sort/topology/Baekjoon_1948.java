package sort.topology;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_1948 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken()); // 도시의 개수

    st = new StringTokenizer(br.readLine());
    int m = Integer.parseInt(st.nextToken()); // 도로의 개수

    ArrayList<Integer>[] graph = new ArrayList[n + 1];
    ArrayList<Integer>[] reverse = new ArrayList[n + 1];
    int[][] time = new int[n + 1][n + 1]; // time[출발 도시][도착 도시] = 걸리는 시간
    int[] indegree = new int[n + 1];

    for (int i = 1; i < n + 1; i++) {
      graph[i] = new ArrayList<>();
      reverse[i] = new ArrayList<>();
    }

    // 도로의 정보
    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());

      int s = Integer.parseInt(st.nextToken()); // 출발 도시
      int e = Integer.parseInt(st.nextToken()); // 도착 도시
      int t = Integer.parseInt(st.nextToken()); // 걸리는 시간

      graph[s].add(e);
      reverse[e].add(s);
      indegree[e]++;
      time[s][e] = t;
    }

    // 출발 도시와 도착 도시
    st = new StringTokenizer(br.readLine());
    int S = Integer.parseInt(st.nextToken());
    int E = Integer.parseInt(st.nextToken());

    Queue<Integer> queue = new LinkedList<>();
    queue.offer(S);

    int[] answer = new int[n + 1];
    while (!queue.isEmpty()) {
      int now = queue.poll();
      for (Integer next : graph[now]) {
        indegree[next]--;
        answer[next] = Math.max(answer[next], answer[now] + time[now][next]);
        if (indegree[next] == 0) {
          queue.offer(next);
        }
      }
    }

    int count = 0;
    boolean[] visited = new boolean[n + 1];
    queue.offer(E);
    visited[E] = true;
    while (!queue.isEmpty()) {
      int now = queue.poll();
      for (Integer next : reverse[now]) {
        if (answer[next] + time[next][now] == answer[now]) {  // next 의 임계 경로값 + next 와 now 간 소요 시간 == now 의 임계 경로값
          count++;
          if (!visited[next]) {
            visited[next] = true;
            queue.offer(next);
          }
        }
      }
    }

    System.out.println(answer[E]);
    System.out.println(count);
  }
}
