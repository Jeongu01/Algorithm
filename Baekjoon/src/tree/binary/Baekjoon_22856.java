package tree.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_22856 {

  static int N, count = 0, visitCount = 0, answer, endPoint;
  static int[][] tree;
  static boolean[] isVisited;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken()); // 노드의 개수
    tree = new int[N + 1][2]; // tree[N][K] = N 번 노드의 K(0:왼, 1:오른)쪽 자식 노드
    isVisited = new boolean[N + 1];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());   // 현재 노드
      int b = Integer.parseInt(st.nextToken());   // 왼쪽 자식 노드
      int c = Integer.parseInt(st.nextToken());   // 오른쪽 자식 노드

      tree[a][0] = b;
      tree[a][1] = c;
    }

    endPoint = 1;
    while (tree[endPoint][1] != -1) {
      endPoint = tree[endPoint][1];
    }

    dfs(1);

    if (endPoint != 1) {
      System.out.println(answer);
    } else {
      System.out.println(count);
    }

  }

  static void dfs(int node) {
    if (isVisited[node]) return;
    isVisited[node] = true;
    visitCount++;

    int left = tree[node][0];
    int right = tree[node][1];

    if (left != -1) {
      count++;
      dfs(left);
      count++;
    }
    if (right != -1) {
      count++;
      dfs(right);
      count++;
    }

    if (node == endPoint && visitCount == N) answer = count;

  }

}
