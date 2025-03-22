package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_3986 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int count = 0;

    for (int i = 0; i < n; i++) {
      Stack<Character> stack = new Stack<>();

      String input = br.readLine();

      for (int j = 0; j < input.length(); j++) {
        char c = input.charAt(j);

        if (stack.isEmpty()) {
          stack.push(c);
        } else {
          if (stack.peek() == c) {
            stack.pop();
          } else {
            stack.push(c);
          }
        }
      }

      if (stack.isEmpty()) {
        count++;
      }
    }
    System.out.println(count);
  }

}
