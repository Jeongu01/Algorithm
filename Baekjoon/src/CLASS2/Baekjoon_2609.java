package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2609 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int g = gcd(n, m);
    System.out.println(g);
    System.out.println(n * m / g);
  }

  public static int gcd(int x, int y) {
    if (x % y == 0)
      return y;
    else {
      return gcd(y, x % y);
    }
  }

}
