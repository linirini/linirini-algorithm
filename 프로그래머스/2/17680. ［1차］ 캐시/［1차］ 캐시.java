import java.util.*;

class Solution {
    
    public static int HIT = 1;
    public static int MISS = 5;
    public Queue<String> LRU = new LinkedList<>();
    public Set<String> cache = new HashSet<>();
    
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        for(int i=0;i<cities.length;i++){
            cities[i] = cities[i].toLowerCase();
        }
        for(int i=0;i<cities.length;i++){
            if(cacheSize==0){
                answer+=MISS;
            }
            else if(!cache.contains(cities[i])){
                if(cache.size()==cacheSize){
                    cache.remove(LRU.poll());
                }
                cache.add(cities[i]);
                LRU.add(cities[i]);
                answer+=MISS;
            }
            
            else{
                LRU.remove(cities[i]);
                LRU.add(cities[i]);
                answer+=HIT;
            }
        }
        return answer;
    }
}