#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include "Functions.h"

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
        "|Display students with \"K\" id      |" };/*8*/

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
void editingMenu(std::vector<student>& st, int id, bool deleting)
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
        if (i == id && !deleting) setColor(0, 15);
        std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |";
        if (i == id && deleting)
        {
            setColor(15, 0);
            setColor(0, 4);
            std::cout << "  x  ";
        }
        setColor(15, 0);
        std::cout << '\n';
    }

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "| Controls:                                                       |\n"
        "|                                                                 |\n"
        "| [w]     -> scroll up                                            |\n"
        "| [s]     -> scroll down                                          |\n"
        "| [d]     -> delelting mode ON                                    |\n"
        "| [a]     -> deleting mode OFF                                    |\n"
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
void errormessage(int& value, int rangeFrom, int rangeTo)
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
    getline(std::cin, temp.fullName, '\n'); //нужно поставить лимит на символы
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
    errormessage(temp.id, 1, 50);
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
void deletingEntry(int &id, std::vector<student>& st)
{
    int scroll = 0;
    char str[][8] = { "[ No ]", "[ Yes ]" };
    bool isEnable = true;
    while (isEnable)
    {
        system("cls");
        std::cout <<
            "+===============================================+\n"
            "|  Are you sure you want to delete this entry?  |\n"
            "+===============================================+\n"
            "|                                               |\n"
            "|           ";


        for (int i = 1; i >= 0; i--)
        {
            if (i == 0 && i == scroll) setColor(0, 2);
            if (i == 1 && i == scroll) setColor(0, 4);
            std::cout << str[i];
            setColor(15, 0);
            std::cout << "           ";
        }

        std::cout << " |\n"
            "|                                               |\n"
            "+===============================================+\n"
            "| Controls:                                     |\n"
            "|                                               |\n"
            "| [a] [d] -> choosing an option                 |\n"
            "| [Space] -> select                             |\n"
            "+===============================================+\n";

        switch (_getch())
        {
        case 'a':
            if (scroll != 1)scroll++;
            else scroll = 0;
            break;
        case 'd':
            if (scroll != 0)scroll--;
            else scroll = 1;
            break;
        case ' ':
            if (scroll == 1)
            {
                st.erase(st.begin() + id);
                id--;
            }
            isEnable = false;
            break;
        }
    }
}
void editingEntry(int &id, std::vector<student>& st, bool &deleting)
{
    system("cls");

    if (deleting)
    {
        deletingEntry(id, st);
        deleting = false;
    }
    else
    {
        std::cout <<
            "+===============+\n"
            "| Entry editing |\n"
            "+===============+\n";

        std::cout << "Name: " << st[id].fullName << " -> ";
        getline(std::cin, st[id].fullName, '\n'); //нужно поставить лимит на символы
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
        errormessage(st[id].id, 1, 50);
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
}
void withOutGrant(const std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].sessionGrades[0] == 3 || st[i].sessionGrades[1] == 3 || st[i].sessionGrades[2] == 3 || st[i].commonGrades[0] == 3 || st[i].commonGrades[1] == 3 || st[i].commonGrades[2] == 3 || st[i].commonGrades[3] == 3)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void goodExcellent(const std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].sessionGrades[0] > 3 && st[i].sessionGrades[1] > 3 && st[i].sessionGrades[2] > 3 && st[i].commonGrades[0] > 3 && st[i].commonGrades[1] > 3 && st[i].commonGrades[2] > 3 && st[i].commonGrades[3] > 3)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void excellent(const std::vector<student> st)
{
    system("cls");
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = 0; i < st.size(); i++)
        if (st[i].sessionGrades[0] == 5 && st[i].sessionGrades[1] == 5 && st[i].sessionGrades[2] == 5 && st[i].commonGrades[0] == 5 && st[i].commonGrades[1] == 5 && st[i].commonGrades[2] == 5 && st[i].commonGrades[3] == 5)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void selectingGrant(int id, const std::vector<student> st)
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
    bool isEnabled = true,
        isDeleting = false;


    while (isEnabled)
    {
        editingMenu(st, scroll, isDeleting);
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
        case 'd':
            if(scroll != -1) isDeleting = true;
            break;
        case 'a':
            isDeleting = false;
            break;
        case ' ':
            if (scroll == -1) isEnabled = false;
            else editingEntry(scroll, st, isDeleting);
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
        if (st[i].group == group)
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

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
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << st[i].sex << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

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
            std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    system("pause");
}
void displayTopGPAStudents(std::vector<student> st)
{
    int size = st.size();

    std::sort(st.begin(), st.end());

    std::cout <<
        "+=======+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "| Place |          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+=======+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    for (int i = size-1; i >= 0; i--)
        std::cout << "|   " << (i - size) * -1 << "   | " << std::left << std::setw(23) << st[i].fullName << "|  " << st[i].sex << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

    std::cout <<
        "+=======+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";

    system("pause");
}
void displayAllStudentsInfo(const std::vector<student> st)
{
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";


    for (int i = 0; i < st.size(); i++)
        std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << std::setw(3) << st[i].id << "|  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";

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
        displayAllStudentsInfo(students);
        break;
    case 4:
        displaySelectedGroup(students);
        break;
    case 5:
        displayTopGPAStudents(students);
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

void getFromFile(std::vector<student>& st)
{
    std::string fN;              //structure field  -> fullName
    char s;                      //structure field  -> sex
    int a, gr, id, sG[3], cG[4]; //structure fields -> age, group, id, sessionGrades, commonGrades
    double GPA;

    std::ifstream fin("DataBase.txt");

    if (fin.is_open())
    {
        while ((fin >> s >> a >> gr >> id >> sG[0] >> sG[1] >> sG[2] >> cG[0] >> cG[1] >> cG[2] >> cG[3]) && (getline(fin, fN, ';')))
        {
            student temp;
            temp.sex = s;
            temp.age = a;
            temp.group = gr;
            temp.id = id;
            for (int i = 0; i < 3; i++)
                temp.sessionGrades[i] = sG[i];
            for (int i = 0; i < 4; i++)
                temp.commonGrades[i] = cG[i];
            temp.fullName = fN;
            temp.fullName.erase(temp.fullName.find('\n'), 1);
            temp.GPA = floor((sG[0] + sG[1] + sG[2] + cG[0] + cG[1] + cG[2] + cG[3]) / 7.0 * 100) / 100;
            st.push_back(temp);
        }
    }
    else
    {
        std::cout << "Something went wrong, the file was not opened\n";
        exit(0);
    }
    fin.close();
}
void writeInToFile(const std::vector<student> st)
{
    std::ofstream fout("DataBase.txt");

    fout.open("DataBase.txt", std::ofstream::out | std::ofstream::trunc);
    fout.close();

    fout.open("DataBase.txt");
    if (fout.is_open())
        for (int i = 0; i < st.size(); i++)
            fout << st[i].sex << ' ' << st[i].age << ' ' << st[i].group << ' ' << st[i].id << ' ' << st[i].sessionGrades[0] << ' ' << st[i].sessionGrades[1] << ' ' << st[i].sessionGrades[2] << ' ' << st[i].commonGrades[0] << ' ' << st[i].commonGrades[1] << ' ' << st[i].commonGrades[2] << ' ' << st[i].commonGrades[3] << '\n' << st[i].fullName << ";\n\n";

    fout.close();
}