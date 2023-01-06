#include<bits/stdc++.h>
using namespace std;

/**
* 并查集
* Luogu-1551
*/

int Find(vector<int>& parent, int index)
{
	//todo 优化
	if (parent[index] == index) return index;
	return Find(parent, parent[index]);
}

void Merge(vector<int>& parent, int i, int j) 
{
	parent[Find(parent, i)] = Find(parent, j);
}

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<int> parent = vector<int>(n+1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int a, b;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d", &a, &b);
		Merge(parent, a, b);
	}

	int c, d;
	for (int i = 1;i <= q;i++)
	{
		scanf("%d%d", &c, &d);
		if (Find(parent, c) == Find(parent, d))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}