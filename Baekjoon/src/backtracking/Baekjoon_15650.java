package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Baekjoon_15650 {

  static List<Integer> isVisited;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    for (int i = 1; i <= n; i++) {
      isVisited = new ArrayList<>();
      isVisited.add(i);
      func(n, m);
    }
  }

  public static void func(int n, int m) {
    if (isVisited.size() == m) {
      for (int i : isVisited) {
        System.out.print(i + " ");
      }
      System.out.println();
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (isVisited.get(isVisited.size() - 1) < i) {
        isVisited.add(i);
        func(n, m);
        isVisited.remove(Integer.valueOf(i));
      }
    }
  }


}
