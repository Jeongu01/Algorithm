package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2512 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[] arr = new int[N];
    long start = 1;
    long end = 1;

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
      end = Math.max(end, arr[i]);
    }

    st = new StringTokenizer(br.readLine());
    long total = Long.parseLong(st.nextToken());

    long answer = 0;
    while (start <= end) {
      long mid = (start + end) / 2;

      long sum = 0;
      for (int e : arr) {
        sum += Math.min(mid, e);
      }

      if (sum > total) {
        end = mid - 1;
      } else {
        answer = mid;
        start = mid + 1;
      }
    }

    System.out.println(answer);
  }

}
