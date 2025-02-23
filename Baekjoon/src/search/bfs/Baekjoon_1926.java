package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_1926 {

  static int[][] arr;
  static boolean[][] isVisited;
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, -1, 1};
  static int n, m;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    arr = new int[n][m];
    isVisited = new boolean[n][m];

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!isVisited[i][j] && arr[i][j] == 1) {
          count++;
          isVisited[i][j] = true;
          max = Math.max(max, bfs(new Pos(i, j)));
        }
      }
    }
    System.out.println(count);
    System.out.println(max);
  }

  public static int bfs(Pos pos) {
    Queue<Pos> queue = new LinkedList<>();
    queue.add(pos);

    int sum = 0;
    while (!queue.isEmpty()) {
      Pos now = queue.poll();
      sum++;

      for (int i = 0; i < 4; i++) {
        int x = now.x + dx[i];
        int y = now.y + dy[i];

        if (x >= 0 && x < n && y >= 0 && y < m) {
          if (!isVisited[x][y] && arr[x][y] == 1) {
            isVisited[x][y] = true;
            queue.add(new Pos(x, y));
          }
        }
      }
    }
    return sum;
  }

  public static class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

}
