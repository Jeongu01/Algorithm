package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1541 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String input = br.readLine();
    String[] pluses = input.split("-");

    int sum = 0;
    for (int i = 0; i < pluses.length; i++) {
      int temp = 0;
      String[] ss = pluses[i].split("\\+");
      for (String s : ss) {
        temp += Integer.parseInt(s);
      }

      if (i == 0) {
        sum = temp;
      } else {
        sum -= temp;
      }
    }
    System.out.println(sum);
  }

}
