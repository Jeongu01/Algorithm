package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_18352 {

  static ArrayList<Integer>[] cities;
  static int[] distance;
  static int N, M, K, X;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken()); // 도시의 개수
    M = Integer.parseInt(st.nextToken()); // 도로의 개수
    K = Integer.parseInt(st.nextToken()); // 최단 거리
    X = Integer.parseInt(st.nextToken()); // 출발 도시의 번호

    cities = new ArrayList[N + 1];
    distance = new int[N + 1];

    for (int i = 1; i < N + 1; i++) {
      cities[i] = new ArrayList<>();
      distance[i] = -1;
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int index = Integer.parseInt(st.nextToken());
      int city = Integer.parseInt(st.nextToken());
      cities[index].add(city);
    }

    bfs(X);

    boolean isExist = false;
    for (int i = 1; i < N + 1; i++) {
      if (distance[i] == K) {
        System.out.println(i);
        isExist = true;
      }
    }

    if (!isExist) {
      System.out.println("-1");
    }
  }

  static void bfs(int start) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    distance[start] = 0;

    while (!queue.isEmpty()) {
      int now = queue.poll();
      for (int city : cities[now]) {
        if (distance[city] == -1) {
          distance[city] = distance[now] + 1;
          queue.add(city);
        }
      }
    }
  }

}
