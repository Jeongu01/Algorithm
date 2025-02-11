package tree.segment;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2042 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());   // 수의 개수
    int M = Integer.parseInt(st.nextToken());   // 수의 변경 횟수
    int K = Integer.parseInt(st.nextToken());   // 구간의 합 구하는 횟수
    int treeHeight = 0;
    int length = N;

    while (length != 0) {
      length /= 2;
      treeHeight++;
    }

    int treeSize = (int) Math.pow(2, treeHeight + 1);
    long[] tree = new long[treeSize + 1];

    for (int i = treeSize / 2; i < treeSize / 2 + N; i++) {
      st = new StringTokenizer(br.readLine());
      tree[i] = Long.parseLong(st.nextToken());
    }

    // 부모 노드 채우기
    for (int i = treeSize; i > 1; i--) {
      tree[i / 2] += tree[i];
    }

    for (int i = 0; i < M + K; i++) {
      st = new StringTokenizer(br.readLine());
      int command = Integer.parseInt(st.nextToken());

      if (command == 1) { // 수 변경
        int index = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
        long org = tree[index];
        long val = Long.parseLong(st.nextToken());
        long change = val - org;
        while (index != 0) {
          tree[index] += change;
          index /= 2;
        }
      } else if (command == 2) {  // 구간 합
        int startIndex = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;
        int endIndex = Integer.parseInt(st.nextToken()) + treeSize / 2 - 1;

        long answer = 0;
        while (startIndex <= endIndex) {
          if (startIndex % 2 == 1) answer += tree[startIndex];
          if (endIndex % 2 == 0) answer += tree[endIndex];
          startIndex = (startIndex + 1) / 2;
          endIndex = (endIndex - 1) / 2;
        }
        System.out.println(answer);
      }
    }
  }

}
