class Solution {
    public int solution(String before, String after) {
        int answer = 1;
        int[] visited = new int[26];
        for(int i=0;i<before.length();i++){
            visited[before.charAt(i)-'a']++;
        }
        for(int i=0;i<after.length();i++){
            if(visited[after.charAt(i)-'a']==0){
                answer = 0;
                break;
            }
            else visited[after.charAt(i)-'a']--;
        }
        return answer;
    }
}