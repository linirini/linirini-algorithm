import java.util.*;
class Solution {
    public PriorityQueue<Integer> pq = new PriorityQueue<>();
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        for(int i=0;i<enemy.length;i++){
            if(k>0){
                pq.add(enemy[i]);
                k--;
            }
            else{
                int num = enemy[i];
                if(pq.peek()<enemy[i]){
                    num = pq.poll();
                    pq.add(enemy[i]);
                }
                if(n>=num){
                    n = n-num;
                }
                else{
                    break;
                }
            }
            answer++;
        }
        return answer;
    }
}