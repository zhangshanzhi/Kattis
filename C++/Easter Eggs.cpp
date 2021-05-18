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
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,Blue,Red;
int match[300]; 
double k[300][300]; 
bool vis[300];
double mid;

struct node
{
	ll x,y;
}dot_r[300],dot_b[300];

bool dfs(int fo1){
	for (int i = 0; i < Red; i++ ){
		if (k[fo1][i] < mid && vis[i] == 0){
			vis[i] = 1;
			if (match[i] == -1 || dfs(match[i])){
				match[i] = fo1;
				return 1;
			}
		}
	}
		return 0;
}
int big_matching(){
	int ans = 0; 
	memset(match,-1,sizeof(match));
	for (int i = 0; i < Blue; i++){
		memset(vis,0,sizeof(vis));
		if (dfs(i)) ans++;
	}
    return Blue + Red - ans;
}
 
int main(){
	cin>>N>>Blue>>Red;
	for (int i = 0; i < Blue; i++)
		cin>>dot_b[i].x>>dot_b[i].y;
	for (int i = 0; i < Red; i++)
		cin>>dot_r[i].x>>dot_r[i].y;
	for (int i = 0; i < Blue; i++){
		for (int j = 0; j < Red; j++){
			int t1 = (dot_b[i].x - dot_r[j].x)*(dot_b[i].x - dot_r[j].x);
			int t2 = (dot_b[i].y - dot_r[j].y)*(dot_b[i].y - dot_r[j].y);
			k[i][j] = sqrt(t1+t2);
		}
	}
	double l = 0, r = 1e6;
	int Ans;
	for (int i = 0; i < 100; i++){
		double total_len = l+r; 
		mid = total_len / 2;
		Ans = big_matching();
		if (Ans >= N) l = mid; else r = mid;
	}	
 
	printf("%.15lf\n",l);
	return 0;
}

