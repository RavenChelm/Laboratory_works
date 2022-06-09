def LAB4_VAR_8(stroka):
    stroka = str(stroka)
    stroka = stroka.replace(" ", "").lower() #Убрать из строки пробелы, преобразовать все символы в нижний регистр
    res = stroka[::-1] #Скопировать строку с конца
    if stroka == res: #Если строки равны
        return "Да"
    return "Нет"