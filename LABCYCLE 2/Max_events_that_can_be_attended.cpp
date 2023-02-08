#include<bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
    int size = events.size() , i = 0 , ans = 0 , day = 0 ;
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(events.begin(),events.end());
    while(pq.size() > 0 || i < size) {
        if(pq.size()==0) day = events[i][0] ;
        while(i<size && events[i][0] <= day) {
            pq.push(events[i++][1]);
        }
        day++;
        ans++;
        pq.pop();
        while(pq.size() > 0 && pq.top() < day ) {
            pq.pop();
        }
    }
    return ans;
}

int main(int argc,char const *argv[]) {
    int t; cin >> t;
    while(t--) {
        int n ; cin >> n;
        vector<vector<int>> events;
        for(int i=0 ; i<n ; i++ ) {
            vector<int> knnc(2) ;
            cin >> knnc[0] ; cin >> knnc[1] ;
            events.push_back(knnc);
        }
        cout << maxEvents(events) << endl;
    }
    return 0;
}
