#include<bits/stdc++.h>
using namespace std;
/**
f（i，j）代表字符串A的前i个字符（包括第i个）变为字符串B的前j个（包括第j个）需要多少步。也就是说解出来f（lenA，lenB）就可以了。

删：可以看做把A串最后一个字符删去后不再考虑这个字符 所以f(i,j)=min(f(i,j),f(i-1,j)+1);

加：可以看做与B串最后一个字符抵消后不再考虑这个字符 所以f(i,j)=min(f(i,j),f(i,j-1)+1);

改：可以看做删和加的集合 抵消了A、B串最后的两个字符 所以f(i,j)=min(f(i,j),f(i-1,j-1)+1); 

当然若A、B串最后一个字符相同就可以不用操作了
*/

char a[4005], b[4005];
int lena, lenb, f[4005][4005], k;

int main() {
    cin >> a >> b;
    lena = strlen(a);
    lenb = strlen(b);
    //初始化
    for(int i = lena; i >= 1;i--) a[i] = a[i-1];
    for(int i = lenb; i >= 1;i--) b[i] = b[i-1];
    //边界状态 因为将A串无字符变到B串i个字符时需要加i个字符 B串无字符时同理
    for(int i = 0; i <= lena; i++) f[i][0] = i;
    for(int i = 0;i <= lenb; i++) f[0][i] = i;

    for(int i = 1; i <= lena; i++)
    {
        for(int j = 1; j <= lenb; j++)
        {
            k = 1;//在后面会用到 方便‘改’的操作
            if(a[i] == b[j]) k=0;
            f[i][j] = min(min(f[i-1][j] + 1, f[i][j-1] + 1), f[i-1][j-1] + k);//若当前A、B串指向字符相等则不进行‘改’的操作
        }
    }

    printf("%d",f[lena][lenb]);//就是将A串前lena个数变为B串前lenb个数
    return 0;
}