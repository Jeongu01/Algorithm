package prefixSum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * N : N개의 수 M : 수의 변경 횟수 K : 구간의 합을 구하는 횟수 a :  1 -> b번째 수를 c로 변경 2 -> b번째 수부터 c번째 수까지 합을 구하여 출력
 */
public class Baekjoon_2042 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long n = Long.parseLong(st.nextToken());
    long m = Long.parseLong(st.nextToken());
    long k = Long.parseLong(st.nextToken());
    long a, b, c;

    long[] arr = new long[(int) n + 1];
    long[] sum = new long[(int) n + 1];
    Map<Long, Long> calcDifference = new HashMap<>();

    for (int i = 1; i <= n; i++) {
      arr[i] = Long.parseLong(br.readLine());
      sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < m + k; i++) {
      st = new StringTokenizer(br.readLine());
      a = Long.parseLong(st.nextToken());
      b = Long.parseLong(st.nextToken());
      c = Long.parseLong(st.nextToken());

      if (a == 1) {
        calcDifference.put(b, c - arr[(int) b]);
      } else {
        long answer = sum[(int) c] - sum[(int) b - 1];
        long start = b;
        long end = c;
        long differenceSum = calcDifference.keySet().stream().mapToLong(x -> x).filter(x -> x >= start && x <= end).map(
            calcDifference::get).sum();
        answer += differenceSum;
        System.out.println(answer);
      }
    }

  }

}
