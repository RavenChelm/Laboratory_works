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
		cout << "Введите первый  элемент последовательности (x):" << endl;
		cin >> x;
		cout << "Введите число из которого нужно вычислить корень (a):" << endl;
	    cin >> a;
		cout << "Введите точность (q):" << endl;
		cin >> q;
		cout <<"Корень из числа a = " << Geron(x, a, q);
		cout << endl << "Завершить программу? 1 - да, 0 - нет" << endl;
		cin >> t;
		system("cls");
	}
	return 0;
}