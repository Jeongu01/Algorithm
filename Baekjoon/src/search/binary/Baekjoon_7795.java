package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_7795 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());
    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      int N = Integer.parseInt(st.nextToken());
      int M = Integer.parseInt(st.nextToken());

      int[] A = new int[N];
      int[] B = new int[M];

      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        A[j] = Integer.parseInt(st.nextToken());
      }

      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        B[j] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(B);

      int sum = 0;
      for (int e : A) {
        int count = 0;
        int start = 0;
        int end = B.length - 1;
        while (start <= end) {
          int midi = (start + end) / 2;
          int midV = B[midi];

          if (e <= midV) {
            end = midi - 1;
          } else {
            start = midi + 1;
            count = midi + 1;
          }
        }
        sum += count;
      }
      System.out.println(sum);
    }
  }

}
