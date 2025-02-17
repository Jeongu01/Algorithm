package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_14501 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    int[] dp = new int[N + 1]; // N일째 최대 이익

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      int T = Integer.parseInt(st.nextToken());
      int P = Integer.parseInt(st.nextToken());
      int day = i + T - 1;
      while (day <= N) {
        dp[day] = Math.max(dp[day], dp[i - 1] + P);
        day++;
      }
    }

    System.out.println(dp[N]);
  }

}
