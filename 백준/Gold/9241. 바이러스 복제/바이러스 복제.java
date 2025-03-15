import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String before = reader.readLine();
        String after = reader.readLine();
        int st = 0, en = 0;
        int min = Math.min(before.length(), after.length());
        while(st<min && before.charAt(st) == after.charAt(st))st++;
        while(en<min && before.charAt(before.length() - 1 - en) == after.charAt(after.length() - 1 -en))en++;
        if(min-en <= st){
            if(before.length() > after.length())System.out.println(0);
            else System.out.println(after.length() - before.length());
        }
        else System.out.println(after.length() - en - st);
    }
}