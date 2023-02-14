#include<bits/stdc++.h>
using namespace std;

/**
是1方法的优化，建一个dp数组。

dp[i]表示长度为i的上升子序列中末尾元素的最小值。

因为dp数组一定是有序的，这样每次插入元素的时候可以结合二分查找使效率更高。

复杂度为logn*n;
*/

const int maxn=1e3+5;
int n;
int a[maxn];
int dp[maxn];
int len;
int main()
{
	scanf("%d",&n);
	len=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int loc=lower_bound(dp,dp+len,a[i])-dp;
		if(loc==len) dp[len++]=a[i];
		else 
		{
			dp[loc]=a[i];
		}
	}
	printf("%d\n",len);
	return 0;
}