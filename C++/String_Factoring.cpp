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
#define maxn 1000
#define inf 1e9+7
typedef long long ll;
using namespace std;
 
string s;
ll n;
ll dp[maxn][maxn],table[maxn];
ll dp_cal(ll l,ll r){
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	if(l==r){
		return 1;
	}
	dp[l][r]=inf;
	table[l]=0;
	for(ll i = l;i<=r-1;i++){
		dp[l][r]=min(dp[l][r],dp_cal(l,i)+dp_cal(i+1,r));
	}
	ll p;
	ll len=r-l+1;
	for(ll i = l+1;i<=r;i++){
		p=table[i-1];
		while(p>0&&s[i]!=s[l+p]) p=table[l+p-1];
		p+=(s[i]==s[l+p]);
		table[i]=p;
	}
	ll k=len-table[r];
	if(len%k==0){
		dp[l][r]=min(dp[l][r],dp_cal(l,l+k-1));
	}
	return dp[l][r];
}
int main() {


    cin>>s;
	n=s.size();
	memset(dp,-1,sizeof(dp));
	cout<<dp_cal(0,n-1)<<endl;

    return 0;
}

