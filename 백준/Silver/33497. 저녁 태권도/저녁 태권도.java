import java.util.*;
import java.io.*;
import java.lang.*;

public class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int[] A = new int[101];
        int[] B = new int[101];
        char[][] schedule = new char[N][M];
        int[] morningCount = new int[M];
        int[] eveningCount = new int[M];
        for(int i=0;i<M;i++){
            input = reader.readLine().split(" ");
            A[i] = Integer.parseInt(input[0]);
            B[i] = Integer.parseInt(input[1]);
        }
        for(int i=0;i<M;i++){
            if(A[i]+B[i]>N){
                System.out.println("NO");
                return;
            }
        }
        for (int student = 0; student < N; student++) {
            int bestDay = -1;
            int minNeed = Integer.MAX_VALUE;
            for (int day = 0; day < M; day++) {
                int need = Math.max(0, A[day] - morningCount[day]) + Math.max(0, B[day] - eveningCount[day]);
                if (need < minNeed) {
                    minNeed = need;
                    bestDay = day;
                }
            }
            for (int day = 0; day < M; day++) {
                if (day == bestDay) {
                    schedule[student][day] = 'X';
                } else {
                    if (morningCount[day] < A[day]) {
                       schedule[student][day] = '+';
                       morningCount[day]++;
                    } else {
                       schedule[student][day] = '-';
                       eveningCount[day]++;
                    }
                }
            }
        }
        for (int day = 0; day < M; day++) {
            if (morningCount[day] < A[day] || eveningCount[day] < B[day]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
        for (int i = 0; i < N; i++) System.out.println(new String(schedule[i]));
    }
}