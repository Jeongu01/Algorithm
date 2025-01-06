package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
* 재귀함수로 dfs를 구현
* 한 자리 수일 경우 2,3,5,7만 소수이고, 두 자리 이상이 될 경우 일의 자리에 짝수가 올 수 없다는 점을 이용
* */

public class Baekjoon_2023 {

  static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

  }

  static void dfs(int start, int now) {
    if (isPrime(start)) {
      if (now == N) {
        System.out.println(start);
      } else {
        for (int i = 1; i <= 9; i += 2) {
          dfs(start * 10 + i, now + 1);
        }
      }
    }
  }

  static boolean isPrime(int n) {
    for (int i = 2; i * i <= n ; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

}
