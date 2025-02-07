import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        List<Long> a = Arrays.stream(reader.readLine().split(" "))
                .map(Long::parseLong)
                .collect(Collectors.toList());
        long S = a.stream().mapToLong(Long::longValue).sum();
        for(Long num: a){
            S=Math.max(S,-num);
        }
        System.out.println(S);
    }
}