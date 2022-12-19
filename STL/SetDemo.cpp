#include <iostream>
#include <set>
using namespace std;

/**
* STL  set  demo
*/

int main()
{
    set<int> s;

    s.insert(11);
    s.insert(21);
    s.insert(31);

    cout << "Set size: " << s.size() << endl;
    cout << "11出现的次数: " << s.count(11) << endl;

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;


    it = s.find(21);
    cout << *it << endl;
    s.erase(it);

    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;

    it = s.find(21);
    if (it == s.end())
        cout << "not found" << endl;

}