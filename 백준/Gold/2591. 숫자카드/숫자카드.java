import java.util.*;
import java.io.*;

class Main {
    public static int[] dp=new int[41];
    public static String str;
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        str = reader.readLine();
        dp[0]=1;
        for(int i=1; i<str.length();i++){
            if(Integer.parseInt(str.substring(i-1,i+1))<=34 && str.charAt(i-1) !='0'){
                if(i==1) dp[i]=1;
                else dp[i]=dp[i-2];
            }
            if(str.charAt(i)!='0') dp[i] += dp[i-1];
        }
        System.out.println(dp[str.length()-1]);
    }
    
    
}