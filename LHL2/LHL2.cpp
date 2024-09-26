/*Вагоны поезда.

Варианты полей: количество мест, цена места, количество свободных
мест, номер вагона
Варианты методов: продать билеты, разнести чай, дать объявление о
маршруте следования поезда
Возможные классы иерархии: вагоны (базовый), СВ, вагон-ресторан, купе, товарный.

        */

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

class ALL
{
    int counter;
    int price;
    int free;
    int number;

public:
    virtual ~ALL() {};
    virtual void name() = 0;
    virtual void unique() = 0;

    void sale()//продать билеты
    {
        
        int a = 0;
        cout << "сколько билетов нужно продать?" << endl;
        cout << "A = "; while (!(cin >> a)) {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Не int,введите int: ";
        }

        if (a <= free) {
            free -= a;
            cout << "Вы заработали: " << a * price << " денег" << endl;
        }
        else {
            cout <<"Вам не хватило: "<<a-free<<endl<< "Вы заработали: " << free * price << " денег" << endl;
            free = 0;
        }
    }
    void tea()//разнести чай
    {
        cout << "Вы разнесли " << counter - free << " кружек чая" << endl;
    }

    void scream()//дать объявление о маршруте поезда
    {
        cout << "Вы дали объявление о маршруте следования поезда в вагоне номер " << number << endl;
    }

    void info()
    {
        cout << "Количество мест(int): " << counter << endl;
        cout << "Цена места(int): " << price << endl;
        cout << "свободных мест(int): " << free << endl;
        cout << "Номер вагона (int): " << number << endl;
    }

    void Set(int a, int b, int c, int d)
    {
        counter = a;
        price = b;
        free = c;
        number = d;

    }
    int Get_free()
    {
        return free;
    }


};

class SW : public ALL
{
public:
    SW() {}
    SW(int a, int b, int c, int d)
    {
        Set(a, b, c, d);
    }
    ~SW() {}
    void name()
    {
        cout << "СВ\n";
    }
    void unique()
    {
        cout << "Вы спите Zzz..\n";
    }
};

class VAGONR : public ALL
{
public:
    VAGONR() {}
    VAGONR(int a, int b, int c, int d)
    {
        Set(a, b, c, d);
    }
    ~VAGONR() {}
    void name()
    {
        cout << "Вагон ресторан\n";
    }
    void unique()
    {
        cout << "Вы поели\n";
    }
};

class cupe : public ALL
{
public:
    cupe() {}
    cupe(int a, int b, int c, int d)
    {
        Set(a, b, c, d);
    }
    ~cupe() {}
    void name()
    {
        cout << "Купе\n";
    }
    void unique()
    {
        cout << "Вы отдыхаете\n";
    }
};

class tovar : public ALL
{
public:
    tovar() {}
    tovar(int a, int b, int c, int d)
    {
        Set(a, b, c, d);
    }
    ~tovar() {}
    void name()
    {
        cout << "Товарный вагон\n";
    }
    void unique()
    {
        if (Get_free() > 0)
            cout << "место для товара есть\n";
        else cout << "мест для товара нет\n";
    }
};

class vector
{
    ALL** data;
    int maxlength = 100;
    int count = -1;
public:
    vector()
    {
        data = new ALL * [maxlength];
        count = -1;
    }
    int add(ALL* x)
    {
        if (count == maxlength - 1) return 0;
        data[++count] = x;
        return 1;
    }
    ALL* get(int cur)
    {
        return(data[cur]);
    }
    int Get_count()
    {
        return (count);
    }
};

void input(vector* mas, ALL* item);
void print(vector* mas);
void sale_ALL(vector* mas);
void tea_ALL(vector* mas);
void scream_ALL(vector* mas);
int Unique(vector* mas);

int main()
{
    setlocale(LC_ALL, "rus");
    int menu, menu2, a = 0;
    vector mas;

    do
    {
        system("cls");
        cout << "1.Добавить новый объект\n2.Выполнить метод для всех объектов\n3.Вывод всех объектов в массиве\n4.Выполнить уникальный метод\n5.Выход\n";
        do
        {
            if (a)
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
            cin >> menu;
            a++;
        } while (cin.fail()); a = 0;
        switch (menu)
        {
        case 1: do
        {
            system("cls");
            cout << "Объект какого класса добавить?\n1.СВ\n2.Вагон ресторан\n3.Купе\n4.Товарный\n5.Отмена\n";
            do
            {
                if (a)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cin >> menu2;
                a++;
            } while (cin.fail()); a = 0;
            switch (menu2)
            {
            case 1: input(&mas, new SW); break;
            case 2: input(&mas, new VAGONR); break;
            case 3: input(&mas, new cupe); break;
            case 4: input(&mas, new tovar); break;
            }
        } while (!(menu2 <= 5 && menu2 >= 1));
        system("pause"); break;
        case 2: do
        {
            system("cls");
            cout << "1.Продать билеты\n2.Разнести чай\n3.Подать объявление\n4.Отмена\n";
            do
            {
                if (a)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cin >> menu2;
                a++;
            } while (cin.fail()); a = 0;
            switch (menu2)
            {
            case 1: sale_ALL(&mas); break;
            case 2: tea_ALL(&mas); break;
            case 3: scream_ALL(&mas); break;
            }
        } while (!(menu2 <= 4 && menu2 >= 1));
        system("pause"); break;
        case 3: print(&mas); system("pause"); break;
        case 4: Unique(&mas);
            system("pause"); break;
        }
    } while (menu != 5);
}

int Unique(vector* mas)
{
    int i, a = mas->Get_count() + 1, a1 = 0;
    system("cls");
    cout << "Впишите номер объекта для выполнения уникального метода (Всего объектов: " << a << ")\nДля возврата введите 0\n";
    print(mas);
    do
    {
        do
        {
            if (a1)
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
            cin >> i;
            a1++;
        } while (cin.fail()); a1 = 0;
    } while (i > a || i < 0);
    if (!i) return 0;
    mas->get(i - 1)->unique();
}

void sale_ALL(vector* mas)
{
    int i;
    for (i = 0; i <= mas->Get_count(); i++)
    {
        mas->get(i)->sale();
    }
}

void tea_ALL(vector* mas)
{
    int i;
    for (i = 0; i <= mas->Get_count(); i++)
    {
        mas->get(i)->tea();
    }
}

void scream_ALL(vector* mas)
{
    int i;
    for (i = 0; i <= mas->Get_count(); i++)
    {
        mas->get(i)->scream();
    }
}

void input(vector* mas, ALL* item)
{
    
    int a; int b; int c; int d;


    cout << "Введите количество мест\n";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
         cout << "Не int,введите int: ";
    }

    cout << "Введите цену места\n";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Не int,введите int: ";
    }

    cout << "Введите количество свободных мест\n";
   while (!(cin >> c)) {  
       
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Не int,введите int: ";
   } if (c > a) { cout << "Все места свободны \n"; c = a; }
  
    cout << "Введите номер вагона\n";
    while (!(cin >> d)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Не int,введите int: ";
    }
    item->Set(a, b, c, d);
    mas->add(item);
}

void print(vector* mas)
{
    int count_item = 0, count = mas->Get_count();
    while (count_item != count + 1)
    {
        cout << count_item + 1<<". ";
        mas->get(count_item)->name();
        mas->get(count_item)->info();
        cout << endl;
        count_item++;
    }
}

