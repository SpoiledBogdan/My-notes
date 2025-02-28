#include <stdio.h>

/*
Создаем тип для указателей на функции:

- typedef: Это ключевое слово используется для создания псевдонимов (новых имен) для существующих типов.
- void: Это тип возвращаемого значения функции.
- (*stepTask): Это имя нового типа, который является указателем на функцию.
- (void): Это список параметров функции. В данном случае функция не принимает никаких параметров.
*/
typedef void (*stepTask)(void);

/*Создаем переменную (function cycler), которая будет меняться в ходе выполнения программы и будет выполнять функции*/
stepTask Task;

/*Пример функций, которые будут последовательно выполняться. Их реализация должна быть снизу программы, иначе будут ошибки*/
void FirstFunc (void);
void SecondFunc(void);
void ThirdFunc(void);
void FourthFunc(void);

int main(void)
{
    /*В нашу переменную (function cycler) кладем указатель на первую функцию*/
    Task = FirstFunc;


    /*Просто цикл, в котором и будет меняться основная переменная (function cycler)*/
    while (Task != FourthFunc) 
    {
        /*Таким образом идет вызов переменной, которая находится внутри function cycler'а*/
        Task();
    }

    return 0;
}


/*В каждой функции идет присваивание указателя function cycler'у на следующую функцию*/
void FirstFunc (void)
{
    printf("FirstFunc\n");
    Task = SecondFunc;
}

void SecondFunc(void)
{
    printf("SecondFunc\n");
    Task = ThirdFunc;
}

void ThirdFunc(void)
{
    printf("ThirdFunc\n");
    Task = FourthFunc;
}

void FourthFunc(void)
{
    printf("FourthFunc\n");
}