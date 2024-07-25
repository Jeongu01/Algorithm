import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Baekjoon_20920 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    Map<String, Integer> vocabularyMap = new HashMap<>();

    for (int i = 0; i < n; i++) {
      String s = br.readLine();
      if (s.length() >= m) {
        vocabularyMap.put(s, vocabularyMap.getOrDefault(s, 0) + 1);
      }
    }

    List<String> vocabularyList = new ArrayList<>(vocabularyMap.keySet());

    vocabularyList = vocabularyList.stream().sorted((s1, s2) -> {
      if (vocabularyMap.get(s1) - vocabularyMap.get(s2) != 0) {
        return vocabularyMap.get(s2) - vocabularyMap.get(s1);
      } else if (s1.length() != s2.length()) {
        return s2.length() - s1.length();
      } else {
        return s1.compareTo(s2);
      }
    }).collect(Collectors.toList());

    for (String s : vocabularyList) {
      bw.append(s).append("\n");
    }

    bw.flush();
  }
}
