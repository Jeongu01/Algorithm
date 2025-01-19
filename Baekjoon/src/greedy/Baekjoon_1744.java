package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_1744 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int count0 = 0;
    int count1 = 0;
    PriorityQueue<Integer> posNums = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> negNums = new PriorityQueue<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      if (x == 0) {
        count0++;
      } else if (x == 1) {
        count1++;
      } else if (x > 1) {
        posNums.add(x);
      } else {
        negNums.add(x);
      }
    }

    int sum = 0;
    int data1;
    int data2;
    while (posNums.size() > 1) {
      data1 = posNums.remove();
      data2 = posNums.remove();
      sum += data1 * data2;
    }

    if (!posNums.isEmpty()) {
      sum += posNums.remove();
    }

    while (negNums.size() > 1) {
      data1 = negNums.remove();
      data2 = negNums.remove();
      sum += data1 * data2;
    }

    if (!negNums.isEmpty()) {
      if (count0 == 0) {
        sum += negNums.remove();
      }
    }

    sum += count1;
    System.out.println(sum);
  }

}
