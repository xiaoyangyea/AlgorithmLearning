#include<vector>
#include<iostream>
using namespace std;
void quickSort(int l, int r, vector<int>&arr) {
    if(l >= r) return;
    int key = arr[l+r>>1], i = l-1, j = r+1;
    while(i < j) {
        while(arr[++i] < key);
        while(arr[--j] > key);
        if(i < j) swap(arr[i], arr[j]);
    }
    quickSort(l, j, arr);
    quickSort(j+1, r, arr);
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i = 1; i <= n; i ++) cin>>arr[i];
    quickSort(1, n, arr);
    for(int i = 1; i <= n; i ++)
        cout<<arr[i]<<(i == n ? '\n':' ');
}