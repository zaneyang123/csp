#include<bits/stdc++.h>
using namespace std;

struct node
{
    int dis;
    int pos;
    //重载运算符，建堆用
    bool operator <(const node &x)const
    {
        return x.dis < dis;
    }
};
//最小堆
priority_queue<node> q;


int main()
{
    q.push((node){100, 1});
    q.push((node){90, 2});
    q.push((node){80, 3});

    cout << q.top().pos << endl;
    q.pop();

    cout << q.top().pos << endl;
    q.pop();

    cout << q.top().pos << endl;
    q.pop();
}