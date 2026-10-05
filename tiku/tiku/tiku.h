#pragma once
#include <string>
using namespace std;
class sjx {
private:
	double length1, length2, length3,  rans_s, uans_s;
	int num;
public:
	sjx();
	void setlength(double l1, double l2, double l3);
	void answer();
	void user();
	void show();
	int duibi();
	void setnum(int n) { num = n; }
	int getnum() { return num; }
	void back();
};
class tkl {
private:
	sjx sjx1[10]; 
	string tkname;
	int tknum;
	int score[10];
public:
	tkl();
	void add();
	void delet();
	void search(int x);
	void pjsore();
};