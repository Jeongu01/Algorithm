package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_2110 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int C = Integer.parseInt(st.nextToken());
    long[] houses = new long[N];
    long[] distance = new long[N];
    long[] prefixSum = new long[N];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      houses[i] = Long.parseLong(st.nextToken());
    }

    Arrays.sort(houses);

    distance[0] = 0;
    prefixSum[0] = 0;

    long answer = 0;
    for (int i = 1; i < N; i++) {
      distance[i] = houses[i] - houses[i - 1];
      prefixSum[i] = distance[i] + prefixSum[i - 1];
    }

    long start = 1;
    long end = prefixSum[N - 1];

    while (start <= end) {
      long mid = (start + end) / 2;

      int tempi = 0;
      int count = 1;
      for (int i = 0; i < N; i++) {
        if (prefixSum[i] - prefixSum[tempi] >= mid) {
          tempi = i;
          count++;
        }
      }

      if (count >= C) {
        answer = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    System.out.println(answer);
  }

}
