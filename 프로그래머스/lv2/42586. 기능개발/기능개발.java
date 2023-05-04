import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] pro = new int[progresses.length];
        ArrayList<Integer>ans = new ArrayList<>();
        for(int i=0;i<progresses.length;i++){
            if((100-progresses[i])%speeds[i]==0)pro[i]=(100-progresses[i])/speeds[i];
            else pro[i] = (100-progresses[i])/speeds[i]+1;
        }
        int day = pro[0],cnt=1;
        for(int i=1;i<pro.length;i++){
            if(day>=pro[i])cnt++;
            else{
                day=pro[i];
                ans.add(cnt);
                cnt = 1;
            }
        }
        ans.add(cnt);
        int[] answer = new int[ans.size()];
        for(int i=0;i<ans.size();i++)answer[i]=ans.get(i);
        return answer;
    }
}