import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Mandu[] mandus = new Mandu[101];
        int ans = 0;
        int[][] dp = new int[11][1001];
        String[] input = reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);
        int d = Integer.parseInt(input[3]);
        mandus[0] = new Mandu(0,0,c,d);
        for(int i=1;i<=m;i++){
            input = reader.readLine().split(" ");
            mandus[i] = new Mandu(
                Integer.parseInt(input[0]),
                Integer.parseInt(input[1]),
                Integer.parseInt(input[2]),
                Integer.parseInt(input[3])
            );
        }
        for(int i=1;i<=n;i++){
            if(i%mandus[0].c==0)dp[0][i]=i/mandus[0].c*mandus[0].d;
            ans = Math.max(ans, dp[0][i]);
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int cnt = Math.min(j/mandus[i].c,mandus[i].a/mandus[i].b);
                dp[i][j]=dp[i-1][j];
                for(int k=1;k<=cnt;k++){
                    if(j!=k*mandus[i].c && dp[i-1][j-k*mandus[i].c]==0)continue;
                    dp[i][j]=Math.max(dp[i-1][j-k*mandus[i].c]+k*mandus[i].d, dp[i][j]);
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }
        System.out.println(ans);
    }
    
    static class Mandu {
       int a;
       int b;
       int c;
       int d;
       
       public Mandu(int a, int b, int c, int d){
           this.a = a;
           this.b = b;
           this.c = c;
           this.d = d;
       }
    }
}