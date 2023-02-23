#include<bits/stdc++.h>
#include <climits>
using namespace std;

int n;
int a[100][100];

/**
核心代码只有四行，三行循环，一行更新 

该算法是基于动态规划的。我们从动态规划的角度考虑，解动态规划题目的重点就是合理的定义状态，划分阶段，
我们定义 f[k][i][j]为经过前k的节点，从i到j所能得到的最短路径，
f[k][i][j]可以从f[k-1][i][j]转移过来，即不经过第k个节点，也可以从f[k-1][i][k]+f[k-1][k][j]转移过来，
即经过第k个节点。
观察一下这个状态的定义，满足不满足最优子结构和无后效性原则。
*/
void floyd() 
{
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            cout << a[i][j];
        }
    }
}