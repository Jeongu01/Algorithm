import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Baekjoon_5567 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    int m = Integer.parseInt(st.nextToken());

    ArrayList<Integer>[] relations = new ArrayList[n + 1];
    boolean[] invited = new boolean[n + 1];

    for (int i = 0; i <= n; i++) {
      relations[i] = new ArrayList<>();
    }

    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());

      Integer a = Integer.parseInt(st.nextToken());
      Integer b = Integer.parseInt(st.nextToken());

      relations[a].add(b);
      relations[b].add(a);
    }

    for (Integer f : relations[1]) {
      invited[f] = true;
      for (Integer ff : relations[f]) {
        invited[ff] = true;
      }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
      if (invited[i]) count++;
    }
    System.out.println(count);
  }

}
