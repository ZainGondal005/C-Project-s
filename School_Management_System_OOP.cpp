#include <iostream>

using namespace std;
class teachers
{
private:
    int TeachersID[5];
    string Teachers_name[5];
    string Department[5];

public:
    teachers() {}
    void read_teachers(int &, int &);
    void Display_teachers(int);
    void update_Teacher_record(int &);
    void teacherview(int, int);
    void Delete_Teacher_Record(int &);
};
void teachers::read_teachers(int &Tsize, int &totalteachers)
{
    cout << "Enter number of Teachers : " << endl;
    cin >> Tsize;
    if (totalteachers == 0)
    {
        totalteachers = totalteachers + Tsize;
        for (int i = 0; i < Tsize; i++)
        {

            cout << "the record of Teacher " << i + 1 << " is :" << endl;
            cout << "\n Teachers ID :";
            cin >> TeachersID[i];
            cout << "\n FirstName :";
            cin >> Teachers_name[i];
            cout << "\n Department :";
            cin >> Department[i];
            cout << endl;
        }
    }
    else
    {
        for (int i = totalteachers; i < totalteachers + Tsize; i++)
        {
            cout << "the record of Teacher " << i + 1 << " is :" << endl;
            cout << "\n Teachers ID :";
            cin >> TeachersID[i];
            cout << "\n FirstName :";
            cin >> Teachers_name[i];
            cout << "\n Department :";
            cin >> Department[i];
            cout << endl;
        }
        totalteachers = totalteachers + Tsize;
    }
}
void teachers::Display_teachers(int totalteachers)
{
    for (int i = 0; i < totalteachers; i++)
    {

        cout << "the record of Teacher " << i + 1 << " is :" << endl;
        cout << "\t Teachers ID :";
        cout << TeachersID[i];
        cout << "\t FirstName :";
        cout << Teachers_name[i];

        cout << "\t Department :";
        cout << Department[i];
        cout << endl;
    }
}
void teachers::teacherview(int totalteachers, int see_teacher_record)
{
    if (totalteachers == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        cout << "enter records number that you want to see_teacher_record :";
        cin >> see_teacher_record;
        for (int i = 0; i < totalteachers; i++)
        {

            if (see_teacher_record == TeachersID[i])
            {

                cout << "\n Teachers ID :";
                cout << TeachersID[i];
                cout << "\t FirstName :";
                cout << Teachers_name[i];

                cout << "\t Department :";
                cout << Department[i];
                cout << endl;
            }
        }
    }
}
void teachers::Delete_Teacher_Record(int &totalteachers)
{
    if (totalteachers == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter Teacher Index to Delete : ";
        cin >> ID;
        while (ID > totalteachers)
        {
            cout << "Enter index number of teachers from [0 - " << totalteachers << "]" << endl;
            cin >> ID;
        }
        for (int i = 0; i < totalteachers; i++)
        {

            for (int i = ID; i < totalteachers - 1; i++)
            {
                TeachersID[i] = TeachersID[i + 1];
                Teachers_name[i] = Teachers_name[i + 1];
                Department[i] = Department[i + 1];
            }

            totalteachers--;
            cout << "Your Teacher deleted successfully ." << endl;
            return;
        }
        cout << "not fount" << endl;
    }
}
void teachers::update_Teacher_record(int &totalteachers)
{
    if (totalteachers == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter Teacher ID to Modify : ";
        cin >> ID;
        for (int i = 0; i < totalteachers; i++)
        {

            if (ID == TeachersID[i])
            {

                cout << "\n Teachers ID :";
                cin >> TeachersID[i];
                cout << "\n FirstName :";
                cin >> Teachers_name[i];
                cout << "\n Department :";
                cin >> Department[i];
                cout << endl;
            }
            else
            {

                cout << "not fount" << endl;
            }
        }

        cout << "Your Teacher updated successfully ." << endl;
    }
}
class student
{
private:
    int rollnumber[5];
    string firstName[5];
    int classnumber[5];

public:
    void read_data(int &, int &);
    void display(int);
    void update_record(int &);
    void View(int, int);
    void Delete_Record(int &);

    student() {}
};
void student::read_data(int &size, int &totalstudent)
{

    cout << "enter number of students :" << endl;

    cin >> size;

    // ptr=new string[size];
    if (totalstudent == 0)
    {
        totalstudent = totalstudent + size;
        for (int i = 0; i < size; i++)
        {

            cout << "the record of student " << i + 1 << " is :" << endl;
            cout << "i is " << i;
            cout << " Rollnumber :";
            cin >> rollnumber[i];
            cout << "\n FirstName :";
            cin >> firstName[i];

            cout << "\n Classnumber :";
            cin >> classnumber[i];
            cout << endl;
        }
    }
    else
    {
        for (int i = totalstudent; i < totalstudent + size; i++)
        {

            cout << "the record of student " << i + 1 << " is :" << endl;
            cout << " Rollnumber :";
            cin >> rollnumber[i];

            // for (int j = 0; j < size; j++)
            // {
            //     if (rollnumber[i] == rollnumber[j])
            //     {
            //         cout << "repeated record can not be allowed : " << endl;
            //         return;
            //     }
            // }

            cout << "\n FirstName :";
            cin >> firstName[i];
            cout << "\n Classnumber :";
            cin >> classnumber[i];
            //     cout << "\n Cources that you are enroll :";
            // cin >> totalcources[i];
            cout << endl;
        }
        totalstudent = totalstudent + size;
    }
}
void student::Delete_Record(int &totalstudent)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter student ID index number to Delete from [0 - " << totalstudent << "]" << endl;
        cin >> ID;
        while (ID > totalstudent)
        {
            cout << "Enter index number of student from [0 - " << totalstudent << "]" << endl;
            cin >> ID;
        }

        for (int i = 0; i < totalstudent; i++)
        {
            for (int i = ID; i < totalstudent - 1; i++)
            {
                rollnumber[i] = rollnumber[i + 1];
                firstName[i] = firstName[i + 1];
                classnumber[i] = classnumber[i + 1];
            }
            totalstudent--;
            cout << "Your student deleted successfully ." << endl;
            return;
        }
        cout << "not fount" << endl;
    }
}
void student::View(int totalstudent, int see_student_record)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        cout << "enter records number that you want to see_student_record";
        cin >> see_student_record;
        for (int i = 0; i < totalstudent; i++)
        {

            if (see_student_record == rollnumber[i])
            {

                cout << " \nRollnumber :";
                cout << rollnumber[i];
                cout << "\t FirstName :";
                cout << firstName[i];

                cout << "\t Classnumber :";
                cout << classnumber[i];
                cout << endl;
                // cout << "\t Your  enroll coures are :";
                // cout << std[i].totalcources;
            }
        }
    }
}
void student::display(int totalstudent)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        for (int i = 0; i < totalstudent; i++)
        {

            cout << "the record of student " << i + 1 << " is :" << endl;
            cout << " Rollnumber :";
            cout << rollnumber[i];
            cout << "\t FirstName :";
            cout << firstName[i];
            cout << "\t Classnumber :";
            cout << classnumber[i];
            // cout << "\t Your  enroll coures are :";
            // cout << totalcources[i];
            cout << endl;
        }
    }
}
void student::update_record(int &totalstudent)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter student ID to update record : ";
        cin >> ID;
        for (int i = 0; i < totalstudent; i++)
        {

            if (ID == rollnumber[i])
            {

                cout << " Rollnumber :";
                cin >> rollnumber[i];
                cout << "\n FirstName :";
                cin >> firstName[i];
                cout << "\n Classnumber :";
                cin >> classnumber[i];
                // cout << "\n Cources that you are enroll :";
                // cin >> totalcources[i];
                cout << "Your student updated successfully ." << endl;
                cout << endl;
                return;
            }
        }
        cout << "not fount" << endl;
    }
}

int main()
{
    student obj1;
    teachers sir;
    int Tsize = 0;
    int size = 0;
    int totalstudent = 0;
    int totalteachers = 0;
    int see_teacher_record;
    int see_student_record;
    int choice;
    int option;
    // Display Admin menu options

    do
    {

        cout << "------------School Management System --------------------" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "1. TEACHER" << endl;
        cout << "2. STUDENT" << endl;
        cout << "3. For Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            do
            {

                cout << "---------------------------" << endl;
                cout << "------Teacher section------" << endl;
                cout << "---------------------------" << endl;
                cout << "1. Add Teacher record" << endl;
                cout << "2. Display Teacher record" << endl;
                cout << "3. view specific Teacher record" << endl;
                cout << "4. Delete Teacher record" << endl;
                cout << "5. Modify/update Teacher record" << endl;
                cout << "6. For Exit" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter choice: " << endl;
                cout << "---------------------------" << endl;
                cin >> option;
                switch (option)
                {
                case 1:
                {
                    sir.read_teachers(Tsize, totalteachers);
                    sir.Display_teachers(totalteachers);
                    break;
                }
                case 2:
                {
                    sir.Display_teachers(totalteachers);
                    break;
                }
                case 3:
                {
                    sir.teacherview(totalteachers, see_teacher_record);
                    break;
                }
                case 4:
                {
                    sir.Delete_Teacher_Record(totalteachers);
                    break;
                }
                case 5:
                {
                    sir.update_Teacher_record(totalteachers);
                    break;
                }
                case 6:

                    cout << "Exiting....." << endl;
                    break;

                default:
                    cout << "Invalid option entered " << endl;
                    break;
                }

            } while (option != 6);
            break;
        }
        case 2:
        {
            do
            {

                cout << "---------------------------" << endl;
                cout << "------Student section------" << endl;
                cout << "---------------------------" << endl;
                cout << "1. Add Students record" << endl;
                cout << "2. Display student record" << endl;
                cout << "3. View specific student record" << endl;
                cout << "4. Delete Students record" << endl;
                cout << "5. Modify/update Students record" << endl;
                cout << "6. Exit" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter choice: " << endl;
                cout << "---------------------------" << endl;
                cin >> option;
                switch (option)
                {
                case 1:
                {
                    obj1.read_data(size, totalstudent);
                    break;
                }
                case 2:
                {

                    obj1.display(totalstudent);
                    break;
                }
                case 3:
                {
                    obj1.View(totalstudent, see_student_record);
                    break;
                }
                case 4:
                {
                    obj1.Delete_Record(totalstudent);
                    break;
                }
                case 5:
                {
                    obj1.update_record(totalstudent);
                    break;
                }
                case 6:
                {
                    cout << "Exiting....." << endl;
                    break;
                }
                default:
                    cout << "Invalid option entered " << endl;
                    break;
                }
            } while (option != 6);
            break;
        }
        case 3:
            cout << "Exiting....." << endl;
            break;

        default:
            cout << "Invalid option entered " << endl;
            break;
        }
    } while (option != 3);
    return 0;
}
