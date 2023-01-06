#include<bits/stdc++.h>
using namespace std;

/**
* 最小生成树
* Prim实现方式
* Luogu-3366
*/

/**
输入：
4 5
1 2 2
1 3 2
1 4 3
2 3 4
3 4 3


输出：
7
**/

struct Edge
{
    int start, to, distance;
};

int main()
{
    int N, M;
    cin >> N >> M;
    
    //初始化邻接表
    vector<vector<Edge>> adj = vector<vector<Edge>>(N + 1);

    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        //邻接表加边
        adj[x].push_back(Edge{x, y, z});
        adj[y].push_back(Edge{y, x, z});
    }

    //最小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 

    //已选顶点集合
    set<int> selectedSet;

    q.push(make_pair(0, N));

    //最短路径和
    int minDistance = 0;

    //直到堆空
    while (q.size())
    {
        //最小堆，首个元素
        pair<int, int> cur = q.top();
        int curDistance = cur.first, curTo = cur.second;
        q.pop();

        //点已被选，则Pass
        if (selectedSet.count(curTo)) continue;

        //叠加当前距离
        minDistance += curDistance;

        //加入已选顶点
        selectedSet.insert(curTo);

        //往队列中，加入新的邻接边
        for (int i = 0; i < adj[curTo].size(); i++)
        {
            //新的点不能在已选集合中
            if (!selectedSet.count(adj[curTo][i].to))
            {
                q.push(make_pair(adj[curTo][i].distance, adj[curTo][i].to));
            }
        }
    }

    //有可能，图不是连通的
    if (selectedSet.size() != N) cout << "orz";
    else cout << minDistance;

    return 0;
}