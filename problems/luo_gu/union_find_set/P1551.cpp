#include<vector>
#include<iostream>
using namespace std;
typedef pair<int, int> PII;
int findRoot(int x, vector<PII>& root) {
    if(x != root[x].first)
        root[x].first = findRoot(root[x].first, root);
    return root[x].first;
}
void unionSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    if(_x == _y) return;
    if(root[_x].second < root[_y].second) root[_x].first = _y;
    else if(root[_x].second > root[_y].second) root[_y].first = _x;
    else {
        root[_y].first = _x;
        root[_x].second ++;
    }
}

bool isSameSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    return _x == _y;
}

void initSet(vector<PII>& root) {
    for(int i = 0; i < root.size(); i ++) {
        root[i].first = i;
        root[i].second = 0;
    }
}

int main() {
    int n, m, p;
    cin>>n>>m>>p;
    vector<PII>root(n+1);
    initSet(root);
    while(m --) {
        int x, y;
        cin>>x>>y;
        unionSet(x, y, root);
    }
    while(p --) {
        int x, y;
        cin>>x>>y;
        cout<<(isSameSet(x, y, root) ? "Yes\n":"No\n");
    }
}