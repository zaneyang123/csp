#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; //邻接表

//c 当前点
//s 初试搜索的点
//mp 数组  
void solutionDFS(int c, int s, vector<int>& mp)
{
    if(mp[c] != 0) return;
    mp[c] = s;
    //遍历当前的点的所有逆邻接表
    for (int i = 0; i < adj[c].size(); i++)
	{
		solutionDFS(adj[c][i], s, mp);
	}
}

int main() 
{
    int N, M;

	scanf("%d%d", &N, &M);

    //邻接表初始化
    adj = vector<vector<int>>(N+1);

    int u, v;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &u, &v);
        //反向建边 构建逆邻接表
        adj[v].push_back(u);
	}

    vector<int> maxPoint = vector<int>(N + 1); //记录能访问到的最大的点 初始化每个值=0

    for (int i = N; i > 0; i--)
    {
        solutionDFS(i, i, maxPoint);
    }

    for (int i = 1; i <= N; i++)
	{
		printf("%d ", maxPoint[i]);
	}
	printf("\n");
	return 0;

}