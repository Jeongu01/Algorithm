package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_7569 {

  static int[][][] box;
  static int M, N, H;
  static Queue<Position> queue;
  static int[] dx = {1, -1, 0, 0, 0, 0};
  static int[] dy = {0, 0, 1, -1, 0 ,0};
  static int[] dz = {0, 0, 0, 0, 1, -1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());
    H = Integer.parseInt(st.nextToken());

    box = new int[H + 1][N + 1][M + 1];
    queue = new LinkedList<>();

    for (int i = 1; i < H + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        st = new StringTokenizer(br.readLine());
        for (int k = 1; k < M + 1; k++) {
          box[i][j][k] = Integer.parseInt(st.nextToken());
          if (box[i][j][k] == 1) {
            queue.add(new Position(i, j, k));
          }
        }
      }
    }

    int count = 0;
    while (!queue.isEmpty()) {
      bfs();
      count++;
    }

    count--;

    for (int i = 1; i < H + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        for (int k = 1; k < M + 1; k++) {
          if (box[i][j][k] == 0) {
            count = -1;
            break;
          }
        }
      }
    }

    System.out.println(count);
  }

  static void bfs() {
    int size = queue.size();
    for (int i = 0; i < size; i++) {
      Position position = queue.poll();
      int pos_x = position.x;
      int pos_y = position.y;
      int pos_z = position.z;

      for (int j = 0; j < 6; j++) {
        int x = pos_x + dx[j];
        int y = pos_y + dy[j];
        int z = pos_z + dz[j];

        if (x >= 1 && y >= 1 && z >= 1 && x <= H && y <= N && z <= M) {
          if (box[x][y][z] == 0) {
            box[x][y][z] = 1;
            queue.add(new Position(x, y, z));
          }
        }
      }
    }
  }

  static class Position {
    int x;
    int y;
    int z;

    public Position(int x, int y, int z) {
      this.x = x;
      this.y = y;
      this.z = z;
    }
  }

}
