package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_15486 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[] T = new int[N + 1];
    int[] P = new int[N + 1];
    long[] D = new long[N + 1]; // D[N] = N - 1 일까지 최대 이익

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      T[i] = Integer.parseInt(st.nextToken()); // 기간
      P[i] = Integer.parseInt(st.nextToken()); // 이익
    }

    D[0] = 0;
    if (T[0] <= N) D[T[0]] = D[0] + P[0];
    for (int i = 1; i <= N; i++) {
      int day = i + T[i];
      D[i] = Math.max(D[i], D[i - 1]);
      if (day <= N) {
        D[day] = Math.max(D[day], D[i] + P[i]);
      }
    }

    System.out.println(D[N]);
  }

}
