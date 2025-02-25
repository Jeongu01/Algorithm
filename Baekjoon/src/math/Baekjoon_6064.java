package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
* M=10, N=12, x=3, y=9
* <3:9> => <3+10*a:9+12*b> // a, b 는 미지수
* 3+10*a 와 9+12*b 값은 같아야함
* 3+10*a == 9+12*b 을 만족하는 양의 정수 a, b를 찾으면 됨
* 미지수가 2개니까 식을 2개 구하면 됨
*
* 1번 방정식
* b에 관한 식으로 표현해보면
* b = (10*a-6)/12
* b는 정수여야하기 때문에 (10*a-6) % 12 == 0 을 만족해야함
*
* 2번 방정식
* 마지막날은 M과 N의 최소공배수임
* 3+10*a <= lcm(M,N) 을 만족해야함
*
* 2번 방정식의 조건을 반복문으로 돌리며 1번 방정식을 만족하는 해를 찾음
* */

public class Baekjoon_6064 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());
    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      long M = Long.parseLong(st.nextToken());
      long N = Long.parseLong(st.nextToken());
      long x = Long.parseLong(st.nextToken());
      long y = Long.parseLong(st.nextToken());

      long lcm = M * N / gcd(M, N);

      long a = 0;
      boolean isFind = false;
      while (!isFind && x + M * a <= lcm) {
        if ((x + M * a - y) % N == 0) {
          sb.append(x + M * a).append("\n");
          isFind = true;
        }
        a++;
      }
      if (!isFind) sb.append(-1).append("\n");
    }

    System.out.println(sb);
  }

  public static long gcd(long a, long b) {
    while (a % b != 0) {
      long temp = a % b;
      a = b;
      b = temp;
    }
    return b;
  }

}
