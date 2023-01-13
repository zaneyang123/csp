#include<bits/stdc++.h>
using namespace std;

/**
输入格式:
第一行两个正整数n,m
第二行n个整数，其中第i个数ai表示点 ii 的点权。
第三至m+2行，每行两个整数 u,v，表示一条u→v的有向边。

输出格式：
共一行，最大的点权之和。

用例：
输入
2 2
1 1
1 2
2 1
输出
2

**/
const int N=1e6+10; //点的最大数量

int n, m;   //输入的n，m
int fa[N];  //记录父节点数组
int w[N];   //点的权重

int dfn[N]; //dfn数组  DFN(u)为节点u 搜索的次序编号(时间戳);
int low[N]; //low数组  LOW(u)为u 或 u的子树能够追溯到的最早的栈中节点的次序号;
int num;    //时间序号
int vis[N]={0}; //记录点是否访问过
int w2[N];   //缩点后，点的权重
stack<int> s; //栈

int in[N]={0}; //点的入度

vector<int> e1[N]; //原图
vector<int> e2[N]; //缩点后，重建的图

int dp[N]={0}; //排序用的dp数组

//tarjan算法的实现，具体逻辑见伪代码
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    s.push(x);   
    vis[x]=1;

    for(int i=0; i< e1[x].size(); i++)
	{
		int y = e1[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);	
	}

    if(low[x]==dfn[x])
	{
		int pre;
		do
		{
			pre=s.top();
			s.pop();
			vis[pre]=0;
			w2[x]+=w[pre];
			fa[pre]=x;	
		} while(pre!=x);
	}
}

//topo排序
int topo()
{
	queue<int> q;
    //入度为0的点作为起点，入队列
	for(int i = 1; i <= n; i++)
	{
        if(fa[i] == i)
		{
			dp[i] = w2[i];
			if(in[i] == 0)
            {
                q.push(i);
            }		
		}		
    }
    //类似广搜
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < e2[u].size(); i++)
		{
			int v = e2[u][i];
			dp[v] = max(dp[v], dp[u] + w2[v]);
			in[v]--; //更新入度
			if(in[v] == 0) 
            {
                q.push(v);
            }
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
    {
        //过滤新图中不是节点的点
        if(fa[i] == i)
        {
            ans=max(ans, dp[i]);
        }
    }
	return ans;
}

int main() 
{
    cin >> n >> m;

    for(int i=1; i<=n; i++)
	{
		fa[i]=i;
		cin >> w[i];
	}

    //针对输入，构建原始的图
    for(int i=1; i<=m; i++)
	{
		int u,v;
		cin >> u >> v;
		e1[u].push_back(v);  
	}

    //缩点
    for(int i=1; i<=n; i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
		

    //重建图
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<e1[i].size(); j++)
		{
			int v=e1[i][j];
            //如果点的父节点相同，也就是在同一个通量中，则在新图中舍去该点
			if(fa[i]==fa[v])
				continue;
			else
			{
				e2[fa[i]].push_back(fa[v]);
                //统计点的入度
				in[fa[v]]++;    
			}			
		}
    }
	
    cout << topo() << endl;
	return 0;
}