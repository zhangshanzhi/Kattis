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
#define MAX 100000
using namespace std;

int dom[MAX],times[MAX];

int next_s(int x){
    if(dom[x]==x){
		return x;
	}
    else
    {
        dom[x]=next_s(dom[x]);
        return dom[x];
    }
}
int update(int x,int y){
    int u_x=next_s(x);
    int u_y=next_s(y);
    if(u_x!=u_y) dom[u_y]=u_x;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	int sum=0,ans=0;
        cin >> n >> m;

    	for(int i=1;i<=n;i++){
       		dom[i]=i;
       		times[i]=0;
   		}
        int x,y;
        for(int i=1;i<=m;i++)
        {
            cin >> x >> y;
            update(x,y);
            times[y]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dom[i]==i){
				sum+=1;
			}
            if(!times[i]){
				ans+=1;
			}
        }
        cout << max(sum,ans)<< endl;
    }
    return 0;
}

