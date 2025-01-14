package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
* dfs 는 재귀함수를 사용하여 구현
* bfs 는 queue 를 사용하여 구현
*
* 문제에서 오름차순으로 방문하라고 하여 탐색을 하기 전 미리 정렬
* */
public class Baekjoon_1260 {

  static ArrayList<Integer>[] arr;
  static boolean[] visited;
  static int N, M;
  static StringBuilder builder = new StringBuilder();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    int V = Integer.parseInt(st.nextToken());

    arr = new ArrayList[N + 1];
    visited = new boolean[N + 1];

    // arr 초기화
    for (int i = 0; i < N + 1; i++) {
      arr[i] = new ArrayList<>();
    }

    // 간선 정보 저장
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int v1 = Integer.parseInt(st.nextToken());
      int v2 = Integer.parseInt(st.nextToken());

      arr[v1].add(v2);
      arr[v2].add(v1);
    }

    // 오름차순으로 정렬
    for (int i = 0; i < N + 1; i++) {
      arr[i].sort((a, b) -> a - b);
    }

    dfs(V);

    System.out.println(builder.toString());
    builder = new StringBuilder();

    visited = new boolean[N + 1];

    bfs(V);
    System.out.println(builder.toString());

  }

  static void dfs(int v) {
    if (visited[v]) {
      return;
    }

    visited[v] = true;
    builder.append(v).append(" ");
    for (int i = 0; i < arr[v].size(); i++) {
      dfs(arr[v].get(i));
    }

  }

  static void bfs(int start) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    visited[start] = true;
    builder.append(start).append(" ");

    while (!queue.isEmpty()) {
      int v = queue.poll();

      for (Integer i : arr[v]) {
        if (!visited[i]) {
          visited[i] = true;
          builder.append(i).append(" ");
          queue.add(i);
        }
      }
    }

  }

}
