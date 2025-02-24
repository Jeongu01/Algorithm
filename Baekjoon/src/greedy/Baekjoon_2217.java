package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Baekjoon_2217 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    Integer[] ropes = new Integer[N + 1];
    int[] D = new int[N + 1]; // D[K] = K ~ N 번째 로프까지 사용했을 때 최대 중량

    ropes[0] = 0;
    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      int w = Integer.parseInt(st.nextToken());
      ropes[i] = w;
    }

    Arrays.sort(ropes);
    for (int i = N; i >= 1; i--) {
      D[i - 1] = Math.max(D[i], ropes[i] * (N - i + 1));
    }

    System.out.println(D[0]);
  }

}
