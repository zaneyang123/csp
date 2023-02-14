#include<bits/stdc++.h>
using namespace std;

int n, a[150][150], value[150][150], maxn = INT_MIN;

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1;j <= n; j++) 
        {
            cin >> a[i][j]; //输入
        }
    }
   
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            value[i][j] = a[i][j] + value[i][j-1] + value[i-1][j] - value[i-1][j-1]; //已推得
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) //对于每一个点
        {
            for(int q = i; q <= n; q++)
            {
                for(int w = j; w <= n; w++)//找遍它右下侧所有可能权值，取最优
                {
                    int tmp = value[q][w] - value[i-1][w] - value[q][j-1] + value[i-1][j-1];//以得公式
                    maxn = max(maxn, tmp);//贪心
                }
            }
        }
    }

    cout << maxn;
    return 0;
}