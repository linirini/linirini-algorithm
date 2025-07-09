import java.util.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int ans = 0;
        Set<Double> u = new LinkedHashSet<>();
        Set<Double> d = new LinkedHashSet<>();
        Set<Double> l = new LinkedHashSet<>();
        Set<Double> r = new LinkedHashSet<>();
        Set<Double> ul = new LinkedHashSet<>();
        Set<Double> ur = new LinkedHashSet<>();
        Set<Double> dr = new LinkedHashSet<>();
        Set<Double> dl = new LinkedHashSet<>();
        for(int i=0;i<N;i++){
            String[] input = br.readLine().split(" ");
            double x = Integer.parseInt(input[0]);
            double y = Integer.parseInt(input[1]);
            if (x == 0 && y > 0) {
				u.add(0.0);
			} else if (x == 0 && y < 0) {
				d.add(0.0);
			} else if (x > 0 && y == 0) {
				l.add(0.0);
			} else if (x < 0 && y == 0) {
				r.add(0.0);
			} else if (x > 0 && y > 0) {
				ul.add(Math.abs(y)/Math.abs(x));
			} else if (x > 0 && y < 0) {
				dl.add(Math.abs(y)/Math.abs(x));
			} else if (x < 0 && y > 0) {
				ur.add(Math.abs(y)/Math.abs(x));
			} else {
				dr.add(Math.abs(y)/Math.abs(x));
			}
        }
        ans = u.size() + d.size() + l.size() + r.size() + ul.size() + ur.size() + dr.size() + dl.size();
        System.out.println(ans);
    }
}