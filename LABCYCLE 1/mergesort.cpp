#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int low,int mid,int high) {
    int b[high+1];
    int i=low;
    int j=mid+1;
    int k=low;
    while( i <= mid && j <= high ) {
        if(nums[i] >= nums[j]) b[k++] = nums[j++];
        else b[k++] = nums[i++];
    }
    while( i<=mid ) b[k++] = nums[i++];
    while( j<=high ) b[k++] = nums[j++];
    for(int i=low ; i<=high ; i++ ) nums[i] = b[i];
}

void mergesort(vector<int>& nums,int low,int high) {
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergesort(nums,low,mid);
    mergesort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

vector<int> sortArray(vector<int>& nums) {
    mergesort(nums,0,nums.size()-1);
    return nums;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0 ; i<n ; i++ ) cin >> nums[i];
    auto h = sortArray(nums);
    for(auto it:h) cout << it << " " << endl;
}
