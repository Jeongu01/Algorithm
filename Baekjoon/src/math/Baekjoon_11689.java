package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_11689 {

  /*
  * 오일러 피 공식
  * n 의 소인수 p1, p2, p3 ...
  * n * (1 - 1/p1) * (1 - 1/p2) * (1 - 1/p3) ...
  * p1 부분 계산
  * (n - n/p1) * (1 - 1/p2) * (1 - 1/p3) ...
  * (n - n/p1) 를 P[1] 로 치환
  * P[1] * (1 - 1/p2) * (1 - 1/p3) ...
  * (P[1] - P[1]/p2) * (1 - 1/p3) ...
  * (P[1] - P[1]/p2) 를 P[2] 로 치환
  * (P[2] - P[2]/p3) ...
  *
  * 이를 일반화 하면
  * P[i] - P[i]/K
  * */

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    long n = Long.parseLong(br.readLine());
    long result = n;

    for (int i = 2; i <= Math.sqrt(n); i++) {
      if (n % i == 0) {
        result -= result / i;
        while (n % i == 0) {
          n /= i;
        }
      }
    }

    // n 의 제곱근까지만 탐색을 했기 때문에 그보다 큰 소인수가 남아있을 수 있음
    if (n > 1) {
      result -= result / n;
    }

    System.out.println(result);
  }
}
