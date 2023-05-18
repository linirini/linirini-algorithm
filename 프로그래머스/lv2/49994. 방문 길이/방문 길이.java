class Solution {
    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,1,-1};
    public int solution(String dirs) {
        int answer = 0;
        int board[][] = new int[11][11];
        int visited[][][] = new int[11][11][4];
        int x = 5, y =5;
        for(int i=0;i<dirs.length();i++){
            char c = dirs.charAt(i);
            int idx = 0;
            if(c == 'U')idx=0;
            else if(c=='D')idx=1;
            else if(c=='R')idx=2;
            else if(c=='L')idx=3;
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if(nx>=0&&nx<11&&ny>=0&&ny<11){
                if(visited[nx][ny][idx]==0){
                    visited[nx][ny][idx]=1;
                    if(idx==0)visited[x][y][1]=1;
                    else if(idx==1)visited[x][y][0]=1;
                    else if(idx==2)visited[x][y][3]=1;
                    else if(idx==3)visited[x][y][2]=1;
                    answer++;
                }
                x=nx;
                y=ny;
            }
        }
        return answer;
    }
}