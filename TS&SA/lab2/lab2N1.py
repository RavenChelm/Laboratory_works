import numpy

def LAB_2_VAR19(A, B):
    if numpy.linalg.det(A) == 0:
        return
    X = numpy.linalg.solve(A,B)
    return X


def Print(A, B):
    print("Коэффициенты СЛАУ:")
    for i in A:
        for j in i:
            print(j, end=' ')
        print()
    print("Свободные члены:")
    print(B)
    if numpy.linalg.det(A) == 0:
        print('Определитель матрицы равен 0.')
    else:
        print("Решение: ", LAB_2_VAR19(A, B))


if __name__ == "__main__":
    A = numpy.array([[2, 5, 0], [7, -3, 8], [3, -13, 8]])
    B = numpy.array([7, -20, -34])
    Print(A, B)