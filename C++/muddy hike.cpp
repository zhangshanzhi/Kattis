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
using namespace std;

int main() {
    int r,c;
    cin >> r >> c;	
    vector<int> start(r,0);
    	for (int i = 0; i < r+1; i++){
		cout << start.at(i);		//如果访问越界，会抛出异常，比下标运算更安全，流畅
	}
	
}
