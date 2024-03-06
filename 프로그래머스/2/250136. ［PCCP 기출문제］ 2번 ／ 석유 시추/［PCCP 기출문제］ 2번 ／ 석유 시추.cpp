#include <string>
#include <vector>
#include<iostream>
#include<set>

using namespace std;
int land_copy[501][501],area[501][501], number,cnt;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int>areaSize;

void go(int x, int y){
    area[x][y]=number;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(land_copy[nx][ny]&&area[nx][ny]==-1){
            cnt++;
            go(nx, ny);
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size(),M = land[0].size();
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            area[i][j]=-1;
            land_copy[i][j]=land[i][j];
        }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(land[i][j]&&area[i][j]==-1){
                cnt = 1;
                go(i,j);
                number++;
                areaSize.push_back(cnt);
            }
        }
    }
    for(int j=0;j<M;j++){
        int sum = 0;
        set<int>visited;
        for(int i=0;i<N;i++){
            if(area[i][j]!=-1){
                if(visited.find(area[i][j])==visited.end()){
                    sum+=areaSize[area[i][j]];
                    visited.insert(area[i][j]);
                }
            }
        }
        answer = max(answer,sum);
    }
    return answer;
}