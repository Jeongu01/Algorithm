package tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
* 주석처리 되어 있는 부분은 삭제 노드의 자식들에 임의의 노드를 추가함으로 리프 노드가 아니게 만드는 방법
* 실제 실행 코드는 삭제 노드를 미리 방문 처리를 하여 해당 노드의 자식 노드로는 방문하지 않게 하는 방법
* */
public class Baekjoon_1068 {

  static int N, target, answer = 0;
  static ArrayList<Integer>[] tree;
//  static int[] parent;
  static boolean[] visited;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    tree = new ArrayList[N];
    visited = new boolean[N];
//    parent = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      tree[i] = new ArrayList<>();
    }

    int root = 0;
    for (int i = 0; i < N; i++) {
      int p = Integer.parseInt(st.nextToken());
//      parent[i] = p;
      if (p == -1) {
        root = i;
      } else {
        tree[p].add(i);
      }
    }

    st = new StringTokenizer(br.readLine());
    target = Integer.parseInt(st.nextToken());
    visited[target] = true;
    dfs(root);
    System.out.println(answer);

//    addNode(target);  // target 및 자식 노드들엔 노드를 하나씩 더 붙임
//
//    int leaf = 0;
//    for (int i = 0; i < N; i++) {
//      int p = parent[target];
//      int size = tree[i].size();
//      // target 의 부모 노드는 이후 계산할 때 size 에 -1을 한 값이 0인지 확인
//      if (size == 0 || (i == p && size == 1)) {
//        leaf++;
//      }
//    }
//
//    System.out.println(leaf);
  }

//  static void addNode(int n) {
//    tree[n].add(-1);
//    for (Integer child : tree[n]) {
//      if (child != -1) {
//        addNode(child);
//      }
//    }
//  }

  static void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    int size = tree[n].size();
    boolean haveTarget = false;
    for (int i = 0; i < size; i++) {
      int next = tree[n].get(i);
      if (next == target) haveTarget = true;
      dfs(next);
    }
    if (size == 0 || (size == 1 && haveTarget)) {
      answer++;
    }
  }

}
