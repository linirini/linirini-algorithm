import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        String str = reader.readLine();
        int ans = 0;
        ArrayDeque<Integer>st = new ArrayDeque<Integer>();
        for (int i = 0; i < N; i++) {
            if(str.charAt(i)=='s') st.addLast(1);
            else if(str.charAt(i) == 'k'){
                if (!st.isEmpty() && st.peekLast() == 1) st.addLast(st.pollLast() + 1);
                else st.clear();
            } else if(str.charAt(i) == 'e') {
                if (!st.isEmpty() && (st.peekLast() == 2 || st.peekLast() == 3)) st.addLast(st.pollLast() + 1);
                else st.clear();
            } else if(str.charAt(i)=='p') {
                if (!st.isEmpty() && st.peekLast() == 4) st.addLast(st.pollLast() + 1);
                else st.clear();
            } else st.clear();
            
            while(!st.isEmpty() && st.peekLast() == 5){
                st.pollLast();
                ans++;
                if(!st.isEmpty()) st.addLast(st.pollLast()+1);
            }
        }
        System.out.println(ans);
    }
}