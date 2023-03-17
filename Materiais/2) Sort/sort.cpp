#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) 
{
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first <= p2.first;
} 

int main() {

    vector<pair<int,int>> v = {{5,1}, {4,4}, {3,4}};

    for(auto x : v) cout << x.first << " " << x.second << " | "; cout << endl;

    sort(v.begin(), v.end(), compare);

    for(auto x : v) cout << x.first << " " << x.second << " | "; cout << endl; 
}