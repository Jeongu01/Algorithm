package prefixSum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_10986 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    long[] prefixSum = new long[n];
    long[] counts = new long[m];

    prefixSum[0] = Long.parseLong(st.nextToken());
    for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i - 1] + Long.parseLong(st.nextToken());
    }

    for (long i : prefixSum) {
      counts[(int) (i % m)]++;
    }

    long answer = 0;
    answer += counts[0];
    for (int i = 0; i < m; i++) {
      answer += counts[i] * (counts[i] - 1) / 2;
    }

    System.out.println(answer);
  }

}
