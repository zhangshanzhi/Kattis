#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
//extern "C"{void *__dso_handle=0;}
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define lowbit(x) x&-x

const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=1e6+10;
const int maxm=100+10;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> g[25];
double A[25][25];

void guess_elimination(int n)
{
	for(int i=1;i<=n;i++)
	{
		//选择一行r并与第i行交换
		int r=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(A[j][i]) > fabs(A[r][i])) r=j;
		if(r != i) for(int j=1;j <= n+1;j++) swap(A[r][j],A[i][j]);
		
		//与i+1~n进行消元       
		for(int k=i+1;k<=n;k++)
			for(int j=n+1;j>=i;j--)
				A[k][j] -= A[k][i]/A[i][i] *A[i][j];
	}
	
	//回代
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++) 
			A[i][n+1] -= A[j][n+1] * A[i][j];
		A[i][n+1] /= A[i][i];
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		x++,y++;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<n;i++)
	{
		int sum=g[i].size();
		A[i][i]=sum;
		A[i][n+1]=sum;
		for(int j=0;j<sum;j++)
		{
			int v=g[i][j];
			A[i][v]= -1.0;
		}
	}
	A[n][n] = 521.0;
	guess_elimination(n);
	printf("%.6f\n",A[1][n+1]);
}

