#include "iostream"
#include <cassert>
using namespace std;

template < typename T >

class Vect {
private:
	T* data;
	int len = 0;
public:
	Vect(){
		len = 0;
		data = nullptr;
	}
	Vect(int q, int val = 0) {
		len = q;
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
	void leng() {
		cout << len << endl;
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
		return (data[len-1]); 
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
		new_data =nullptr;
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
		new_data[len-1] = val;
		clear();
		len = n;
		data = new_data;
		new_data = nullptr;
	};
	void pop_back() {//������� ������� �� ����� �������
		len = len - 1;
		T* new_data = new T[len];
		for (int i = 0; i < len; i++)
			new_data[i] = data[i];
		clear();
		len = n;
		data = new_data;
		new_data = nullptr;
	}
	void insert(int val = 0, int n = 1, int it = 0) {//��������� �������� � ������ �������
		len = len + n;
		T* new_data = new T[len+1];
		for (int i = it; i < n; i++)
			new_data[i] = val;
		for (int i = n; i < len; i++)
			new_data[i] = data[i-n];
		clear();
		len = n;
		data = new_data;
		new_data = nullptr;
	}
	void erase(int n) { //������� ��������� ������� 
		len = len - 1;
		T* new_data = new T[len+1];
		for (int i = 0; i < n; i++)
			new_data[i] = data[i];
		for (int i = n+1; i < len+1; i++)
			new_data[i - 1] = data[i];
		clear();
		len = n;
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
			cout << data[i];
		cout << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������ ������� 8:" << endl;
	Vect <double> vect(8);
	vect.show();
	vect.empty();
	vect.resize(10,5);
	vect.show();	
	vect.pop_back();
	vect.show();
	vect.push_back(4);
	vect.show();
	vect.insert(1, 2);
	vect.show();
	vect.erase(0);
	vect.show();
	vect.swap(0, 8);
	vect.show();
	vect.empty();
	cout << vect.back() << endl;
	cout << vect.front() << endl;
	vect.clear();
	vect.show();
	vect.empty();
	return 0;
}