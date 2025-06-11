import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] agrs) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        long N = Long.parseLong(input);
        long ans = 0;
        for(long i = N - 9 * input.length(); i <= N; i++) {
            long sum = find(i);
            if(sum == N){
                ans = i;
                break;
            }
        }
        System.out.println(ans);
    }
    
    private static long find(long num){
        long sum = num;
        while(num != 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}