#include <iostream>
#include "math.h"
using namespace std;
class nonlinear_queat {
	private:
		double a, b, c, i, j, eps, x0;
		bool qub = false;
	public:
		nonlinear_queat(){
			a = 0; b = 0; c = 0; i = 0, j = 0, eps = 0.1, x0 = 0;
	}
		void enter(int k = 0)  {
			do {
				if (k != 0) {
					cout << "Enter x0: ";
					cin >> x0;
				}
				else {
				cout << "Enter interval ( i, j): ";
				cin >> i >> j;
				}
				cout << "is the equation cubic?1/0" << endl;
				cin >> qub;
				cout << "Enter coefficients of a non-Linear equations ( a, b, c): ";
				cin >> a >> b >> c;
				if ((func(i, a, b, c) * func(j, a, b, c) > 0) && (k==0))
					cout << "Wrong interval!\n";
			} while (func(i, a, b, c) * func(j, a, b, c) > 0 && (k == 0));
			cout << "epsilon: ";
			cin >> eps;
	}
		double func(double x, double a, double b, double c) {
			if (qub == false)
				return a * x * x + b * x + c;
			else
				return a * x * x * x + b * x + c;
		}
		double Dihotomia(){
		double q = 0;
		enter();
		while ((j - i) / 2 > eps) {
			q = (i + j) / 2;
			if ((func(i, a, b, c) * func(q, a, b, c)) > 0)
				i = q;
			else
				j = q;
		}
		return q;
		}
		double Chords() {
			double Fi = 0, Fj = 0, Fq = 0; double q;
			enter();
			Fi = func(i, a, b, c);
			Fj = func(j, a, b, c);
			
			if (Fi * Fj > 0) {
				cout << "error" << endl;
				return 0;
			}
			do {
				q = i - (j - i) / (func(j, a, b, c) - func(i, a, b, c)) * func(i, a, b, c);
				Fq = func(q, a, b, c);
				if (Fi * Fq) {
					i = q;
					Fi = Fq;
				}
				else {
					j = q;
					Fj = Fq;
				}
			} while (abs(j - i) > eps);
			return q;
		}
		double Newton(int k) {
			double f0 = 0, f1 = 0, f2 = 0, x1 = 0;
			int t = 0;
			enter(k);
			f0 = func(x0, a, b, c);
			f1 = ((func((x0 + eps), a, b, c) - func((x0 - eps), a, b, c)) / (2 * eps));
			f2 = (func((x0 + eps), a, b, c) - 2 * func(x0, a, b, c) + func((x0 - eps), a, b, c)) / (eps * eps);
			//cout << f0 << endl << f1 << endl << f2 << endl << (f0 * f2) / pow(f1, 2) << endl;
			if (abs((f0 * f2) / pow(f1, 2)) >= 1) {
				cout << "Process diverges" << endl;
				return 0;
			}
			do {
				if (t > 0) {
					x0 = x1;
					f0 = func(x0, a, b, c);
				}
				x1 = x0 - f0 / f1;
				t++;
			} while (abs(x1 - x0) > eps);
			return x1;
		}
};
int main() {
	int k;
	double x = 0;
	bool t = true;
	nonlinear_queat q = nonlinear_queat();
	do {
		cout << "Choose method:" << endl;
		cout << "1)Dichotomy:" << endl;
		cout << "2)Chords:" << endl;
		cout << "3)Newton:" << endl;
		cin >> k;
		switch (k) {
		case(1):
			x = q.Dihotomia();
			break;
		case(2):
			x = q.Chords();
			break;
		case(3):
			x = q.Newton(k);
			break;
		default:
			cout << "You enter wrong value";
		}
		cout << "x = " << x << endl;
		cout << "Proceed calculations?1/0" << endl;
		cin >> t;
		system("cls");
	} while (t == true);
	return 0;
}