package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_16960 {

  static int[] L;  // 램프 -> 스위치 개수
  static ArrayList<Integer>[] S;  // 스위치 -> 램프 정보

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken()); // 스위치의 수
    int M = Integer.parseInt(st.nextToken()); // 램프의 수

    S = new ArrayList[N + 1];
    for (int i = 0; i <= N; i++) {
      S[i] = new ArrayList<>();
    }

    L = new int[M + 1];

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      int K = Integer.parseInt(st.nextToken()); // 스위치와 연결된 램프의 수

      for (int j = 0; j < K; j++) {
        int l = Integer.parseInt(st.nextToken());
        S[i].add(l);
        L[l]++;
      }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
      int size = S[i].size();
      int[] temps = new int[size]; // 스위치에 연결된 램프 리스트
      for (int j = 0; j < size; j++) {
        temps[j] = S[i].get(j);
      }

      boolean b = true;
      for (int j = 0; j < size; j++) {
        L[temps[j]]--;
        if (L[temps[j]] == 0) {
          b = false;
        }
      }
      if (b) answer = 1;

      for (int j = 0; j < size; j++) {
        L[temps[j]]++;
      }
    }

    System.out.println(answer);
  }

}
