package MST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_17472 {

  static int[][] map;
  static int[] parent;
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, -1, 1};
  static boolean[][] visited;
  static int N, M;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    map = new int[N][M];
    visited = new boolean[N][M];

    // 섬 정보 저장
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        map[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    // 섬 번호 메기기, 섬 번호는 2번부터 시작
    int mapCount = 0;   // 섬 개수
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j] == 1) {   // 같은 섬일 경우 같은 mapCount 를 적용
          dfs(i, j, ++mapCount + 1);  // 섬 번호는 2번부터 시작
        }
      }
    }

    parent = new int[mapCount + 2];
    for (int i = 2; i <= mapCount; i++) {
      parent[i] = i;
    }

    PriorityQueue<Bridge> queue = new PriorityQueue<>();

    // 다리 정보 저장
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j] != 0) {
          int mapNum = map[i][j]; // 현재 섬 번호
          for (int k = 0; k < 4; k++) { // 상하좌우 방향으로
            for (int l = 1; l < 10; l++) {  // 10 * 10 크기니까 10번을 넘지 않음
              int x = i + dx[k] * l;
              int y = j + dy[k] * l;
              if (x < 0 || x >= N || y < 0 || y >= M) { // 범위를 벗어나면 중지
                break;
              }
              // 땅을 발견하면 중지
              if (map[x][y] != 0) {
                // 다른 섬이고 거리가 2 이상이면 다리 정보 저장, 중복되는 다리 정보 저장을 방지하기 위해 start < end 조건을 붙임
                if (mapNum < map[x][y] && l > 2) {
                  queue.add(new Bridge(mapNum, map[x][y], l - 1));
                }
                break;
              }
            }
          }
        }
      }
    }

    int bridgeCount = 0;
    int answer = 0;
    while (bridgeCount < mapCount - 1 && !queue.isEmpty()) {
      Bridge now = queue.poll();
      if (find(parent[now.start]) != find(parent[now.end])) {
        answer += now.weight;
        bridgeCount++;
        union(now.start, now.end);
      }
    }

    if (bridgeCount == mapCount - 1) {
      System.out.println(answer);
    } else {
      System.out.println(-1);
    }
  }

  static public void dfs(int x, int y, int num) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    map[x][y] = num;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1) {
        dfs(nx, ny, num);
      }
    }
  }

  static public void union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
      parent[b] = a;
    }
  }

  static public int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  static class Bridge implements Comparable<Bridge>{

    int start;
    int end;
    int weight;

    public Bridge(int start, int end, int weight) {
      this.start = start;
      this.end = end;
      this.weight = weight;
    }

    @Override
    public int compareTo(Bridge bridge) {
      return this.weight - bridge.weight;
    }
  }

}
