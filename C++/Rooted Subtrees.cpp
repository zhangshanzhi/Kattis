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

#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 200100
#define LOGN 18 
typedef long long ll;
using namespace std;

vector<int> g[MAXN];
int up[LOGN][MAXN], depth[MAXN];

void dfs(int v, int pre, int d) {
    depth[v] = d;

    for (auto t2 : g[v])
        if (t2 != pre)
            dfs(t2, v, d+1);

    up[0][v] = pre;
}

int lca(int a, int dot_b) {
    if (depth[a] > depth[dot_b]) swap(a, dot_b);

    for (int j = LOGN-1; j >= 0; --j)
        if (depth[a] + (1<<j) <= depth[dot_b])
            dot_b = up[j][dot_b];

    if (a == dot_b) return a;

    for (int j = LOGN-1; j >= 0; --j)
        if (up[j][a] != up[j][dot_b]) {
            a = up[j][a];
            dot_b = up[j][dot_b];
        }

    return up[0][a];
}

ll dist(ll a, ll dot_b) {
    return depth[a] + depth[dot_b] - 2*depth[lca(a, dot_b)] + 1;
}

int main() {
    int n;
    ll q;
    cin >> n >>q;

    for (int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    for (auto x : up) fill(x, x+MAXN, -1);
    dfs(0, -1, 0);

    for (int j = 1; j < LOGN; ++j)
        for (int v = 0; v < n; ++v)
            if (up[j-1][v] != -1)
                up[j][v] = up[j-1][up[j-1][v]];


    for(int i=0;i < q;i++){
    	ll k,p,cal,ans;
    	cin >> k>> p;
    	cal = dist(k-1,p-1);
    	ans = cal*(cal-1)/2 +n;
		cout<<ans<<endl;
    }

    return 0;
}















