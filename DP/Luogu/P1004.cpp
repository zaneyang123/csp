#include <bits/stdc++.h>
using namespace std;

/**
用例:

输入
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0

输出
67
**/

 const int maxn=10;

 int a[maxn][maxn], dp[maxn][maxn][maxn][maxn];

 int main()
 {
     int n, x, y, c;
     cin >> n;
     while(scanf("%d %d %d", &x, &y, &c) && x && y && c)
         a[x][y] = c;

    memset(dp,0,sizeof(0)); //初始化DP数组

     for(int i = 1; i <= n; i++){
         for(int j = 1; j <= n; j++){
             for(int k = 1; k <= n; k++){
                 for(int l = 1; l <= n; l++){
                     //转移方程
                     dp[i][j][k][l] = max(dp[i-1][j][k-1][l], max(dp[i][j-1][k-1][l], max(dp[i-1][j][k][l-1], dp[i][j-1][k][l-1]))) + a[i][j]+a[k][l];
                     //点只能走一次，去重
                     if(i == k && j == l)
                     {
                         dp[i][j][k][l] -= a[i][j];
                     }
                 }
             }
         }
     }
    cout << dp[n][n][n][n] << endl;
  }