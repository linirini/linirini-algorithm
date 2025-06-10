import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(str.nextToken());
        int M = Integer.parseInt(str.nextToken());
        long [][] dp = new long[N+1][M+1];
        int[][] garo = new int[N][M+1];
        int[][] sero = new int[N+1][M];
        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            str = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(str.nextToken());
            int b = Integer.parseInt(str.nextToken());
            int c = Integer.parseInt(str.nextToken());
            int d = Integer.parseInt(str.nextToken());
            if(b == d) {
                garo[Math.min(a, c)][b] = 1;
            }
            else {
                sero[a][Math.min(b, d)] = 1;
            }
        }
        for (int i = 1; i < N+1; i++) {
            if (garo[i-1][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 1; i < M+1; i++) {
            if (sero[0][i-1] == 1) {
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (garo[i-1][j] == 1) {
                    dp[i][j] -= dp[i-1][j];
                }
                if (sero[i][j-1] == 1) {
                    dp[i][j] -= dp[i][j-1];
                }
            }
        }
        System.out.println(dp[N][M]); 
    }
}