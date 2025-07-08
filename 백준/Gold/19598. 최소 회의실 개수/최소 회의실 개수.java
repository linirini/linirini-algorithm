import java.util.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Room> rooms = new ArrayList<>();
        int ans = 0;
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            rooms.add(new Room(Long.parseLong(input[0]), 1));
            rooms.add(new Room(Long.parseLong(input[1]), -1));
        }
        Collections.sort(rooms);
        int cnt = 0;
        for(Room room: rooms) {
            cnt += room.isOver;
            ans = Math.max(ans, cnt);
        }
        System.out.println(ans);
    }
    
    static class Room implements Comparable<Room> {
        long st;
        int isOver;
        
        public Room(long st, int isOver){
            this.st = st;
            this.isOver = isOver;
        }
        
        @Override
        public int compareTo(Room o) {
            int cmp = Long.compare(this.st, o.st);
            if (cmp != 0) {
                return cmp;
            }
            return Integer.compare(this.isOver, o.isOver);
        }
    }
}