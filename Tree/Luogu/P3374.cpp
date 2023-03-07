#include <bits/stdc++.h>
using namespace std;

//介绍：https://blog.csdn.net/ls2868916989/article/details/119268741
//补充：https://zhuanlan.zhihu.com/p/93795692
//原码反码补码：https://blog.csdn.net/qq_48052049/article/details/125994544

int const maxn=500005;
int n,m,p,x,y;
long long a,c[maxn];

long long lowbit(int x)//lowbit是求得区间范围 
{
    return x & -x;
}

//在u位置update上v  从赋值处往上修改 u+lowbit(u) 
void update(int u, int val)
{
    for(int i = u; i <= n; i += lowbit(i))
        c[i] += val;
}

//从末开始往前找 每次加上自己所管辖的数
//比如搜索sum(7)则 sum=c[7]+c[6]+c[4] 
long long sum(int u)
{
    int ans=0;
    for(int i = u; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a);
        update(i, a);
    }
    for(int i = 1; i<=m; i++)
    {
        scanf("%d%d%d", &p, &x, &y);
        if(p == 1)
        {
            update(x, y);
        }
        if(p == 2)
        {
            printf("%lld\n", sum(y) - sum(x - 1));
        }
    }
    return 0;
}