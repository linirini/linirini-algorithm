import java.util.*;

class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        HashMap<Character,String> words = new HashMap<>() {{
            put('a',"aya");
            put('y',"ye");
            put('w',"woo");
            put('m',"ma");
        }};
        for(String s: babbling) {
            char prev=' ';
            int i=0;
            while(i<s.length()) {
                if(prev==s.charAt(i)) break;
                String word = words.getOrDefault(s.charAt(i),"");
                if(word.equals("")) break;
                String curStr = s.substring(i,Math.min(s.length(),i+word.length()));

                if(curStr.equals(word)) {
                    prev = s.charAt(i);
                    i+= word.length();
                } 
                else break;
            }
            if(i==s.length()) answer++;
        }
        return answer;
    }
}