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
#define neg_out "Impossible"
#define start_letter 'a'
#define maxn 100
#define maxx 100000 
using namespace std;
string str;
int letter[27];
bool dec_odd_num(){
    int odd_num = 0;
    for(int i = 0; i < 26; i++){
        if(letter[i]%2) odd_num++;
        if(odd_num > 1){
            cout<<neg_out<<endl;
            return false;
        }
    }
    return true;
}
void calculate(){
    int s_l = 0 , tot_size = str.length()-1 , ans = 0;
    for(int i = 0; i < str.length(); i++){
        letter[str[i]-start_letter]++;
    }
    
    if(!dec_odd_num()){
        return;
    }
    
    while(s_l < tot_size){
        if(str[s_l] != str[tot_size]){
            int x = maxx , y = maxx;
            for(int i = s_l+1; i < tot_size; i++){
                if(str[i] == str[s_l]) y = i;
                if(str[i] == str[tot_size] && x == maxx) x  = i;
            }
            if(abs(x - s_l) >= abs(tot_size - y)){
                ans += tot_size-y;
                for(int i = y; i < tot_size; i++){
                    str[i] = str[i+1];
                }
                str[tot_size] = str[s_l];
            }else{
                ans += x-s_l;
                for(int i = x; i > s_l; i--){
                    str[i] = str[i-1];
                }
                str[s_l] = str[tot_size];
            }
        }
        s_l++;
        tot_size--;
    }
    cout<<ans<<endl;
}
 
int main(){
    int T;
    cin >> T;
    while(T--){
        memset(letter, 0, sizeof(letter));
        cin >> str;
        calculate();
    }
    return 0;
}


