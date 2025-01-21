package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_1966 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      int N = Integer.parseInt(st.nextToken());
      int target = Integer.parseInt(st.nextToken());
      int tPoint = 0;
      Queue<Integer> queue = new LinkedList<>();
      int[] counts = new int[10]; // 중요도 별 개수 저장

      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        int x = Integer.parseInt(st.nextToken());
        if (j == target) tPoint = x;
        queue.add(x);
        counts[x]++;
      }

      int count = 1;
      boolean find = false;
      // 높은 중요도부터 탐색
      for (int j = 9; j >= 1; j--) {
        while (counts[j] != 0) {
          // 현재 탐색하는 중요도와 찾는 문서의 중요도가 같고
          // 타겟의 위치가 맨 왼쪽으로 왔을 때
          if (j == tPoint && target == 0){
            find = true;
            break;
          }
          Integer temp = queue.poll();
          if (temp == j) {  // 맨 왼쪽의 중요도가 높은 중요도면 뺌
            count++;
            counts[j]--;
          } else { // 높은 중요도가 아니면 다시 넣음
            queue.add(temp);
          }
          target = (target - 1) >= 0 ? (target - 1) : queue.size() - 1; // 타겟의 위치는 서서히 왼쪽으로 옴, -1이 되면 제일 오른쪽으로 이동
        }
        if (find) {
          break;
        }
      }
      System.out.println(count);
    }
  }
}
