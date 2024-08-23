package stack2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Baekjoon_9935 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s = br.readLine();
    String bomb = br.readLine();

    Stack<Character> stack = new Stack<>();

    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      stack.push(c);
      if (stack.size() >= bomb.length() && c == bomb.charAt(bomb.length() - 1)) {
        boolean check = true;
        for (int j = 0; j < bomb.length(); j++) {
          if (stack.get(stack.size() - j - 1) != bomb.charAt(bomb.length() - j - 1)) {
            check = false;
            break;
          }
        }
        if (check) {
          for (int j = 0; j < bomb.length(); j++) {
            stack.pop();
          }
        }
      }
    }

    StringBuilder sb = new StringBuilder();
    for (Character character : stack) {
      sb.append(character);
    }

    if (sb.length() == 0) {
      System.out.println("FRULA");
    } else {
      System.out.println(sb);
    }

  }

}
