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
#include<iostream>
#include<cstdio>
#include <cmath>
#include<algorithm>

using namespace std;
const double eps=1e-9;
const double Pi=acos(-1.0);

int dcmp(double x)
{
	if(fabs(x)<eps){
		return 0;
	}
	else {
		if (x > 0){
			return 1;
		}
		else{
			return -1;
		}
	}
}
 
struct point{
	double x,y;
	point() {}
	point(double x,double y):x(x),y(y) {}
	bool operator < (const point &p_y) const {
		return dcmp(x-p_y.x)<0||(dcmp(x-p_y.x)==0&&dcmp(y-p_y.y)<0);
	}
	point operator + (const point &p_y) const {
		return point(x+p_y.x,y+p_y.y);
	}
	point operator - (const point &p_y) const {
		return point(x-p_y.x,y-p_y.y);
	}
	point operator * (const double &p_y) const {
		return point(x*p_y,y*p_y);
	}
	point operator / (const double &p_y) const {
		return point(x/p_y,y/p_y);
	}
}p_x[2510],p_y[2510];

point Rotate(point p,double p_x)
{
	double x = p.x*cos(p_x)-p.y*sin(p_x);
	double y = p.x*sin(p_x)+p.y*cos(p_x);
	return point(x,y);
}

double dete(const point &p_x,const point &p_y) {return p_x.x*p_y.y-p_x.y*p_y.x;}
  
int main()
{
	int N;
	cin >> N;
	while(N--) {
		int n=0;
		int cot = 0;
		cin >> n;
		double x,y,w,h,v,rad,board_area=0.0,poly_area=0.0;
		for(int i=0;i<n;i++) {
			cin >> x >> y >> w >> h >> v;
			point s(x,y);
			board_area+=w*h;
			if (board_area < eps) break;
			rad=-v/180*Pi;
			
			point p1=point(-w/2.0,-h/2.0);
			point p2=point(-w/2.0,h/2.0);
			point p3=point(w/2.0,-h/2.0);
			point p4=point(w/2.0,h/2.0);

			p_x[cot++]=s+Rotate(p1,rad);
			p_x[cot++]=s+Rotate(p2,rad);
			p_x[cot++]=s+Rotate(p3,rad);
			p_x[cot++]=s+Rotate(p4,rad);
		}
		sort(p_x,p_x+cot);
		
		int j=0;
		for(int i=0;i<cot;i++) {
			while(j>1 && dcmp(dete(p_y[j-1]-p_y[j-2], p_x[i]-p_y[j-2]))<=0) j--;
			p_y[j++]=p_x[i];
		}
		int k=j;
		for(int i=cot-2;i>=0;i--) {
			while(j > k && dcmp(dete(p_y[j-1]-p_y[j-2], p_x[i]-p_y[j-2]))<=0) j--;
			p_y[j++]=p_x[i];
		}
		for(int i=0;i<j-1;i++) {
			poly_area+=dete(p_y[i],p_y[i+1]);
		}
		poly_area/=2.0;
		board_area=(board_area/poly_area)*100.0;
		
		printf("%.1lf %%\n",board_area);
	}
}
