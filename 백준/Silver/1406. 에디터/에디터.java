import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        String line = reader.readLine();
        Stack<Character> st = new Stack<>();
        for(int i=0;i<line.length();i++)st.push(line.charAt(i));
        int m = Integer.parseInt(reader.readLine());
        Stack<Character>tmp = new Stack<>();
        for(int i=0;i<m;i++){
            String opr = reader.readLine();
            char command = opr.charAt(0);
            if(command == 'L' && !st.isEmpty()) tmp.push(st.pop());
            else if(command == 'D' && !tmp.isEmpty()) st.push(tmp.pop());
            if(command == 'B' && !st.isEmpty()) st.pop();
            if(command == 'P') st.push(opr.charAt(2));
        }
        while(!tmp.isEmpty())st.push(tmp.pop());
        for(int i=0;i<st.size();i++)writer.write(st.get(i));
        writer.flush();
        writer.close();
    }
}