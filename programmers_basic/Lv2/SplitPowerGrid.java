package Lv2;

public class SplitPowerGrid {

  public static void main(String[] args) {
    SplitPowerGrid Solution = new SplitPowerGrid();
    int[][] wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
    System.out.println(Solution.solution(9, wires));
    int[][] wires2 = {{1, 2}, {2, 3}, {3, 4}};
    System.out.println(Solution.solution(4, wires2));
    int[][] wires3 = {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}};
    System.out.println(Solution.solution(7, wires3));
  }

  int[][] edges;
  boolean[] visited;
  int count;

  public int solution(int n, int[][] wires) {
    edges = new int[n + 1][n + 1];

    for (int[] wire : wires) {
      edges[wire[0]][wire[1]] = 1;
      edges[wire[1]][wire[0]] = 1;
    }

    int min = Integer.MAX_VALUE;
    for (int[] wire : wires) {
      visited = new boolean[n + 1];
      visited[wire[0]] = true;
      visited[wire[1]] = true;
      count = 1;
      dfs(wire[0]);
      min = Math.min(min, Math.abs(count - (n - count)));
    }

    return min;
  }

  public void dfs(int root) {
    for (int i = 1; i < edges.length; i++) {
      if (edges[root][i] == 1 && !visited[i]) {
        visited[i] = true;
        count++;
        dfs(i);
      }
    }
  }

}
