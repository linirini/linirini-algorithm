import java.util.*;
class Solution {
    public int stx, sty, enx, eny, n, m;
    public int[] dx = { 1,-1,0,0};
    public int[] dy = {0,0,1,-1};
    public int[][] visited = new int[101][101];
    public Queue<Movement> q = new LinkedList();
    public int solution(String[] board) {
        int answer = 0;
        n = board.length;
        m = board[0].length();
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i].charAt(j)=='R'){
                    stx = i;
                    sty = j;
                }
                if(board[i].charAt(j)=='G'){
                    enx = i;
                    eny = j;
                }
            }
        }
        q.add(new Movement(stx,sty,0));
        while(!q.isEmpty()){
            int x = q.peek().x;
            int y = q.peek().y;
            int cnt = q.peek().cnt;
            q.poll();
            if(x == enx && y == eny){
                answer = cnt;
                break;
            }
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m ||  board[nx].charAt(ny) == 'D') continue; 
                while(true){
                    nx += dx[i]; 
                    ny += dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx].charAt(ny) == 'D'){
                        nx -= dx[i];
                        ny -= dy[i];
                        if(visited[nx][ny] == 0){
                            visited[nx][ny] = 1;
                            q.add(new Movement(nx, ny, cnt + 1));
                        }
                        break;
                    }
                }
            }
        }
        if(answer == 0){
            answer = -1;
        }
        return answer;
    }
    
    public class Movement{
        public int x;
        public int y;
        public int cnt;
        
        public Movement(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}