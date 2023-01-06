#include<bits/stdc++.h>
using namespace std;

/**
* 无向图
* 链式前向星 实现方式
*/

const int maxn=100000+5;
int maxx[maxn],head[maxn];

int n; //顶点个数
int m; //边的个数
int x, y, w; //x起始顶点，y目标顶点，w权重
int cnt; //定义一个边的计数器cnt，表示当前已录入边的数量

struct Edge{
	int to; //表示该边的终点
    int w;  //该边权值
    int next; //同起点的上一条边的位置，值为-1表示没有上一条边
}e[maxn];

void add(int u,int v,int w){//添加一条边u--v 
 	e[cnt].to=v;
 	e[cnt].w=w;
	e[cnt].next=head[u]; //插入：该边为起点a的所有边里最新的边 
	head[u]=cnt++;
} 

void printg(){//输出链式前向星
	cout<<"----------链式前向星如下：----------"<<endl;
	for(int v=1;v<=n;v++){
		cout<<v<<"：  ";
		for(int i=head[v];~i;i=e[i].next){
			int v1=e[i].to,w1=e[i].w;
			cout<<"["<<v1<<" "<<w1<<"]\t";
		}
		cout<<endl;
	}
}

int main(){
	cin >> n >> m;
	memset(head,-1,sizeof(head)); //定义链头head，存储每个起点的最新一条边的索引，-1表示该点无边
	cnt=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		add(x,y,w);//添加边
		add(y,x,w);//添加反向边 
	}
	printg();
	return 0;
}
/*输入样例
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9
*/