#include<bits/stdc++.h>
using namespace std;

struct node {
	int l, w;
} a[11000];
int n;
int dp[11000]= {0},ans;

//compare
bool cmp(node x, node y) { 
	if(x.l == y.l) 
    {
        //按长度排序，长度相同按宽度降序排列，大的在前
        return x.w > y.w; 
    }
    //降序排列，大的在前
	return x.l > y.l;
}

int main()
{
    //输入
    cin >> n;
	for(int i=1; i<=n; i++) 
    {
        cin >> a[i].l >> a[i].w; 
    }

    //排序
    sort(a + 1, a + 1 + n, cmp);


    //求不下降子序列最少个数
    //Dilworth定理
    //即求 最长上升子序列
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].w > dp[len]) 
        {
            len++;
            dp[len] = a[i].w;
        } else 
        {
          //假设a是一个数组，n是数组长度，lower_bound(a, a+n, x)返回数组a[0]~a[n-1]中，大于等于x的数中，最小的数的指针。
            int pos = lower_bound(dp + 1, dp + len + 1, a[i].w) - dp;  
            dp[pos] = a[i].w;
        }
    }

    cout << len;
    return 0;
}