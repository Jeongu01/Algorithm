package prefixSum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2559 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    long[] arr = new long[N];
    long[] sum = new long[N + 1];
    sum[0] = 0;

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      arr[i] = Long.parseLong(st.nextToken());
      sum[i + 1] = sum[i] + arr[i];
    }

    long max = Long.MIN_VALUE;
    for (int i = 0; i < N + 1 - K; i++) {
      max = Math.max(max, sum[i + K] - sum[i]);
    }
    System.out.println(max);
  }

}
