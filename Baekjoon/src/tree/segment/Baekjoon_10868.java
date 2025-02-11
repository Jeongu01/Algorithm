package tree.segment;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_10868 {

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
    int[] tree = new int[treeSize + 1];
    Arrays.fill(tree, Integer.MAX_VALUE);

    for (int i = treeSize / 2; i < treeSize / 2 + N; i++) {
      st = new StringTokenizer(br.readLine());
      tree[i] = Integer.parseInt(st.nextToken());
    }


    for (int i = treeSize; i > 1; i--) {
      tree[i / 2] = Math.min(tree[i / 2], tree[i]);
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int start_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
      int end_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;

      int answer = Integer.MAX_VALUE;
      while (start_index <= end_index) {
        if (start_index % 2 == 1) answer = Math.min(answer, tree[start_index]);
        if (end_index % 2 == 0) answer = Math.min(answer, tree[end_index]);
        start_index = (start_index + 1) / 2;
        end_index = (end_index - 1) / 2;
      }
      System.out.println(answer);
    }
  }

}
