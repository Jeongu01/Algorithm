package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_15829 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int L = Integer.parseInt(br.readLine());

    char[] s = br.readLine().toCharArray();

    long r = 31;
    long M = 1234567891;

    long answer = 0;
    for (int i = 0; i < L; i++) {
      long a = s[i] - 'a' + 1;
      for (int j = 0; j < i; j++) {
        a *= r;
        a %= M;
      }
      answer += a;
      answer %= M;
    }

    System.out.println(answer);
  }

}
