package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_4963 {

  static int[][] island;
  static boolean[][] visited;
  static int w, h;
  static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
  static int[] dy = {0, 0, 1, -1, 1, -1, 1, -1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    while (true) {
      st = new StringTokenizer(br.readLine());

      w = Integer.parseInt(st.nextToken()); // 너비
      h = Integer.parseInt(st.nextToken()); // 높이

      if (w == 0 && h == 0) {
        break;
      }

      island = new int[h][w];
      visited = new boolean[h][w];

      // 섬 정보 저장
      for (int i = 0; i < h; i++) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < w; j++) {
          island[i][j] = Integer.parseInt(st.nextToken());
          if (island[i][j] == 0) visited[i][j] = true;  // 바다일 경우 방문한 거로 취급
        }
      }

      int count = 0;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (!visited[i][j]) {
            dfs(i, j);
            count++;
          }
        }
      }
      System.out.println(count);
    }
  }

  static public void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
      int xp = x + dx[i];
      int yp= y + dy[i];
      if (xp >= 0 && xp < h && yp >= 0 && yp < w) {
        dfs(xp, yp);
      }
    }
  }

}
