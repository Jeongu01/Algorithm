package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_2579 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int[] stairs = new int[301];

    for (int i = 0; i < N; i++) {
      stairs[i] = Integer.parseInt(br.readLine());
    }

    int[] dp = new int[301];
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = Math.max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    for (int i = 3; i < N; i++) {
      dp[i] = Math.max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }

    System.out.println(dp[N - 1]);
  }

}
