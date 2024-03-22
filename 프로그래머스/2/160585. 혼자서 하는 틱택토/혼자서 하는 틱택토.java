import java.util.*;
class Solution {
    public int solution(String[] board) {
        int answer = 1;
        int oCnt = 0;
        int xCnt = 0;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i].charAt(j)=='O')oCnt++;
                if(board[i].charAt(j)=='X')xCnt++;
            }
        }
        int oBingo = 0;
        int xBingo = 0;
        for(int i=0;i<board.length;i++){
            if(board[i].charAt(0)=='O'&&board[i].charAt(1)=='O'&&board[i].charAt(2)=='O')oBingo++;
            if(board[i].charAt(0)=='X'&&board[i].charAt(1)=='X'&&board[i].charAt(2)=='X')xBingo++;
        }
        for(int i=0;i<board.length;i++){
            if(board[0].charAt(i)=='O'&&board[1].charAt(i)=='O'&&board[2].charAt(i)=='O')oBingo++;
            if(board[0].charAt(i)=='X'&&board[1].charAt(i)=='X'&&board[2].charAt(i)=='X')xBingo++;
        }
        if(board[0].charAt(0) == 'O' && board[1].charAt(1)=='O'&&board[2].charAt(2) == 'O')oBingo++;
        if(board[0].charAt(0) == 'X' && board[1].charAt(1)=='X'&&board[2].charAt(2) == 'X')xBingo++;
        if(board[2].charAt(0) == 'O' && board[1].charAt(1)=='O'&&board[0].charAt(2) == 'O')oBingo++;
        if(board[2].charAt(0) == 'X' && board[1].charAt(1)=='X'&&board[0].charAt(2) == 'X')xBingo++;
        if(oCnt<xCnt)answer = 0;
        else if(oCnt-xCnt>1)answer = 0;
        else if(oBingo!=0 &&xBingo !=0 && oBingo == xBingo) answer = 0;
        else if(oBingo != 0 && oCnt == xCnt) answer = 0;
        else if(xBingo != 0 && oCnt>xCnt)answer = 0;
        return answer;
    }
}