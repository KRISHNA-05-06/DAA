#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m , vector<int>& nums2 , int n) {
    for(int i=m;i<=m+n-1;i++) {
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(),nums1.end());
}

int main() {
    int m ; cin >> m ;
    vector<int> nums1,nums2;
    for( int i=0 ; i<m ; i++ ) {
        int k ; cin >> k;
        nums1.push_back(k);
    }
    int n ; cin >> n;
    for( int i=0 ; i<n ; i++ ) {
        nums1.push_back(0);
        int h ; cin >> h;
        nums2.push_back(h);
    }
    merge(nums1,m,nums2,n);
    for(auto it:nums1) cout << it << " " ;
    cout << endl ;
    return 0;
}
