package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
* 적록색약인 사람이 보는 그림과 아닌 사람이 보는 그림의 탐색 방식은 동일하므로 dfs는 하나로 고정
* 정상인 방식으로 탐색 후
* 그림 배열의 G 색을 R로 변경
* 이후 적록색약 방식으로 탐색
* */
public class Baekjoon_10026 {

  static String[][] paint;
  static boolean[][] visited;
  static int answer1, answer2, n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());

    paint = new String[n][n];
    visited = new boolean[n][n];

    for (int i = 0; i < n; i++) {
      String[] line = br.readLine().split("");
      for (int j = 0; j < n; j++) {
        paint[i][j] = line[j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          dfs(i, j, paint[i][j]);
          answer1++;
        }
        if (paint[i][j].equals("G")) {
          paint[i][j] = "R";
        }
      }
    }

    visited = new boolean[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          dfs(i, j, paint[i][j]);
          answer2++;
        }
      }
    }

    System.out.println(answer1 + " " + answer2);

  }

  static void dfs(int x, int y, String target) {
    if (visited[x][y]) {
      return;
    }

    if (paint[x][y].equals(target)) {
      visited[x][y] = true;
      if (x != 0) dfs(x - 1, y, target);
      if (x != n - 1) dfs(x + 1, y, target);
      if (y != 0) dfs(x, y - 1, target);
      if (y != n - 1) dfs(x, y + 1, target);
    }
  }
}
