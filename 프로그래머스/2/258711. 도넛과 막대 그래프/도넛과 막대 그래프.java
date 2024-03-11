import java.util.*;
class Solution {
    
    public List<Integer>[] graph = new ArrayList[1000001];
    public int[] inEdge = new int[1000001];
    public int[] visited = new int[1000001];
    public int maxNum = 0;
    public int root = 0;
    public int nodeCount = 0;
    public int edgeCount = 0;
    
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        for (int i = 0; i < 1000001; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i=0;i<edges.length;i++){
            graph[edges[i][0]].add(edges[i][1]);
            inEdge[edges[i][1]]+=1;
            maxNum = Math.max(maxNum,Math.max(edges[i][0],edges[i][1]));
        }
        for(int i=1;i<=maxNum;i++){
            if(inEdge[i]==0 && graph[i].size()>1){
                root = i;
            }
        }
        answer[0]=root;
        for(int i=0;i<graph[root].size();i++){
            edgeCount = 0;
            nodeCount = 0;
            int next = graph[root].get(i);
            if(visited[next]==1){
                continue;
            }
            dfs(next);
            if(edgeCount==nodeCount){
                answer[1]++;
            }
            else if(edgeCount+1 == nodeCount){
                answer[2]++;
            }
            else {
                answer[3]++;
            }
        }
        return answer;
    }
    
    void dfs(int now){
        visited[now]=1;
        nodeCount++;
        for(int next : graph[now]){
            if(visited[next]==0)dfs(next);
            edgeCount++;
        }
    }
}