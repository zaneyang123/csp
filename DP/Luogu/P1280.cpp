#include<iostream>  
#include<algorithm>  
using namespace std;  

long int n, k, sum[10001], num=1, f[10001];  
struct ren//结构体，一起排序 ，从大到小   
{  
    long int ks, cx;  
};

ren z[10001];  

//按开始时间降序排列，大的在前
int cmp(ren a, ren b)  
{  
    return a.ks > b.ks;  
}  

int main()  
{  
    long int i,j;   
    cin >> n >> k;  
    for(i = 1; i <= k; i++)  
    {  
        cin >> z[i].ks >> z[i].cx;    
        sum[z[i].ks]++;  
    }  

    sort(z + 1, z + k + 1, cmp);  

    //f[i]表示i~n的最大空闲时间
    for(i = n; i >= 1; i--) //倒着搜   
    {  
        if(sum[i] == 0)  
        {
            f[i] = f[i+1] + 1; 
        }
        else 
        {
            for(j = 1; j <= sum[i]; j++)  
            {  
                if(f[i + z[num].cx] > f[i])
                {
                    f[i] = f[i + z[num].cx];  
                }          
                num++;//当前已扫过的任务数   
            }  
        }
    }  
    cout << f[1] << endl;  
}