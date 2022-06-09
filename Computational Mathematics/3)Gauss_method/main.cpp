#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;

class SLAU {
private:
    double** a, * y, * x;
    int n;
public:
    SLAU(int w) {
        n = w;
        a = new double* [n];
        for (int i = 0; i < n; i++)
            a[i] = new double[n];
        y = new double[n];
        x = new double[n];
    }
    ~SLAU() {
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        delete[] y;
        delete[] x;
    }
    void enter() {
        cout << "������� ����������: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        cout << "������� ������ ����� ���������: " << endl;
        for (int i = 0; i < n; i++)
            cin >> y[i];
    }
    void enter_vect() {
        cout << "������� �������� �������: " << endl;
        for (int j = 0; j < n; j++)
                cin >> a[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
        }
    }
    void system_equat()
    {
        cout << "������� ���������: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << "*x" << j;
                if (j < n - 1)
                    cout << " + ";
            }
            cout << " = " << y[i] << endl;
        }
        return;
    }
    void system_result() {
        cout << "�����: " << endl;
        for (int i = 0; i < n; i++)
            cout << "x[" << i << "]=" << x[i] << endl;
        cin.get();
    }
    void transp()
    {
        double** at = new double* [n];
        for (int i = 0; i < n; i++)
            at[i] = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                at[j][i] = a[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                a[i][j] = at[i][j];
        }
        for (int i = 0; i < n; i++)
            delete[] at[i];
        delete[] at;
        return;
    }
    double** get_matr() {return a;}
    void set_matr(double** c) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                a[i][j] = c[i][j];
        }
    }
    void  mpn(double** b) { // ��������� �������
        double** c = new double* [n];
        for (int i = 0; i < n; i++)
        {
            c[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] <= 0.00001)
                    c[i][j] = 0;
                a[i][j] = c[i][j];
            }
        }
        for (int i = 0; i < n; i++)
            delete[] c[i];
        delete[] c;
    }
    void gauss()
    {
        double max;
        int k, index;
        const double eps = 0.000000001;  // ��������
        k = 0;
        while (k < n)
        {
            // ����� ������ � ������������ a[i][k]
            max = std::abs(a[k][k]);
            index = k;
            for (int i = k + 1; i < n; i++)
            {
                if (abs(a[i][k]) > max)
                {
                    max = abs(a[i][k]);
                    index = i;
                }
            }
            // ������������ �����

            for (int j = 0; j < n; j++)
            {
                double temp = a[k][j];
                a[k][j] = a[index][j];
                a[index][j] = temp;
            }
            double temp = y[k];
            y[k] = y[index];
            y[index] = temp;
            // ������������ ���������
            for (int i = k; i < n; i++)
            {
                double temp = a[i][k];
                if (abs(temp) < eps) continue; // ��� �������� ������������ ����������
                for (int j = 0; j < n; j++)
                    a[i][j] = a[i][j] / temp;
                y[i] = y[i] / temp;
                if (i == k)  continue; // ��������� �� �������� ���� �� ����
                for (int j = 0; j < n; j++)
                    a[i][j] = a[i][j] - a[k][j];
                y[i] = y[i] - y[k];
            }
            k++;
        }
        // �������� �����������
        for (k = n - 1; k >= 0; k--)
        {
            x[k] = y[k];
            for (int i = 0; i < k; i++)
                y[i] = y[i] - a[i][k] * x[k];
        }
    }
    void out() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "�������:" << endl;
    }
    double front() {
        return a[0][0];
    };
    double sum(double** c, double** v) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += c[0][i] * v[0][i];
        }
        return sum;
    }
    double sum(double** c) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += c[0][i];
        }
        return sum;
    }
};

int main()
{
    system("chcp 1251");
    system("cls");
    cout << "������ ���������:" << endl;
    SLAU q = SLAU(4);
    q.enter();
    q.system_equat();
    q.gauss();
    q.system_result();
    
    cout << endl << "������ ���������:" << endl;
    SLAU z = SLAU(4);
    SLAU t = SLAU(4);
    SLAU r = SLAU(4);
    z.enter();
    t.set_matr(z.get_matr());
    t.transp();
    t.mpn(z.get_matr());
    r.set_matr(z.get_matr());
    r.transp();
    t.mpn(r.get_matr());
    z.set_matr(t.get_matr());
    z.system_equat();
    z.gauss();
    z.system_result();

    cout << endl << "�������� ������������ �����: " << endl;
    SLAU a = SLAU(4);
    SLAU a_tr = SLAU(4);
    SLAU y = SLAU(4);
    SLAU y_tr = SLAU(4);
    a.enter();
    a_tr.set_matr(a.get_matr());
    a_tr.transp();
    y_tr.enter_vect();
    y.set_matr(y_tr.get_matr());
    y.transp();
    y_tr.mpn(a.get_matr());
    y_tr.mpn(a_tr.get_matr());
    y_tr.mpn(a.get_matr());
    y_tr.mpn(a_tr.get_matr());
    y_tr.mpn(y.get_matr());
    cout << "�����: " << fixed << y_tr.front();

    cout << endl << endl << "���������� ���������:" << endl;
    SLAU g = SLAU(4);
    SLAU h = SLAU(4);
    g.enter_vect();
    h.enter_vect();
    cout << "�����:" << (g.sum(g.get_matr(), g.get_matr()) + 5 * g.sum(g.get_matr(), h.get_matr())) * (1 + g.sum(g.get_matr()) + g.sum(h.get_matr()) - 3 + g.sum(g.get_matr(), g.get_matr()));
    return 0;
}
/*
7 6 2 7
4 9 5 5
2 3 4 9
1 5 6 9
3 2 0 2
7 6 2 7
4 9 5 5
2 3 4 9
1 5 6 9
3 2 0 2
7 6 2 7
4 9 5 5
2 3 4 9
1 5 6 9
0 0 0 0
1 1 3 3
3 2 0 2
1 1 3 3
*/