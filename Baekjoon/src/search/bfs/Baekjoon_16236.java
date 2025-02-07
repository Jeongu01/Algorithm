package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_16236 {

  static int[][] arr;
  static boolean[][] eaten;
  static boolean[][] visited;
  static int N, time, size = 2, exp = 0;
  static int[] dx = {-1, 0, 0, 1};
  static int[] dy = {0, -1, 1, 0};
  static Pos target;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken()); // 공간의 크기
    arr = new int[N][N];
    eaten = new boolean[N][N];

    Pos sharkPos = new Pos(0, 0);

    // 공간의 상태 저장
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
        if (arr[i][j] == 0) eaten[i][j] = true;         // 0 일 경우 먹힌 물고기로 취급
        if (arr[i][j] == 9) sharkPos = new Pos(i, j);
      }
    }

    move(sharkPos);

    System.out.println(time);
  }

  static void move(Pos p) {
    Queue<Pos> queue = new LinkedList<>();
    queue.add(p);
    visited = new boolean[N][N];
    visited[p.x][p.y] = true;
    eaten[p.x][p.y] = true;
    target = new Pos(100, 100);  // 초기 값은 최대 범위보다 큰 값으로 설정

    int depth = 0;
    while (!queue.isEmpty()) {

      int qsize = queue.size();
      depth++;
      boolean find = false;

      // 같은 거리 내에 먹을 수 있는 물고기가 있는지 찾기
      while (qsize > 0) {
        qsize--;
        Pos now = queue.poll();

        for (int i = 0; i < 4; i++) {
          int nextX = now.x + dx[i];
          int nextY = now.y + dy[i];

          if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
            if (arr[nextX][nextY] < size && !eaten[nextX][nextY]) {  // 먹을 수 있는 물고기찾기
              if (target.x > nextX || (target.x == nextX && target.y > nextY)) {
                find = true;
                target = new Pos(nextX, nextY);
              }
            }
            if (arr[nextX][nextY] == size || eaten[nextX][nextY]) { // 지나갈 수 있는 경우 해당 위치를 큐에 저장
              if (!visited[nextX][nextY]) { // 지나간 곳을 또 지나지 않기 위함
                visited[nextX][nextY] = true;
                queue.add(new Pos(nextX, nextY));
              }
            }
          }
        }
      }

      // 먹을 수 있는 물고기가 있는 경우 해당 위치로 move 실행
      if (find) {
        time += depth;
        exp++; // 사이즈 키우기
        if (exp == size) {
          size++;
          exp = 0;
        }
        move(target);
        break;  // 더이상의 반복은 의미가 없으므로 중단 시켜줌
      }
    }
  }

  static class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }
}
