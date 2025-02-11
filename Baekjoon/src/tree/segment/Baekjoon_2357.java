package tree.segment;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_2357 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int treeHeight = 0;
    int length = N;
    while (length != 0) {
      length /= 2;
      treeHeight++;
    }
    int treeSize = (int) Math.pow(2, treeHeight + 1);
    int[][] tree = new int[2][treeSize + 1];  // 0: 최솟값 1: 최댓값
    Arrays.fill(tree[0], Integer.MAX_VALUE);
    Arrays.fill(tree[1], Integer.MIN_VALUE);

    for (int i = treeSize / 2; i < treeSize / 2 + N; i++) {
      st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      tree[0][i] = n;
      tree[1][i] = n;
    }

    for (int i = treeSize; i > 1; i--) {
      tree[0][i / 2] = Math.min(tree[0][i / 2], tree[0][i]);
      tree[1][i / 2] = Math.max(tree[1][i / 2], tree[1][i]);
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int start_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
      int end_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;

      int min = Integer.MAX_VALUE;
      int max = Integer.MIN_VALUE;
      while (start_index <= end_index) {
        if (start_index % 2 == 1) {
          min = Math.min(min, tree[0][start_index]);
          max = Math.max(max, tree[1][start_index]);
        }
        if (end_index % 2 == 0) {
          min = Math.min(min, tree[0][end_index]);
          max = Math.max(max, tree[1][end_index]);
        }

        start_index = (start_index + 1) / 2;
        end_index = (end_index - 1) / 2;
      }
      System.out.println(min + " " + max);
    }
  }

}
