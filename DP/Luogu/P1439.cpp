#include<iostream>
#include<cstdio>
using namespace std;
int a[100001],b[100001],map[100001],f[100001];
int main()
{
    int n;
    cin >> n;
    //输入  第一个序列  同时记录映射
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        map[a[i]]=i;
    }
    //第二个序列
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        f[i]=0x7fffffff;
    }


    //求第二个序列映射后的(即为map[b[i]]]最长上升子序列
    //为什么可以这么做？因为是1-n的全排列
    int len = 0;
    f[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        if (map[b[i]] > f[len])
        {
            len++;
            f[len] = map[b[i]];
        } 
        else 
        {
            int pos = lower_bound(f + 1, f + len + 1, map[b[i]]) - f; 
            f[pos] = map[b[i]];
        }
    }
    cout << len;
    return 0;
}



/**

关于为什么可以转化成LIS问题，这里提供一个解释。

A:3 2 1 4 5

B:1 2 3 4 5

我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：

A: a b c d e
B: c b a d e

这样标号之后，LCS长度显然不会改变。但是出现了一个性质：

两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
因此这个子序列是单调递增的。

换句话说，只要这个子序列在B中单调递增，它就是A的子序列。

哪个最长呢？当然是B的LIS最长。

自此完成转化。

*/