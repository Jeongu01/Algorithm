import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Baekjoon_13414 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int K = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());
    Map<String, Integer> map = new HashMap<>();
    String[] arr = new String[L + 1];

    for (int i = 0; i < L; i++) {
      String studentId = br.readLine();

      if (map.containsKey(studentId)) {
        arr[map.get(studentId)] = null;
        map.remove(studentId);
      }
      map.put(studentId, i);
      arr[i] = studentId;
    }

    StringBuilder sb = new StringBuilder();

    int count = 0;
    for (int i = 0; i <= L; i++) {
      if (arr[i] != null) {
        sb.append(arr[i]).append("\n");
        count++;
      }
      if (count == K) break;
    }
    System.out.println(sb);
  }

}
