#include<bits/stdc++.h>
using namespace std;

/**
* 最近公共祖先
* 倍增法
* Luogu-3379
*/

/*
输入：
5 5 4
3 1
2 4
5 1
1 4

2 4
3 2
3 5
1 2
4 5

输出：
4
4
1
4
4
*/

//数据储存方式
const int MAXN=500050,MAXF=19;

vector<int> G[MAXN];//存图
int depth[MAXN];//点深度
int father[MAXN][MAXF];//[i][j]为第i个点的距离为2^j的祖先
bool vis[MAXN];//访问标记

/*
假设与u距离2^5=32步的祖先节点为v

那么与u距离2^6=64步的祖先节点，也就是与v距离2^5=32步的祖先节点

又因为深度优先搜索，所以一旦搜索到某个节点u

也就代表着它的所有祖先都已经被搜索并处理过

此时就能直接获得迭代关系 father[u] [i] = father[v] [i-1]

此时u=pos , v=father[pos] [i-1]

所以关系为 father[pos] [i] = father[ father[pos] [i-1] ] [i-1]
*/

//dfs处理与每个节点存在指数关系的father以及深度depth
void dfs(int pos,int fa)
{
	vis[pos]=true;
	depth[pos]=depth[fa]+1;
	father[pos][0]=fa;
	for(int i=1;i<MAXF;i++)
		father[pos][i]=father[father[pos][i-1]][i-1];
	int cnt=G[pos].size();
	for(int i=0;i<cnt;i++)
	{
		if(!vis[G[pos][i]])
			dfs(G[pos][i],pos);
	}
}

//求出最近公共祖先LCA
int lca(int a,int b)
{
	while(depth[a]<depth[b])//如果b的深度比a大
	{
		for(int i=MAXF-1;i>=0;i--)
		{
			if(depth[b]-(1<<i)>=depth[a])//如果b跳2^i步后深度大于等于a，则可以进行跳跃
				b=father[b][i];
		}
	}
	while(depth[a]>depth[b])//如果a的深度比b大
	{
		for(int i=MAXF-1;i>=0;i--)
		{
			if(depth[a]-(1<<i)>=depth[b])//同上，如果a跳2^i步后深度大于等于b，则可以进行跳跃
				a=father[a][i];
		}
	}
    
	if(a==b)//处理完深度后，如果ab为同一节点，说明原本就在同一条边上，此时直接返回即可
		return a;
    
	while(father[a][0]!=father[b][0])//如果与ab相邻的父节点不是同一个节点，说明还需要继续寻找下去
	{
		for(int i=MAXF-1;i>=0;i--)
		{
			if(father[a][i]!=father[b][i])//如果跳跃2^i步到达的祖先节点不同的话才能跳跃
			{
				a=father[a][i];
				b=father[b][i];
			}
		}
	}
	return father[a][0];//返回此时相邻的父节点作为LCA
}

int main()
{
	//输入数据的处理与调用
	int n,m,s,a,b;
	scanf("%d%d%d",&n,&m,&s);

	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(s, 0); //从节点s开始深搜处理father数组与depth数组，令s的父节点为0
	while(m--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}

	return 0;
}