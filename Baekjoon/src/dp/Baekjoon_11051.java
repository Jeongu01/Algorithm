package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_11051 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    int[][] arr = new int[N + 1][N + 1];
    Arrays.fill(arr[0], 1);
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        arr[i][j] = 1;
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        arr[i][j] = (arr[i - 1][j - 1] + arr[i][j - 1]) % 10007;
      }
    }

    System.out.println(arr[K][N]);
  }

}
