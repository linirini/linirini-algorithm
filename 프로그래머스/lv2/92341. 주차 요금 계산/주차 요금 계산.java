import java.util.*;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        int defaultTime = fees[0];
        int defaultCost = fees[1];
        int unitTime = fees[2];
        int unitCost = fees[3];
        Map<String, Record> recordList = new HashMap<>();
        Map<String,Integer> timeList = new HashMap<>();
        List<String> inCarList = new ArrayList<>();
        for(int i=0;i<records.length;i++){
            int h = Integer.parseInt(records[i].substring(0,2));
            int m = Integer.parseInt(records[i].substring(3,5));
            String carNumber = records[i].substring(6,10);
            String inOut = records[i].substring(11);
            int flag = 0;
            if(inOut.equals("IN"))flag = 1;
            if(flag == 1){
                recordList.put(carNumber,new Record(h, m));
                inCarList.add(carNumber);
            }else if(flag == 0){
                Record r = recordList.get(carNumber);
                int t = (h-r.getHour())*60 + m-r.getMinute();
                if(timeList.containsKey(carNumber))timeList.put(carNumber,timeList.get(carNumber)+t);
                else timeList.put(carNumber,t);
                inCarList.remove(carNumber);
            }
        }
        for(int i=0;i<inCarList.size();i++){
            String carNumber = inCarList.get(i);
            int h=recordList.get(carNumber).getHour();
            int m=recordList.get(carNumber).getMinute();
            int t = (23-h)*60+59-m;
            if(timeList.containsKey(carNumber))timeList.put(carNumber,timeList.get(carNumber)+t);
            else timeList.put(carNumber,t);
        }
        List<Integer>ans = new ArrayList<>();
        List<String>keySet = new ArrayList<>(timeList.keySet());
        Collections.sort(keySet);
        for(String key : keySet){
            int cost = defaultCost;
            int t = timeList.get(key) - defaultTime;
            if(t>0){
                if(t%unitTime == 0)cost+=(t/unitTime)*unitCost;
                else cost+=(t/unitTime+1)*unitCost;
            }
            ans.add(cost);
        }
        int[] answer = new int[ans.size()];
        for(int i=0;i<ans.size();i++){
            answer[i] = ans.get(i);
        }
        return answer;
    }
    class Record{
        int hour;
        int minute;
        public Record(int hour, int minute){
            this.hour = hour;
            this.minute= minute;
        }
        public int getHour(){
            return hour;
        }
        public int getMinute(){
            return minute;
        }
    }
}