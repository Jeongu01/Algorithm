package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_10844 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    long mod = 1_000_000_000;

    long[][] stairs = new long[101][10];  // stairs[N][K] = N 자리에 K로 끝나는 계단 수
    // 0, 9 로 끝나는 수는 i - 1개

    for (int i = 1; i <= 9; i++) {
      stairs[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
      stairs[i][0] = stairs[i - 1][1];
      stairs[i][9] = stairs[i - 1][8];
      for (int j = 1; j <= 8; j++) {
        stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % mod;
      }
    }

    long sum = 0;
    for (int i = 0; i <= 9; i++) {
      sum = (sum + stairs[N][i]) % mod;
    }
    System.out.println(sum);
  }

}
