package floydwarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_11404 {

  static final int MAX_VALUE = 100_000_000;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken()); // 도시의 개수
    st = new StringTokenizer(br.readLine());
    int m = Integer.parseInt(st.nextToken()); // 버스의 개수

    int[][] dist = new int[n + 1][n + 1];


    for (int i = 1; i <= n; i++) {
      Arrays.fill(dist[i], MAX_VALUE);  // 비용의 최대값은 100_000
      dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken()); // 시작 도시
      int b = Integer.parseInt(st.nextToken()); // 도착 도시
      int c = Integer.parseInt(st.nextToken()); // 비용

      dist[a][b] = Math.min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][j] == MAX_VALUE) {
          System.out.print("0 ");
        } else {
          System.out.print(dist[i][j] + " ");
        }
      }
      System.out.println();
    }
  }

}
