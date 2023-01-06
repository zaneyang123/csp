#include<bits/stdc++.h>
using namespace std;

/**
* 最短路径
* SPFA实现方式
* Luogu-3371
*/

struct Edge
{
    int vertex, distance;
}; //结构体表示边

vector<vector<Edge>> adj; //静态邻接表
vector<int> dis; //结果

void addedge(int u, int v, int w)
{
    //建图，有向图连一次边就可以了
    Edge e = Edge{ v , w };
    adj[u].push_back(e);
}

void spfa(int s)
{
    for (int i = 1; i < dis.size(); i++)
    {
        dis[i] = INT_MAX;
    }

    vector<bool> isInqueue = vector<bool>(dis.size());

    queue<int> q; 
    q.push(s);
    dis[s] = 0;
    isInqueue[s] = true;
    
    while (q.size())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++)
        {
            Edge e = adj[cur][i];
            int w = e.vertex;
            if (dis[w] > dis[cur] + e.distance)
            {
                dis[w] = dis[cur] + e.distance;
                if (!isInqueue[w])
                {
                    q.push(w);
                }
            }
        }
    }

}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    adj = vector<vector<Edge>>(n + 1);
    dis = vector<int>(n + 1);
    
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w); 
    }
    spfa(s); //开始跑spfa
    for (int i = 1; i <= n; i++)
        if (s == i) cout << 0 << " "; //如果是回到自己，直接输出0
        else cout << dis[i] << " "; //否则打印最短距离
    return 0;
} //结束