import lab3
#Иницилизация переменных
x = 0
e = 0
sumx = 0
#Начало бесконечного цикла
while True:
    #Начало блока обработки исключений
    try:
        x = input("Введите x: ")#Ввод х
        e = input("Введите точность: ")#Ввод точности
        sumx = lab3.LAB3_VAR_32(x, e)#Вызов функции и запись результата её работы в переменную
        print("Значение функции: " + str(sumx))#Вывод в консоль результата
    #При вызове исключения
    except TypeError: 
        print("Некорректный тип")#Вывод в консоль сообщния об ошибке
    #Выход в случае успешного выполнения
    if isinstance(sumx, float):
        break
#Конец бесконечного цикла