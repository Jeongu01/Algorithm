package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_7562 {

  static boolean[][] board;
  static int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
  static int[] dy = {2, 1, -1, -2, -2, -1, 1, 2};
  static int l;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      l = Integer.parseInt(st.nextToken());

      st = new StringTokenizer(br.readLine());
      int now_x = Integer.parseInt(st.nextToken());
      int now_y = Integer.parseInt(st.nextToken());

      st = new StringTokenizer(br.readLine());
      int target_x = Integer.parseInt(st.nextToken());
      int target_y = Integer.parseInt(st.nextToken());

      board = new boolean[l][l];

      sb.append(bfs(now_x, now_y, target_x, target_y)).append("\n");
    }

    System.out.println(sb);
  }

  static int bfs(int x, int y, int target_x, int target_y) {
    Queue<int[]> queue = new LinkedList<>();
    queue.add(new int[]{x, y});
    board[x][y] = true;
    int count = 0;
    if (x == target_x && y == target_y) return count;

    while (!queue.isEmpty()) {
      int size = queue.size();
      count++;

      for (int k = 0; k < size; k++) {
        int[] now = queue.poll();

        for (int i = 0; i < 8; i++) {
          int next_x = now[0] + dx[i];
          int next_y = now[1] + dy[i];

          if (next_x >= 0 && next_x < l && next_y >= 0 && next_y < l) {
            if (next_x == target_x && next_y == target_y) return count;
            if (!board[next_x][next_y]) {
              board[next_x][next_y] = true;
              queue.add(new int[]{next_x, next_y});
            }
          }
        }
      }
    }

    return count;
  }

}
