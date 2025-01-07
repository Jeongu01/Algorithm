package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
* 노드 간의 관계를 저장하기 위한 friends 배열
* 방문 한 노드를 확인하기 위한 visited 배열
* 두 배열을 사용한 dfs 풀이
* */

public class Baekjoon_13023 {

  static boolean visited[];
  static ArrayList<Integer>[] friends;
  static boolean arrived = false;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    friends = new ArrayList[n];
    visited = new boolean[n];

    for (int i = 0; i < n; i++) {
      friends[i] = new ArrayList<>();
    }

    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      friends[a].add(b);
      friends[b].add(a);
    }

    for (int i = 0; i < n; i++) {
      dfs(i, 1);
      if (arrived) break;
    }

    System.out.println(arrived ? 1 : 0);
  }

  static void dfs(int now, int depth) {
    if (depth == 5 || arrived) {
      arrived = true;
      return;
    }

    visited[now] = true;  // 방문 체크
    if (!friends[now].isEmpty()) {  // 친구가 있다면
      for (Integer friend : friends[now]) { // 하나씩 방문
        if (!visited[friend]) {  // 방문 안 한 친구라면
          dfs(friend, depth + 1);
        }
      }
    }
    visited[now] = false;

  }

}
