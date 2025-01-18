package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1654 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int K = Integer.parseInt(st.nextToken());
    int N = Integer.parseInt(st.nextToken());

    long[] LANs = new long[K];

    long start = 1;
    long end = 1;
    for (int i = 0; i < K; i++) {
      st = new StringTokenizer(br.readLine());
      LANs[i] = Integer.parseInt(st.nextToken());
      end = Math.max(LANs[i], end);
    }

    long answer = 0;
    while (start <= end) {
      long mid = (start + end) / 2;

      int count = 0;
      for (long lan : LANs) {
        count += lan / mid;
      }

      if (count >= N) {
        answer = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    System.out.println(answer);
  }

}
