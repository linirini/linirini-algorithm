import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        int[] A = new int[N];
        StringTokenizer str = new StringTokenizer(reader.readLine());
        for(int i=0;i<N;i++){
            A[i] = Integer.parseInt(str.nextToken());
        }
        Arrays.sort(A);
        int st = 0, en = A.length-1;
        long ans = Integer.MAX_VALUE;
        while(st<en){
            long value = A[st]+A[en];
            if(Math.abs(value) < Math.abs(ans)){
                ans = value;
            }
            if(value == 0){
                ans = 0;
                break;
            }
            else if(value<0){
                st++;
            }
            else{
                en--;
            }
        }
        System.out.println(ans);
    }
}