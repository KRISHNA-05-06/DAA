#include <bits/stdc++.h>
using namespace std;

int maximumUnits(vector<vector<int>> boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &x,vector<int> &y){
        return x[1]>y[1];
    });
    int ans = 0; int i=0 ;
    for(i=0;i<boxTypes.size() && truckSize ; i++ ) {
        if(truckSize - boxTypes[i][0] > 0 ) {
            truckSize -= boxTypes[i][0];
            ans += boxTypes[i][0] * boxTypes[i][1];
        }
        else break;
    }
    if(i<boxTypes.size()) ans += (truckSize*boxTypes[i][1]);
    return ans;
}

int main() 
{
    int t ; cin >> t ;
    while(t--) {
        vector<vector<int>> boxTypes;
        int n ; cin >> n ;
        for(int i=0 ; i<n ; i++) {
            int a,b;
            cin >> a >> b;
            boxTypes.push_back({a,b});
        }
        int truckSize ; cin >> truckSize;
        cout << maximumUnits(boxTypes,truckSize) << endl;
    }
    return 0;
}
