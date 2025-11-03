#include <vector>
#include <set>
#include <iostream>

#include <functional>
#include <algorithm>

using namespace std;

void printer(int i)
{

};

Compare(int _Left, int _Right)
{
    cout << i << ", ";

};

int
main()
{

    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    vector <int> v1(mynumbers, mynumbers + 7);
        
    sort(v1.begin(), v1.end(), greater <int>());//LINE I

    for_each(v1.begin(), v1.end(), printer);//LINE II

    return 0;
}