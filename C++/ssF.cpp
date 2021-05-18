
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000 
using namespace std;
char a[maxn];
int f[100][100], pi[maxn];
 
int dp(int l, int r) {

    if (f[l][r] != -1) return f[l][r];
    if (l == r) return 1;
    f[l][r] = inf;
    for (int i = l; i < r; i++) {
        f[l][r] = min(f[l][r], dp(l, i) + dp(i + 1, r));
    }
    pi[l] = 0;
    for (int i = l + 1; i <= r; i++) {
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[l + j]) j = pi[l + j - 1];
        if (a[i] == a[l + j]) j++;
        pi[i] = j;
    }
    int n = r - l + 1;
    int m = n - pi[r];
    if (n % m == 0)
        f[l][r] = min(f[l][r], dp(l, l + m - 1));
    return f[l][r];
}
 
int main() {
    while (scanf("%s", a + 1) != EOF) {
        int n = strlen(a + 1);
        if (n == 1 && a[1] == '*') break;
        memset(f, -1, sizeof(f));
        printf("%d\n", dp(1, n));
    }
    return 0;
} 
