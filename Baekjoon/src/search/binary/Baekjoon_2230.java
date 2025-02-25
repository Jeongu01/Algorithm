package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_2230 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    int[] A = new int[N];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      A[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(A);

    int min = Integer.MAX_VALUE;
    for (int i = 0; i < N; i++) {
      int start = 0;
      int end = N - 1;
      while (start <= end) {
        int mid = (start + end) / 2;

        int sub = A[i] - A[mid];
        if (Math.abs(sub) == M) {
          System.out.println(M);
          return;
        } else if (A[i] - A[mid] > M) {
          min = Math.min(min, Math.abs(sub));
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    System.out.println(min);
  }

}
