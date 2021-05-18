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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void ans(int n){

	vector<string> name_v;
	vector<int> name_num;
	map<string, int> Map;
	vector<string> forbid_v1;
	vector<string> forbid_v2;
	//adding the name to the name vector
	
	for (int i = 0;i<n;i++){
		string name;
		cin>>name;
		name_v.push_back(name);	
	}
	//adding the forbidden pairs in to the forbid vevtor

	int n1;
	cin >> n1;
	while(n1--){
		string forbid_pair1,forbid_pair2;
		cin >> forbid_pair1 >> forbid_pair2;
		forbid_v1.push_back(forbid_pair1);
		forbid_v2.push_back(forbid_pair2);
	}	
	
	sort(name_v.begin(), name_v.end());
	
	for (int i = 0;i<n;i++){
		name_num.push_back(i);
		Map[name_v[i]] = i;
	} 

	do{
		bool jg = true;
		for (int i = 0;i<forbid_v1.size();i++){
			auto it1 = find(name_num.begin(), name_num.end(), Map[forbid_v1[i]]);
			auto it2 = find(name_num.begin(), name_num.end(), Map[forbid_v2[i]]);
			int aa = it1-name_num.begin();
			int bb = it2-name_num.begin();
			int val = aa-bb;
			if(val==1 || val == -1){
				jg=false;
				break; 
			}
		}
		if (jg){
			for (int k = 0;k<name_num.size();k++){
				cout<<name_v.at(name_num[k])<<" ";
			}
			cout<<endl;
			return;		
		}else{
			continue;
		}
	}while(next_permutation(name_num.begin(),name_num.end()));
	
	cout<<"You all need therapy."<<endl;
}

int main(){
    int n;
    while (cin>>n){
        ans(n);
     }
}

