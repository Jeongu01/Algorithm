package stack2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_17299 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    String s = br.readLine();
    st = new StringTokenizer(s);

    Stack<Integer> numbers = new Stack<>();
    Stack<Integer> pos = new Stack<>();
    int[] answer = new int[n];
    int[] counts = new int[1000001];
    Arrays.fill(answer,-1);

    for (int i = 0; i < n; i++) {
      counts[Integer.parseInt(st.nextToken())]++;
    }

    st = new StringTokenizer(s);
    numbers.push(Integer.parseInt(st.nextToken()));
    pos.push(0);
    for (int i = 1; i < n; i++) {
      int x = Integer.parseInt(st.nextToken());
      while (!numbers.isEmpty() && counts[numbers.peek()] < counts[x]) {
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
    System.out.println(sb.toString());
  }

}
