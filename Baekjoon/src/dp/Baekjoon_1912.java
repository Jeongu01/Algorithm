package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1912 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int[] arr = new int[n];
    int[] dp = new int[n];  // dp[N] = 1부터 N까지 수열 중 N이 포함되는 최대 값

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }
    dp[0] = arr[0];
    int max = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = Math.max(dp[i - 1] + arr[i], arr[i]); // 이전까지 + 자신 vs 자신 -> 이후 더할 값들은 똑같이 더해질테니까 여기서 끊고 갈지, 이어서 갈 지 판단하기 위함
      max = Math.max(max, dp[i]);
    }

    System.out.println(max);
  }

}
