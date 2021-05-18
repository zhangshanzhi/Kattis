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
#define MAX 10000
using namespace std;
int dp[10010],vis[10010];
void initial(){
	for(int i = 1; i <= MAX; i++) dp[i] = i - 1;dp[1] = 2;
}

int main()
{
	initial();
    for(int i = 2; i <= MAX; i++){
        memset(vis,0,sizeof(vis));
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
            int p = i / j;
              for(int k = i + j; k <= MAX; k += j)
                   if(!vis[k]) vis[k] = 1,dp[k]--;
              for(int k = i + p; k <= MAX; k += p)
                   if(!vis[k]) vis[k] = 1,dp[k]--;
        }
    }
        for(int j = i + i; j <= MAX; j += i) if(!vis[j]) vis[j] = 1,dp[j]--;
    }
    int ans = 0;
    for(int i = 1 ; i <= MAX; i++) dp[i] += ans,ans = dp[i];
    int T,K,N;
    cin>>T;
    while(T--){
        cin>>K>>N; 
        cout<<K<<" "<<dp[N]<<endl;
    }
    return 0;
}

