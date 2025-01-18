package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2805 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    long M = Long.parseLong(st.nextToken());

    long[] trees = new long[N];

    long start = 0;
    long end = 0;
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      trees[i] = Integer.parseInt(st.nextToken());
      if (trees[i] > end) {
        end = trees[i];
      }
    }

    long answer = 0;
    while (start <= end) {
      long mid = (start + end) / 2;

      long sum = 0;
      for (long tree : trees) {
        sum += Math.max(tree - mid, 0);
      }

      if (sum > M) {
        start = mid + 1;
        answer = mid;
      } else if (sum < M) {
        end = mid - 1;
      } else {
        answer = mid;
        break;
      }
    }

    System.out.println(answer);
  }

}
