package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_15683 {

  static int[][][] office;
  static ArrayList<CCTV> CCTVs;
  static int N, M, min;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    office = new int[N][M][2];  // office[N][M][1] : 이 위치를 감시중인 CCTV 의 수
    CCTVs = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        office[i][j][0] = Integer.parseInt(st.nextToken());
        if (office[i][j][0] != 0) {
          office[i][j][1]++;
        }
        if (1 <= office[i][j][0] && office[i][j][0] <= 5) {
          CCTVs.add(new CCTV(office[i][j][0], 1, i, j));
        }
      }
    }

    min = Integer.MAX_VALUE;
    if (CCTVs.size() == 0) {
      int count = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (office[i][j][1] == 0) count++;
        }
      }
      min = Math.min(min, count);
    } else {
      func(0);
    }
    System.out.println(min);
  }

  public static void func(int n) {
    CCTV now = CCTVs.get(n);
    for (int i = 0; i < 4; i++) {
      now.monitor(true);
      if (CCTVs.size() - 1 == n) {
        int count = 0;
        for (int j = 0; j < N; j++) {
          for (int k = 0; k < M; k++) {
            if (office[j][k][1] == 0) count++;
          }
        }
        min = Math.min(min, count);
      } else {
        func(n + 1);
      }
      now.monitor(false);
      now.turn();
    }
  }

  public static class CCTV {
    int type;
    int d;  // 보는 방향 1:상, 2:우, 3:하, 4:좌
    int x;
    int y;

    public CCTV(int type, int d, int x, int y) {
      this.type = type;
      this.d = d;
      this.x = x;
      this.y = y;
    }

    public void turn() {
      this.d = (this.d + 1) % 4;
      if (this.d == 0) this.d = 4;
    }

    public void monitor(boolean plus) {
      int[] directions = new int[4];
      directions[0] = this.d;
      if (this.type == 2) {
        directions[1] = (this.d + 2) % 4;
      } else if (this.type == 3) {
        directions[1] = (this.d + 1) % 4;
      } else if (this.type == 4) {
        directions[1] = (this.d + 1) % 4;
        directions[2] = (this.d + 2) % 4;
        if (directions[2] == 0) directions[2] = 4;
      } else if (this.type == 5) {
        directions = new int[]{1, 2, 3, 4};
      }
      if (this.type >= 2 && directions[1] == 0) directions[1] = 4;

      for (int direction : directions) {
        switch (direction) {
          case 1: // 상
            for (int i = this.x - 1; i >= 0; i--) {
              if (office[i][y][0] == 6)
                break;
              if (plus) {
                office[i][y][1]++;
              } else {
                office[i][y][1]--;
              }
            }
            break;
          case 2: // 우
            for (int i = this.y + 1; i < M; i++) {
              if (office[x][i][0] == 6)
                break;
              if (plus) {
                office[x][i][1]++;
              } else {
                office[x][i][1]--;
              }
            }
            break;
          case 3: // 하
            for (int i = this.x + 1; i < N; i++) {
              if (office[i][y][0] == 6)
                break;
              if (plus) {
                office[i][y][1]++;
              } else {
                office[i][y][1]--;
              }
            }
            break;
          case 4: // 좌
            for (int i = this.y - 1; i >= 0; i--) {
              if (office[x][i][0] == 6)
                break;
              if (plus) {
                office[x][i][1]++;
              } else {
                office[x][i][1]--;
              }
            }
            break;
        }
      }
    }
  }

}
