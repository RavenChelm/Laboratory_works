#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <cstdlib>
#include <io.h>
using namespace std;
bool create_base();
bool dop_create_base(bool t);
bool release(bool t);
bool searh(bool t);
void name();
void sity();
void tipe();
void price();
void lenght();
const char * dir = "Q:\\MYFiles\\work_space\\lab\\lab_5\\test.txt";
const char * dir2 = "Q:\\MYFiles\\work_space\\lab\\lab_5\\test2.txt";
inline void eatline() { while (cin.get()!='\n') continue; } 

struct airs{
	char name[30];
	char sity[30];
	char tipe[30];
	int price;
	int length;
};
int main()
{
	int n;
	bool t = false;
	system("chcp 1251");
    system("cls");
	while(true){
		cout << "\n    Вид действия:" << endl 
		<< "  1 - создание базы данных" << endl 
		<< "  2 - добавление новых записей" << endl 
		<< "  3 - поиск" << endl 
		<< "  4 - просмотр базы данных" << endl 
		<< "  5 - завершение задачи" << endl 
		<< "  Введите вид действия ->" ; 
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

bool create_base(){
	airs air;
    ofstream base(dir, ios_base::out);
    cin.getline(air.name,0);
    cout<<"Введите наименования перелёта (или 0 для вызова меню):\n"; 
	cin.get(air.name,20); 
	while (air.name[0]!= '0') {
		eatline();
		cout<< "Введите город назначения: ";    
		cin.getline(air.sity,20); 
		cout<< "Введите тип самолёта: "; 
		cin.getline(air.tipe,20); 
		cout<< "Введите стоимость: ";
		cin >> air.price;
		cout<< "Введите протяжённость линии: ";
		cin >> air.length;
		eatline();
		base.write((char *)&air, sizeof air);
    	system("cls");
		cout<<"Введите наименование перелёта (или 0 для вызова меню):\n"; 
		cin.get(air.name,20);
	}
	base.close();
	system("cls");
	return true;
}

bool dop_create_base(bool t){
	airs air;
	if (t == false)
	{
		cout << " База данных ещё не создана.";
		return false;
	}
    ofstream base(dir, ios_base::app);
    cin.getline(air.name,0);
    cout<<"Введите наименования перелёта (или 0 для вызова меню):\n"; 
	cin.get(air.name,20); 
	while (air.name[0]!= '0') {
		eatline();
		cout<< "Введите город назначения: ";    
		cin.getline(air.sity,20); 
		cout<< "Введите тип самолёта: "; 
		cin.getline(air.tipe,20); 
		cout<< "Введите стоимость: ";
		cin >> air.price;
		cout<< "Введите протяжённость линии: ";
		cin >> air.length;
		eatline();
		base.write((char *)&air, sizeof air);
    	system("cls");
		cout<<"Введите наименование перелёта (или 0 для вызова меню):\n"; 
		cin.get(air.name,20);
	}
	system("cls");
	base.close();
	return true;
}

bool release(bool t){
	airs air;
	char* buffer=new char[40];
	if (t == false)
	{
		cout << " База данных ещё не создана.";
		return false;
	}
	ifstream base(dir);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(10)<< "Стоимость"
			 << setw(10)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)) { 
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (4) << setw(20)<< air.price 
			<< setprecision (10) << setw(20)<< air.length << endl; 
		} 
	base.close ();
	return true;
}

bool searh(bool t){
	int n;
	if (t == false){
		cout << " База данных ещё не создана.";
		return false;
	}
	while(true){
		cout << "\n    Вид действия:" << endl 
		<< "  1 - поиск по наименованию перелёта" << endl 
		<< "  2 - поиск по городу назначения" << endl 
		<< "  3 - поиск по типу самолёта" << endl 
		<< "  4 - поиск по стоимости" << endl 
		<< "  5 - поиск по протяжённости линии" << endl 
		<< "  6 - завершение задачи" << endl 
		<< "  Введите вид действия ->" ; 
		cin >> n;
		system("cls");
		switch(n){
			case 1:
				name();
				break;
			case 2:
				sity();
				break;
			case 3:
				tipe();
				break;				
			case 4:
				price();
				break;
			case 5:
				lenght();
				break;
			case 6:
				return true;
				break;												
			default:
				cout << "Unknown comand";
				break;
		}
	}
	return true;
}

void name(){
	airs air;
	bool v;
	char aname[30];
	int j=0;
	cin.getline(aname,0);
	cout<<"Введите наименование:\n"; 
	cin.get(aname,30);
	cout<<"Результаты:\n";
	ifstream base(dir); 
	ofstream obr_base(dir2);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(20)<< "Стоимость"
			 << setw(20)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)){
		for (int i = 0; i <30; i++)
		{
			if (air.name[i]==aname[i]){
				j++;
			}
			else{
				break;
			}
		}
		for (int i = 0; i <j; i++)
		{
			if (air.name[i]==aname[i])
				v = true;
			else{
				v = false;
				break;
			}
		}
		if(v == true)
		{
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (10) << setw(20)<< air.price 
			<< setprecision (10) << setw(20)<< air.length << endl; 	
			obr_base.write((char *)&air, sizeof air);
		}
	}
	base.close ();
	obr_base.close();
}
void sity(){
	airs air;
	bool v;
	char asity[30];
	int j=0;
	cin.getline(asity,0);
	cout<<"Введите город:\n"; 
	cin.get(asity,30);
	cout<<"Результаты:\n";
	ifstream base(dir); 
	ofstream obr_base(dir2);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(20)<< "Стоимость"
			 << setw(20)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)){
		for (int i = 0; i <30; i++)
		{
			if (air.sity[i]==asity[i]){
				j++;
			}
			else{
				break;
			}
		}
		for (int i = 0; i <j; i++)
		{
			if (air.sity[i]==asity[i])
				v = true;
			else{
				v = false;
				break;
			}
		}
		if(v == true)
		{
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (10) << setw(20)<< air.price 
			<< setprecision (10) << setw(20)<< air.length << endl; 	
			obr_base.write((char *)&air, sizeof air);
		}
	}
	base.close ();
	obr_base.close();
}
void tipe(){
	airs air;
	bool v;
	char atipe[30];
	int j=0;
	cin.getline(atipe,0);
	cout<<"Введите тип:\n"; 
	cin.get(atipe,30);
	cout<<"Результаты:\n";
	ifstream base(dir); 
	ofstream obr_base(dir2);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(20)<< "Стоимость"
			 << setw(20)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)){
		for (int i = 0; i <30; i++)
		{
			if (air.tipe[i]==atipe[i]){
				j++;
			}
			else{
				break;
			}
		}
		for (int i = 0; i <j; i++)
		{
			if (air.tipe[i]==atipe[i])
				v = true;
			else{
				v = false;
				break;
			}
		}
		if(v == true)
		{
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (10) << setw(20)<< air.price 
			<< setprecision (10) << setw(20)<< air.length << endl; 	
			obr_base.write((char *)&air, sizeof air);
		}
	}
	base.close ();
	obr_base.close();
}
void price(){
	airs air;
	int aprice;
	cout<<"Введите стоимость перелёта:\n"; 
	cin >> aprice;
	cout<<"Результаты:\n";
	ifstream base(dir); 
	ofstream obr_base(dir2);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(10)<< "Стоимость"
			 << setw(10)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)){
		if(air.price == aprice)
		{
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (4) << setw(10)<< air.price 
			<< setprecision (10) << setw(10)<< air.length << endl; 
		}
	}
	base.close ();
	obr_base.close();
}
void lenght(){
	airs air;
	int alenght;
	cout<<"Введите протяжённость перелёта:\n"; 
	cin >> alenght;
	cout<<"Результаты:\n";
	ifstream base(dir); 
	ofstream obr_base(dir2);
	cout << setw(20) << "Наименования перелёта"
			 << setw(20) << "Город назначения"
			 << setw(20) << "Тип самолёта"
			 << setw(20)<< "Стоимость"
			 << setw(20)<< "Протяжённость линии" << endl;
	while (base.read((char *)&air, sizeof air)){
		if(air.length == alenght)
		{
			cout <<setprecision(0) << setw(20) << air.name
			<<setprecision(0) << setw(20) << air.sity 
			<< setprecision (0) << setw(20) << air.tipe 
			<< setprecision (10) << setw(20)<< air.price 
			<< setprecision (10) << setw(20)<< air.length << endl; 
		}
	}
	base.close ();
	obr_base.close();
}

/*
1
qqqq
wwww
eeee
1000
1000
aaaa
ssss
dddd
2000
2000
0
2
zzzz
xxxx
cccc
3000
4000
0
*/
