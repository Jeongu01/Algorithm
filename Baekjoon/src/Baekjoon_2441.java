import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2441 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            for (int j = i; j >0; j--) {
                System.out.print(" ");
            }
            for(int j = i; j < n; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
