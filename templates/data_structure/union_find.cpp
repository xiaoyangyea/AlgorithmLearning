#include<vector>
#include<iostream>
using namespace std;
typedef pair<int, int> PII;

int findRoot(int x, vector<PII>& root) {
    if(x != root[x].first)
        root[x].first = findRoot(root[x].first);
    return root[x].first;
}

void unionSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    if(_x == _y) return;
    if(root[_x].second < root[_y].second) root[_x].first = _y;
    else if(root[_x].second > root[_y].second) root[_y].first = _x;
    else {
        root[_x].second ++;
        root[_y].first = _x;
    }
}

bool isSameSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    return _x == _y;
}