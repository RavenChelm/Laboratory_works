#include <iostream>
using namespace std;

double Geron(double x, double a, double q) {
	if (((a / x) <= x + q) && ((a / x) >= x - q))
		return x;
	return Geron(0.5*(x + a / x), a, q);
}
int main() {
	system("chcp 1251");
	system("cls");
	bool t = false;
	double x = 0, a = 0, q = 0.1;
	while (t == false) {
		cout << "������� ������  ������� ������������������ (x):" << endl;
		cin >> x;
		cout << "������� ����� �� �������� ����� ��������� ������ (a):" << endl;
	    cin >> a;
		cout << "������� �������� (q):" << endl;
		cin >> q;
		cout <<"������ �� ����� a = " << Geron(x, a, q);
		cout << endl << "��������� ���������? 1 - ��, 0 - ���" << endl;
		cin >> t;
		system("cls");
	}
	return 0;
}