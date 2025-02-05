package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_14502 {

  static int[][] lab, tempLab;
  static boolean[][] visited;
  static int[] dx = {1, -1, 0, 0};
  static int[] dy = {0, 0, 1, -1};
  static int N, M, answer = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken()); // 세로 크기
    M = Integer.parseInt(st.nextToken()); // 가로 크기

    lab = new int[N][M];
    tempLab = new int[N][M];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        lab[i][j] = Integer.parseInt(st.nextToken());
        tempLab[i][j] = lab[i][j];
      }
    }

    wall(0);

    System.out.println(answer);
  }

  static void wall(int n) {
    if (n == 3) {
      for (int i = 0; i < N; i++) {
        System.arraycopy(lab[i], 0, tempLab[i], 0, M);
      }

      visited = new boolean[N][M];

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (lab[i][j] == 2) {
            bfs(i, j);
          }
        }
      }

      int count = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (tempLab[i][j] == 0) {
            count++;
          }
        }
      }
      answer = Math.max(answer, count);
    } else {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (lab[i][j] == 0) {
            lab[i][j] = 1;
            wall(n + 1);
            lab[i][j] = 0;
          }
        }
      }
    }
  }

  static void bfs(int x, int y) {
    Queue<int[]> queue = new LinkedList<>();
    queue.add(new int[]{x, y});
    visited[x][y] = true;

    while (!queue.isEmpty()) {
      int[] pos = queue.poll();

      for (int i = 0; i < 4; i++) {
        int nextX = pos[0] + dx[i];
        int nextY = pos[1] + dy[i];
        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && tempLab[nextX][nextY] == 0) {
          tempLab[nextX][nextY] = 2;
          queue.add(new int[]{nextX, nextY});
        }
      }
    }

  }

//  static void dfs(int x, int y) {
//    if (visited[x][y]) return;
//    visited[x][y] = true;
//
//    for (int i = 0; i < 4; i++) {
//      int nextX = x + dx[i];
//      int nextY = y + dy[i];
//      if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && tempLab[nextX][nextY] == 0) {
//        tempLab[nextX][nextY] = 2;
//        dfs(nextX, nextY);
//      }
//    }
//  }


}
