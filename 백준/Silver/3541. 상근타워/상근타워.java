import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Elevator[] elevators = new Elevator[2001];
        String[] input = reader.readLine().split(" ");
        int ans = Integer.MAX_VALUE;
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        for(int i=0;i<m;i++){
            input = reader.readLine().split(" ");
            elevators[i]= new Elevator(
                Integer.parseInt(input[0]),
                Integer.parseInt(input[1])
            );
        }

        for (int i=0;i<m;i++) {
            int current = 0;
            int lcm = lcm(elevators[i].u, elevators[i].d);
            int k = (n % (lcm / elevators[i].u + lcm / elevators[i].d)) + lcm / elevators[i].u + lcm / elevators[i].d;

            for (int j = 0; j < k; j++) {
                if (current > elevators[i].d) current -= elevators[i].d;
                else current += elevators[i].u;
            }
            ans = Math.min(ans, current);
        }
        System.out.println(ans);
    }
    
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    
    static class Elevator{
        int u;
        int d;
        
        public Elevator(int u, int d){
            this.u = u;
            this.d = d;
        }
    }
}