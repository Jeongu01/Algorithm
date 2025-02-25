package twoPointer;

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

    int start = 0;
    int end = 0;
    int min = Integer.MAX_VALUE;
    while (end < N) {
      if (A[end] - A[start] == M) {
        min = M;
        break;
      }
      else if (A[end] - A[start] < M) end++;
      else if (A[end] - A[start] > M) {
        min = Math.min(min, A[end] - A[start]);
        start++;
      }
    }
    System.out.println(min);
  }

}
