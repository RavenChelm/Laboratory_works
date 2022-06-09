#U(t)=U*cos(ωt-φ). - формула амплитуды 
from sqlite3 import Time
import numpy as np
import matplotlib.pyplot as plt
def LAB7_VAR_3(Amp, phase, time, freq1, freq2):
    #Блок обработки ошибок
    TestArr = [Amp, phase, time, freq1, freq2] #Список для проверки соответствия типам
    if (all(isinstance(x, (int, float)) for x in TestArr)) != True: #Проверка соответсвия типам
        return ValueError
    elif time <= 0: #Проверка условия времени для построения графика
        return ValueError
    elif freq1 <= 0.3 or freq2 > 3000000000000: #Проверка условия диапазона частот
        return ValueError
    elif freq2 <= freq1: #Проверка логичности диапазона частот
        return ValueError

    fig, ax = plt.subplots(nrows = 2, ncols = 1) #Создание figure и axes для постронния графиков
    freq = np.random.randint(freq1, freq2, time)  #  Частота
    Uarr = np.zeros(time)   #Создание массива для записи значений амплитуды
    TimeArr = np.zeros(time)    #Создание массива для отсчёта времени
    for i in range(time):   #цикл по заполнению вышесозданных массивов
        Uarr[i] = (Amp*np.cos(freq[i]*i - phase))   #Заполнение массива с амплитудой
        TimeArr[i] = i  #Заполнение массива со временем

    ax[0].plot(TimeArr, Uarr)  #Отображение данных на графике
    ax[0].set(title='График изменения ампилтуды радисигнала')    #Размещение заголовока над "Axes"
    ax[0].set_xlabel('время (с)')   #подпись оси x
    ax[0].set_ylabel('Амплитуда (В)')   #подпись оси y
    ax[1].plot(TimeArr, freq)   #Отображение данных на графике
    ax[1].set(title='График изменения частоты сигнала')     #Размещение заголовока над "Axes"
    ax[1].set_xlabel('время (с)')   #подпись оси x
    ax[1].set_ylabel('Циклическая частота (Рад/с)')    #подпись оси y
    plt.show()  #Отрисовка окна
    return "Успешное построение графика"