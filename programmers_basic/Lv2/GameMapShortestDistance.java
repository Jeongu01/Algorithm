package Lv2;

import java.util.LinkedList;
import java.util.Queue;

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
    System.out.println(Solution.solution(maps));  // 11
    int[][] maps2 = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };
    System.out.println(Solution.solution(maps2));   // -1
    int[][] maps3 = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
    System.out.println(Solution.solution(maps3));   // 9
    int[][] maps4 = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    System.out.println(Solution.solution(maps4));   // 9
    int[][] maps5 = {
        {1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 1}
    };
    System.out.println(Solution.solution(maps5));   // -1

  }


  public int solution(int[][] maps) {
    int n = maps.length - 1;
    int m = maps[0].length - 1;

    Queue<Pos> queue = new LinkedList<>();
    boolean[][] isVisited = new boolean[n + 1][m + 1];

    queue.add(new Pos(0, 0, 1));
    isVisited[0][0] = true;

    while (!queue.isEmpty()) {
      Pos currentPos = queue.remove();
      int x = currentPos.x;
      int y = currentPos.y;
      int dist = currentPos.dist;

      if (x == n && y == m) {
        return dist;
      }
      if (x - 1 >= 0 && !isVisited[x - 1][y] && maps[x - 1][y] == 1) {
        queue.add(new Pos(x - 1, y, dist + 1));
        isVisited[x - 1][y] = true;
      }
      if (x + 1 <= n && !isVisited[x + 1][y] && maps[x + 1][y] == 1) {
        queue.add(new Pos(x + 1, y, dist + 1));
        isVisited[x + 1][y] = true;
      }
      if (y - 1 >= 0 && !isVisited[x][y - 1] && maps[x][y - 1] == 1) {
        queue.add(new Pos(x, y - 1, dist + 1));
        isVisited[x][y - 1] = true;
      }
      if (y + 1 <= m && !isVisited[x][y + 1] && maps[x][y + 1] == 1) {
        queue.add(new Pos(x, y + 1, dist + 1));
        isVisited[x][y + 1] = true;
      }

    }

    return -1;
  }

  static class Pos {

    int x;
    int y;
    int dist;

    public Pos(int x, int y, int dist) {
      this.x = x;
      this.y = y;
      this.dist = dist;
    }
  }

}
