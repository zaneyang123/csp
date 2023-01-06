#include<bits/stdc++.h>

using namespace std;

/**
* 最小生成树
* Kruskal实现方式
* Luogu-3366
*/

struct Edge  //边
{
    int u, v, distance;
};

vector<Edge> edgeList;
bool cmp(Edge e1, Edge e2)
{
    return e1.distance < e2.distance;
}

int Find(vector<int>& parent, int index)
{
    //todo 优化
    if (parent[index] != index) parent[index] = Find(parent, parent[index]);
    return parent[index];
}

void Merge(vector<int>& parent, int i, int j)
{
    parent[Find(parent, i)] = Find(parent, j);
}

int main()
{
    int N, M;
    cin >> N >> M;

    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        Edge edge = Edge{ x, y, z };
        edgeList.push_back(edge);
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    vector<int> parent = vector<int>(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int dis = 0;
    for (int i = 0; i < edgeList.size(); i++)
    {
        Edge edge = edgeList[i];
        if (Find(parent, edge.u) != Find(parent, edge.v))
        {
            dis += edge.distance;
            Merge(parent, edge.u, edge.v);
        }
    }

    //增加判断，是否有未联通的
    for (int i = 1; i < N; i++)
    {
        if (Find(parent, i) != Find(parent, i + 1))
        {
            cout << "orz";
            return 0;
        }
    }

    cout << dis;
    return 0;
}