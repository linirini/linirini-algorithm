import java.util.*;
import java.io.*;

public class Main{
    
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        int ans = 0;
        int[] books = new int[N];
        for(int i = 0; i < N; i++) {
            books[i] = Integer.parseInt(reader.readLine());
        }
        int num = N;
        for(int i = N - 1; i >= 0; i--){
            if(books[i] == num)num--;
            else ans++;
        }
        System.out.println(ans);
    }
}