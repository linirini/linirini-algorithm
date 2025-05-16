import java.io.*;
import java.util.*;

public class Main {

	public static final int INF = 987654321; 
    
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		int[][] map = new int[N+1][N+1];
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(i != j) map[i][j] = INF;
			}
		}
		
		String str;
        StringTokenizer st;
		while(!(str = br.readLine()).equals("-1 -1")) {
			st = new StringTokenizer(str);
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			map[a][b] = 1;
			map[b][a] = 1;
		}
		
		for(int k = 1; k <= N; k++) {
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= N; j++) {
					if(map[i][k] + map[k][j] < map[i][j]){
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		
		int min = INF;
		int[] answer = new int[N+1];
		for(int i = 1; i <= N; i++) {
			int score = 0;
			for(int j = 1; j <= N; j++) {
				score = Math.max(score, map[i][j]);
			}
			answer[i] = score;
			min = Math.min(min, score);
		}
		
		int cnt = 0;
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= N; i++) {
			if(answer[i] == min) {
				cnt++;
				sb.append(i +" ");
			}
		}
		
		System.out.println(min + " " + cnt);
		System.out.println(sb.toString());
		
	}
}
