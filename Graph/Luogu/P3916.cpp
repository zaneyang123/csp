#include<vector>
#include<queue>
#include<iostream>
using namespace std;

/**
* 有向图
* 邻接表实现方式
* Luogu-3916
*/
class Graph
{
	public:
		int v;  //顶点个数
		vector<vector<int>> adj; //邻接表

		//构造函数
		Graph(int v)
		{
			this->v = v;
			this->adj = vector<vector<int>>(v);   //初始化邻接表
		}

		/**
		* 添加边,方向：s->t
		* @param s 起始顶点
		* @param t 目标顶点
		*/
		void addEdge(int s, int t)
		{
			//有向图一条边存一次
			this->adj[s].push_back(t);
	
		}

		void solutionBFS(int s, vector<int> &mp)
		{
			if (mp[s] != 0) return;
			mp[s] = s;

			queue<int> qList;
			qList.push(s);
			while (qList.size() != 0)
			{
				int w = qList.front();
				qList.pop();
				for (int i = 0; i < adj[w].size(); i++)
				{
					int q = adj[w][i];
					if (mp[q] == 0) 
					{
						mp[q] = s;        //注意这里不是记录上一个点，这里记录的是，最初始的点
						qList.push(q);
					}
				}
			}
		}

		void solutionDFS(int c, int s, vector<int>& mp)
		{
			if (mp[c] != 0) return;
			mp[c] = s;
			for (int i = 0; i < adj[c].size(); i++)
			{
				solutionDFS(adj[c][i], s, mp);
			}

		}
};

int main()
{
	int N, M;

	scanf("%d%d", &N, &M);

	Graph g = Graph(N + 1); //初始化图

	int u, v;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &u, &v);
		g.addEdge(v, u); //反向建边 
	}

	vector<int> maxPoint = vector<int>(N + 1); //记录能访问到的最大的点
	for (int i = N; i > 0; i--)
	{
		g.solutionDFS(i, i, maxPoint);
	}

	for (int i = 1; i <= N; i++)
	{
		printf("%d ", maxPoint[i]);
	}
	printf("\n");
	return 0;
}