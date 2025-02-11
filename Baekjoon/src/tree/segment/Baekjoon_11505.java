package tree.segment;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_11505 {

  static final long divisor = 1_000_000_007;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());   // 수의 개수
    int M = Integer.parseInt(st.nextToken());   // 수의 변경 횟수
    int K = Integer.parseInt(st.nextToken());   // 구간의 곱 횟수

    int treeHeight = 0;
    int length = N;
    while (length != 0) {
      length /= 2;
      treeHeight++;
    }
    int treeSize = (int) Math.pow(2, treeHeight + 1);
    long[] tree = new long[treeSize + 1];
    Arrays.fill(tree, 1);

    for (int i = treeSize / 2; i < treeSize / 2 + N; i++) {
      st = new StringTokenizer(br.readLine());
      tree[i] = Long.parseLong(st.nextToken());
    }

    for (int i = treeSize; i > 1; i--) {
      tree[i / 2] = tree[i / 2] * tree[i] % divisor;
    }

    for (int i = 0; i < M + K; i++) {
      st = new StringTokenizer(br.readLine());
      int command = Integer.parseInt(st.nextToken());

      if (command == 1) { // 수의 변경
        int index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
        long value = Integer.parseInt(st.nextToken());
        tree[index] = value;
        index /= 2;

        while (index > 0) {
          tree[index] = tree[2 * index] * tree[2 * index + 1] % divisor;
          index /= 2;
        }
      } else if (command == 2) {  // 구간 곱 구하기
        int start_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
        int end_index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
        long answer = 1;

        while (start_index <= end_index) {
          if (start_index % 2 == 1) answer = answer * tree[start_index] % divisor;
          if (end_index % 2 == 0) answer = answer * tree[end_index] % divisor;
          start_index = (start_index + 1) / 2;
          end_index = (end_index - 1) / 2;
        }

        System.out.println(answer);
      }
    }
  }

}
