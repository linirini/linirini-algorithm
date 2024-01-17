import java.util.*;
class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        Map<String,Integer> names = new HashMap<>();
        int[][] results = new int[friends.length][friends.length];
        int[] give = new int[friends.length];
        int[] take = new int[friends.length];
        int[] presentIndex = new int[friends.length];
        int[] ans = new int[friends.length];
        for(int i=0;i<friends.length;i++){
            names.put(friends[i],i);
        }
        for(int i=0;i<gifts.length;i++){
            String[] tmp = gifts[i].split(" ");
            results[names.get(tmp[0])][names.get(tmp[1])]++;
        }
        for(int i=0;i<results.length;i++){
            for(int j=0;j<results.length;j++){
                give[i]+=results[i][j];
            }
        }
        for(int j=0;j<results.length;j++){
            for(int i=0;i<results.length;i++){
                take[j]+=results[i][j];
            }
        }
        for(int i=0;i<presentIndex.length;i++){
            presentIndex[i]=give[i]-take[i];
        }
        for(int i=0;i<results.length;i++){
            for(int j=i+1;j<results.length;j++){
                if(results[i][j]>results[j][i]){
                    ans[i]++;
                }else if(results[i][j]<results[j][i]){
                    ans[j]++;
                }else if(results[i][j]==results[j][i]){
                    if(presentIndex[i]>presentIndex[j])ans[i]++;
                    else if(presentIndex[i]<presentIndex[j])ans[j]++;
                }
            }
        }
        for(int i=0;i<ans.length;i++){
            System.out.print(ans[i]);
            if(answer<ans[i])answer = ans[i];
        }
        return answer;
    }

}