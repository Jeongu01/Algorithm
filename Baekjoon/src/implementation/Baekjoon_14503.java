package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_14503 {

  static int[][] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    arr = new int[N][M];

    st = new StringTokenizer(br.readLine());    // 로봇 청소기 정보
    int r = Integer.parseInt(st.nextToken());   // 위치
    int c = Integer.parseInt(st.nextToken());
    int d = Integer.parseInt(st.nextToken());   // 바라보는 방향 0:북, 1:동, 2:남, 3:서
    Robot robot = new Robot(r, c, d);

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());   // 0:청소되지 않은 빈 칸, 1:벽, 2: 청소 됨
      }
    }

    int sum = 0;
    while (true) {
      // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
      if (arr[robot.r][robot.c] == 0) {
        arr[robot.r][robot.c] = 2;
        sum++;
      }
      boolean isMoved = false;
      for (int i = 0; i < 4; i++) {
        //    반시계 방향으로 회전
        robot.d = robot.d == 0 ? 3 : robot.d - 1;
        //    바라보는 방향이 청소 안되어 있으면 전진
        switch (robot.d) {
          case 0: // 북
            if (robot.r - 1 >= 0 && arr[robot.r - 1][robot.c] == 0) {
              robot.r -= 1;
              isMoved = true;
            }
            break;
          case 1: // 동
            if (robot.c + 1 < M && arr[robot.r][robot.c + 1] == 0) {
              robot.c += 1;
              isMoved = true;
            }
            break;
          case 2: // 남
            if (robot.r + 1 < N && arr[robot.r + 1][robot.c] == 0) {
              robot.r += 1;
              isMoved = true;
            }
            break;
          case 3: // 서
            if (robot.c - 1 >= 0 && arr[robot.r][robot.c - 1] == 0) {
              robot.c -= 1;
              isMoved = true;
            }
            break;
        }
        if (isMoved) break;
      }
      //    한칸 후진한다.  (청소된 곳이어도 후진 할 수 있으니까 벽만 아니면 됨)
      if (!isMoved) {
        boolean isBlocked = true;
        switch (robot.d) {
          case 0: // 북
            if (robot.r + 1 < N && arr[robot.r + 1][robot.c] != 1) {
              robot.r += 1;
              isBlocked = false;
            }
            break;
          case 1: // 동
            if (robot.c - 1 >= 0 && arr[robot.r][robot.c - 1] != 1) {
              robot.c -= 1;
              isBlocked = false;
            }
            break;
          case 2: // 남
            if (robot.r - 1 >= 0 && arr[robot.r - 1][robot.c] != 1) {
              robot.r -= 1;
              isBlocked = false;
            }
            break;
          case 3: // 서
            if (robot.c + 1 < M && arr[robot.r][robot.c + 1] != 1) {
              robot.c += 1;
              isBlocked = false;
            }
            break;
        }
        // 후진이 안되면 멈춘다
        if (isBlocked) break;
      }
      //    1번으로 돌아감
    }

    System.out.println(sum);
  }

  private static class Robot {
    int r;
    int c;
    int d;

    public Robot(int r, int c, int d) {
      this.r = r;
      this.c = c;
      this.d = d;
    }
  }
}
