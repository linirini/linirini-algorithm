import java.util.*;
import java.io.*;

class Main{
    static final int OFFSET = 1500;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean[][] board = new boolean[3100][3100];
    static int count;
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        Queue<Node>queue = new LinkedList<>();
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        for(int i=0;i<N;i++){
            String[] line= reader.readLine().split("");
            for(int j=0;j<M;j++){
                if(line[j].equals("o")){
                    board[i+OFFSET][j+OFFSET] = true;
                    queue.add(new Node(i+OFFSET, j+OFFSET, 0));
                }
            }
        }
        int K = Integer.parseInt(reader.readLine());
        while(!queue.isEmpty()) {
            Node now = queue.poll();
            count++;
            if (now.moveCnt >= K) continue;
            for (int i = 0; i < 4; i++) {
                int nextRow = now.row + dx[i];
                int nextCol = now.col + dy[i];
                if (board[nextRow][nextCol]) continue;
                board[nextRow][nextCol] = true;
                queue.add(new Node(nextRow, nextCol, now.moveCnt + 1));
            }
        }
        System.out.println(count);
    }
    
    static class Node {
        int row, col, moveCnt;

        Node(int row, int col, int moveCnt) {
            this.row = row;
            this.col = col;
            this.moveCnt = moveCnt;
        }
    }
}