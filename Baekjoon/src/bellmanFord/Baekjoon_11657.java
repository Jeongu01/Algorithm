package bellmanFord;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_11657 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());   // 도시의 개수
    int M = Integer.parseInt(st.nextToken());   // 버스 노선의 개수

    Edge[] edges = new Edge[M + 1];
    long[] distance = new long[N + 1];
    Arrays.fill(distance, Integer.MAX_VALUE);

    // 노선 정보 저장
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      int A = Integer.parseInt(st.nextToken());   // 출발 도시
      int B = Integer.parseInt(st.nextToken());   // 도착 도시
      int C = Integer.parseInt(st.nextToken());   // 소요 시간

      edges[i] = new Edge(A, B, C);
    }

    distance[1] = 0;
    for (int i = 0; i < N - 1; i++) { // N - 1 번 반복
      for (int j = 0; j < M; j++) {
        Edge edge = edges[j];
        if (distance[edge.start] != Integer.MAX_VALUE
            && distance[edge.end] > distance[edge.start] + edge.time) {
          distance[edge.end] = distance[edge.start] + edge.time;
        }
      }
    }

    boolean mCycle = false;
    for (int i = 0; i < M; i++) {
      Edge edge = edges[i];
      if (distance[edge.start] != Integer.MAX_VALUE
          && distance[edge.end] > distance[edge.start] + edge.time) {
        mCycle = true;
        break;
      }
    }

    if (mCycle) {
      System.out.println(-1);
    } else {
      for (int i = 2; i <= N; i++) {
        if (distance[i] == Integer.MAX_VALUE) {
          System.out.println(-1);
        } else {
          System.out.println(distance[i]);
        }
      }
    }
  }

  static class Edge {
    int start;
    int end;
    int time;

    public Edge(int start, int end, int time) {
      this.start = start;
      this.end = end;
      this.time = time;
    }
  }
}
