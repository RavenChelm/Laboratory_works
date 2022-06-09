import csv
import matplotlib.pyplot as plt
import numpy as np
import random

def LAB8_VAR_1(n):
    #иницилизация списков
    LOCATION = []
    TIME = []
    VALUE = []
    Uniq_LOCATION = [] 
    
    if (isinstance(n, (int))) != True: return ValueError #Проверка соответсвия типам
    elif n <= 0: return ValueError                       #Проверка для соответсвия условиям

    #Получение заголовков из файла
    with open('AccessToComputersFromHome.csv') as file: #Открытие файла
        reader = csv.reader(file) #Создания объекта reader для чтения файла
        next(reader)              #Прохождение строки с коментарием
        next(reader)              #Прохождение пустой строки 
        headers = next(reader)    #Получение заголовка

    #Чтение файла и сохранение данных в файл
    with open('AccessToComputersFromHome.csv') as file: #Открытие файла
        reader = csv.reader(file)    #Создания объекта reader для чтения файла
        next(reader)                 #Прохождение строки с коментарием
        next(reader)                 #Прохождение пустой строки 
        reader = csv.DictReader(file)#Создание объекта DictReader для чтения по определёным позициям
        for row in reader:           #Запись данных в списки по определённым заголовкам
            LOCATION += [row[headers[0]]]
            TIME += [row[headers[5]]]
            VALUE += [row[headers[6]]]
    
    #Выбор случайных стран
    Uniq_LOCATION = list(set(LOCATION)) #Создание списка для хранения стран в единственном экземпляре
    if len(Uniq_LOCATION) < n: return ValueError #Провека для соответвия условиям
    loc_help = [] #Вспомогательный список для нумерации стран
    for i in range(len(Uniq_LOCATION)): loc_help += [i]
    Num_LOCATION = random.sample(loc_help, n) #выбор случайных стран в количестве введёнх пользователем

    #Создание графиков
    fig, ax = plt.subplots(n, squeeze=False)
    #Цикл по выбранным странам
    for i in range(n):
        first = LOCATION.index(Uniq_LOCATION[Num_LOCATION[i]])                          #Получение первого вхождение страны
        last =  len(LOCATION) - 1 -LOCATION[::-1].index(Uniq_LOCATION[Num_LOCATION[i]]) #Получение последнего вхождения страны
        this_time = []  #список значений времени для конкретной страны
        this_value =[]  #список значений для конкретной страны
        while first != (last):  #цикл для записи конкретных значений
                this_time += [TIME[first]]
                this_value += [VALUE[first]]
                first +=1
        arr1 = np.array(this_time)  #Создания массивов для создания графика
        arr2 = np.array(this_value)
        ax[i, 0].plot(arr1, arr2)  #Отображение данных на графике
        ax[i, 0].set(title=Uniq_LOCATION[Num_LOCATION[i]])    #Размещение заголовока над "Axes"
        ax[i, 0].set_xlabel('Год')   #подпись оси x
        ax[i, 0].set_ylabel('Значение') #подпись оси y

    #Дополнительное задание
    average = [0]*len(Uniq_LOCATION) #Список со средними значениями
    cwadro = [0]*len(Uniq_LOCATION)  #Список со среднекваратичными отклонениями
    colva = 0                       #Переменная для хранения количества упоминаний конкретной странн
    for i in range(len(Uniq_LOCATION)):
        first = LOCATION.index(Uniq_LOCATION[loc_help[i]])  #Получение первого вхождение страны
        last =  len(LOCATION) - 1 -LOCATION[::-1].index(Uniq_LOCATION[loc_help[i]]) #Получение последнего вхождения страны
        first1 = first  #Копия первого вхождения страны
        colva = last - first +1 #Вычисление количества стран
        while first != (last):  #цикл для вычисления суммы значений
            average[i] = float(average[i]) + float(VALUE[first])
            first +=1
        average[i] /= colva #Вычисление среднего значения
        while first1 != (last): #цикл для вычисления квадрата среднеквадратичного отклонения значеня
            cwadro[i] = float(cwadro[i]) + pow((float(VALUE[first]) - average[i]), 2)
            first1 +=1
        cwadro[i] = pow((cwadro[i]/colva), 0.5) #среднеквадратичное отлонение

    #Вывод в файл
    data_help = [['LOCATION', 'average', 'cwadro']] #Создание списка для записи в файл
    for i in range(len(Uniq_LOCATION)): data_help += [ [Uniq_LOCATION[i], average[i], cwadro[i]]]
    with open('DataOut.csv', 'w', newline="") as fileOut: #Открытие файла для записи
        writer = csv.writer(fileOut)    #Создание объекта writer
        writer.writerows(data_help)     #Запись по строкам в файл
    plt.show() #Отрисовка графика
    return "successful" #Возвращение сообщения о завершение функции
