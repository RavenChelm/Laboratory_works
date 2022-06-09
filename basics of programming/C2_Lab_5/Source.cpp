#include "iostream"
#include <cassert>
#include <ctime>
#include <chrono> 

using namespace std;

class Timer
{
private:
	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

template < typename T >
class Vect {
private:
	T* data;
	int len = 0, p, s;
public:
	Vect() {
		len = 0;
		data = nullptr;
	}
	Vect(int q, int val = 0) {
		len = q;
		p = 0; s = 0; 
		assert(q >= 0);
		if (len >= 0) {
			data = new T[len];
			for (int i = 0; i < len; i++)
				data[i] = val;
		}
		else
			data = nullptr;
	}
	~Vect() {
		delete[] data;
		data = nullptr;
		len = 0;
	}
	int& operator[](int index)
	{
		return data[index];
	}
	int leng() {
		return len;
	}
	void create(int q, int val = 0) {
		len = q;
		if (len >= 0) {
			data = new T[len];
			for (int i = 0; i < len; i++)
				data[i] = val;
		}
	}
	void clear() { //������ �������� �������
		delete[] data;
		data = nullptr;
		len = 0;
	}
	int front() { //�������� ������ ������
		return (data[0]);
	}
	int back() { //�������� ��������� ������
		return (data[len - 1]);
	}
	void resize(int n, int val = 0) {//���������� ������ ������� �� n ��������� � ��������� ����� �� �������� val
		if (n == len) //���� ���������
			return;
		if (n <= 0) { //���� ����� �������� ������
			clear();
			return;
		}
		T* new_data = new T[n];
		if (n > len) { //���� ����� ������ �������� ������
			for (int i = 0; i < len; i++)
				new_data[i] = data[i];
			for (int i = len; i < n; i++)
				new_data[i] = val; //���������
			clear();
			len = n;
			data = new_data;
		}
		if (n < len) { //���� ����� ������ ������� ������
			for (int i = 0; i < n; i++)
				new_data[i] = data[i];
			clear();
			len = n;
			data = new_data;
		}
		new_data = nullptr;
	}
	void empty() { //���� ��������� ���� ���������� true, ���� ��� - false
		if (len == 0) {
			cout << "������ �� �������� ������" << endl;
			return;
		}
		for (int i = 0; i < len; i++)
			if (data[i] != 0) {
				cout << "������ �������� ������" << endl;
				return;
			}
		cout << "������ �� �������� ������" << endl;
		return;
	}
	void push_back(int val = 0) {//��������� �������� ������� � ����� �������
		len = len + 1;
		T* new_data = new T[len];
		for (int i = 0; i < len - 1; i++)
			new_data[i] = data[i];
		new_data[len - 1] = val;
		clear();
		data = new_data;
		new_data = nullptr;
	};
	void pop_back() {//������� ������� �� ����� �������
		len = len - 1;
		T* new_data = new T[len];
		for (int i = 0; i < len; i++)
			new_data[i] = data[i];
		clear();
		data = new_data;
		new_data = nullptr;
	}
	void insert(int val = 0, int n = 1, int it = 0) {//��������� �������� � ������ �������
		len = len + n;
		T* new_data = new T[len + 1];
		for (int i = it; i < n; i++)
			new_data[i] = val;
		for (int i = n; i < len; i++)
			new_data[i] = data[i - n];
		clear();
		data = new_data;
		new_data = nullptr;
	}
	void erase(int n) { //������� ��������� ������� 
		len = len - 1;
		T* new_data = new T[len + 1];
		for (int i = 0; i < n; i++)
			new_data[i] = data[i];
		for (int i = n + 1; i < len + 1; i++)
			new_data[i - 1] = data[i];
		clear();
		data = new_data;
		new_data = nullptr;
	}
	void swap(int n, int m) { //������ ��� �������� �������
		int q = data[n];
		data[n] = data[m];
		data[m] = q;
	}
	void show() {
		if (len == 0)
			cout << "er";
		for (int i = 0; i < len; i++)
			cout << data[i] << " ";
		cout << endl;
	}
	void show_char() {
		cout << "���������� ������������:" << p << endl << "���������� ���������:" << s << endl;
		p = 0;
		s = 0;
	}
	void quickSort(int left, int right)
	{
		int pivot; // ����������� �������
		int l_hold = left; //����� �������
		int r_hold = right; // ������ �������
		pivot = data[left];
		while (left < right) // ���� ������� �� ���������
		{
			while ((data[right] >= pivot) && (left < right)) {
				right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
				s++;//���������
			}
			if (left != right) // ���� ������� �� ����������
			{
				data[left] = data[right]; // ���������� ������� [right] �� ����� ������������
				left++; // �������� ����� ������� ������
				p++;//������������
			}
			while ((data[left] <= pivot) && (left < right)){
				left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
				s++;//���������
			}
			if (left != right) // ���� ������� �� ����������
			{
				data[right] = data[left]; // ���������� ������� [left] �� ����� [right]
				right--; // �������� ������ ������� ������
				p++;//������������
			}
		}
		data[left] = pivot; // ������ ����������� ������� �� �����
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
			quickSort(left, pivot - 1);
		if (right > pivot)
			quickSort(pivot + 1, right);
	}
	void insertsort() {
		for (int i = 1; i < len; i++) {
			s++;
			for (int j = i; j > 0 && data[j - 1] > data[j]; j--) {
				swap(j - 1, j);
				p++;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	int n, k, j;
	bool t = false;
	cout << "������� ������ �������:" << endl;
	cin >> n;
	Vect <int> q(n);
	do {
		cout << "�������� ������� �������:" << endl;
		cout << "1)���������������" << endl;
		cout << "2)��������������� � �������� �������" << endl;
		cout << "3)���������" << endl;
		cout << "4)�����" << endl;
		cin >> k;
		if (k == 1) {
			for (int i = 0; i < q.leng(); i++)
				q[i] = i;
			t = true;
		}
		if (k == 2) {	
			j = n;
			for (int i = 0; i < q.leng(); i++) {
				q[i] = j;
				j--;
			}
			t = true;
		}
		if (k == 3) {
			srand(time(NULL));
			for (int i = 0; i < q.leng(); i++)
				q[i] = rand() % 101;
			t = true;
		}
		if (k == 4) {
			return 0;
			break;
		}
		system("pause");
		system("cls");
		if (t == true) {
			do {
				cout << "�������� ��������:" << endl;
				cout << "1)������� ����������" << endl;
				cout << "2)���������� ���������" << endl;
				cout << "3)�����" << endl;
				cin >> k;
				if (k == 1) {
					//cout << "�������������� ������: " << endl;
					//q.show();
					Timer t;
					q.quickSort(0, q.leng() - 1);
					cout << "����� ������ ����������: " << fixed << t.elapsed() << '\n';
					q.show_char();
					//cout << "��������������� ������: " << endl;
					//q.show();
				}
				if (k == 2) {
					//cout << "�������������� ������: " << endl;
					//q.show();
					Timer t;
					q.insertsort();
					cout << "����� ������ ����������: " << fixed << t.elapsed() << '\n';
					q.show_char();
					//cout << "��������������� ������: " << endl;
					//q.show();
				}
				if (k == 3) {
					t = false;
				}
				system("pause");
				system("cls");
			} while (t == true);
		}
	} while (t == false);
}