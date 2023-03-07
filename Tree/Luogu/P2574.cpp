#include <bits/stdc++.h>
#define maxx 300020
#define ll long long
using namespace std;

int n, m, p, l, r, a[maxx];
char s[maxx];
ll add[maxx * 4], sum[maxx * 4];

inline void getup(int rt)
{
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}

//建树
inline void bulid(int l, int r, int rt) 
{
	if(l == r)
	{
		sum[rt] = a[l];//赋值 
		return ;
	}
	int mid = (l + r) / 2;
	bulid(l, mid, rt * 2);
	bulid(mid + 1, r, rt * 2 + 1);
	getup(rt); //向上更新 
}

//传递tag
inline void pushdown(int rt, int len)
{
	if(add[rt])
	{
		add[rt * 2] ^= 1;
		add[rt * 2 + 1] ^= 1; 
		sum[rt * 2] = (len - (len / 2)) - sum[rt * 2];
		sum[rt * 2 + 1] = (len / 2) - sum[rt * 2 + 1];
		add[rt] = 0;
	}
}

//分区间查询
//LR是要查询的区间，lr是给定的区间
inline ll query(int L, int R, int l, int r, int rt) 
{ 
	if(l >= L && r <= R) return sum[rt];
	pushdown(rt, r - l + 1);
	int mid = (r + l) >> 1;
	ll tot = 0;
	if(L <= mid) tot += query(L, R, l, mid, rt * 2);
    if(mid + 1 <= R) tot += query(L, R, mid + 1, r, rt * 2 + 1);
    return tot;
}

//更新
//LR是要查询的区间，lr是给定的区间
inline void update(int L, int R, int l, int r, int rt) 
{
	pushdown(rt, r - l + 1);
	if(l >= L && r <= R)
	{
		add[rt] ^= 1;
		sum[rt] = r - l + 1 - sum[rt];
		return;
	}
	int mid = (l + r) >> 1;
    if(L <= mid) update(L, R, l, mid, rt * 2);
    if(mid + 1 <= R) update(L, R, mid + 1, r, rt * 2 + 1);  
    getup(rt);
} 

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) cin >> s[i];//先读入字符 
	for(int i = 1; i <= n; i++) a[i] = s[i] - '0';//再转换成数字 
	bulid(1, n, 1);
	for(int i = 1; i <= m; i++) 
	{
		scanf("%d%d%d", &p, &l, &r);
		if(p == 0)
			update(l, r, 1, n, 1);
		if(p == 1)
			cout << query(l, r, 1, n, 1) << endl; 
	}
	return 0;
}