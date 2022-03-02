#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>


struct student
{
    std::string fullName = "test";
    bool sex = 0;
    int age = 0;
    int group = 1000;
    int id = 0;
    double GPA = 0.01;
    int sessionGrades[3] = {3, 3, 3};
    int commonGrades[4] = {3, 3, 3, 3};
};

void setColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void menu(int id)
{
    char str[][80] = {
        "               Exit               |",
        "Create a new student entry        |",
        "Edit an existing entry            |",
        "Displaying all student data       |",
        "Displaying information of group N |" };

    std::cout << "+----------------------------------+\n";

    for (int i = 0; i < 5; i++)
    {
        if (i == id) setColor(0, 7);
        std::cout << '|' << str[i] << '\n';
        if (i == id) setColor(15, 0);
    }

    std::cout << 
        "+----------------------------------+\n"
        "| Controls:                        |\n"
        "|                                  |\n"
        "| [w]     -> scroll up             |\n"
        "| [s]     -> scroll down           |\n"
        "| [Space] -> select                |\n"
        "+----------------------------------+\n";

}
void outputAllStudentsInfo(const std::vector<student> st)
{
    std::cout << 
        "+------------------------+-----+---------+--------+----------------+--------+-----+-------+-------------+-----------------------+-------------------------+---------+---------+\n"
        "|          Имя           | пол | возраст | группа | номер в группе | G.P.A. | АиГ | МатАн | Информатика | Программирование(пр.) | Программирование(лекц.) | История | Анг.яз. |\n"
        "+------------------------+-----+---------+--------+----------------+--------+-----+-------+-------------+-----------------------+-------------------------+---------+---------+\n";


    for (int i = 0; i < st.size(); i++)
        std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << ((st[i].sex) ? 'M' : 'F') << "  |    " << st[i].age << "   |  " << st[i].group << "  |\t" << st[i].id << "\t   |  " << st[i].GPA << "  |  "  << st[i].sessionGrades[0] << "  |   " << st[i].sessionGrades[1] << "   |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |            " << st[i].commonGrades[1] << "            |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout << 
        "+------------------------+-----+---------+--------+----------------+--------+-----+-------+-------------+-----------------------+-------------------------+---------+---------+\n";
}
void createNewEntry(std::vector<student> st)
{
    std::cout << 
        "+--------------------+\n"
        "| Creating new entry |\n"
        "+--------------------+\n";

    student temp;
    std::cout << "Last name first name: ";
    std::cin >> temp.fullName;

    std::cout << "\nSex (0/1): ";
    std::cin >> temp.sex;

    std::cout << "\nAge: ";
    std::cin >> temp.age;

    std::cout << "\nGroup: ";
    std::cin >> temp.group;

    std::cout << "\nId: ";
    std::cin >> temp.id;

    std::cout << "\nGPA: ";
    std::cin >> temp.GPA;

    std::cout << "\nAlgebra and geometry grade: ";
    std::cin >> temp.sessionGrades[0];

    std::cout << "\nMath analysis grade: ";
    std::cin >> temp.sessionGrades[1];

    std::cout << "\nInformation technologies grade: ";
    std::cin >> temp.sessionGrades[2];

    std::cout << "\nProgramming(lecture) grade: ";
    std::cin >> temp.commonGrades[0];

    std::cout << "\nProgramming(practice) grade: ";
    std::cin >> temp.commonGrades[1];

    std::cout << "\nHistory grade: ";
    std::cin >> temp.commonGrades[2];

    std::cout << "\nEnglish language grade: ";
    std::cin >> temp.commonGrades[3];

    st.push_back({ temp.fullName, temp.sex, temp.age, temp.group, temp.id, temp.GPA, temp.sessionGrades[0], temp.sessionGrades[1], temp.sessionGrades[2], temp.commonGrades[0], temp.commonGrades[1], temp.commonGrades[2], temp.commonGrades[3] });
}
void selectedField(int id, bool& status)
{
    std::vector<student> students;
    students.push_back({ "Бессмертных Артем", 1, 20, 1324, 1, 0.01, 0, 5, 0, 0, 0, 0, 0 });
    students.push_back({ "Мансуров Ярослав",  1, 20, 1324, 2, 0.01, 0, 0, 0, 4, 4, 0, 0 });
    students.push_back({ "Митин Илья",        1, 20, 1324, 3, 4.86, 5, 4, 5, 5, 5, 5, 5 });

    system("Cls");
    switch (id)
    {
    case 0:
        status = false;
        break;
    case 1:
        createNewEntry(students);
        system("pause");
        break;
    case 2:
        std::cout << "222222\n";
        system("pause");
        break;
    case 3:
        outputAllStudentsInfo(students);
        system("pause");
        break;
    }
}

int main()
{
    setlocale(0, "rus");
    ShowWindow(GetForegroundWindow(), SW_SHOWMAXIMIZED);

    int scroll = 0;
    bool isEnabled = true;
    while (isEnabled)
    {
        menu(scroll);
        switch (_getch())
        {
        case 'w':
            if (scroll != 0)
                scroll--;
            break;
        case 's':
            if (scroll != 4)
                scroll++;
            break;
        case ' ':
            selectedField(scroll, isEnabled);
            break;
        }
        system("Cls");
    }
    return 0;
}