//Создать структуру ВИДЕОМАГАЗИН со следующими полями :
// Название фильма;
// Режиссер;
// Жанр;
// Рейтинг популярности;
// Цена диска.

//Реализовать следующие возможности :
// Поиск по названию;
// Поиск по жанру;
// Поиск по режиссеру;
// Самый популярный фильм в жанре;
// Показ всех записей и добавление.

//Для реализации задачи используйте функции.Объекты
//структуры можно передавать в функцию целиком или
//отдельными полями.Выберите верный механизм пере -
//дачи в каждом конкретном случае.

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MaxVideoDisk = 100;
struct Disk
{
    char Film[15];
    char director[15];
    char genre[15];
    double rating;
    double price;
};
struct ListDisk
{
    Disk Disks[MaxVideoDisk];
    int count = 0;
};
void fillDisk(Disk& emp, const char* Film, const char* director, const char* genre, double rating, double price)
{
    strncpy_s(emp.director, director, sizeof(emp.director) - 1);
    emp.director[sizeof(emp.director) - 1] = '\0';
    strncpy_s(emp.Film, Film, sizeof(emp.Film) - 1);
    emp.Film[sizeof(emp.Film) - 1] = '\0';
    strncpy_s(emp.genre, genre, sizeof(emp.genre) - 1);
    emp.genre[sizeof(emp.genre) - 1] = '\0';
    emp.rating = rating;
    emp.price = price;
}
void addDisk(Disk emp, ListDisk& list)
{
    if (list.count < MaxVideoDisk)
    {
        list.Disks[list.count++] = emp;
    }
}
void printDisk(Disk& emp)
{
    cout << emp.director << " " << emp.Film << " " << emp.genre << " " << emp.rating << emp.price << endl;
}
void findEDirector(ListDisk& list, const char* director)
{
    for (int i = 0; i < list.count; i++)
    {
        if (strcmp(list.Disks[i].director, director) == 0)
        {
            printDisk(list.Disks[i]);
        }
    }
}
void findEFilm(ListDisk& list, const char* Film)
{
    for (int i = 0; i < list.count; i++)
    {
        if (strcmp(list.Disks[i].Film, Film) == 0)
        {
            printDisk(list.Disks[i]);
        }
    }
}
void findEGenre(ListDisk& list, char* genre)
{
    for (int i = 0; i < list.count; i++)
    {
        if (strcmp(list.Disks[i].genre, genre) == 0)
        {
            printDisk(list.Disks[i]);
        }
    }
}
bool compareDisk(Disk empa, Disk empb)
{
    return empa.rating > empb.rating;
}
void sortDiskByRating(ListDisk& list)
{
    sort(list.Disks, list.Disks + list.count, compareDisk);
}
void printHighRating(ListDisk& list, double rating)	
{
    for (int i = 0; i < list.count; i++)
    {
        if (list.Disks[i].rating > rating)
        {
            printDisk(list.Disks[i]);
        }
    }
}
void printDisks(ListDisk& list)
{
    for (int i = 0; i < list.count; i++)

    {
        printDisk(list.Disks[i]);
    }
}













int main()
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    ListDisk List;
    Disk disk1, disk2, disk3, disk4, disk5, disk6, disk7, disk8;
    fillDisk(disk1, "Балабанов", "Брат2", "боевик", 8.2, 5000);
    addDisk(disk1, List);
    fillDisk(disk2, "Братья Люмьер", "Прибытие поезда", "документальный", 7.5, 4800);
    addDisk(disk2, List);
    fillDisk(disk3, "Эйзенштейн", "Иван Грозный", "исторический", 9.2, 7800);
    addDisk(disk3, List);
    fillDisk(disk4, "Чаплин", "Бенни и Джун", "комедия", 6.8, 3200);
    addDisk(disk4, List);
    fillDisk(disk5, "Хичкок", "Птицы", "ужасы", 7.9, 6950);
    addDisk(disk5, List);
    fillDisk(disk6, "Феллини", "Дорога", "мелодрамма", 7.2, 4900);
    addDisk(disk6, List);
    fillDisk(disk7, "Годар", "Безумный Пьеро", "мелодрамма", 6.9, 3950);
    addDisk(disk7, List);
    fillDisk(disk8, "Тарковский", "Сталкер", "боевик", 8.2, 8650);
    addDisk(disk8, List);
    int menu;
    int rat;
    char str[20];
    do
    {
        cout << "!!! МЕНЮ ПОИСКА !!!" << "\n\n";
        cout << "1. Поиск по фамилии режиссера." << endl;
        cout << "2. Поиск по названию фильма." << endl;
        cout << "3. Поиск по жанру." << endl;
        cout << "4. Поиск по рейтингу." << endl;
        cout << "5. Показать весь список фильмов." << endl;
        cout << "6. ВЫХОД" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            cout << "Введите фамилию режиссера: ";
            cin.ignore();
            cin.getline(str, 20);
            findEDirector(List, str);
            break;
        }
        case 2:
        {
            cout << "Введите название фильма: ";
            cin.ignore();
            cin.getline(str, 20);
            findEFilm(List, str);
            break;
        }
        case 3:
        {
            cout << "Введите жанр фильма: ";
            cin.ignore();
            cin.getline(str, 20);
            findEGenre(List, str);
            break;
        }
        case 4:
        {
            cout << "Введите минимальный рейтинг: ";
            cin >> rat;
            printHighRating(List, rat);
            break;
        }
        case 5:
        {
            cout << "Весь список фильмов: " << endl;;
            printDisks(List);
            break;
        }
        default:
            cout << "Не корректный выбор" << endl;
        }
    } while (menu < 6);
}
