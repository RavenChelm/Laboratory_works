import lab7
#Иницилизация переменных
Amp = 0.0
phase = 0.0
time = 0
freq1 = 0 
freq2 = 0
key = ""
result = ""
#Начало бесконечного цикла
while True:
    try:
        Amp = float(input("Введите значение амплитуды: "))    #Ввод амплитуды
        phase = float(input("Введите начальную фазу: "))      #Ввод фазы
        time = int(input("Введите длительность сигнала: "))   #Ввод длитльности
        freq1 = int(input("Введите нижнюю границу частот: ")) #ВВод нижней границы
        freq2 = int(input("Введите верхнюю границу частот: "))#Ввод верхней границы
        result = lab7.LAB7_VAR_3(Amp, phase, time, freq1, freq2)       #Вызов функции
    except ValueError: 
        print("Ошибка, попробуйте ещё раз.")
    key = str(input("Введите Y, если хотите продолжить. Любую другую комбинацию, чтобы выйти.\n "))#Ввод комбинации для продолжения или завершения программы
    if(key == "Y"):
        continue #Продолжение программы
    else: 
            break #Завершение программы
#Конец бесконечного цикла