import java.util.*;
class Solution {
    public Queue<Integer> item = new LinkedList<>();
    public Stack<Integer> st = new Stack<>();
    
    public int solution(int[] order) {
        int answer = 0;
        for(int i=1;i<=order.length;i++){
            item.add(i);
        }
        int seq = 0;
        while(!item.isEmpty()||!st.empty()){
            if(!item.isEmpty() &&item.peek()==order[seq]){
                item.poll();
                seq++;
            }
            else if(!st.empty()&& st.peek() == order[seq]){
                st.pop();
                seq++;
            }
            else if(!item.isEmpty() && item.peek()!=order[seq]){
                st.push(item.poll());
            }
            else break;
        }
        answer = seq;
        return answer;
    }
    
}