package MST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_1414 {

  static int[] parent;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());

    parent = new int[N];

    for (int i = 0; i < N; i++) {
      parent[i] = i;
    }

    PriorityQueue<Lan> queue = new PriorityQueue<>();

    int answer = 0;
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      char[] input = st.nextToken().toCharArray();
      for (int j = 0; j < N; j++) {
        int value = 0;
        if ('a' <= input[j] && input[j] <= 'z') {
          value = input[j] - 'a' + 1;
        } else if ('A' <= input[j] && input[j] <= 'Z') {
          value = input[j] - 'A' + 27;
        }
        answer += value;
        if (i != j && value != 0) { // 자기자신, 랜선이 없는 경우 제외하고 큐에 저장
          queue.add(new Lan(i, j, value));
        }
      }
    }

    int lanCount = 0;
    while (lanCount < N - 1 && !queue.isEmpty()) {
      Lan now = queue.poll();
      if (find(now.start) != find(now.end)) {
        union(now.start, now.end);
        lanCount++;
        answer -= now.length;
      }
    }

    if (lanCount == N - 1) {
      System.out.println(answer);
    } else {
      System.out.println("-1");
    }
  }

  static public void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      parent[b] = a;
    }
  }

  static public int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  static class Lan implements Comparable<Lan>{
    int start;
    int end;
    int length;

    public Lan(int start, int end, int length) {
      this.start = start;
      this.end = end;
      this.length = length;
    }

    @Override
    public int compareTo(Lan lan) {
      return this.length - lan.length;
    }
  }
}
