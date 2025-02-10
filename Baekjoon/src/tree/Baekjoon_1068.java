package tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_1068 {

  static int N;
  static ArrayList<Integer>[] tree;
  static int[] parent;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    tree = new ArrayList[N];
    parent = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      tree[i] = new ArrayList<>();
    }

    for (int i = 0; i < N; i++) {
      int p = Integer.parseInt(st.nextToken());
      parent[i] = p;
      if (p != -1) {
        tree[p].add(i);
      }
    }

    st = new StringTokenizer(br.readLine());
    int target = Integer.parseInt(st.nextToken());
    addNode(target);  // target 및 자식 노드들엔 노드를 하나씩 더 붙임

    int leaf = 0;
    for (int i = 0; i < N; i++) {
      int p = parent[target];
      int size = tree[i].size();
      // target 의 부모 노드는 이후 계산할 때 size 에 -1을 한 값이 0인지 확인
      if (size == 0 || (i == p && size == 1)) {
        leaf++;
      }
    }

    System.out.println(leaf);
  }

  static void addNode(int n) {
    tree[n].add(-1);
    for (Integer child : tree[n]) {
      if (child != -1) {
        addNode(child);
      }
    }
  }


}
