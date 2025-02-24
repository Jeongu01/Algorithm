package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_6198 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[] counts = new int[N];  // 볼 수 있는 빌딩 수
    Stack<int[]> stack = new Stack<>(); // 번호, 높이
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int h = Integer.parseInt(st.nextToken());

      while (!stack.isEmpty() && stack.peek()[1] <= h) {
        if (stack.peek()[1] <= h) {
          int[] now = stack.pop();
          if (!stack.isEmpty()) {
            counts[stack.peek()[0]] += counts[now[0]] + 1;
          }
        }
      }
      stack.push(new int[]{i, h});
    }

    // 스택 비워주기
    while (!stack.isEmpty()) {
      int[] now = stack.pop();
      if (!stack.isEmpty()) {
        counts[stack.peek()[0]] += counts[now[0]] + 1;
      }
    }

    long sum = 0;
    for (int i = 0; i < N; i++) {
      sum += counts[i];
    }
    System.out.println(sum);
  }

}
