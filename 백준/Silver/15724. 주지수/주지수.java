import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str = br.readLine().split(" ");
		int N = Integer.parseInt(str[0]);
		int M = Integer.parseInt(str[1]);
		int[][] board = new int[N][M];
		int[][] sum = new int[N + 1][M + 1];
		int result = 0;
		for (int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(str[j]);
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + board[i][j];
			}
		}

		int K = Integer.parseInt(br.readLine());
		int stx, sty, enx, eny;

		for (int i = 0; i < K; i++) {
			str = br.readLine().split(" ");
			sty = Integer.parseInt(str[0]);
            stx = Integer.parseInt(str[1]);
			eny = Integer.parseInt(str[2]);
			enx = Integer.parseInt(str[3]);
			result = sum[eny][enx] - sum[eny][stx - 1] - sum[sty - 1][enx] + sum[sty - 1][stx - 1];
			System.out.println(result);

		}

	}

}