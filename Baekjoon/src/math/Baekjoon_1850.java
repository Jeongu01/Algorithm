package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/*
* 3 6 이 들어왔을 때
* A = 111, B = 111,111
* 111,111 = 111 * 1000 + 111
* 자릿수를 기준으로 유클리드 호제법을 적용시키면 될 듯 하다
* */
public class Baekjoon_1850 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long A = Long.parseLong(st.nextToken());
    long B = Long.parseLong(st.nextToken());

    long max = Math.max(A, B);
    long min = Math.min(A, B);

    while (max % min != 0) {
      long temp = max % min;
      max = min;
      min = temp;
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < min; i++) {
      sb.append("1");
    }

    System.out.println(sb);
  }

}
