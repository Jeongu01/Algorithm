package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_24060 {

  static int N, K, count = 0, answer = -1;
  static int[] A, tmp;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());   // 배열의 크기
    K = Integer.parseInt(st.nextToken());   // 저장 횟수

    A = new int[N];
    tmp = new int[N];
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(st.nextToken());
    }

    merge_sort(0, N - 1);

    System.out.println(answer);
  }

  static public void merge_sort(int s, int e) {
    if (s < e) {
      int m = (s + e) / 2;
      merge_sort(s, m);
      merge_sort(m + 1, e);
      merge(s, m ,e);
    }
  }

  static public void merge(int s, int m, int e) {
    int i = s;
    int j = m + 1;
    int t = 0;
    while (i <= m && j <= e) {
      if (A[i] <= A[j]) {
        tmp[t++] = A[i++];
      } else {
        tmp[t++] = A[j++];
      }
    }

    while (i <= m) {
      tmp[t++] = A[i++];
    }
    while (j <= e) {
      tmp[t++] = A[j++];
    }
    i = s;
    t = 0;
    while (i <= e) {
      A[i++] = tmp[t++];
      count++;
      if (count == K) {
        answer = A[i - 1];
      }
    }
  }

}
