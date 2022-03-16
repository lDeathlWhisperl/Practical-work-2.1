#pragma once

struct student
{
    std::string fullName;
    char sex = 'F';
    int age = 10;
    int group = 1000;
    int id = 0;
    int sessionGrades[3] = { 3, 3, 3 };
    int commonGrades[4] = { 3, 3, 3, 3 };
    double GPA = floor((sessionGrades[0] + sessionGrades[1] + sessionGrades[2] + commonGrades[0] + commonGrades[1] + commonGrades[2] + commonGrades[3]) / 7.0 * 100) / 100;

    bool operator< (const student& a) const {
        return GPA < a.GPA;
    }
};

//other
void fullscreen();
void setColor(int text, int background);
//menu types
void mainMenu(int id);
void editingMenu(std::vector<student>& st, int id);
void grantMenu(int id);
//editing
void errormessage(int& value, int rangeFrom, int rangeTo);
void createNewEntry(std::vector<student>& st);
void editingEntry(int id, std::vector<student>& st);
//student's marks
void withOutGrant(const std::vector<student> st);
void goodExcellent(const std::vector<student> st);
void excellent(const std::vector<student> st);
//output
void displaySelectedGroup(const std::vector<student> st);
void displaySelectedSex(const std::vector<student> st);
void displaySelectedId(const std::vector<student> st);
void displayTopGPAStudents(std::vector<student> st);
void displayAllStudentsInfo(const std::vector<student> st);
//field selecting
void selectingGrant(int id, const std::vector<student> st);
void selectingEntry(std::vector<student>& st);
void studentsGrant(const std::vector<student> st);
void selectedField(int position, std::vector<student>& students);
//file processing
void writeInToFile(const std::vector<student> st);
void getFromFile(std::vector<student>& st);