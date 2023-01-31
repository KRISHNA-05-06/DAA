#include<bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
    int size=events.size(), i=0 , ans=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(events.begin(),events.end());
    for(int days=1; days<=100000 ; days++) {
        while(i<size && events[i][0]==days) {
            pq.push(events[i++][1]);
        }
        while(pq.size() && pq.top()<days) {
            pq.pop();
        }
        if(pq.size()) {
            pq.pop();
            ans++;
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        vector<vector<int>> events;
        int n; cin >> n;
        for(int i=0;i<n;i++) {
            vector<int> ksks(2);
            cin >> ksks[0]; cin >> ksks[1];
            events.push_back(ksks);
        }
        cout << maxEvents(events) << endl;
    }
    return 0;
}
