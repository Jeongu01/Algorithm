import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[] arr = new int[N];
    int[] length = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
      length[i] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[j] > arr[i]) {
          length[i] = Math.max(length[i], length[j] + 1);
        }
      }
      max = Math.max(max, length[i]);
    }

    System.out.println(N - max);
  }

}
