package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_28702 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String[] input = new String[3];

    int answer = 0;
    for (int i = 0; i < 3; i++) {
      input[i] = br.readLine();
      if (!input[i].endsWith("zz")) {
        answer = Integer.parseInt(input[i]) + (3 - i);
      }
    }

    boolean three = answer % 3 == 0;
    boolean five = answer % 5 == 0;

    if (three && five) {
      System.out.println("FizzBuzz");
    } else if (three) {
      System.out.println("Fizz");
    } else if (five) {
      System.out.println("Buzz");
    } else {
      System.out.println(answer);
    }

  }

}
