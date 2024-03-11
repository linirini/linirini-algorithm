import java.util.*;
class Solution {
    
    public int[][] board;
    public int[][] visited;
    public List<Integer> ans = new ArrayList<>();
    public int[] dx = {1,-1,0,0};
    public int[] dy = {0,0,-1,1};
    int cnt = 0;
    
    public int[] solution(String[] maps) {
        int[] answer;
        board = new int[maps.length][maps[0].length()];
        visited = new int[maps.length][maps[0].length()];
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[i].length();j++){
                if(maps[i].charAt(j)=='X'){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = Integer.parseInt(""+maps[i].charAt(j));
                }
            }
        }
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]!=0 && visited[i][j]==0){
                    cnt = 0;
                    dfs(i,j);
                    ans.add(cnt);
                }
            }
        }
        if(ans.size()==0){
            ans.add(-1);
        }
        answer = new int[ans.size()];
        for(int i=0;i<ans.size();i++){
            answer[i]=ans.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }
    
    public void dfs(int x, int y){
        visited[x][y]=1;
        cnt+=board[x][y];
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<board.length&&ny>=0&&ny<board[0].length){
                if(board[nx][ny]!=0&&visited[nx][ny]==0){
                    dfs(nx,ny);
                }
            }
        }
    }
}