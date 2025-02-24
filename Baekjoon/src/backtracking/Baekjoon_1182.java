package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1182 {

  static int[] arr;
  static int N, S, sum = 0, answer = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    S = Integer.parseInt(st.nextToken());

    arr = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    func(0);
    System.out.println(answer);
  }

  public static void func(int n) {
    if (n == N) return;
    // 포함 할 때
    sum += arr[n];
    if (sum == S) answer++;
    func(n + 1);
    sum -= arr[n];
    // 포함 안할 때
    func(n + 1);
  }

}
