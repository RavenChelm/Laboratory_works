n = int(input("Ввод количества строк:")) 
a = []
print("Колличество введёных чисел в первой строке определяет количество столбцов. ")
for i in range(n):
    row = input("Введите строку: ").split()
    for i in range(len(row)):
        row[i] = int(row[i])
    a.append(row)

for i in range(len(a)):
    for j in range(len(a[i])):
        print(a[i][j], end=' ')
    print()

