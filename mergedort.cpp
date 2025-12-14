#include <bits/stdc++.h>

using namespace std;

void merge(int low, int mid, int high, vector < int > & arr) {
    vector < int > temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (int h = 0; h < k; h++) {
        arr[low + h] = temp[h];
    }
}
void mergesort(int low, int high, vector < int > & arr) {
    if (low < high) {
        int mid = (low + high) >> 1;
        mergesort(low, mid, arr);
        mergesort(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}

int main() {
    // your code goes here
    vector<int>arr={9,4,3,8,7,0};
    mergesort(0,5,arr);
    for(int i=0;i<n;i++) cout << arr[i] << " ";

}