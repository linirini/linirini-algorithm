import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T!=0){
            T--;
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String arr = br.readLine();
            Deque<String> dq = new ArrayDeque<>();
            StringTokenizer st = new StringTokenizer(arr.substring(1, arr.length() - 1),",");
            while(st.hasMoreTokens()){
                dq.add(st.nextToken());
            }
            int pointer = 0, flag = 0;
            List<String>ans = new ArrayList<>();
            for(int i=0;i<p.length();i++){
                if(p.charAt(i)=='R'){
                    pointer = 1-pointer;
                } else {
                    if(dq.isEmpty()){
                        flag = -1;
                        break;
                    }
                    if(pointer==0){
                        dq.pollFirst();
                    }else{
                        dq.pollLast();
                    }
                }
            }
            if(flag == -1) System.out.println("error");
            else {
                if (pointer == 0) {
                    while (!dq.isEmpty()) {
                        ans.add(dq.pollFirst());
                    }
                } else {
                    while (!dq.isEmpty()) {
                        ans.add(dq.pollLast());
                    }
                }
                StringBuilder sb = new StringBuilder();
                sb.append("[");
                sb.append(String.join(",", ans));
                sb.append("]");
                System.out.println(sb);
            }
        }
    }
}