/*
  <Your Name> Shanzhi Zhang
  <Student ID #> 1541578

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  <List Resources Here>
	https://www.rieselprime.de/ziki/Modular_square_root
	https://max.book118.com/html/2017/1226/146027944.shtm
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
#define moding(a,b) (a*b)%MOD
using namespace std;
typedef long long ll; 
ll MOD,MMO;
int x;
int sumn = 0;
//Binary Exponentiation 
ll mod_exp(ll a,ll b){
	a %= MOD;
    ll sol = 1;
    while(b!=0)
    {
        if(b&1){
			sol = moding(sol,a);
		}
        a=moding(a,a);
        b>>=1;
    }
    return sol;
}
//special cases
ll quick_sol(){
	while(MMO%2==0){
        MMO>>=1;
        sumn++;
    }
    if(sumn==1){
    	ll o_r = (MOD+1)/4;
        return mod_exp(x,o_r);
    }
    return -1;
}
//Tonelli-Shanks algorithm
ll solve(){
	MMO = MOD-1;
    ll rd;
    ll rt = quick_sol();
	if (rt!=-1){
 		return rt;
	}
    while(true){
        rd= rand()%(MOD-1) + 1;
        if(mod_exp(rd,(MOD-1)/2)!=1){
			break;
		}
    }
    ll mod1=mod_exp(rd,MMO);
    ll mod2;
    ll mod3=mod_exp(x,(MMO+1)/2);
    ll mod4=mod_exp(x,MMO);
    ll M=sumn;
    ll i;
    while(mod4%MOD!=1){
        for(i=1;i<M;i++){
            if(mod_exp(mod4,1<<i)==1){
				break;
			}
        }
        mod2=mod_exp(mod1,1<<(M-i-1));
        mod1=moding(mod2,mod2);
        mod3=moding(mod3,mod2);
        mod4=moding(mod4,mod2*mod2);
        M=i;
    }
    ll ans = mod3%MOD;
    return ans;
}
//MOD = 2 and the Euler Fermat
int special_case_sqrt(){
	if(MOD==2){
        if(x%MOD==1){
			cout<<"Special root: "<<1<<endl;
		}
        else{
			cout<<"No root"<<endl;
		}
		return -1;
    }
    //Euler criterion
    if(mod_exp(x,(MOD-1)/2)!=1)
    {
        cout<<"No root"<<endl;
        return -1;
    }
    return 1;
}

int main()
{
    int n,ans;
	cout<<"Enter in the Prime number x: ";
    cin>>x;
    cout<<"Enter in the P(mod): ";
    cin>>MOD;
    //special cases
	if(special_case_sqrt() == -1){
		return 0;
	}
    //get the final answers
    ans=solve();
    if(ans==MOD-ans){
		cout<<ans<<endl;//if min ans == max ans the output one sol
	}
    else{
    	// for Tonelli¨CShanks algorithm have 2 anwer
		cout<<"Min answer: "<<min(ans,(int)MOD-ans)<<" "<<"Max answer: "<<max(ans,(int)MOD-ans)<<endl;
	}
    return 0;
}
