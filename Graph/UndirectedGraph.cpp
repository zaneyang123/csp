#include<vector>
#include<iostream>
#include <queue>
using namespace std;

/**
* 无向图
* 邻接表实现方式
*/
class UndirectedGraph
{
	public:
		int v;  //顶点个数
		vector<vector<int>> adj; //邻接表

		/**
		* 构造函数
		* @param v 顶点个数
		*/
		UndirectedGraph(int v)
		{
			this->v = v;
			this->adj = vector<vector<int>>(v);   //初始化邻接表
		}

		/**
		* 添加边
		* @param s 起始顶点
		* @param t 目标顶点
		*/
		void addEdge(int s, int t) 
		{
			//无向图一条边存两次
			this->adj[s].push_back(t);
			this->adj[t].push_back(s);
		}

		/**
		* 广度搜索
		* @param s 起始顶点
		* @param t 目标顶点
		*/
		void bfs(int s, int t)
		{
			if (s == t) return;

			vector<bool> visited = vector<bool>(v);
			visited[s] = true;

			queue<int> qList;
			qList.push(s);

			vector<int> prev = vector<int>(v);
			for (int i = 0; i < v; i++)
			{
				prev[i] = -1;
			}

			while (qList.size() != 0)
			{
				int w = qList.front();
				qList.pop();

				for (int i = 0; i < adj[w].size(); i++)
				{
					int q = adj[w][i];
					if (visited[q] != true)
					{
						prev[q] = w;
						if (q == t) 
						{
							//打印最短路径
							print(prev, s, t);
							return;
						}
						visited[q] = true;
						qList.push(q);
					}
				}
			}
		}


		/**
		* 打印最短路径
		* @param prev	记录搜索路径的数组
		* @param s      起始顶点
		* @param t      目标顶点
		*/
		void print(vector<int> prev, int s, int t)
		{
			if (prev[t] != -1 && t != s)
			{
				print(prev, s, prev[t]);
			}
			cout << t << " " << endl;
		}



		bool found = false; // 全局变量或者类成员变量，标记是否找到

		/**
		* 深度搜索
		* @param s      起始顶点
		* @param t      目标顶点
		*/
		void dfs(int s, int t)
		{
			found = false;
			vector<bool> visited = vector<bool>(v);
			vector<int> prev = vector<int>(v);
			for (int i = 0; i < v; i++)
			{
				prev[i] = -1;
			}
			recurDfs(s, t, visited, prev);
			print(prev, s, t);
		}


		/**
		* 深度搜索-回溯
		* @param w           当前顶点
		* @param t           目标顶点
		* @param &visited    记录顶点是否被访问过的数组，注意，这里使用&，标记为引用传递
		* @param &prev	     记录搜索路径的数组，注意，这里使用&，标记为引用传递
		*/
		void recurDfs(int w, int t, vector<bool> &visited, vector<int> &prev)
		{
			if (found) return;
			visited[w] = true;
			if (w == t) 
			{
				found = true;
				return;
			}
			for (int i = 0; i < adj[w].size(); i++) 
			{
				int q = adj[w][i];
				if (visited[q] == false) 
				{
					prev[q] = w;
					recurDfs(q, t, visited, prev);
				}
			}
		}
};

int main()
{
	UndirectedGraph g = UndirectedGraph(8);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 7);
	g.addEdge(6, 7);
	g.dfs(0,6);
}