#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
class square{
protected:
    double a;
public:
    square() {a = 1;}
    void set_a(double q) { a = q; }
    double D(){return sqrt(2) * a;}
    double P(){return 4 * a;}
    virtual double S(){return a * a;}
    virtual void Show(){cout << D() << endl << P() << endl << S() << endl;}
};
class pyramid: public square {
private:
    double A = 5 * a;
public:
    pyramid() { a = 1; }
    pyramid(double q) { a = q; }
    double V() {return (1 / 3) * P() * (sqrt(pow(A,2)- pow(0.5*a,2)));}
    double S() {return pow(a, 2) + 2 * sqrt((pow(A, 2) + pow(a / 2, 2)) - pow(a / 2, 2));}
    void Show(){cout << D() << endl << P() << endl << S() << endl << V() << endl;}
};
int main()
{
    setlocale(LC_ALL, "Russian");
    int N, M;
    double S_sr = 0, a;

    cout << "¬ведите количество квадратов:";
    cin >> N;
    square* sq = new square[N];
    for (int i = 0; i < N; i++) {
        cout << "¬ведите длинну стороны " << i + 1 << "-го квадрата:";
        cin >> a;
        sq[i].set_a(a);
    }
    for (int i = 0; i < N; i++)
        S_sr = S_sr + sq[i].S();
    cout << endl << "—редн€€ площадь квадратов:" << S_sr / N << endl;
    delete[] sq;

    cout << endl << "¬ведите количество пирамид:";
    cin >> M;
    pyramid* pir = new pyramid[M];
    for (int i = 0; i < M; i++) {
        cout << "¬ведите длинну стороны " << i + 1 << "-ой пирамиды:";
        cin >> a;
        pir[i].set_a(a);
    }
    a = pir[0].S();
    for (int i = 0; i < M; i++) {
        if (a >= pir[i].S())
            a = pir[i].S();
    }
    cout << "ћинимальна€ площадь пирамиды :" << a;
    delete[] pir;
    return 0;
}