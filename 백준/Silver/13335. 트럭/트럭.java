import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken()); // 트럭의 수
    int w = Integer.parseInt(st.nextToken()); // 다리의 길이
    int L = Integer.parseInt(st.nextToken()); // 최대 하중

    Queue<Integer> queue = new LinkedList<>();
    for (int i = 0; i < w; i++) {
      queue.add(0);
    }

    int sum = 0, count = 0;
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      int r = queue.remove();
      sum -= r;

      int input = Integer.parseInt(st.nextToken());
      while (sum + input > L) {
        queue.add(0);
        sum -= queue.remove();
        count++;
      }
      queue.add(input);
      sum += input;
      count++;
    }

    System.out.println(count + w);
  }

}
