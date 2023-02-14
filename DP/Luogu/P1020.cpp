#include<bits/stdc++.h>
using namespace std;


/**
一问： 求最长不上升子序列

整体思想：贪心+二分

最多能拦截多少很简单。我们用数组维护一个栈。这个栈具有单调性。

然后将原数组从头到尾扫一遍。每次扫到一个数，我们对其进行以下操作：

如果这个数 
≤
≤ 栈顶：

将这个数直接入栈。

否则：

找到栈里最小的大于该数的元素，将这个元素替换成这个数。因为栈的单调性，使用二分查找即可。
nlogn


二问：Dilworth定理
最长上升子序列的长度就是能构成的不上升序列的个数。证明略，记住即可。


*/
const int N = 1e5 + 5;
int a[N];
int d[N];

int main(){
    int tot = 0;
    while(scanf("%d", &a[++tot]) == 1){}
    tot--;

    int len = 1;
    d[1] = a[1];
    for(int i = 2; i <= tot; i++)
    {
        if(a[i] <= d[len]) 
        {
            d[++len] = a[i];
        }
        else 
        {
            //假设a是一个数组，n是数组长度，upper_bound(a, a+n, x)返回数组a[0]~a[n-1]中，大于x的数中，最小的数的指针。
            //加greater<int>()，关系变成 小于
            int pos = upper_bound(d + 1, d + len + 1, a[i], greater<int>()) - d;
            d[pos] = a[i];
        }
    }
    cout << len << endl;

    d[1] = a[1];
    len = 1;
    for(int i = 2; i <= tot; i++)
    {
        if(a[i] > d[len]) 
        {
            d[++len] = a[i];
        }
        else 
        {
            //假设a是一个数组，n是数组长度，lower_bound(a, a+n, x)返回数组a[0]~a[n-1]中，大于等于x的数中，最小的数的指针。
            int pos = lower_bound(d + 1, d + len + 1, a[i]) - d;
            d[pos] = a[i];
        }
    }
    cout << len;
}
