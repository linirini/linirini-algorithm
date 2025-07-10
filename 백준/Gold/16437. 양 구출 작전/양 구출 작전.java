import java.util.*;
import java.io.*;

public class Main {
    static Node[] nodes;
    static List<List<Integer>> graph;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        nodes = new Node[N+1];
        graph = new ArrayList<>();
        for(int i=0;i<=N;i++){
            graph.add(new ArrayList<>());
        }
        nodes[1] = new Node(false, 0);
        for(int i=2;i<=N;i++) {
            String[] input = br.readLine().split(" ");
            graph.get(Integer.parseInt(input[2])).add(i);
            if(input[0].equals("W")){
                nodes[i] = new Node(true, Integer.parseInt(input[1]));
            } else{
                nodes[i] = new Node(false, Integer.parseInt(input[1]));
            }
        }
        System.out.println(dfs(1));
    }
    
    static class Node {
        boolean isWolf;
        int count;
        
        public Node(boolean isWolf, int count) {
            this.isWolf = isWolf;
            this.count = count;
        }
    }
    
    private static long dfs(int now) {
        long ans = 0;
        for(int next : graph.get(now)) {
            ans += dfs(next);
        }
        if(nodes[now].isWolf) {
            ans -= nodes[now].count;
            if(ans < 0) ans = 0;
        } else {
            ans += nodes[now].count;
        }
        return ans;
    }
}