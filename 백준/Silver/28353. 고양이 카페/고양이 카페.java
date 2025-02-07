import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(str.nextToken());
        int K = Integer.parseInt(str.nextToken());
        str = new StringTokenizer(reader.readLine());
        List<Integer> cats = new ArrayList<>();
        for (int i = 0; i < N; i++) cats.add(Integer.parseInt(str.nextToken()));
        Collections.sort(cats);
        int start = 0;
        int end = cats.size()-1;
        int count = 0;
        while (start < end) {
            if (cats.get(start) + cats.get(end) <= K) {
                count += 1;
                start += 1;
                end -= 1;
            }
            if (cats.get(start) + cats.get(end) > K) end -= 1;
        }
        System.out.println(count);
    }
}
