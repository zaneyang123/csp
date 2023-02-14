#include<bits/stdc++.h>
using namespace std;

/**
dp，也可以说的纯暴力吧。

dp[i]表示以a[i]为结尾的最长上升子序列的长度。

所以只要满足j<i且a[j]<a[i]，则一定满足dp[j]=max(dp[j],dp[i]+1);

复杂度为n^2;
*/

const int maxn=1e3+5;
int n;
int a[maxn];
int dp[maxn];


int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) dp[i]=1;
	int Max=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j]) dp[j]=max(dp[j],dp[i]+1);
			Max=max(dp[j],Max);
		}
	}	
	printf("%d\n",Max);
	return 0;
}