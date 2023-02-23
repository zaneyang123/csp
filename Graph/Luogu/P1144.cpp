#include<bits/stdc++.h>
#include <climits>
using namespace std;

const int MaxN = 100010, MaxM = 500010;

//链式前向星存图，详细说明见：https://cloud.tencent.com/developer/article/1912251
struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt, ans[MaxN];
bool vis[MaxN];
int n, m;

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
        //注意：这里的顺序，正常的写法是 dis < right.dis，这里反了一下，所以实现了最小堆
        return right.dis < dis;
    }
};

//最小堆
//详细的使用方法，网上很多，例如：https://blog.csdn.net/auccy/article/details/123318695
priority_queue<node> q;

void dijkstra()
{
    //起点dis为0
    dis[1] = 0;
    //起点入堆
    q.push((node){0, 1});
    ans[1] = 1;
    //直到堆为空
    while( !q.empty() )
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
            int y = e[i].to;
            if(dis[x] + e[i].dis < dis[y])
            {
                dis[y] = dis[x] + e[i].dis;
                //下一个节点未访问过，则出列
                if(!vis[y])
                {
                    ans[y] = ans[x];
                    q.push((node){dis[y], y});
                }
            } else if (dis[x] + e[i].dis == dis[y])
            {
                ans[y] = (ans[y] + ans[x]) % 100003;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    //初始化dis，均为“无穷大”
    for(int i = 1; i <= n; ++i) 
    {
        dis[i] = INT_MAX;
        ans[i] = 0;
    }
    //建图
    for(int i = 0; i < m; ++i)
    {
        int u, v, d;
        scanf("%d %d", &u, &v);
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    //调用算法
    dijkstra();
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}