import numpy

def LAB_2_VAR19(A, B):
    if numpy.linalg.det(A) == 0:
        return
    obrA = numpy.linalg.inv(A)
    x = numpy.dot(obrA, B)
    return x

def Print(A, B):
    print("Решение СЛАУ методом обратной матрицы")
    print("Коэффициенты при x:")
    for i in A:
        for j in i:
            print(j, end=' ')
        print()
    print("Свободные члены:")
    print(B)
    if numpy.linalg.det(A) == 0:
        print('Определитель матрицы равен 0! Нет решения')
    else:
        print("Решение: ", LAB_2_VAR19(A, B))

if __name__ == "__main__":
    A = numpy.array([[1, -5, 1], [2, 4, 1], [7, 4, 0]])
    B = numpy.array([-14, 16, 13])
    Print(A, B)