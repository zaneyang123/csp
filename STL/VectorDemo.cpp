#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> a = vector<vector<int>> (4+1);
    a[1][3] = 1;
    cout << a[1][3];


    vector<int> b = vector<int>(2);

    b[0]; //1
    b[1]; //2

    vector<vector<int>> c;
}