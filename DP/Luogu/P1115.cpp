#include<bits/stdc++.h>
using namespace std;
int n, a[200020], dp[200020], i, ans = INT_MIN;

// dp[i] 表示截止到 i 时，第 i 个数所在的有效序列的元素和。

int main(){
   cin >> n;
   for(i = 1; i <= n; i++){
       cin >> a[i];
       if( i == 1) 
       {
           dp[i] = a[i];
       }
       else 
       {
           dp[i] = max(a[i], dp[i-1] + a[i]);
       }
       ans = max(ans, dp[i]);
   }
   cout << ans;
   return 0;
}