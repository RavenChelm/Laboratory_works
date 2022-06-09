def LAB5_VAR_1(list):
    if (all(isinstance(x, (int, float)) for x in list)) != True: #Проверка, что введенны значения правильных типов
        return ValueError
    if(list.index(min(list)) > list.index(max(list))): #Если индекс масксимального элемента больше индекса минимального, 
        list[list.index(min(list))], list[list.index(max(list))] = list[list.index(max(list))], list[list.index(min(list))] #Поменять их местами
    sumX = sum(list[list.index(min(list)):list.index(max(list))+1]) #Проссумировать все элементы от индекса минимального до индекса максимального
    return sumX