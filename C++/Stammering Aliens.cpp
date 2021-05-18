
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
 
 
const ull ThatMan=19260817;
ull mul[40005],pre[40005];
char s[40005];
int n,len,maxx,anspos;
map<ull,int>vis;
 
void HashString()
{
    pre[0]=0;
    for(int i=1;i<=len;i++) pre[i]=pre[i-1]*ThatMan+(s[i]-'a'+1);
}
 
bool check(int mid)
{
    vis.clear();
    bool tag=false;
    for(int i=1;i+mid-1<=len;i++)
    {
        ull righ=pre[i+mid-1];
        ull left=pre[i-1]*mul[mid];
        ull HashNum=righ-left;
        vis[HashNum]++;
        if(vis[HashNum]>=n)
        {
            if(mid>=maxx)
            {
                maxx=mid;anspos=i;
            }
            tag=true;
        }
    }
    return tag;
}
 
int main()
{
    mul[0]=1;
    for(int i=1;i<=40000;i++){
		mul[i]=mul[i-1]*ThatMan;
	}
    while(scanf("%d",&n),n)
    {
        scanf("%s",s+1);
        len=strlen(s+1);
        HashString();
 
        int l=1,r=len;
        int mid;
        maxx=anspos=-1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                l=mid+1;
            }
            else r=mid-1;
        }
        if(maxx!=-1)printf("%d %d\n",maxx,anspos-1);
        else printf("none\n");
    }
}

