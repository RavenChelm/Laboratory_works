def LAB1_VAR_19(a, b, c):
    sumX = 0
    multiply = 0
    # Проверка на возможность обработать данные как числа:
    # Проверка, что тип переменных не логический
    if type(a) == bool or type(b) == bool or type(c) == bool:
        return TypeError
    # Преведение введеных значений к типу float
    try:
        a = float(a)
        b = float(b)
        c = float(c)
    except:
        return TypeError
    #Проверка на неравенства коэффициента "a" нулю
    if (a == 0):
        return "Ошибка.", "Уравнение не является квадратным."
    #Проверка на существование корней
    if (b**2 - 4*a*c) <= 0:
        return "Ошибка.", "Корней не существует."
    #Вычисление суммы и произведения корней
    sumX = -b/a
    multiply = c/a
    return sumX, multiply