#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

struct FIO
{
    char f[20];
    char io[10];
};

struct Group
{
    FIO fio;
    char gender;
    char edBase;
    char adress;
    char exMoney;

    Date birth;
    
    int marks[5];
    int points;
};

void fill_table(int i, Group* tempStruct);
void record(std::ofstream& tempfile, Group* tempStruct, int i);
void scan(std::ifstream& tempfile, Group* tempStruct, int size);
void print(Group* sheet, int i);
int control(Group* list, int size, bool* check);

int main()
{
    system("chcp 1251");
    system("cls");

    const int size = 7;
    int counter = size;
    bool check[size];
    char dir[50], name[20];
    char dir2[50], name2[20];

    std::cout << "Введите путь для создания файла исходных данных:\n> ";
    std::cin.getline(dir, 50);
    std::cout << "Введите название и тип файла:\n> ";
    std::cin.getline(name, 20);
    strcat(dir, name);

    std::cout << "Введите путь для создания файла готовых данных:\n> ";
    std::cin.getline(dir2, 50);
    std::cout << "Введите название и тип файла:\n> ";
    std::cin.getline(name2, 20);
	strcat(dir2, name2);

    std::ofstream original(dir);
    if (!original.is_open())
        std::cout << "\n Ошибка \n";
    else {
        Group list[size];
        std::cout << "Запоните построчно таблицу группы:\n\n";
        for (int i = 0; i < size; i++)
            fill_table(i, list);
        for(int i = 0; i < size; i++)
            record(original, list, i);
        original.close();

        system("cls");

        std::cout << "Исходные данные:\n";
        std::ifstream originaltoo(dir);
        if (!originaltoo.is_open())
            std::cout << "\n Ошибка \n";
        else {
            Group listcopy[size];
            scan(originaltoo, listcopy, size);
            originaltoo.close();

            std::cout << "______________________________________________________________________________________________________________________________________________";
            std::cout << "\n|ФИО\t\t|Пол\t|Окончил\t|Адрес\t|Стипендия\t|День\t|Месяц\t|Год рождения\t|Оценки за сессию\t|Баллы при поступлении|\n";
            std::cout << "______________________________________________________________________________________________________________________________________________";
            std::cout << "\n";
            for (int i = 0; i < size; i++)
                print(listcopy, i);

            counter = control(listcopy, size, check);
            
            std::ofstream sorted(dir2);
            if (!sorted.is_open())
                std::cout << "\n Ошибка \n";
            else {
                for (int i = 0; i < size; i++)
                    if(check[i] == 1)
                        record(sorted, listcopy, i);
                sorted.close();

                Group final[size];

                std::ifstream res(dir2);
                if (!res.is_open())
                    std::cout << "\n Ошибка \n";
                else {
                    scan(res, final, counter);
                    res.close();
                    std::cout << "\n\Отобранные анкетные данные:\n";
                    std::cout << "______________________________________________________________________________________________________________________________________________";
                    std::cout << "\n|ФИО\t\t|Пол\t|Окончил\t|Адрес\t|Стипендия\t|День\t|Месяц\t|Год рождения\t|Оценки за сессию\t|Баллы при поступлении|\n";
                    std::cout << "______________________________________________________________________________________________________________________________________________";
                    std::cout << "\n";
                    for(int i = 0; i < counter; i++)
                        print(final, i);
                    std::cout << "\n\nСтудентов, удовлетворяющих условию: " << counter << "\n";
                }
            }
        }
    }

	return 0;
}

void fill_table(int i, Group* tempStruct)
{
    std::cout << "Ф:\n> ";
    std::cin.getline(tempStruct[i].fio.f, 20);
    std::cout << "ИО:\n> ";
    std::cin.getline(tempStruct[i].fio.io, 10);
    std::cout << "Пол:\n> ";
    std::cin >> tempStruct[i].gender;
    std::cout << "Тип учебного заведения:\n> ";
    std::cin >> tempStruct[i].edBase;
    std::cout << "Адрес:\n> ";
    std::cin >> tempStruct[i].adress;
    std::cout << "Наличие стипендии:\n> ";
    std::cin >> tempStruct[i].exMoney;
    std::cout << "День рождения:\n> ";
    std::cin >> tempStruct[i].birth.day;
    std::cout << "Месяц рождения:\n> ";
    std::cin >> tempStruct[i].birth.month;
    std::cout << "Год рождения:\n> ";
    std::cin >> tempStruct[i].birth.year;
    std::cout << "Оценки за сессию (5 штук через пробел):\n> ";
    for (int j = 0; j < 5; j++)
        std::cin >> tempStruct[i].marks[j];
    std::cout << "Баллы:\n> ";
    std::cin >> tempStruct[i].points;
    std::cout << "\n";
    std::cin.get();
}

void record(std::ofstream& tempfile, Group* tempStruct, int i)
{
    tempfile << tempStruct[i].fio.f << " ";
    tempfile << tempStruct[i].fio.io << "\t";
    tempfile << tempStruct[i].gender << "\t";
    tempfile << tempStruct[i].edBase << "\t";
    tempfile << tempStruct[i].adress << "\t";
    tempfile << tempStruct[i].exMoney << "\t";
    tempfile << tempStruct[i].birth.day << " ";
    tempfile << tempStruct[i].birth.month << " ";
    tempfile << tempStruct[i].birth.year << "\t";

    for (int j = 0; j < 5; j++)
        tempfile << tempStruct[i].marks[j] << " ";

    tempfile << "\t";
    tempfile << tempStruct[i].points << "\n";
}

void scan(std::ifstream& tempfile, Group* tempStruct, int size)
{
    for (int i = 0; i < size; i++) {
        tempfile >> tempStruct[i].fio.f;
        tempfile >> tempStruct[i].fio.io;
        tempfile >> tempStruct[i].gender;
        tempfile >> tempStruct[i].edBase;
        tempfile >> tempStruct[i].adress;
        tempfile >> tempStruct[i].exMoney;
        tempfile >> tempStruct[i].birth.day;
        tempfile >> tempStruct[i].birth.month;
        tempfile >> tempStruct[i].birth.year;

        for (int j = 0; j < 5; j++)
            tempfile >> tempStruct[i].marks[j];

        tempfile >> tempStruct[i].points;
    }
}

void print(Group* sheet, int i)
{
        std::cout << "|" << sheet[i].fio.f << " ";
        std::cout << sheet[i].fio.io << "\t|";
        std::cout << sheet[i].gender << "\t|";
        std::cout << sheet[i].edBase << "\t\t|";
        std::cout << sheet[i].adress << "\t|";
        std::cout << sheet[i].exMoney << "\t\t|";
        std::cout << sheet[i].birth.day << "\t|";
        std::cout << sheet[i].birth.month << "\t|";
        std::cout << sheet[i].birth.year << "\t\t|";
        for (int j = 0; j < 5; j++)
            std::cout << sheet[i].marks[j] << " ";
        std::cout << "\t\t|" << sheet[i].points;
        std::cout << "\t\t      |\n";
        std::cout << "______________________________________________________________________________________________________________________________________________";
        std::cout << "\n";
}

int control(Group* list, int size, bool* check)
{
    int numberOf = 0;
    for (int i = 0; i < size; i++)
        if ((list[i].birth.month <= 2 || list[i].birth.month ==12) && (list[i].marks[0] >=4 && list[i].marks[1] >=4 && list[i].marks[2] >=4  && list[i].marks[3] >=4  && list[i].marks[4] >=4)) {
            numberOf++;
            check[i] = 1;
        }
        else
            check[i] = 0;
    return numberOf;
}

/*
Q:\\stydy\\Gr_M023\\temp\\
list.txt
Q:\\study\\Gr_M023\\temp\\
	
    */

/*

*/
