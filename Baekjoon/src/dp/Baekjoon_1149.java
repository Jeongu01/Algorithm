package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1149 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[][] rgb = new int[N][3];
    int[][] D = new int[N][3];  // D[N][K] = N 번째까지 K 색을 골랐을 때의 최솟값

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      rgb[i][0] = Integer.parseInt(st.nextToken());
      rgb[i][1] = Integer.parseInt(st.nextToken());
      rgb[i][2] = Integer.parseInt(st.nextToken());
    }

    D[0][0] = rgb[0][0];
    D[0][1] = rgb[0][1];
    D[0][2] = rgb[0][2];
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < 3; j++) {
        D[i][j] = Math.min(D[i - 1][(j + 1) % 3], D[i - 1][(j + 2) % 3]) + rgb[i][j];
      }
    }

    System.out.println(Math.min(D[N - 1][0], Math.min(D[N - 1][1], D[N - 1][2])));
  }

}
