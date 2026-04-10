#include<vector>
#include<iostream>
using namespace std;
void mergeSort(int l, int r, vector<int>& arr, vector<int>& temp) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(l, mid, arr, temp);
    mergeSort(mid+1, r, arr, temp);
    int i = l, j = mid+1, k = l;
    while(i <= mid && j <= r) {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    for(i = l; i <= r; i ++) arr[i] = temp[i];
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n+1), temp(n+1);
    for(int i = 1; i <= n; i ++) cin>>arr[i];
    mergeSort(1, n, arr, temp);
    for(int i = 1; i <= n; i ++) cout<<arr[i]<<(i == n ? '\n':' ');
}