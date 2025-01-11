package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Baekjoon_2667 {

  static ArrayList<Integer> answers = new ArrayList<>();
  static int[][] arr;
  static boolean[][] visited;
  static int N, count = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());

    arr = new int[N][N];
    visited = new boolean[N][N];

    for (int i = 0; i < N; i++) {
      String line = br.readLine();
      String[] input = line.split("");
      for (int j = 0; j < N; j++) {
        arr[i][j] = Integer.parseInt(input[j]);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] == 1) {
          count = 0;
          dfs(i, j);
          if (count != 0) answers.add(count);
        }
      }
    }

    System.out.println(answers.size());
    answers.stream().sorted().forEach(System.out::println);
  }

  static void dfs(int x, int y) {
    if (visited[x][y]) {
      return;
    }

    visited[x][y] = true;
    count++;
    if (x != 0 && arr[x - 1][y] == 1) dfs(x - 1, y);
    if (x != N - 1 && arr[x + 1][y] == 1) dfs(x + 1, y);
    if (y != 0 && arr[x][y - 1] == 1) dfs(x, y - 1);
    if (y != N - 1 && arr[x][y + 1] == 1) dfs(x, y + 1);
  }

}
