#include <iostream>

int main(){
	int n;
	bool t = false;
	system("chcp 1251");
    system("cls");
	while(true){
		cout << "\n    ��� ��������:" << endl 
		<< "  1 - ���� �� ���������" << endl 
		<< "  2 - ���������� ������ " << endl 
		<< "  3 - �������� ������ " << endl 
		<< "  4 - ���������� ������ " << endl 
		<< "  5 - ����� ����� " << endl 
		<< "  6 - ����� ����������� ���� " << endl 
		<< "  7 - ����� ���������� �� �����" << endl 
		<< "  8 - ������ ����� � ����" << endl 
		<< "  ������� ��� �������� ->" ; 
		cin >> n;
		system("cls");
		switch(n){
			case 1:
				t = create_base();
				break;
			case 2:
				dop_create_base(t);
				break;
			case 3:
				searh(t);
				break;				
			case 4:
				release(t);
				break;
			case 5:
				return 0;
				break;												
			default:
				cout << "Unknown comand";
				break;
		}
	}
}
