#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main()
{

    map<pair<int, int>, int> m;

    // m.insert(pair<pair<int, int>, int>(pair<int, int>(1, 2), 3));
    // m[pair<int, int>(1, 2)] = 5;       
    // int c = m.at(pair<int, int>(1, 2));
    // int c = m[pair<int, int>(1, 2)];
    // cout << c;
    cout << m.count(pair<int, int>(1, 2)) << endl;

    const int maxn = 2e5 + 10;
    cout << (maxn << 1);
}