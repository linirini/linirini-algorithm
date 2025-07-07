import java.util.*;
import java.io.*;

public class Main {
    
    public static int N;
    public static long[] A;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new long[N+1];
        long ans = 0;
        String[] input = br.readLine().split(" ");
        for(int i = 1; i <= N; i++) {
            A[i] = A[i-1] + Long.parseLong(input[i-1]);
        }
        for(int i = N; i > 0; i--) {
            ans += find(i);
        }
        System.out.println(ans);
    }
    
    private static long find(int now) {
        long belly = A[N] - A[now-1];
        long chestAndHead = A[now];
        if(belly >= chestAndHead) {
            return 0;
        }
        int st = 0, en = now - 1, cnt = 0;
        chestAndHead = A[now-1];
        while(st <= en) {
            int mid = (st + en) / 2;
            long head = A[mid];
            long chest = chestAndHead - head;
            if(head < belly && chest > belly){
                cnt = mid;
                st = mid + 1;
            }
            else {
                en = mid - 1;
            }
        }
        return cnt;
    }
}