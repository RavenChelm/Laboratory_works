import math

def check_inputx(x): # Проверка введённого значения x на ошибки

    try: # Проверка на флоатовское значение

        float(x)

    except ValueError:

        return ('Error')

    x = float(x)

    return x

def check_inpute(e): # Проверка введённого значения e на ошибки

    try:

        float(e)

    except ValueError:

        return ('Error')

    e = float(e)

    return e

def LAB3_VAR_33(x,e):

    x = check_inputx(x)

    if (x == 'Error'):

        print('Ошибка. Введено не числовое значение x.')

        return ('Error')

    e = check_inpute(e)

    if (e == 'Error'):

        print('Ошибка. Введено не числовое значение e.')

        return ('Error')

    if (x) > 1:

        print('Ошибка. Введено недопустимое значение x.')

        return ('Error')

    n = 1 # коэффициент определяющий знак слагаемого

    z = 1 # значение знаменателя и степени, изначально равно единице

    result = 0

    while 1:

        s = n * ((x ** z) / z)

        z = z + 1

        n = n * (-1)

        result = result + s

        if math.fabs(s) < e:

            break

    return result


TEST_LAB3_VAR_33()