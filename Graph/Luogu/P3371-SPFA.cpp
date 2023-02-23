#include<bits/stdc++.h>
using namespace std;

/**
* 最短路径
* SPFA实现方式
* Luogu-3371
*/
/**
spfa的本质是广度优先搜索，将图所有的边都遍历一遍。平均时间复杂度是O(m)，最坏时间复杂度是O(mn)，其中m是图的边数。
1、实现spfa算法需要一个队列q，一个标记数组vis[N]用来标记某点是否在队列中。数组dist[N]，用来存储起点到某个点的最短距离。
2、初始化dist数组为正无穷
3、从起点开始枚举每个点的所有子节点，设父节点到子节点的距离为s，父节点到起点的距离为dist[u]，子节点到起点的距离为dist[v]，如果dist[u]+s<dist[v],当且仅当上式成立时就更新dist[v]，如果v没有在队列中，就将v入队。

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
                    isInqueue[w] = true;
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