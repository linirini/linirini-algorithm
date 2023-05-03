import java.util.*;
class Solution {
    public int[] solution(int l, int r) {
        ArrayList<Integer> list = new ArrayList<>();
        int n = 1;
        while(true)
        {
            int tmp = n, bit = 0, pos = 1;
            n++;
            while(tmp>0){
                int num = tmp%2;
                tmp/=2;
                bit += num*pos;
                pos*=10;
            }
            bit += tmp*pos;
            int cur = bit * 5;
            if(cur> r)break;
            if(cur<l)continue;
            list.add(cur);
        }  
        if(list.size()==0)list.add(-1);
        int count = list.size();
        int[] answer = new int[count];
         for (int i = 0; i < count; i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}