from random import randint
def MaxMinus(list):
    i = 0
    index = list.index(min(list))
    while i < len(list):
        if list[i] < 0 and list[i] > list[index]:
            index = i
        i += 1
    return list[index]

def randomlist(size):
    list=[]
    for i in range(size):
        list.append(randint(-100,100))
    return(list)

def Print(list, result):
    print("Это исходные данные: ", list)
    print("Это максимальное отрицательное число: ", result)

if __name__ == "__main__":
    key="Y"
    while key=="Y":
        list = randomlist(int(input("Введите размер массива:")))
        result = MaxMinus(list)
        Print(list, result)
        key=input("Введите 'Y' для продолжения:")
