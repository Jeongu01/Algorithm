package stack2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_17298 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());

    Stack<Integer> numbers = new Stack<>();
    Stack<Integer> pos = new Stack<>();
    int[] answer = new int[n];
    Arrays.fill(answer, -1);

    // 맨 처음 스택에 추가
    numbers.push(Integer.parseInt(st.nextToken()));
    pos.push(0);
    for (int i = 1; i < n; i++) {
      int x = Integer.parseInt(st.nextToken());
      // 다음으로 들어온 숫자가 오큰수인 숫자 개수 세기
      while (!numbers.isEmpty() && numbers.peek() < x) {
        numbers.pop();
        answer[pos.pop()] = x;
      }
      numbers.push(x);
      pos.push(i);
    }

    StringBuilder sb = new StringBuilder();
    for (int i : answer) {
      sb.append(i + " ");
    }
    System.out.println(sb.toString().trim());
  }
}
