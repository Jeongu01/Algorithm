package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1629 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long a = Long.parseLong(st.nextToken());
    long b = Long.parseLong(st.nextToken());
    long c = Long.parseLong(st.nextToken());

    System.out.println(mul(a, b, c));
  }

  static long mul(long a, long b, long c) {
    if (b == 1) return a % c;
    long temp = mul(a, b / 2, c) % c;
    temp = temp * temp % c;
    if (b % 2 == 1) temp = temp * a % c;
    return temp;
  }

}
