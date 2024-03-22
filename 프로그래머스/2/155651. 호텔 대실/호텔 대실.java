import java.util.*;
class Solution {
    public int solution(String[][] book_time) {
        int[][] book = new int[book_time.length][2];
        for(int i=0;i<book_time.length;i++){
            String start = book_time[i][0];
            String end = book_time[i][1];
            int st_hour = Integer.parseInt(start.split(":")[0]);
            int st_minute = Integer.parseInt(start.split(":")[1]);
            int en_hour = Integer.parseInt(end.split(":")[0]);
            int en_minute = Integer.parseInt(end.split(":")[1]);
            book[i][0] = st_hour*60 + st_minute;
            book[i][1] = en_hour*60+en_minute+10;
        }
        Arrays.sort(book,new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[0]==o2[0]){
                    return o1[1]-o2[1];
                }
                return o1[0]-o2[0];
            }
        });
        PriorityQueue<Integer>pq = new PriorityQueue<>();
        for(int i=0;i<book.length;i++){
            if(!pq.isEmpty()){
                if(pq.peek() <=book[i][0]){
                    pq.poll();
                }
            }
            pq.add(book[i][1]);
        }
        return pq.size();
    }
}