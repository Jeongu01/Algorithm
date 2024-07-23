package Lv3;

public class Network {

  public static void main(String[] args) {
    Network Solution = new Network();
    int[][] computers = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    System.out.println(Solution.solution(3, computers));
    int[][] computers2 = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    System.out.println(Solution.solution(3, computers2));
  }

  static boolean[] isVisited;
  public int solution(int n, int[][] computers) {
    int answer = 0;

    isVisited = new boolean[n];

    for (int i = 0; i < n; i++) {
      if (!isVisited[i]) {
        answer++;
        isVisited[i] = true;
        dfs(i, computers);
      }
    }

    return answer;
  }

  public static void dfs(int n, int[][] computers) {
    for (int i = 0; i < computers[0].length; i++) {
      if (!isVisited[i] && computers[n][i] == 1) {
        isVisited[i] = true;
        dfs(i, computers);
      }
    }
  }

}