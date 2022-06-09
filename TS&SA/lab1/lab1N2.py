from random import randint
def MaxMeeting(list):
    return (max(list, key=list.count))

def randomlist(size):
    list=[]
    for i in range(size):
        list.append(randint(0,9))
    return(list)

def Print(list, result):
    print("Это исходные данные: ", list)
    print("Это самое частое число: ", result)

if __name__ == "__main__":
    key="Y"
    while key=="Y":
        list = randomlist(int(input("Введите размер массива:")))
        result = MaxMeeting(list)
        Print(list, result)
        key=input("Введите 'Y' для продолжения:")
