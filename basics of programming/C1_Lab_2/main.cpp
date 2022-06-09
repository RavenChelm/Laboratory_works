#include "iostream"
#include "conio.h"
#include <windows.h>

void fill_table(int i, Group* table);
void print(int q, Group* table, bool* check);
int control(int size, Group* list, bool* check);

struct Date
{
    int day;
    int month;
    int year;
};
struct Group
{
    char FIO[100];
    char gender;
    char school;
    char adress;
    char money;
    Date birth;
    int marks[5];
    int points;
};
void fill_table(int i, Group* table)
{
    std::cout << "ФИО:\n>";
    std::cin.getline(table[i].FIO, 100);
    std::cout << "Пол:\n>";
    std::cin >> table[i].gender;
    std::cout << "Тип учебного заведения:\n>";
    std::cin >> table[i].school;
    std::cout << "Адрес:\n>";
    std::cin >> table[i].adress;
    std::cout << "Наличие стипендии:\n>";
    std::cin >> table[i].money;
    
    std::cout << "День рождения:\n>";
    std::cin >> table[i].birth.day;
    std::cout << "Месяц рождения:\n>";
    std::cin >> table[i].birth.month;
    std::cout << "Год рождения:\n>";
    std::cin >> table[i].birth.year;
    
    std::cout << "Оценки за семестр(5, через пробел)):\n>";
    for(int j = 0; j < 5; j++)
        std::cin >> table[i].marks[j];
    std::cout << "Баллы:\n>";
    std::cin >> table[i].points;
    std::cout << "\n";
    std::cin.get();
}
void print(int q, Group* table, bool* check)
{
    std::cout << "\n|ФИО\t\t|Пол\t|Окончил\t|Адрес\t|Стипендия\t|День\t|Месяц\t|Год рождения\t|оценки за семестр\t|Баллы при поступлении|\n";
    for (int i = 0; i < q; i++)
        if (check[i] == 1) {
            std::cout << "|" << table[i].FIO << "\t|";
            std::cout << table[i].gender << "\t|";
            std::cout << table[i].school << "\t\t|";
            std::cout << table[i].adress << "\t|";
            std::cout << table[i].money << "\t\t|";
            std::cout << table[i].birth.day << "\t|";
            std::cout << table[i].birth.month << "\t|";
            std::cout << table[i].birth.year << "\t\t|";
            for (int j = 0; j < 5; j++)
            	std::cout << table[i].marks[j] << " ";
            std::cout << "\t\t|" << table[i].points;
            std::cout << "\t\t      |\n";
            std::cout << "\n";
        }
}
int control(int size, Group* list, bool* check)
{
    int numberOf = 0;

    for (int i = 0; i < size; i++)
        if ((list[i].birth.month <= 2 || list[i].birth.month ==12) && (list[i].marks[0] >=4 && list[i].marks[1] >=4 && list[i].marks[2] >=4  && list[i].marks[3] >=4  && list[i].marks[4] >=4))
            numberOf++;
        else
            check[i] = 0;

    return numberOf;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
    const int q = 7;
    Group table[q];
    bool check[q];
    int i = 0, count = 2;
    for (int i = 0; i < q; i++)
        check[i] = 1;
    for (int i = 0; i < q; i++)
        fill_table (i, table);
    system("cls");
    std::cout << "Исходные данные:\n";
    print(q, table, check); 
    count = control(q, table, check); // отбор + количество
    std::cout <<"Количество отобранных студентов:" << count <<"\n" ;
    std::cout << "Отобранные данные:\n";
    print(q, table, check); //печать отобранного
    getch();
    return 0;
}


