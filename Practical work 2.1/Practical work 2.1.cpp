#include <iostream>
#include <vector>
#include <conio.h>
#include "Functions.h"

int main()
{
    setlocale(0, "rus");
    fullscreen();

    std::vector<student> students;
    students.push_back({ "Бессмертных Артем", 'M', 20, 1324, 1, 3, 5, 4, 3, 3, 4, 5});
    students.push_back({ "Мансуров Ярослав",  'M', 20, 1324, 2, 3, 5, 3, 3, 4, 4, 5});
    students.push_back({ "Митин Илья",        'M', 20, 1324, 3, 5, 4, 5, 5, 5, 5, 5});
    students.push_back({ "Лбова Анна",        'F', 18, 1323, 1, 5, 5, 5, 5, 5, 5, 5});

    int scroll = 0;
    bool isEnabled = true;
    while (isEnabled)
    {
        mainMenu(scroll);
        switch (_getch())
        {
        case 'w':
            if (scroll != 0) scroll--;
            else scroll = 8;
            break;
        case 's':
            if (scroll != 8)scroll++;
            else scroll = 0;
            break;
        case ' ':
            if (scroll == 0) isEnabled = false;
            selectedField(scroll, students);
            break;
        }
        system("Cls");
    }
    return 0;
}