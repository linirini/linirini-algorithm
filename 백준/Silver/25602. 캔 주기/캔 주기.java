import java.util.*;
import java.io.*;

public class Main {
    
    public static int N, K;
    public static int[] A;
    public static int[][] R, M;
    public static int ans = 0;
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        A = new int[N];
        R = new int[K][N];
        M = new int[K][N];
        input = reader.readLine().split(" ");
        for(int i = 0; i < N; i++){
            A[i] = Integer.parseInt(input[i]);
        }
        for(int i = 0; i < K; i++) {
            input = reader.readLine().split(" ");
            for(int j = 0; j < N; j++) {
                R[i][j] = Integer.parseInt(input[j]);
            }
        }
        for(int i = 0; i < K; i++) {
            input = reader.readLine().split(" ");
            for(int j = 0; j < N; j++) {
                M[i][j] = Integer.parseInt(input[j]);
            }
        }
        go(0, 0, 0);
        System.out.println(ans);
    }
    
    static void go(int day, int r, int m) {
        if (day >= K) {
            ans = Math.max(ans, r + m);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (A[i] > 0) {
                A[i]--;
                int nowR = r + R[day][i];

                for (int j = 0; j < N; j++) {
                    if (A[j] > 0) {
                        A[j]--;
                        int nowM = m + M[day][j];
                        go(day + 1, nowR, nowM);
                        A[j]++;
                    }
                }
                A[i]++;
            }
        }
    }
}