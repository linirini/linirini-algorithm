import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws Exception {
        int N = 0;
        int T = 0;
        Thunder[] thunder = new Thunder[1001];
        int total = 0;
        int[] dp = new int[1001];
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        T = Integer.parseInt(input[1]);
        for(int i=0;i<N;i++){
            input = reader.readLine().split(" ");
            thunder[i] = new Thunder(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
            total += Integer.parseInt(input[1]);
        }
        for(int i=0;i<N;i++){
            for(int j=T;j>= 0;j--){
                if(j-thunder[i].d >= 0)dp[j] = Math.max(dp[j],dp[j-thunder[i].d]+thunder[i].m);
            }
        }
        System.out.println(total - dp[T]);
    }
    
    static class Thunder {
        public int d;
        public int m;
        
        public Thunder(int d,int m){
            this.d = d;
            this.m = m;
        }
    }
}