import java.util.*;
class Solution {
    
    public int cnt = 0; 
    public int number = 0;
    public int[] dx = {1,-1,0,0};
    public int[] dy = {0,0,-1,1};
    public int[][]area;
    public int[][] landCopy;
    public List<Integer> areaSize;
    
    public int solution(int[][] land) {
        int answer = 0;
        area = new int[land.length][land[0].length];
        landCopy = new int[land.length][land[0].length];
        areaSize = new ArrayList<>();
        for(int i=0;i<land.length;i++){
            for(int j=0;j<land[i].length;j++){
                area[i][j] = -1;
                landCopy[i][j] = land[i][j];
            }
        }
        for(int i=0;i<land.length;i++){
            for(int j=0;j<land[i].length;j++){
                if(land[i][j]==1 && area[i][j]==-1){
                    cnt = 1;
                    go(i,j);
                    number+=1;
                    areaSize.add(cnt);
                }
            }
        }
        for(int j=0;j<land[0].length;j++){
            Set<Integer> visited = new HashSet<>();
            int sum = 0;
            for(int i=0;i<land.length;i++){
                if(area[i][j]!=-1){
                    if(!visited.contains(area[i][j])){
                        sum +=areaSize.get(area[i][j]);
                        visited.add(area[i][j]);
                    }
                }
            }
            answer = Math.max(answer,sum);
        }
        return answer;
    }
    
    public void go(int x, int y){
        area[x][y]=number;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<landCopy.length&&ny>=0&&ny<landCopy[0].length){
                if(landCopy[nx][ny]==1 && area[nx][ny]==-1){
                    cnt+=1;
                    go(nx, ny);
                }
            }
        }
    }   
}