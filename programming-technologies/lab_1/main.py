import lab1
#иницилизация переменных
a = 0
b = 0
c = 0
sumX = 0
multiply = 0
#начало бесконечного цикла
while True:
    #обработка исключения для корректного ввода
    try:
        a = input("Введите коофицент a: ")#Ввод коофицента a
        b = input("Введите коофицент b: ") #Ввод коофицента b
        c = input("Введите коофицент c: ") #Ввод коофицента c
        sumX, multiply = lab1.LAB1_VAR_19(a, b, c) #вызов функции
        print("Сумма корней: " + str(sumX) + "\nПроизведение корней: " + str(multiply)) #Вывод полученных значений
    except TypeError:
            print("Некорректный тип")
    #Если полученные коректные значения - прервать цикл
    if isinstance(sumX, float) and isinstance(multiply, float):
        break
#Конец цикла
    