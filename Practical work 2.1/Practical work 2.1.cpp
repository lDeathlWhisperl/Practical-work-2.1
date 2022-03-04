#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>

struct student
{
    std::string fullName = "test";
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
void menu(int id)
{
    char str[][80] = {
        "|               Exit               |",
        "|Create a new student entry        |",
        "|Edit an existing entry            |",
        "|Display all student data          |",
        "|Display information of group \"N\"  |",
        "|Top DPA students                  |",
        "|Display male or female students   |",
        "|Display students which are...     |",
        "|Display students with \"K\" id      |"};

    std::cout <<
        "+==================================+\n";

    for (int i = 0; i < 9; i++)
    {
        if (i == id && i != 0) setColor(0, 2);
        else if (i == id && i == 0) setColor(0, 4);
        std::cout << str[i] << '\n';
        if (i == id) setColor(15, 0);
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
void outputAllStudentsInfo(const std::vector<student>& st)
{
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n"
        "|          Name          | Sex | Age | Group  | ID | G.P.A. | A&G | Math An | Informatics | Programming (lecture) | Programming(practice) | History | English |\n"
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";


    for (int i = 0; i < st.size(); i++)
        std::cout << "| " << std::left << std::setw(23) << st[i].fullName << "|  " << (char)toupper(st[i].sex) << "  | " << st[i].age << "  |  " << st[i].group << "  | " << st[i].id << "  |  " << std::setw(6) << st[i].GPA << "|  " << st[i].sessionGrades[0] << "  |    " << st[i].sessionGrades[1] << "    |      " << st[i].sessionGrades[2] << "      |           " << st[i].commonGrades[0] << "           |           " << st[i].commonGrades[1] << "           |    " << st[i].commonGrades[2] << "    |    " << st[i].commonGrades[3] << "    |\n";
    
    std::cout <<
        "+========================+=====+=====+========+====+========+=====+=========+=============+=======================+=======================+=========+=========+\n";
    //"+------------------------+-----+-----+--------+----+--------+-----+---------+-------------+-----------------------+-----------------------+---------+---------+\n
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
    using namespace std;
    std::cout <<
        "+====================+\n"
        "| Creating new entry |\n"
        "+====================+\n";

    student temp;
    cout << "Last name first name: ";
    cin >> temp.fullName;
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nSex (F/M): ";
    cin >> temp.sex;

    while ((temp.sex != 'F' && temp.sex != 'M') && (temp.sex != 'f' && temp.sex != 'm'))
    {
        cout << "you entered unacceptable value, try again: ";
        cin >> temp.sex;
    }
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nAge: ";
    cin >> temp.age;
    errormessage(temp.age, 18, 99);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nGroup: ";
    cin >> temp.group;
    errormessage(temp.group, 1000, 9999);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nId: ";
    cin >> temp.id;
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nAlgebra and geometry grade: ";
    cin >> temp.sessionGrades[0];
    errormessage(temp.sessionGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nMath analysis grade: ";
    cin >> temp.sessionGrades[1];
    errormessage(temp.sessionGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nInformatics grade: ";
    cin >> temp.sessionGrades[2];
    errormessage(temp.sessionGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nProgramming(lecture) grade: ";
    cin >> temp.commonGrades[0];
    errormessage(temp.commonGrades[0], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nProgramming(practice) grade: ";
    cin >> temp.commonGrades[1];
    errormessage(temp.commonGrades[1], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nHistory grade: ";
    cin >> temp.commonGrades[2];
    errormessage(temp.commonGrades[2], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "\nEnglish grade: ";
    cin >> temp.commonGrades[3];
    errormessage(temp.commonGrades[3], 3, 5);
    ////////////////////////////////////////////////////////////////////////////////////
    st.push_back(temp);
}
void selectedField(int position, bool& status, std::vector<student>& students)
{
    system("Cls");
    switch (position)
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
    fullscreen();

    std::vector<student> students;
    students.push_back({ "Бессмертных Артем", 'M', 20, 1324, 1, 0, 5, 0, 0, 0, 0, 0});
    students.push_back({ "Мансуров Ярослав",  'M', 20, 1324, 2, 0, 0, 0, 0, 4, 4, 0});
    students.push_back({ "Митин Илья",        'M', 20, 1324, 3, 5, 4, 5, 5, 5, 5, 5});

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
            if (scroll != 8)
                scroll++;
            break;
        case ' ':
            selectedField(scroll, isEnabled, students);
            break;
        }
        system("Cls");
    }
    return 0;
}