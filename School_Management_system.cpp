#include <iostream>
using namespace std;

struct student
{
    int rollnumber;
    string firstName;

    int classnumber;
    int totalcources;
};
void read_data(student std[], int &size, int &totalstudent)
{

    cout << "enter number of students :" << endl;

    cin >> size;

    if (totalstudent == 0)
    {
        totalstudent = totalstudent + size;
        for (int i = 0; i < size; i++)
        {

            cout << "the record of student " << i + 1 << " is :" << endl;
            cout << " Rollnumber :";
            cin >> std[i].rollnumber;
            cout << "\n FirstName :";
            cin >> std[i].firstName;

            cout << "\n Classnumber :";
            cin >> std[i].classnumber;
            cout << "\n Cources that you are enroll :";
            cin >> std[i].totalcources;
            cout << endl;
        }
    }
    else
    {
        for (int i = totalstudent; i < totalstudent + size; i++)
        {

            cout << "the record of student " << i + 1 << " is :" << endl;
            cout << " Rollnumber :";
            cin >> std[i].rollnumber;
            for (int j = 0; j < size; j++)
            {
                if (std[i].rollnumber == std[j].rollnumber)
                {
                    cout << "repeated record can not be allowed : " << endl;
                    return;
                }
            }

            cout << "\n FirstName :";
            cin >> std[i].firstName;

            cout << "\n Classnumber :";
            cin >> std[i].classnumber;
            cout << "\n Cources that you are enroll :";
            cin >> std[i].totalcources;
            cout << endl;
        }
        totalstudent = totalstudent + size;
    }
}
void display(student std[], int totalstudent)
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
            cout << std[i].rollnumber;
            cout << "\t FirstName :";
            cout << std[i].firstName;

            cout << "\t Classnumber :";
            cout << std[i].classnumber;
            cout << "\t Your  enroll coures are :";
            cout << std[i].totalcources;
            cout << endl;
        }
    }
}
void View(student std[], int totalstudent, int see_student_record)
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

            if (see_student_record == std[i].rollnumber)
            {

                cout << " \nRollnumber :";
                cout << std[i].rollnumber;
                cout << "\t FirstName :";
                cout << std[i].firstName;

                cout << "\t Classnumber :";
                cout << std[i].classnumber;
                cout << "\t Your  enroll coures are :";
                cout << std[i].totalcources;
            }
        }
    }
}
void Delete_Record(student std[], int &totalstudent)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter student ID to Delete : ";
        cin >> ID;
        for (int i = 0; i < totalstudent; i++)
        {

            if (ID == std[i].rollnumber)
            {

                for (int i = ID; i < totalstudent - 1; i++)
                {
                    std[i] = std[i + 1];
                }

                totalstudent--;
            }
            else
            {

                cout << "not fount" << endl;
                return;
            }
        }

        cout << "Your student deleted successfully ." << endl;
    }
}
void update_record(student std[], int &totalstudent)
{
    if (totalstudent == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter student ID to Delete : ";
        cin >> ID;
        for (int i = 0; i < totalstudent; i++)
        {

            if (ID == std[i].rollnumber)
            {

                cout << " Rollnumber :";
                cin >> std[i].rollnumber;
                cout << "\n FirstName :";
                cin >> std[i].firstName;

                cout << "\n Classnumber :";
                cin >> std[i].classnumber;
                cout << "\n Cources that you are enroll :";
                cin >> std[i].totalcources;
                cout << endl;
            }
            else
            {
                cout << std[i].rollnumber;
                cout << "not fount" << endl;
            }
        }

        cout << "Your student updated successfully ." << endl;
    }
}
struct teachers
{
    int TeachersID;
    string firstname;

    char Subject_Specialization[30];
    char Department[30];
};
void read_teachers(teachers sir[], int &Tsize, int &totalteachers)
{
    cout << "enter number of Teachers : " << endl;
    cin >> Tsize;
    if (totalteachers == 0)
    {
        totalteachers = totalteachers + Tsize;
        for (int i = 0; i < Tsize; i++)
        {

            cout << "the record of Teacher " << i + 1 << " is :" << endl;
            cout << "\n Teachers ID :";
            cin >> sir[i].TeachersID;
            cout << "\n FirstName :";
            cin >> sir[i].firstname;
            cout << "\n Subject_Specialization :";
            cin >> sir[i].Subject_Specialization;
            cout << "\n Department :";
            cin >> sir[i].Department;
            cout << endl;
        }
    }
    else
    {
        for (int i = totalteachers; i < totalteachers + Tsize; i++)
        {
            cout << "the record of Teacher " << i + 1 << " is :" << endl;
            cout << "\n Teachers ID :";
            cin >> sir[i].TeachersID;
            for (int j = 0; j < Tsize; j++)
            {
                if (sir[i].TeachersID == sir[j].TeachersID)
                {
                    cout << "repeated record can not be allowed : " << endl;
                    return;
                }
            }
            cout << "\n FirstName :";
            cin >> sir[i].firstname;

            cout << "\n Subject_Specialization :";
            cin >> sir[i].Subject_Specialization;
            cout << "\n Department :";
            cin >> sir[i].Department;
            cout << endl;
        }
        totalteachers = totalteachers + Tsize;
    }
}
void Display_teachers(teachers sir[], int &totalteachers)
{
    for (int i = 0; i < totalteachers; i++)
    {

        cout << "the record of Teacher " << i + 1 << " is :" << endl;
        cout << "\t Teachers ID :";
        cout << sir[i].TeachersID;
        cout << "\t FirstName :";
        cout << sir[i].firstname;

        cout << "\t Subject_Specialization :";
        cout << sir[i].Subject_Specialization;
        cout << "\t Department :";
        cout << sir[i].Department;
        cout << endl;
    }
}
void teacherview(teachers sir[], int totalteachers, int see_teacher_record)
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

            if (see_teacher_record == sir[i].TeachersID)
            {

                cout << "\n Teachers ID :";
                cout << sir[i].TeachersID;
                cout << "\t FirstName :";
                cout << sir[i].firstname;

                cout << "\t Subject_Specialization :";
                cout << sir[i].Subject_Specialization;
                cout << "\t Department :";
                cout << sir[i].Department;
                cout << endl;
            }
        }
    }
}
void Delete_Teacher_Record(teachers sir[], int &totalteachers)
{
    if (totalteachers == 0)
    {
        cout << " Thereare zero record at that time." << endl;
    }
    else
    {
        int ID;
        cout << "Enter Teacher ID to Delete : ";
        cin >> ID;
        for (int i = 0; i < totalteachers; i++)
        {

            if (ID == sir[i].TeachersID)
            {

                for (int i = ID; i < totalteachers - 1; i++)
                {
                    sir[i] = sir[i + 1];
                }

                totalteachers--;
            }
            else
            {
                cout << "not fount" << endl;
                return;
            }
        }

        cout << "Your Teacher deleted successfully ." << endl;
    }
}
void update_Teacher_record(teachers sir[], int &totalteachers)
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

            if (ID == sir[i].TeachersID)
            {

                cout << "\n Teachers ID :";
                cin >> sir[i].TeachersID;
                cout << "\n FirstName :";
                cin >> sir[i].firstname;
                cout << "\n Subject_Specialization :";
                cin >> sir[i].Subject_Specialization;
                cout << "\n Department :";
                cin >> sir[i].Department;
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

int main()
{
    int Tsize = 0;
    int size = 0;
    int totalstudent = 0;
    int totalteachers = 0;
    teachers sir[10];
    student std[10];
    int see_teacher_record;
    int see_student_record;
    char choice;
    int option;
    do
    { // Menu

        cout << "School Management System " << endl;
        cout << "1. ADMIN" << endl;
        cout << "2. TEACHER" << endl;
        cout << "3. STUDENT" << endl;
        cout << "4. For Exit" << endl;
        cout << "Enter choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            do
            {
                // Display ADMIN menu options
                cout << "---------------------------" << endl;
                cout << "School Management System (ADMIN)" << endl;
                cout << "a. Add Teacher record" << endl;
                cout << "b. Display Teacher record" << endl;
                cout << "c. view specific Teacher record" << endl;
                cout << "d. Delete Teacher record" << endl;
                cout << "e. Modify/update Teacher record" << endl;
                cout << "f. Add Students record" << endl;
                cout << "g. Display student record" << endl;
                cout << "h. View specific student record" << endl;
                cout << "i. Delete Students record" << endl;
                cout << "j. Modify/update Students record" << endl;
                cout << "q. For Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    read_teachers(sir, Tsize, totalteachers);
                    Display_teachers(sir, totalteachers);
                    break;
                }
                case 'b':
                {
                    Display_teachers(sir, totalteachers);
                    break;
                }
                case 'c':
                {
                    teacherview(sir, totalteachers, see_teacher_record);
                    break;
                }
                case 'd':
                {
                    Delete_Teacher_Record(sir, totalteachers);
                    break;
                }
                case 'e':
                {
                    update_Teacher_record(sir, totalteachers);
                    break;
                }
                case 'f':
                {
                    read_data(std, size, totalstudent);
                    display(std, totalstudent);
                    break;
                }
                case 'g':
                {
                    View(std, totalstudent, see_student_record);
                    break;
                }
                case 'h':
                {
                    display(std, totalstudent);
                    break;
                }
                case 'i':
                {
                    Delete_Record(std, totalstudent);
                    break;
                }
                case 'j':
                {
                    update_record(std, totalstudent);
                    break;
                }
                case 'q':
                    cout << "Exiting program..." << endl;
                    cout << "---------------" << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
                }
            } while (choice != 'q');
        }
        break;
        case 2:
        {
            cout << endl;
            choice = '\0';

            // Display TEACHERS menu options
            do
            {
                cout << "---------------------------" << endl;
                cout << "School Management System (TEACHERS)" << endl;
                cout << "x. Add Students record" << endl;
                cout << "y. Display Students record" << endl;
                cout << "z. View specific student record" << endl;
                cout << "q. For Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                switch (choice)
                {
                case 'x':
                {
                    read_data(std, size, totalstudent);
                    display(std, totalstudent);
                    break;
                }
                case 'y':
                {
                    display(std, totalstudent);
                    break;
                }
                case 'z':
                {

                    View(std, totalstudent, see_student_record);
                    break;
                }
                case 'q':
                    cout << "Exiting program..." << endl;
                    cout << "---------------------" << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
                }
            } while (choice != 'q');
            break;
        }

        case 3:
        {
            cout << endl;
            choice = '\0';

            do
            {
                // Display STUDENTS menu options
                cout << "---------------------------" << endl;
                cout << "School Management System (STUDENTS)" << endl;
                cout << "x. Display student record" << endl;
                cout << "y. View specific student record" << endl;
                cout << "q. For Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                switch (choice)
                {
                case 'x':
                {
                    display(std, totalstudent);
                    break;
                }
                case 'y':
                {

                    View(std, totalstudent, see_student_record);
                    break;
                }
                case 'q':
                    cout << "Exiting program..." << endl;
                    cout << "--------------------------------------" << endl;
                    cout << "Program END";
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
                }
            } while (choice != 'q');
            break;
        }
        case 4:
        {
            cout << "Exiting program..." << endl;
            cout << "--------------------------------------" << endl;
            cout << "Program END";
            break;
        }
        default:
            cout << "Invalid option entered " << endl;
            break;
        }

    } while (option != 4);
    return 0;
}

// delete the specific student record
