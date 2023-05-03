class Solution {
    public int solution(int[] array) {
        int answer = 0;
        int[] visited = new int[1001];
        int maxRange = 0;
        for(int i=0;i<array.length;i++){
            visited[array[i]]++;
            maxRange = Math.max(maxRange,array[i]);
        }
        int fre = 0,flag = 1;
        for(int i=0;i<=maxRange;i++){
            if(visited[i]>fre){
                flag = 1;
                answer = i;
                fre = visited[i];
            }else if(visited[i]==fre){
                flag = 0;
            }
        }
        if(flag == 0)answer = -1;
        return answer;
    }
}