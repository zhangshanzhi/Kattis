#include <bits/stdc++.h>
using namespace std;
int get(){
truechar ch; int v=0,f=0;
truewhile (!isdigit(ch=getchar())) if (ch=='-') break;
trueif (ch=='-') f=1;else v=ch-48;
truewhile (isdigit(ch=getchar())) v=v*10+ch-48;
truereturn f?-v:v;
} 

typedef pair<int, int> P;
const int maxn = 1000020;
int b[maxn];
int main() {
    vector<int> H;
    int n = get();
    for (int i = 0; i < n; i++) {
        int x = get();
        if (H.empty() || H.back() != x) H.push_back(x);
    }
    n = (int)H.size();
    for (int i = 0; i < n; i++) b[i] = H[i];
    sort(b, b + n);
    int sz = unique(b, b + n) - b;
    vector<vector<int> > posi(sz);
    for (int i = 0; i < n; i++) H[i] = lower_bound(b, b + sz, H[i]) - b, posi[H[i]].push_back(i);
    P best[2] = {P(0, n), P(0, n)};
    for (int h = 0; h < sz - 1; h++) {
        P nbest[2] = {best[0], best[1]};
        for (int i = 0; i < posi[h].size(); i++) {
            int p = posi[h][i];
            if (p == n - 1 || H[p] + 1 != H[p + 1]) continue;
            P s(0, n);
            if (p != best[0].second) s = best[0];
            else s = best[1];
            s.first++, s.second = p + 1;
            if (posi[h + 1].size() == 1) s.second = n;
            if (s > nbest[0]) nbest[1] = nbest[0], nbest[0] = s;
            else if (s > nbest[1]) nbest[1] = s;
        }

        best[0] = nbest[0], best[1] = nbest[1];
    }
    printf("%d\n", n - 1 - best[0].first);    
}
