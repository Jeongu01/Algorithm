package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1676 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    int two = 0;
    int five = 0;

    for (int i = 1; i <= N; i++) {
      int temp = i;
      while (temp % 2 == 0) {
        temp /= 2;
        two++;
      }
      while (temp % 5 == 0) {
        temp /= 5;
        five++;
      }
    }

    System.out.println(Math.min(two, five));
  }

}
