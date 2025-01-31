package unionfind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_1043 {

  static int[] parent;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken()); // 사람의 수
    int M = Integer.parseInt(st.nextToken()); // 파티의 수

    parent = new int[N + 1];
    ArrayList<Integer>[] parties = new ArrayList[M];

    for (int i = 1; i < N + 1; i++) {
      parent[i] = i;
    }

    // 진실을 아는 사람의 수
    boolean[] truth = new boolean[N + 1];

    st = new StringTokenizer(br.readLine());
    int a = Integer.parseInt(st.nextToken());
    for (int i = 0; i < a; i++) {
      truth[Integer.parseInt(st.nextToken())] = true;
    }

    // 각 파티마다 오는 사람 들
    for (int i = 0; i < M; i++) {
      parties[i] = new ArrayList<>();

      st = new StringTokenizer(br.readLine());
      int num = Integer.parseInt(st.nextToken());
      parties[i].add(Integer.parseInt(st.nextToken()));

      for (int j = 0; j < num - 1; j++) {
        union(parties[i].get(0), Integer.parseInt(st.nextToken()));
      }
    }

    // 진실을 알게 된 사람들 업데이트
    for (int i = 0; i < N + 1; i++) {
      if (truth[i]) {
        for (int j = 1; j < N + 1; j++) {
          if (find(parent[i]) == find(parent[j])) {
            truth[j] = true;
          }
        }
      }
    }

    int count = M;
    for (ArrayList<Integer> party : parties) {
      for (int person : party) {
        if (truth[person]) {
          count--;
          break;
        }
      }
    }

    System.out.println(count);
  }

  static void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      parent[b] = a;
    }
  }

  static int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
  }

}
