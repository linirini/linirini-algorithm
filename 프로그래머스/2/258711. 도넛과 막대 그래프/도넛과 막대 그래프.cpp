#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<int>graphEdge[1000001];
int inEdge[1000001],visited[1000001];
int root, MaxNum, nodeCount, edgeCount;
void dfs(int now){
    visited[now]=1;
    nodeCount++;
    for(int next : graphEdge[now]){
        if(!visited[next])dfs(next);
        edgeCount++;
    }
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for(int i=0;i<edges.size();i++){
        graphEdge[edges[i][0]].push_back(edges[i][1]);
        inEdge[edges[i][1]]++;
        MaxNum = max(MaxNum, max(edges[i][0],edges[i][1]));
    }
    for(int i=1;i<=MaxNum;i++)
        if(!inEdge[i]&&graphEdge[i].size()>1)root = i;
    answer.resize(4);
    answer[0]=root;
    for(int i=0;i<graphEdge[root].size();i++){
        edgeCount = 0;
        nodeCount = 0;
        int next = graphEdge[root][i];
        if(visited[next])continue;
        dfs(next);
        if(edgeCount==nodeCount)answer[1]++;
        else if(edgeCount+1 == nodeCount)answer[2]++;
        else answer[3]++;
    }
    return answer;
}