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
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n, k, q;
    cin >> n >> k >> q;

    for(int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;

        ll moves = 0;
        x -= 1;
        y -= 1;
        while(true) {
        	if(x == y){
        		break;
			}
            moves++;
            if(y > x) swap(x, y);
            x = (x-1)/k;
        }

        cout << moves << endl;
    }
    return 0;
}
