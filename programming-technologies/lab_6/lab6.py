def LAB6_VAR_1(first_matrix, second_matrix):
#Проверка на соответствие элементов массива разрешённым типам 
    for i in range(len(first_matrix)):
        for j in range(len(first_matrix[0])):
            if not (type(first_matrix[i][j]) == int or type(first_matrix[i][j]) == float):
                return ValueError
    for i in range(len(second_matrix)):
        for j in range(len(second_matrix[0])):
            if not (type(second_matrix[i][j]) == int or type(second_matrix[i][j]) == float):
                return ValueError
#Конец проверки на соответствие типам
    if len(first_matrix[0]) != len(second_matrix): #если число столбцов не равно числу строк во второй, 
        return "Число столбцов в первой матрице не равно числу строк во второй" #Вернуть соответсвующее сообщение
    length = len(first_matrix) #запись длины первой матрицы
    result_matrix = [[0 for i in range(length)] for i in range(length)] #Создание результирующей матрицы, определяемую длиной первой матрицы
#Процесс вычисления матрицы
    for i in range(length): 
        for j in range(length):
            for k in range(length):
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j]
#Конец вычисления
    return result_matrix