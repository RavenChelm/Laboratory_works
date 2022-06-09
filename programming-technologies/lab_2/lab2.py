import math
def LAB2_VAR_910(x):
    #Проверка, что введённые данные не являются логическим значением
    if type(x) == bool:    
        return TypeError
    #Попытка привестти введённые данные к типу float
    try:
        x = float(x)
    #Вывод ошибки TypeError в случае неудачи
    except:
        raise TypeError
    #При x меньше 1 вычислить
    if x < 1:
       x = 7*math.sin(2*math.pi*x)+7
    #Если x больше или равен 1, или меньше или равен 2, вычислить
    elif x >= 1 and x <= 2:
        x = -28*(x**2)+7
    #Иначе вычислить
    else:
        x = -21*math.sin(2*math.pi*x) -21
    #Вернуть x
    return x;
