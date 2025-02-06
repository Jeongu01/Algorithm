package CLASS4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Baekjoon_15654 {

  static int[] input;
  static boolean[] visited;
  static int N, M;
  static Stack<Integer> stack = new Stack<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    input = new int[N];
    visited = new boolean[N];
    for (int i = 0; i < N; i++) {
      input[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(input);

    backtracking();

  }

  static public void backtracking() {

    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        visited[i] = true;
        stack.push(input[i]);

        if (stack.size() == M) {
          stack.forEach(x -> System.out.print(x + " "));
          System.out.println();
        } else {
          backtracking();
        }

        visited[i] = false;
        stack.pop();
      }
    }

  }

}
