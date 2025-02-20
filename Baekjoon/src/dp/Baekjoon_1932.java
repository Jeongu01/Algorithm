package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1932 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int[][] D = new int[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 1; j <= i; j++) {
        D[i][j] = Integer.parseInt(st.nextToken());
        if (j == 1) D[i][j] += D[i - 1][j];
        else if (j == i) D[i][j] += D[i - 1][j - 1];
        else D[i][j] += Math.max(D[i - 1][j], D[i - 1][j - 1]);
      }
    }

    int max = Integer.MIN_VALUE;
    for (int i = 1; i <= n; i++) {
      max = Math.max(max, D[n][i]);
    }
    System.out.println(max);
  }

}
