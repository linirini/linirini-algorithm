import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        int dp[]= new int[100001];
        for(int i=1;i<=100000;i++)dp[i]=101;
        StringTokenizer st = new StringTokenizer(reader.readLine());
        List<Integer> C = new ArrayList<>();
        while(st.hasMoreTokens()){
            C.add(Integer.parseInt(st.nextToken()));
        }
        dp[0]=0;
        for(Integer c : C){
            for(int i = K; i>=c;i--){
                if(i-c>=0)dp[i]=Math.min(dp[i-c]+1, dp[i]);
            }
        }
        if(dp[K]==101)System.out.println(-1);
        else System.out.println(dp[K]);
    }
}