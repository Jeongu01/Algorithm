package Lv2;

public class Fatigue {

  public static void main(String[] args) {
    Fatigue Solution = new Fatigue();
    int[][] dungeons = {{80,20}, {50,40}, {30,10}};
    System.out.println(Solution.solution(80, dungeons));    // 3
    int[][] dungeons2 = {{78, 18}, {70, 11}, {67, 9}, {60, 8}, {59, 2}, {57, 54}};
    System.out.println(Solution.solution(78, dungeons2));    // 4
    int[][] dungeons3 = {{4, 3}, {2, 2}, {2, 2}};
    System.out.println(Solution.solution(4, dungeons3));    // 2
  }

  boolean[] visited;

  public int solution(int k, int[][] dungeons) {
    int answer = -1;
    visited = new boolean[dungeons.length];

    for (int i = 0; i < dungeons.length; i++) {
      answer = Math.max(answer , func(k, dungeons));
    }

    return answer;
  }

  public int func(int fatigue, int[][] dungeons) {
    boolean isLeaf = true;
    int max = Integer.MIN_VALUE;
    for (int i = 0; i < dungeons.length; i++) {
      if (!visited[i] && fatigue >= dungeons[i][0]) {
        isLeaf = false;
        visited[i] = true;
        max = Math.max(max, func(fatigue - dungeons[i][1], dungeons) + 1);
        visited[i] = false;
      }
    }
    if (isLeaf) return 0;
    else return max;
  }

}
