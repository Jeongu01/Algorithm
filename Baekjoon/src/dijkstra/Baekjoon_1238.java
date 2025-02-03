package dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// X 로 도착하는데 걸리는 시간은 역방향 리스트에 X 를 출발도시로 잡고 다익스트라 적용
public class Baekjoon_1238 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());   // 학생의 수
    int M = Integer.parseInt(st.nextToken());   // 도로의 수
    int X = Integer.parseInt(st.nextToken());   // 목표 마을

    ArrayList<Edge>[] normal = new ArrayList[N + 1];   // 정방향
    ArrayList<Edge>[] reverse = new ArrayList[N + 1];  // 역방향

    int[] timeN = new int[N + 1];   // 정방향 거리
    int[] timeD = new int[N + 1];  // 역방향 거리

    for (int i = 1; i <= N; i++) {
      normal[i] = new ArrayList<>();
      reverse[i] = new ArrayList<>();
    }
    Arrays.fill(timeN, Integer.MAX_VALUE);
    Arrays.fill(timeD, Integer.MAX_VALUE);

    // 도로 정보 저장
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      int start = Integer.parseInt(st.nextToken()); // 출발 도시
      int end = Integer.parseInt(st.nextToken());   // 도착 도시
      int time = Integer.parseInt(st.nextToken());  // 소요 시간

      normal[start].add(new Edge(end, time));
      reverse[end].add(new Edge(start, time));
    }

    // X 에서 각자의 집으로 도착하는데 걸리는 시간 계산
    PriorityQueue<Edge> queue = new PriorityQueue<>();
    queue.offer(new Edge(X, 0));
    timeN[X] = 0;
    boolean[] visited = new boolean[N + 1];

    while (!queue.isEmpty()) {
      Edge now = queue.poll();
      if (visited[now.city]) continue;
      visited[now.city] = true;

      for (Edge next : normal[now.city]) {
        if (timeN[next.city] > timeN[now.city] + next.time) {
          timeN[next.city] = timeN[now.city] + next.time;
          queue.offer(new Edge(next.city, timeN[next.city]));
        }
      }
    }

    // X 에 도착하는데 걸리는 시간 계산
    queue.offer(new Edge(X, 0));
    timeD[X] = 0;
    visited = new boolean[N + 1];

    while (!queue.isEmpty()) {
      Edge now = queue.poll();
      if (visited[now.city]) continue;
      visited[now.city] = true;

      for (Edge next : reverse[now.city]) {
        if (timeD[next.city] > timeD[now.city] + next.time) {
          timeD[next.city] = timeD[now.city] + next.time;
          queue.offer(new Edge(next.city, timeD[next.city]));
        }
      }
    }

    int max = -1;
    for (int i = 1; i <= N; i++) {
      max = Math.max(max, timeN[i] + timeD[i]);
    }

    System.out.println(max);
  }

  static class Edge implements Comparable<Edge>{
    int city;
    int time;

    public Edge(int city, int time) {
      this.city = city;
      this.time = time;
    }

    @Override
    public int compareTo(Edge edge) {
      return this.time - edge.time;
    }
  }
}
