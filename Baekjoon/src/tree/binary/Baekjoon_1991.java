package tree.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_1991 {

  static char[] tree;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    tree = new char[(int) Math.pow(2, N)];
    Arrays.fill(tree, '.');
    tree[1] = 'A';
    int[] pos = new int[N];
    pos[0] = 1;

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      char node = st.nextToken().charAt(0);

      int index = pos[node - 'A'];
      char left = st.nextToken().charAt(0);
      if (left != '.') {
        tree[index * 2] = left;
        pos[left - 'A'] = index * 2;
      }
      char right = st.nextToken().charAt(0);
      if (right != '.') {
        tree[index * 2 + 1] = right;
        pos[right - 'A'] = index * 2 + 1;
      }
    }

    preOrder(1);
    System.out.println();
    inOrder(1);
    System.out.println();
    postOrder(1);
  }

  public static void preOrder(int n) {
    if (n >= tree.length) return;
    if (tree[n] == '.') return;
    System.out.print(tree[n]);
    preOrder(n * 2);
    preOrder(n * 2 + 1);
  }

  public static void inOrder(int n) {
    if (n >= tree.length) return;
    if (tree[n] == '.') return;
    inOrder(n * 2);
    System.out.print(tree[n]);
    inOrder(n * 2 + 1);
  }

  public static void postOrder(int n) {
    if (n >= tree.length) return;
    if (tree[n] == '.') return;
    postOrder(n * 2);
    postOrder(n * 2 + 1);
    System.out.print(tree[n]);
  }

}
