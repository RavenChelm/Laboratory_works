import lab2
#Иницилизация переменной
x=0
#Начало бесконечного цикла
while True:
    #Начало блока обработки исключений 
    try:
        x = input("Введите x: ") #Ввод х
        x = lab2.LAB2_VAR_910(x)#Вызов функции и запись результата её работы в переменную
        print("Значение функции: " + str(x))#Вывод в консоль результата
     #При вызове исключения
    except TypeError: 
        print("Некорректный тип")#Вывод в консоль сообщния об ошибке
    #Выход в случае успешного выполнения
    if isinstance(x, float):
        break