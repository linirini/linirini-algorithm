import java.util.*;
import java.io.*;

class Main {
    static int command;
    static Miro[] miros;
    static int flag;

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            command = Integer.parseInt(reader.readLine());
            if (command == 0)
                break;
            miros = new Miro[command + 1];
            for (int i = 1; i <= command; i++) {
                StringTokenizer str = new StringTokenizer(reader.readLine());
                String content = str.nextToken();
                int cost = Integer.parseInt(str.nextToken());
                List<Integer> rooms = new ArrayList<>();
                while (str.hasMoreTokens()) {
                    int room = Integer.parseInt(str.nextToken());
                    if (str.hasMoreTokens())
                        rooms.add(room);
                }
                miros[i] = new Miro(content, cost, rooms);
            }
            flag = 0;
            go(1, 0);
            if (flag == 0)
                System.out.println("No");
            else
                System.out.println("Yes");
        }
    }

    private static void go(int now, int cost) {
        if (flag == 1)
            return;
        if (now == command) {
            flag = 1;
            return;
        }
        for (Integer room : miros[now].rooms) {
            if (miros[room].visit)
                continue;
            if (miros[room].content.equals("L")) {
                if (cost < miros[room].cost)
                    cost = miros[room].cost;
            } else if (miros[room].content.equals("T")) {
                if (cost < miros[room].cost)
                    return;
                else
                    cost -= miros[room].cost;
            }

            miros[room].visit = true;
            go(room, cost);
            miros[room].visit = false;
        }
    }

    static class Miro {
        String content;
        int cost;
        List<Integer> rooms;
        boolean visit;

        public Miro(String content, int cost, List<Integer> rooms) {
            this.content = content;
            this.cost = cost;
            this.rooms = rooms;
            this.visit = false;
        }
    }
}