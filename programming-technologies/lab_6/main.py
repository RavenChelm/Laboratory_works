import lab6
#Иницилизация переменных
key = ""
first = []
second = []
result = []
countСolumn = 0 #количество столбцов
while True:
    #Начало блока обработки исключений
    try:
        n = int(input("Ввод первого массива. \nВвод количества строк:")) #Ввод количества строк в первом массиве
        for i in range(n): #цикл по строкам
            row = input("Введите строку: ").split() #Ввод строки как массива, разделительный символ "пробел"
            for i in range(len(row)): #цикл по элементам в строке
                row[i] = float(row[i]) #приведение элемента строки к типу float
            if (countСolumn <= len(row)): #Если количество столбцов предыдущей строки меньше, чем данной,
                countСolumn = len(row) #приравнять количество столбцов к данному
            first.append(row) #добавить строку как новый элемент списка

        print("Ввод второго массива.\nКоличество строк второго массива: " + str(countСolumn)) 
        for i in range(countСolumn): #цикл по строкам
            row = input("Введите строку: ").split() #Ввод строки как массива, разделительный символ "пробел"
            for i in range(len(row)): #цикл по элементам в строке
                row[i] = float(row[i]) #приведение элемента строки к типу float
            second.append(row) #добавить строку как новый элемент списка

    
        result = lab6.LAB6_VAR_1(first, second) #Вызов функции и запись результата её работы
        print("Результат умножения матриц:")
        for i in range(len(result)): #Цикл по строкам
            for j in range(len(result[i])): #цикл по элементам в строке
                print(result[i][j], end=' ') #вывод элемента
            print() #переход на новую строку
    except ValueError: #При вызове исключения "ValueError"
        print("Некорректный тип")
    key = str(input("Введите Y, если хотите продолжить. Любую другую комбинацию, чтобы выйти.\n "))#Ввод комбинации для продолжения или завершения программы
    if(key == "Y"):
        countСolumn = 0 #Обнуление счётчика столбцов
        continue #Продолжение программы
    else: 
            break #Завершение программы
#Конец бесконечного цикла

