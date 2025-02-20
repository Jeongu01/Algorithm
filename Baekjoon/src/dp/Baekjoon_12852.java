package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_12852 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    int[] D = new int[N + 1];     // D[N] = N 을 1로 만드는 횟수의 최솟값
    int[] prev = new int[N + 1];  // prev[N] = D[N] 을 구하기 위한 이전 값
    D[1] = 0;

    for (int i = 2; i <= N; i++) {
      prev[i] = i - 1;
      int min = D[i - 1];
      if (i % 3 == 0) {
        if (min > D[i / 3]) {
          min = D[i / 3];
          prev[i] = i / 3;
        }
      }
      if (i % 2 == 0) {
        if (min > D[i / 2]) {
          min = D[i / 2];
          prev[i] = i / 2;
        }
      }
      D[i] = min + 1;
    }
    System.out.println(D[N]);
    int i = N;
    System.out.print(i + " ");
    while (prev[i] != 0) {
      System.out.print(prev[i] + " ");
      i = prev[i];
    }
  }

}
