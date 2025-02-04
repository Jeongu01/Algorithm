package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1987 {

  static char[][] board;
  static boolean[][] vPos;
  static boolean[] vAlpha;
  static int R, C, max = 1, count = 0;
  static int[] dx = {1, -1, 0, 0};
  static int[] dy = {0, 0, 1, -1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    R = Integer.parseInt(st.nextToken()); // 세로
    C = Integer.parseInt(st.nextToken()); // 가로

    board = new char[R][C];

    for (int i = 0; i < R; i++) {
      char[] input = br.readLine().toCharArray();
      for (int j = 0; j < C; j++) {
        board[i][j] = input[j];
      }
    }

    vPos = new boolean[R][C];
    vAlpha = new boolean['Z' - 'A' + 1];
    dfs(0, 0);

    System.out.println(max);
  }

  static void dfs(int x, int y) {
    if (vPos[x][y] || vAlpha[board[x][y] - 'A']){
      max = Math.max(max, count);
      return;
    }

    vPos[x][y] = true;
    vAlpha[board[x][y] - 'A'] = true;
    count++;

    for (int i = 0; i < 4; i++) {
      int tempX = x + dx[i];
      int tempY = y + dy[i];
      if (tempX >= 0 && tempX < R && tempY >= 0 && tempY < C) {
        dfs(tempX, tempY);
      }
    }

    vPos[x][y] = false;
    vAlpha[board[x][y] - 'A'] = false;
    count--;
  }

}
