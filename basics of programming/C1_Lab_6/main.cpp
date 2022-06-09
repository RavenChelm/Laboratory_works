#include <iostream>

int main(){
	int n;
	bool t = false;
	system("chcp 1251");
    system("cls");
	while(true){
		cout << "\n    Вид действия:" << endl 
		<< "  1 - Граф по умолчанию" << endl 
		<< "  2 - Добавление вершин " << endl 
		<< "  3 - Удаление вершин " << endl 
		<< "  4 - Построение связей " << endl 
		<< "  5 - Поиск путей " << endl 
		<< "  6 - Поиск кратчейшего пути " << endl 
		<< "  7 - Вывод информации на экран" << endl 
		<< "  8 - Запись графа в файл" << endl 
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
