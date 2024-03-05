import java.util.*;
class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        Map<String,Integer> index = new HashMap<>();
        for(int i=0;i<friends.length;i++){
            index.put(friends[i],i);
        }
        int[][] giveAndTake = new int[friends.length][friends.length];
        for(int i=0;i<gifts.length;i++){
            String give = gifts[i].split(" ")[0];
            String take = gifts[i].split(" ")[1];
            giveAndTake[index.get(give)][index.get(take)]++;
        }
        int[] presentPow = new int[friends.length]; 
        int[] nextPresent = new int[friends.length]; 
        for(int i=0;i<giveAndTake.length;i++){
            int give = 0;
            int take = 0;
            for(int j=0;j<giveAndTake[i].length;j++){
                give = give + giveAndTake[i][j];
                take = take + giveAndTake[j][i];
            }
            presentPow[i] = give-take;
        }
        for(int i=0;i<giveAndTake.length;i++){
            for(int j=i+1;j<giveAndTake[i].length;j++){
                if(giveAndTake[i][j]>giveAndTake[j][i]){
                    nextPresent[i]++;
                }
                else if(giveAndTake[i][j]==giveAndTake[j][i]){
                    if(presentPow[i]>presentPow[j]){
                        nextPresent[i]++;
                    }else if(presentPow[i]<presentPow[j]){
                        nextPresent[j]++;
                    }
                }
                else if(giveAndTake[i][j]<giveAndTake[j][i]){
                    nextPresent[j]++;
                }
            }
        }
        for(int i=0;i<nextPresent.length;i++){
            System.out.println(nextPresent[i]);
            answer = Math.max(answer,nextPresent[i]);
        }
        return answer;
    }

}