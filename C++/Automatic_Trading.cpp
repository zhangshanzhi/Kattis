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
#include<stdio.h>
#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
#define maxn 100000+7
#define up 123
#define start_lower 'a'
#define start_upper 'A'
#define num_letter 26
typedef long long ll;
using namespace std;
ll h_table[maxn],ep[maxn];

int main()
{
	int ans = 0;
    ep[0] = 1;
    for(int i=1;i<maxn;i++){
		ep[i]=ep[i-1]*up;
	}
	string str;
	cin>>str;
    int s_len=str.size();
    h_table[s_len]=0;
    for(int i=s_len-1;i>=0;i--){
    	ll nn;
    	if(str[i]>=start_lower){
    		nn = str[i]-start_lower;
		}
		else{
			nn = str[i]-start_upper+num_letter;
		}
        h_table[i]=h_table[i+1]*up+nn;
    }
    int q;
    cin >> q;
    while(q--){
        int i,j;
        cin>>i>>j;
        ll bger = max(i,j);
        ll l=0,r=s_len-bger;
        while(l<=r){
            int mid=l+r>>1;
            ll b_sd = h_table[i]-h_table[i+mid]*ep[mid];
            ll c_sd = h_table[j]-h_table[j+mid]*ep[mid];
            if(b_sd==c_sd){
				ans=mid,l=mid+1;
			}
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
