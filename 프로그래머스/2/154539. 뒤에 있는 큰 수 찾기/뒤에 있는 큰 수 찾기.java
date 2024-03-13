import java.util.*;
class Solution {
    public int[] solution(int[] numbers) {
        Stack<Pair> st = new Stack<>();
        int[] answer = new int[numbers.length];
        for(int i=0;i<numbers.length;i++){
            while(!st.isEmpty() && st.peek().first<numbers[i]){
                answer[st.peek().second] = numbers[i];
                st.pop();
            }
            st.push(new Pair(numbers[i],i));
        }
        while(!st.isEmpty()){
            answer[st.peek().second] = -1;
            st.pop();
        }
        return answer;
    }
    
    class Pair{
        int first;
        int second;
        public Pair(int first, int second){
            this.first = first;
            this.second = second;
        }
    }
}