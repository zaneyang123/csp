#include<bits/stdc++.h>
#include <climits>
#define ll long long
using namespace std;

const int MaxN = 200020, MaxM = 200020;

//链式前向星存图，详细说明见：https://cloud.tencent.com/developer/article/1912251
struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

inline void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    //重载运算符，建堆用
    bool operator <(const node &right)const
    {
        //注意：这里的顺序，正常的写法是 dis < right.dis(大堆)，这里反了一下，所以实现了最小堆
        return right.dis < dis;
    }
};

//最小堆
//详细的使用方法，网上很多，例如：https://blog.csdn.net/auccy/article/details/123318695
priority_queue<node> q;

void dijkstra(int start)
{
    //起点dis为0
    dis[start] = 0;
    //起点入堆
    q.push((node){0, start});
    //直到堆为空
    while(!q.empty())
    {
        //取堆顶，即离当前点最小的距离那个
        node tmp = q.top();
        q.pop();
        //当前节点
        int x = tmp.pos;
        //当前距离
        int d = tmp.dis;
        //防止重复遍历，走回头路
        if(vis[x])
        {
            continue;
        }      
        //标记当前节点已遍历
        vis[x] = 1;
        //遍历以当前点为起点的所有边
        for(int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;   //下一个点
            if(dis[x] + e[i].dis < dis[y])
            {
                dis[y] = dis[x] + e[i].dis;
                //下一个节点未访问过，则入队
                if(!vis[y])
                {
                    q.push((node){dis[y], y});
                }
            }
        }
    }
}

int main()
{
    ll ans = 0;

    scanf("%d%d", &n, &m);
    //初始化dis，均为“无穷大”
    for(int i = 1; i <= n << 1; ++i) 
    {
        dis[i] = INT_MAX;
    }
    //建图
    for(int i = 0; i < m; ++i)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        //正向建图
        add_edge(u, v, d);
        //反向建图
        add_edge(v + n, u + n, d);
    }
    //调用算法
    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        ans += dis[i];
    }
    dijkstra(1 + n);
    for(int i = 1 + n; i <= n << 1; i++)
    {
        ans += dis[i];
    }
    printf("%lld \n", ans);
    return 0;
}