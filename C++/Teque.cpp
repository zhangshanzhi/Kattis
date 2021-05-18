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

#include<bits/stdc++.h>
using namespace std;

deque<int> dq1;
deque<int> dq2;

void push_front(int i){

    dq1.push_front(i);
}
void push_back(int i){

    dq2.push_back(i);
}

void push_middle(int i){
   
    dq1.push_back(i);
}

void justi(){

    if(dq2.size()>dq1.size()){

        int t = dq2.front();
        dq2.pop_front();
        dq1.push_back(t);
    }
    else if(dq2.size()+1<dq1.size()){

        int t = dq1.back();
        dq1.pop_back();
        dq2.push_front(t);
    }
}

int get(int i){

    if(i<dq1.size()){
        return dq1.at(i);
    }
    return dq2.at(i-dq1.size());
}

int main(){

   int n;
   scanf("%d",&n);
   while(n--){
       char s[15];
       int data;
       scanf("%s",s);
       scanf("%d",&data);
       if(s[0] == 'p' && s[5] == 'b'){
           push_back(data);
       }
       else if(s[0] == 'p' && s[5] == 'f'){
           push_front(data);
       }
       else if(s[0] == 'p' && s[5] == 'm'){
           push_middle(data);
       }
       else{
           printf("%d\n",get(data));
       }
       justi();
   }
}