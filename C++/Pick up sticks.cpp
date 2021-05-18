/*
  <Your Name> Shanzhi Zhang
  <Student ID #> 1541578

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  <List Resources Here>

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  <List Classmates Here>

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {

    int n, m, up, down;
    cin >> n >> m;
	queue<int> q;
    vector<vector<int>> adj(n+1);
    vector<int> head(n+1, 0);
	vector<int> ans;
	
    for(int i = 0; i < m; i++) {
        cin >> up >> down;
        head[down]++;
        adj[up].push_back(down);
    }

    for(int i = 1; i <= n; i++) {
        if(head[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(auto i : adj[curr]) {
            head[i]--;
            if(head[i] == 0) {
                q.push(i);
            }
        }
    }

    if(ans.size() == n) {
        for(int i = 0; i < n; i ++) {
            cout << ans.at(i) << endl;
        }
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

}    
