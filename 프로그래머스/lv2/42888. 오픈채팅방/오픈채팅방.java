import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        HashMap<String,Info> recordList = new HashMap<>();
        List<String> seq = new ArrayList<>();
        for(int i=0;i<record.length;i++){
            String[] tmp = record[i].split(" ");
            String command = tmp[0];
            String userId = tmp[1];
            String nickname = "";
            String inOut="";
            if(!command.equals("Change")){
                if(command.equals("Enter")){
                    nickname = tmp[2];
                    inOut = "1";
                    if(recordList.containsKey(userId)){
                        String rec = recordList.get(userId).getRec();
                        recordList.put(userId, new Info(nickname,rec+inOut));
                    }
                    else recordList.put(userId, new Info(nickname,inOut));
                }
                else if(command.equals("Leave")){
                    inOut = "0";
                    if(recordList.containsKey(userId)){
                        nickname = recordList.get(userId).getNickname();
                        String rec = recordList.get(userId).getRec();
                        recordList.put(userId, new Info(nickname,rec+inOut));
                    }
                }
                seq.add(userId);
            }
            else{
                nickname = tmp[2];
                if (recordList.containsKey(userId)) {
                    String rec = recordList.get(userId).getRec();
                    recordList.put(userId, new Info(nickname, rec));
                }
            }
        }
        List<String>ans = new ArrayList<>();
        for(int i=0;i<seq.size();i++){
            String userId = seq.get(i);
            String nick = recordList.get(userId).getNickname();
            String rec = recordList.get(userId).getRec();
            if(rec.charAt(0)=='1'){
                ans.add(nick+"님이 들어왔습니다.");
            }else{
                ans.add(nick+"님이 나갔습니다.");
            }
            rec = rec.substring(1,rec.length());
            recordList.put(seq.get(i), new Info(nick,rec));
        }
        String[] answer = new String[ans.size()];
        for(int i=0;i<ans.size();i++){
            answer[i]=ans.get(i);
        }
        return answer;
    }
    class Info{
        String nickname;
        String rec;
        public Info(String nickname, String rec){
            this.nickname = nickname;
            this.rec = rec;
        }
        public String getNickname(){
            return nickname;
        }
        public String getRec(){
            return rec;
        }
    }
}