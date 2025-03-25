import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int[] counts = new int[10];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    Queue<Integer> queue = new LinkedList<>();

    st = new StringTokenizer(br.readLine());

    int answer = 0;
    for (int i = 0; i < N; i++) {
      int input = Integer.parseInt(st.nextToken());
      queue.add(input);
      counts[input]++;

      while (countType() > 2) {
        int k = queue.remove();
        counts[k]--;
      }

      answer = Math.max(answer, countFruits());
    }

    System.out.println(answer);
  }

  public static int countType() {
    int c = 0;
    for (int i = 1; i < 10; i++) {
      if (counts[i] != 0) {
        c++;
      }
    }
    return c;
  }

  public static int countFruits() {
    int c = 0;
    for (int i = 1; i < 10; i++) {
      c += counts[i];
    }
    return c;
  }
}
