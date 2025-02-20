package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_11055 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[] A = new int[N];
    int[] D = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(st.nextToken());
    }

    int max = Integer.MIN_VALUE;
    for (int i = 0; i < N; i++) {
      D[i] = A[i];
      for (int j = 0; j < i; j++) {
        if (A[j] < A[i]) {
          D[i] = Math.max(D[i], D[j] + A[i]);
        }
      }
    }

    for (int i = 0; i < N; i++) {
      max = Math.max(max, D[i]);
    }
    System.out.println(max);
  }

}
