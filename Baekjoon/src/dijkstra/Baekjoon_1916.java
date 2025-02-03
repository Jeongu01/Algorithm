package dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_1916 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken()); // 도시의 개수

    st = new StringTokenizer(br.readLine());
    int M = Integer.parseInt(st.nextToken()); // 버스의 개수

    ArrayList<Bus>[] graph = new ArrayList[N + 1];
    int[] cost = new int[N + 1];  // 비용 저장 배열
    for (int i = 1; i <= N; i++) {
      graph[i] = new ArrayList<>();
      cost[i] = Integer.MAX_VALUE;
    }

    // 버스의 정보 입력
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      int start = Integer.parseInt(st.nextToken()); // 출발 도시
      int end = Integer.parseInt(st.nextToken());   // 도착 도시
      int value = Integer.parseInt(st.nextToken()); // 비용

      graph[start].add(new Bus(end, value));
    }

    // 구하고자 하는 구간
    st = new StringTokenizer(br.readLine());
    int targetStart = Integer.parseInt(st.nextToken());
    int targetEnd = Integer.parseInt(st.nextToken());

    // 도시별 최소 비용 계산
    PriorityQueue<Bus> queue = new PriorityQueue<>();
    queue.add(new Bus(targetStart, 0));
    boolean[] visited = new boolean[N + 1];
    cost[targetStart] = 0;

    while (!queue.isEmpty()) {
      Bus now = queue.poll();
      if (visited[now.city]) continue;
      visited[now.city] = true;

      for (Bus next : graph[now.city]) {
        if (cost[next.city] > cost[now.city] + next.value) {
          cost[next.city] = cost[now.city] + next.value;
          queue.offer(new Bus(next.city, cost[next.city]));
        }
      }
    }


    System.out.println(cost[targetEnd]);
  }

  static class Bus implements Comparable<Bus>{
    int city;
    int value;

    public Bus(int city, int value) {
      this.city = city;
      this.value = value;
    }

    @Override
    public int compareTo(Bus bus) {
      return this.value - bus.value;
    }
  }


}
