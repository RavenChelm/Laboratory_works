#include "iostream"
#include "List.h"
using namespace std;

int main() {
	system("chcp 1251");
	system("cls");
	List<int> list;
	// ������� ������, �������� �������� � �����
	int z = 0;
	int n;
	int s = 0;
	cout << "������� ��������� ������? " << endl;
	cin >> n;
	cout << "������� �������� ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> z;
		list.Add(z, s);
		s++;
	}
	list.Print();
	cout << "������ ����� ��������: " << endl;
	if (list.getvalue(0) >= list.getvalue(1)) {
		list.Swap(1, list.getCount() - 1);
		list.Swap(0, list.getCount()-2);
	}
	else {
		list.Swap(1, list.getCount()-2);
		list.Swap(0, list.getCount() - 1);
	}
	list.Print();
	return 0;
}