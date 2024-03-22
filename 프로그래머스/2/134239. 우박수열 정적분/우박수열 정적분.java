import java.util.*;
class Solution {
    List<Double> table = new ArrayList<>();
    public double[] solution(int k, int[][] ranges) {
        double[] answer = new double[ranges.length];
        double num = k;
        while(num!=1){
            table.add(num);
            if(num%2==0)num/=2;
            else num = num*3+1;
        }
        table.add(num);
        int n = table.size()-1;
        double[] sum = new double[table.size()];
        for(int i=1;i<table.size();i++){
            sum[i] = (table.get(i-1)+table.get(i))/2;
            sum[i] = sum[i-1] + sum[i];
        }
        for(int i=0;i<ranges.length;i++){
            int st = ranges[i][0];
            int en = n+ranges[i][1];
            answer[i] = st>en?-1:sum[en]-sum[st];
        }
        return answer;
    }
}