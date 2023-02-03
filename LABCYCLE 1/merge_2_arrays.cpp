#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m , vector<int>& nums2 , int n) {
    int i=m-1 , j=n-1 , k=m+n-1;
    while(i>=0 && j>=0) {
        if(nums2[j] > nums1[i]) nums1[k--] = nums2[j--] ;
        else nums1[k--] = nums1[i--] ;
    }
    while(j>=0) nums1[k--] = nums2[j--];
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
