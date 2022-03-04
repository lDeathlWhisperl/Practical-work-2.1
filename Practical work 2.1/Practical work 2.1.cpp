#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>

struct student
{
    char fullName[23] = "test";
    char sex = 'F';
    int age = 10;
    int group = 1000;
    int id = 0;
    int sessionGrades[3] = { 3, 3, 3 };
    int commonGrades[4] = { 3, 3, 3, 3 };
    double GPA = floor((sessionGrades[0] + sessionGrades[1] + sessionGrades[2] + commonGrades[0] + commonGrades[1] + commonGrades[2] + commonGrades[3]) / 7.0 * 100) / 100 ;
};

void fullscreen()
{
    ShowWindow(GetForegroundWindow(), SW_SHOWMAXIMIZED);
}
void setColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void mainMenu(int id)
{
    char str[][80] = {
        "|               Exit               |",   /*0*/
        "|Create a new student entry        |",   /*1*/
        "|Edit an existing entry            |",   /*2*/
        "|Display all student data          |",   /*3*/
        "|Display information of group \"N\"  |", /*4*/
        "|Top DPA students                  |",   
        "|Display male or female students   |",   /*6*/
        "|Display students who...           |",   /*7*/
        "|Display students with \"K\" id      |"};/*8*/

    std::cout <<
        "+==================================+\n";

    for (int i = 0; i < 9; i++)
    {
        if (i == id && i != 0) setColor(0, 15);
        else if (i == id && i == 0) setColor(0, 4);
        std::cout << str[i] << '\n';
        setColor(15, 0);
    }

    std::cout <<
        "+==================================+\n"
        "| Controls:                        |\n"
        "|                                  |\n"
        "| [w]     -> scroll up             |\n"
        "| [s]     -> scroll down           |\n"
        "| [Space] -> select                |\n"
        "+==================================+\n";

}
void editingMenu(std::vector<student>& st, int id)
{
    std::cout <<
        "+==============================+==================================+\n|";

    if (id == -1) setColor(0, 4);
    std::cout <<
        "         Back to menu         ";
    setColor(15, 0);

    std::cout <<
        "|     Select entry for editing     |\n";
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
    {
        if (i == id) setColor(0, 15);
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";
        setColor(15, 0);
    }

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "| Controls:                                                       |\n"
        "|                                                                 |\n"
        "| [w]     -> scroll up                                            |\n"
        "| [s]     -> scroll down                                          |\n"
        "| [Space] -> select                                               |\n"
        "+=================================================================+\n";
}
void grantMenu(int id)
{
    std::cout <<
        "+==============================================+\n";

    char menu[][80] = {
        "|                 Back to menu                 |",
        "| ...not receive a scholarship                 |",
        "| ...study only for \"good\" and \"excellent\"     |",
        "| ...study only with \"excellent\"               |" };

    for (int i = 0; i < 4; i++)
    {
        if (i == id && i != 0) setColor(0, 15);
        else if (i == id && i == 0) setColor(0, 4);
        std::cout << menu[i] << '\n';
        setColor(15, 0);
    }

    std::cout <<
        "+==============================================+\n"
        "| Controls:                                    |\n"
        "|                                              |\n"
        "| [w]     -> scroll up                         |\n"
        "| [s]     -> scroll down                       |\n"
        "| [Space] -> select                            |\n"
        "+==============================================+\n";;
}
void outputAllStudentsInfo(const std::vector<student> st)
{
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";


    for (int i = 0; i < st.size(); i++)
        std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";
    
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void errormessage(int &value, int rangeFrom, int rangeTo)
{
    while (value < rangeFrom || value > rangeTo)
    {
        std::cout << "you entered unacceptable value, try again: ";
        std::cin >> value;
    }
}
void createNewEntry(std::vector<student>& st)
{
    std::cout <<
        "+====================+\n"
        "| Creating new entry |\n"
        "+====================+\n";

    student temp;
    std::cout << "Last name first name: ";
    std::cin.getline(temp.fullName, 23);// >> temp.fullName;
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nSex (F/M): ";
    std::cin >> temp.sex;
    while ((temp.sex != 'F' && temp.sex != 'M') && (temp.sex != 'f' && temp.sex != 'm'))
    {
        std::cout << "you entered unacceptable value, try again: ";
        std::cin >> temp.sex;
    }
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nAge: ";
    std::cin >> temp.age;
    errormessage(temp.age, 18, 99);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nGroup: ";
    std::cin >> temp.group;
    errormessage(temp.group, 1000, 9999);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nId: ";
    std::cin >> temp.id;
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nAlgebra and geometry grade: ";
    std::cin >> temp.sessionGrades[0];
    errormessage(temp.sessionGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nMath analysis grade: ";
    std::cin >> temp.sessionGrades[1];
    errormessage(temp.sessionGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nInformatics grade: ";
    std::cin >> temp.sessionGrades[2];
    errormessage(temp.sessionGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nProgramming(lecture) grade: ";
    std::cin >> temp.commonGrades[0];
    errormessage(temp.commonGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nProgramming(practice) grade: ";
    std::cin >> temp.commonGrades[1];
    errormessage(temp.commonGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nHistory grade: ";
    std::cin >> temp.commonGrades[2];
    errormessage(temp.commonGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\nEnglish grade: ";
    std::cin >> temp.commonGrades[3];
    errormessage(temp.commonGrades[3], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    st.push_back(temp);
}
void editingEntry(int id, std::vector<student>& st)
{
    system("cls");

    char escape = '+';

    std::cout <<
        "+===============+\n"
        "| Entry editing |\n"
        "+===============+\n";

    std::cout << "Name: " << st[id].fullName << " -> ";
    std::cin.getline(st[id].fullName, 80);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Sex: " << st[id].sex << " -> ";
    std::cin >> st[id].sex;
    while ((st[id].sex != 'F' && st[id].sex != 'M') && (st[id].sex != 'f' && st[id].sex != 'm'))
    {
        std::cout << "you entered unacceptable value, try again: ";
        std::cin >> st[id].sex;
    }
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Age: " << st[id].age << " -> ";
    std::cin >> st[id].age;
    errormessage(st[id].age, 18, 99);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Group: " << st[id].group << " -> ";
    std::cin >> st[id].group;
    errormessage(st[id].group, 1000, 9999);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Id: " << st[id].id << " -> ";
    std::cin >> st[id].id;
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Algebra and geometry grade : " << st[id].sessionGrades[0] << " -> ";
    std::cin >> st[id].sessionGrades[0];
    errormessage(st[id].sessionGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Math analysis: " << st[id].sessionGrades[1] << " -> ";
    std::cin >> st[id].sessionGrades[1];
    errormessage(st[id].sessionGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "informatics grade: " << st[id].sessionGrades[2] << " -> ";
    std::cin >> st[id].sessionGrades[2];
    errormessage(st[id].sessionGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Programming(lecture) grade: " << st[id].commonGrades[0] << " -> ";
    std::cin >> st[id].commonGrades[0];
    errormessage(st[id].commonGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Programming(practice) grade: " << st[id].commonGrades[1] << " -> ";
    std::cin >> st[id].commonGrades[1];
    errormessage(st[id].commonGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "History grade: " << st[id].commonGrades[2] << " -> ";
    std::cin >> st[id].commonGrades[2];
    errormessage(st[id].commonGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << "English grade: " << st[id].commonGrades[3] << " -> ";
    std::cin >> st[id].commonGrades[3];
    errormessage(st[id].commonGrades[3], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    st[id].GPA = floor((st[id].sessionGrades[0] + st[id].sessionGrades[1] + st[id].sessionGrades[2] + st[id].commonGrades[0] + st[id].commonGrades[1] + st[id].commonGrades[2] + st[id].commonGrades[3]) / 7.0 * 100) / 100;
}
void withOutGrant(std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if(st[i].sessionGrades[0] == 3 || st[i].sessionGrades[1] == 3 || st[i].sessionGrades[2] == 3 || st[i].commonGrades[0] == 3 || st[i].commonGrades[1] == 3 || st[i].commonGrades[2] == 3 || st[i].commonGrades[3] == 3)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void goodExcellent(std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].sessionGrades[0] > 3 && st[i].sessionGrades[1] > 3 && st[i].sessionGrades[2] > 3 && st[i].commonGrades[0] > 3 && st[i].commonGrades[1] > 3 && st[i].commonGrades[2] > 3 && st[i].commonGrades[3] > 3)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void excellent(std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].sessionGrades[0] == 5 && st[i].sessionGrades[1] == 5 && st[i].sessionGrades[2] == 5 && st[i].commonGrades[0] == 5 && st[i].commonGrades[1] == 5 && st[i].commonGrades[2] == 5 && st[i].commonGrades[3] == 5)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void selectingGrant(int id, std::vector<student> st)
{
    switch (id)
    {
    case 1:
        withOutGrant(st);
        break;
    case 2:
        goodExcellent(st);
        break;
    case 3:
        excellent(st);
        break;
    }
}
void selectingEntry(std::vector<student>& st)
{
    int scroll = -1;
    bool isEnabled = true;

    while (isEnabled)
    {
        editingMenu(st, scroll);
        switch (_getch())
        {
        case 'w':
            if (scroll != -1) scroll--;
            else scroll = st.size() - 1;
            break;
        case 's':
            if (scroll != st.size() - 1) scroll++;
            else scroll = -1;
            break;
        case ' ':
            if (scroll == -1) isEnabled = false;
            else editingEntry(scroll, st);
            break;
        }
        system("cls");
    }
}
void displaySelectedGroup(const std::vector<student> st)
{
    int group;
    std::cout << "which group do you want to see?\n";
    std::cin >> group;
    errormessage(group, 1000, 9999);
    system("cls");

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if(st[i].group == group)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void displaySelectedSex(const std::vector<student> st)
{
    char sex;
    std::cout << "enter the gender required for the search (F/M)\n";
    std::cin >> sex;
    while ((sex != 'F' && sex != 'M') && (sex != 'f' && sex != 'm'))
    {
        std::cout << "you entered unacceptable value, try again: ";
        std::cin >> sex;
    }
    system("cls");

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    sex = (char)toupper(sex);

    for (int i = 0; i < st.size(); i++)
        if (st[i].sex == sex)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << st[i].sex << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void displaySelectedId(const std::vector<student> st)
{
    int id;
    std::cout << "which id will be found?\n";
    std::cin >> id;

    system("cls");

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].id == id)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void studentsGrant(const std::vector<student> st)
{
    int scroll = 0;
    bool isEnabled = true;

    while (isEnabled)
    {
        grantMenu(scroll);
        switch (_getch())
        {
        case 'w':
            if (scroll != 0) scroll--;
            else scroll = 3;
            break;
        case 's':
            if (scroll != 3) scroll++;
            else scroll = 0;
            break;
        case ' ':
            if (scroll == 0) isEnabled = false;
            selectingGrant(scroll, st);
            break;
        }
        system("cls");
    }
}
void selectedField(int position, std::vector<student>& students)
{
    system("Cls");
    switch (position)
    {
    case 1:
        createNewEntry(students);
        break;
    case 2:
        selectingEntry(students);
        break;
    case 3:
        outputAllStudentsInfo(students);
        break;
    case 4:
        displaySelectedGroup(students);
        break;
    case 6:
        displaySelectedSex(students);
        break;
    case 7:
        studentsGrant(students);
        break;
    case 8:
        displaySelectedId(students);
        break;
    }
}

int main()
{
    setlocale(0, "rus");
    fullscreen();

    std::vector<student> students;
    students.push_back({ "Бессмертных Артем", 'M', 20, 1324, 1, 0, 5, 0, 3, 0, 0, 0});
    students.push_back({ "Мансуров Ярослав",  'M', 20, 1324, 2, 0, 0, 0, 0, 4, 4, 0});
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