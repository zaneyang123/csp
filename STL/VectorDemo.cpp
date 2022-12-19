#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> a = vector<vector<int>> (4+1);
    a[1][3] = 1;
    cout << a[1][3];
}