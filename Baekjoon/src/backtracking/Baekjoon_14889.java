package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_14889 {

  static int N, teamCount = 0, answer = Integer.MAX_VALUE;
  static int[][] abilities;
  static boolean[] team;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    abilities = new int[N][N];
    team = new boolean[N];  // true: start 팀, false: link 팀

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        abilities[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    makeTeam(0);
    System.out.println(answer);
  }

  static void makeTeam(int s) {
    if (teamCount == N / 2) {
      int startTeam = 0, linkTeam = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (team[i] && team[j]) {
            startTeam += abilities[i][j];
          }
          if (!team[i] && !team[j]) {
            linkTeam += abilities[i][j];
          }
        }
      }
      answer = Math.min(answer, (int) Math.abs(startTeam - linkTeam));
      return;
    }
    for (int i = s + 1; i < N; i++) {
      team[i] = true;
      teamCount++;
      makeTeam(i);
      team[i] = false;
      teamCount--;
    }
  }

}
