import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int a, b, count = 1;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    a = Integer.parseInt(st.nextToken());
    b = Integer.parseInt(st.nextToken());

    while (a < b) {
      count++;
      if (b % 2 == 0) b /= 2;
      else if (b % 10 == 1) b /= 10;
      else {
        count = -1;
        break;
      }
    }

    if (a != b) count = -1;

    System.out.println(count);
  }

}
