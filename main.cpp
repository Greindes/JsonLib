#include <iostream>

using namespace std;
#include <vector>
int main()
{
    vector<int> vec;
    auto iter = vec.begin();
    vector<int>::iterator iter2;
    cout << (iter != iter2) << endl;
    return 0;
}
