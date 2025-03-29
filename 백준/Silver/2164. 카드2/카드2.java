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

    int n = Integer.parseInt(st.nextToken());

    Queue<Integer> queue = new LinkedList<>();

    for (int i = 1; i <= n; i++) {
      queue.add(i);
    }

    int answer = 0;
    while (!queue.isEmpty()) {
      answer = queue.remove();
      if (queue.isEmpty()) break;
      queue.add(queue.remove());
    }

    System.out.println(answer);
  }

}
