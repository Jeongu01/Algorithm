package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Baekjoon_15651 {

  static List<Integer> isVisited = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    func(n, m);
  }

  public static void func(int n, int m) {
    if (isVisited.size() == m) {
      for (Integer integer : isVisited) {
        System.out.print(integer + " ");
      }
      System.out.println();
      return;
    }
    for (int i = 1; i <= n; i++) {
      isVisited.add(i);
      func(n, m);
      isVisited.remove(Integer.valueOf(i));
    }
  }

}
