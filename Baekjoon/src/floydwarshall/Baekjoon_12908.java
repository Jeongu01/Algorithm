package floydwarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_12908 {

  static Pos[] pos;
  static long[][] graph;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long xs = Long.parseLong(st.nextToken());
    long ys = Long.parseLong(st.nextToken());

    st = new StringTokenizer(br.readLine());
    long xe = Long.parseLong(st.nextToken());
    long ye = Long.parseLong(st.nextToken());

    graph = new long[8][8]; // graph[N][K] = N -> K 걸리는 시간
    for (int i = 0; i < 8; i++) {
      Arrays.fill(graph[i], 2_000_000_000);
    }
    for (int i = 0; i < 8; i++) {
      graph[i][i] = 0;
    }

    pos = new Pos[8];
    int index = 0;
    pos[index++] = new Pos(xs, ys);
    for (int i = 0; i < 3; i++) {
      st = new StringTokenizer(br.readLine());
      long t1x = Long.parseLong(st.nextToken());
      long t1y = Long.parseLong(st.nextToken());
      pos[index++] = new Pos(t1x, t1y);

      long t2x = Long.parseLong(st.nextToken());
      long t2y = Long.parseLong(st.nextToken());
      pos[index++] = new Pos(t2x, t2y);
    }
    pos[index] = new Pos(xe, ye);

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        graph[i][j] = Math.abs(pos[i].x - pos[j].x) + Math.abs(pos[i].y - pos[j].y);
      }
    }

    // 텔레포트 시간 저장
    graph[1][2] = Math.min(10, graph[1][2]);
    graph[2][1] = Math.min(10, graph[2][1]);
    graph[3][4] = Math.min(10, graph[3][4]);
    graph[4][3] = Math.min(10, graph[4][3]);
    graph[5][6] = Math.min(10, graph[5][6]);
    graph[6][5] = Math.min(10, graph[6][5]);

    for (int k = 0; k < 8; k++) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }

    System.out.println(graph[0][7]);
  }

  static class Pos {
    long x;
    long y;

    public Pos(long x, long y) {
      this.x = x;
      this.y = y;
    }
  }

}
