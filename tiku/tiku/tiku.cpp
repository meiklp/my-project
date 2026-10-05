#include <iostream>
#include <cmath>
#include <string>
#include "tiku.h"
using namespace std;
int N = 0;
sjx::sjx() : length1(0), length2(0), length3(0) {
	num = 0;
	rans_s = 0;
	uans_s = 0;
}
void sjx::setlength(double l1, double l2, double l3) {
	cout << "请输入三角形的三边长度：" << endl;
	this->length1 = l1;
	this->length2 = l2;
	this->length3 = l3;
}
void sjx::show() {
	cout << "三角形的三边长度为：" << length1 << ", " << length2 << ", " << length3 << endl;
	cout << "正确答案为：" << rans_s << endl;
	cout << "你的答案为：" << uans_s << endl;
}
void sjx::answer() {
	double p = (length1 + length2 + length3) / 2;
    double area = sqrt(p * (p - length1) * (p - length2) * (p - length3));
	this->rans_s = area;
}
int sjx::duibi() {
	if (uans_s == rans_s) {
		return 1;
	}
	else {
		return 0;
	}
}
void sjx::back() {
	this->length1 = 0;
	this->length2 = 0;
	this->length3 = 0;
	this->rans_s = 0;
	this->uans_s = 0;
	this->num = 0;
}
void sjx::user() {
	cout << "请输入三角形的三边长度：" << endl;
	cin >> length1 >> length2 >> length3;
	// 判断输入的三边是否能构成三角形
	if (length1 + length2 > length3 && length1 + length3 > length2 && length2 + length3 > length1) {
		answer();
		cout << "请输入你计算出的三角形面积：" << endl;
		cin >> uans_s;
		if (uans_s == rans_s) {
			cout << "恭喜你回答正确！" << endl;
		}
		else {
			cout << "很遗憾回答错误！正确答案是：" << rans_s << endl;
		}
	}
	else {
		cout << "输入的三边不能构成三角形！" << endl;
		
	}

}
tkl::tkl() {
	tkname = "三角形面积计算";
	tknum = 0;
	
	for (int i = 0; i < 10; i++) {
		score[i] = 0;
	}
}
void tkl::add() {
	if (tknum < 10) {
		sjx1[tknum].user();
		score[tknum] = sjx1[tknum].duibi();
		sjx1[tknum].setnum(tknum + 1);
		tknum++;
	}
		
	else {
		cout << "题库已满无法添加新题目！" << endl;
	}
}
void tkl::delet() {
	if (tknum > 0) {
		sjx1[tknum].back();
		tknum--;
		cout << "已删除最后一题！" << endl;
	}
	else {
		cout << "题库为空无法删除题目！" << endl;
	}
}
void tkl::search(int x) {
	if (x >= 1 && x <= tknum) {
		cout << "第" << sjx1[x - 1].getnum() << "题" << endl;
		sjx1[x - 1].show();
	}
	else {
		cout << "题目不存在！" << endl;
	}
}
void tkl::pjsore() {
	int sum = 0;
	for (int i = 0; i < tknum; i++) {
		sum += score[i];
	}
	cout << "平均分为：" << (double)sum / tknum << endl;
}
int main() {
	tkl tiku;
	while (true) {
		int choice;
		cout << "请选择操作：" << endl;
		cout << "1. 添加题目" << endl;
		cout << "2. 删除题目" << endl;
		cout << "3. 查询题目" << endl;
		cout << "4. 计算平均分" << endl;
		cout << "5. 退出" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			tiku.add();
			break;
		case 2:
			tiku.delet();
			break;
		case 3:
			int x;
			cout << "请输入要查询的题目编号：" << endl;
			cin >> x;
			tiku.search(x);
			break;
		case 4:
			tiku.pjsore();
			break;
		case 5:
			return 0;
		default:
			cout << "无效的选择，请重新输入！" << endl;
		}
	}
    return 0;
}