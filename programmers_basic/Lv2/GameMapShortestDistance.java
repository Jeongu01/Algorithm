package Lv2;

public class GameMapShortestDistance {

  public static void main(String[] args) {
    GameMapShortestDistance Solution = new GameMapShortestDistance();
    int[][] maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };
    System.out.println(Solution.solution(maps));
    int[][] maps2 = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };
    System.out.println(Solution.solution(maps2));
    int[][] maps3 = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
    System.out.println(Solution.solution(maps3));
    int[][] maps4 = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    System.out.println(Solution.solution(maps4));
    int[][] maps5 = {
        {1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 1}
    };
    System.out.println(Solution.solution(maps5));

  }

  static boolean[][] isVisited;
  static int min = Integer.MAX_VALUE;

  public int solution(int[][] maps) {
    int n = maps.length - 1;
    int m = maps[0].length - 1;

    // 갈 수 있는지 확인
    if (maps[n - 1][m] == 0 && maps[n][m - 1] == 0) return -1;

    isVisited = new boolean[n + 1][m + 1];
    dfs(maps, 0, 0, 1);

    return min;
  }

  public static void dfs(int[][] maps, int x, int y, int distance) {
    int n = maps.length - 1;
    int m = maps[0].length - 1;
    if (isVisited[n][m]) min = Math.min(min, distance);

    if (x + 1 <= n && !isVisited[x + 1][y] && maps[x + 1][y] == 1) {
      isVisited[x + 1][y] = true;
      dfs(maps, x + 1, y, distance + 1);
      isVisited[x + 1][y] = false;
    }
    if (x - 1 >= 0 && !isVisited[x - 1][y] && maps[x - 1][y] == 1) {
      isVisited[x - 1][y] = true;
      dfs(maps, x - 1, y, distance + 1);
      isVisited[x - 1][y] = false;
    }
    if (y + 1 <= m && !isVisited[x][y + 1] && maps[x][y + 1] == 1) {
      isVisited[x][y + 1] = true;
      dfs(maps, x, y + 1, distance + 1);
      isVisited[x][y + 1] = false;
    }
    if (y - 1 >= 0 && !isVisited[x][y - 1] && maps[x][y - 1] == 1) {
      isVisited[x][y - 1] = true;
      dfs(maps, x, y - 1, distance + 1);
      isVisited[x][y - 1] = false;
    }
  }

}
