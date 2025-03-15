package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_1863 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    Stack<Integer> stack = new Stack<>();

    int n = Integer.parseInt(st.nextToken());
    int count = 0;
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      if (y != 0 && stack.isEmpty()) {
        stack.push(y);
        count++;
      } else {
        if (!stack.isEmpty() && stack.peek() < y) { // 높아질 경우
          stack.push(y);
          count++;
        } else {  // 낮아질 경우
          while (!stack.isEmpty()) {  // y 보다 높은 경우는 다 뺌
            if (stack.peek() <= y) {
              break;
            }
            stack.pop();
          }
          if (y != 0 && (stack.isEmpty() || stack.peek() < y)) {
            stack.push(y);
            count++;
          }
        }
      }
    }

    System.out.println(count);

  }

}
