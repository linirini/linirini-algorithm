import java.util.*;

class Solution {
    public Set<String> set = new HashSet<>();

    public int solution(String word) {
        dfs("", 0);

        List<String> sortedList = new ArrayList<>(set);
        Collections.sort(sortedList);
        return sortedList.indexOf(word) + 1;
    }
    
    public void dfs(String word, int loop) {
        String[] chars = {"A","E","I","O","U"};
        if (loop == 5) {
            if (!"".equals(word)) {
                set.add(word);
            }
            return;
        }
        for (String el : chars) {
            dfs(word + el, loop + 1);
            dfs(word, loop + 1);
        }
    }
}
