#include<bits/stdc++.h>
#include <climits>
#define N 205
#define IMAX (INT_MAX / 2)  //保证它不爆炸范围内的最大值
using namespace std;

int n,m;
int a[N];      //数组存各个村庄的建立时间
int f[N][N];   //邻接矩阵存边

//Floyd算法介绍可见Floyd.cpp
void updata(int k)
{
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++)
	        if(f[i][j] > f[i][k] + f[j][k])
	            f[i][j] = f[j][i] = f[i][k] + f[j][k]; //用这个新的更新所有前面的
}
int main(){
    //n 村庄数量  m 公路数量
	cin >> n >> m;

	for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);//依次输入每一个村庄建立完成时需要的时间
    }

	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            f[i][j] = IMAX;//初始化为保证它不爆炸范围内的最大值 
        }
    }

	for(int i = 0; i < n; i++)
    {
        f[i][i] = 0;
    }
	
	int s1, s2, s3;
	for(int i = 1; i <= m; i++)
    {
		scanf("%d%d%d", &s1, &s2, &s3);  //s1 s2 村 s3 公路长度
		f[s1][s2] = f[s2][s1] = s3; //初始化边长 
	}

    
	int q; //问题数量
	cin >> q;
	int now = 0; //用于记录当前时间对应的编号，从第一个村庄开始
	for(int i = 1;i <= q; i++)
    {   
        //处理各询问 
		scanf("%d%d%d", &s1, &s2, &s3); //s1,s2,s3为临时变量，表示两村庄和时间（注意：t3是不下降的，因此这里可以这么做）
		while(a[now] <= s3 && now < n) //如果目前更新的点的时间在询问点之前 （注意：村庄恢复时间是递增的，因此这里可以这么做）
        {
			updata(now);//依次更新点，使它可以被用来更新其他的点 
			now++;
		}

		if(a[s1] > s3 || a[s2] > s3) cout<< -1 <<endl; //村庄未建好
		else 
        {
			if(f[s1][s2] == IMAX) cout << -1 << endl; //两点不连通
			else cout << f[s1][s2] << endl; //输出路径长
		}
	}
	return 0;
} 