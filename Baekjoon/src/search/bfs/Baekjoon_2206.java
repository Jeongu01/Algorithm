package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_2206 {

  static int[][] arr;
  static int[] dx = new int[]{0, 0, -1, 1};
  static int[] dy = new int[]{-1, 1, 0, 0};
  static boolean[][][] visited;
  static int N, M;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    arr = new int[N][M];
    visited = new boolean[N][M][2];

    for (int i = 0; i < N; i++) {
      String input = br.readLine();
      for (int j = 0; j < M; j++) {
        arr[i][j] = input.charAt(j) - '0';
      }
    }

    System.out.println(bfs());
  }

  static int bfs() {
    Queue<int[]> queue = new LinkedList<>();
    queue.add(new int[]{0, 0, 0});  // 행, 열, 벽을 부순 횟수
    visited[0][0][0] = true;
    int count = 1;

    boolean isReach = false;

    if (N == 1 && M == 1) return 1;
    while (!queue.isEmpty()) {
      int size = queue.size();
      count++;

      while (size-- > 0) {
        int[] now = queue.poll();
        int now_x = now[0];
        int now_y = now[1];
        int wall = now[2];

        for (int i = 0; i < 4; i++) {
          int next_x = now_x + dx[i];
          int next_y = now_y + dy[i];

          if (next_x == N - 1 && next_y == M - 1) {
            queue.clear();
            size = 0;
            isReach = true;
            break;
          }

          if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
            // 벽을 아직 안부순 경우
            if (wall == 0) {
              if (!visited[next_x][next_y][0] && arr[next_x][next_y] == 0) {
                visited[next_x][next_y][0] = true;
                queue.add(new int[]{next_x, next_y, 0});
              }
              if (!visited[next_x][next_y][1] && arr[next_x][next_y] == 1) {
                visited[next_x][next_y][1] = true;
                queue.add(new int[]{next_x, next_y, 1});
              }
            // 벽을 이미 부순 경우
            } else if (!visited[next_x][next_y][1] && arr[next_x][next_y] == 0) {
              visited[next_x][next_y][1] = true;
              queue.add(new int[]{next_x, next_y, 1});
            }
          }
        }
      }
    }

    if (isReach) return count;
    else return -1;
  }

}
