#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Library
{
private:
    int size;
    string books[30];
    string *stdName;
    string *stdbook;
    int issuesizebook, count;
    int *stdID;
    int namesize;
    string password;

public:
    Library();
    void setpassword(string);
    void setsize(int);
    void setbooks();
    void set_student_data();
    void addnewBook();
    void issuebook();
    void view_specific_record();
    void View_Issue_Book();
    void View_Student_issue();
    void Return_issued_book();
    void Modify();
    void Delete();
    void change_password(string &);
    void Display();
};

Library::Library()
{
        stdbook = new string[30];
        stdName = new string[30];
        stdID = new int[30];
}
void Library::setpassword(string password)
{
    this->password = password;
}

void Library::setsize(int size)
{
    this->size = size;
}

void Library::setbooks()
{
    fstream file("library.txt", ios::in);
    if (!file.is_open())
    {
        cout << "File cannot open" << endl;
        terminate();
    }
    else
    {
        int k;
        string line;
        while (getline(file, line))
        {
            books[k] = line;
            k++;
        }
        cout << "Books successfully added to file " << endl;
        cout << endl;
        file.close();
    }
}

void Library::set_student_data()
{
    cout << "enter name of student : ";
    cin >> stdName[namesize];
    cout << "Enter student ID : ";
    cin >> stdID[namesize];
}

void Library::addnewBook()
{
    int currentsize = size;
    size++;
    cout << "ENter new book name : ";
    for (int i = currentsize; i < size; i++)
    {
        cin >> books[currentsize];
    }
}

void Library::issuebook()
{
    if (size != 0)
    {
        Display();
        string bookname;
        cout << "Enter book to issue for student : " << stdName[namesize] << " with student ID is : " << stdID[issuesizebook] << endl;
        cin >> bookname;
        for (int i = 0; i < size; i++)
        {

            if (bookname == books[i])
            {
                stdbook[issuesizebook] = books[i];
                for (int j = i; j < size; j++)
                {
                    books[j] = books[j + 1];
                }
                issuesizebook++;
                namesize++;
                count++;
                size--;
                return;
            }
        }
        cout << "No book found" << endl;
    }
    else
    {
        cout << "No book avaiable now" << endl;
    }
}

void Library::view_specific_record()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " for book : ";
        cout << books[i] << endl;
    }
    int seebook;
    cout << "Enter book index to see : ";
    cin >> seebook;
    while (seebook >= size)
    {
        cout << "Invalid index it must be between [ 0-" << size-1 << " ]" << endl;
        cout << "Enter correct index : ";
        cin >> seebook;
    }
    cout <<"Your book is found and name is : "<< books[seebook] << endl;
}

void Library::View_Issue_Book()
{
    if (size == 0)
    {
        cout << "No book issued yet" << endl;
    }
    else
    {
        cout << "Issue Books are " << endl;
        for (int i = 0; i < issuesizebook; i++)
        {
            cout << "The Book " << i + 1 << " is : " << stdbook[i] << endl;
        }
    }
}

void Library::View_Student_issue()
{
    cout << "Students who issued the books" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "The Student " << i + 1 << " is " << stdName[i] << " with ID is : " << stdID[i] << endl;
    }
}

void Library::Return_issued_book()
{
    if (issuesizebook != 0)
    {
        View_Issue_Book();
        string bookname;
        cout << "Enter book name to return" << endl;
        cin >> bookname;
        for (int i = 0; i < size; i++)
        {
            if (bookname == stdbook[i])
            {
                books[size] = stdbook[i];
                for (int j = i; j < issuesizebook; j++)
                {
                    stdbook[j] = stdbook[j + 1];
                }
                issuesizebook--;
                size++;
                return;
            }
        }
        cout << "No book found" << endl;
    }
    else
    {
        cout << "No book avaiable now" << endl;
    }
}

void Library::Modify()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " for book : ";
        cout << books[i] << endl;
    }
    int seebook;
    cout << "Enter book index to modify name : ";
    cin >> seebook;
    while (seebook > size)
    {
        cout << "Invalid index it must be between [ 0-" << size << " ]" << endl;
        cout << "Enter correct index : ";
        cin >> seebook;
    }
    cout << "Enter name of book u want : ";
    cin >> books[seebook];
    cout << endl;
}

void Library::Delete()
{
    Display();
    int i;
    string seebook;
    cout << "Enter book name to delete : ";
    cin >> seebook;
    for (i = 0; i < size; i++)
    {
        if (seebook == books[i])
        {
            books[i] = books[i + 1];
            size--;
            break;
        }
    }
    if (i = size - 1)
    {
        cout << "cannot find the book" << endl;
    }
}

void Library::change_password(string &Enteredpassword)
{
    if (Enteredpassword == password)
    {
        cout << "Correct Password" << endl;
        cout << "Enter new passowrd : ";
        cin >> password;
        Enteredpassword = password;
    }
    else
    {
        cout << "Not Correct Password" << endl;
    }
}
void Library::Display()
{
    cout << "Books are --------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << books[i] << " Book\t";
        if (i==7)
        {
            cout<<"\n";
        }
        
    }
    cout << "\n----------------" << endl;
}
int main()
{
    Library book;
    string Enteredpassword;
    book.setpassword("Gondal123");
    book.setsize(13);
    book.setbooks();

    int choice;
    int option;
    int op;
    do
    {
        cout << "-------------------- Library Management System --------------------" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "1. Librarian" << endl;
        cout << "2. Student" << endl;
        cout << "3. Close Application" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> op;
        cout << "---------------------------" << endl;
        switch (op)
        {

        case 1:
        {
            do
            {

                cout << "-----------------------------" << endl;
                cout << "------Librarian section------" << endl;
                cout << "-----------------------------" << endl;
                cout << "1. View Booklist" << endl;
                cout << "2. Search for a Book" << endl;
                cout << "3. Add Book" << endl;
                cout << "4. Issue Book" << endl;
                cout << "5. Go to main" << endl;
                cout << "6. Change password" << endl;
                cout << "7. Close Application" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter choice: " << endl;
                cout << "---------------------------" << endl;
                cin >> option;
                switch (option)
                {

                case 1:
                {
                    book.Display();
                }
                break;
                case 2:
                {
                    book.view_specific_record();
                }
                break;
                case 3:
                {
                    book.addnewBook();
                }
                break;

                case 4:
                {
                    do
                    {
                        cout << "------Please Choose one option------" << endl;
                        cout << "---------------------------" << endl;
                        cout << "1. Issue Book" << endl;
                        cout << "2. View Issue Book" << endl;
                        cout << "3. Students Who issued Books" << endl;
                        cout << "4. Modify Book" << endl;
                        cout << "5. Delete Book" << endl;
                        cout << "6. Return Book" << endl;
                        cout << "7. Go to main" << endl;
                        cout << "8. Close Application" << endl;
                        cout << "---------------------------" << endl;
                        cout << "Enter choice : " << endl;
                        cout << "---------------------------" << endl;
                        cin >> choice;
                        switch (choice)
                        {

                        case 1:
                        {
                            book.set_student_data();
                            book.issuebook();
                        }
                        break;
                        case 2:
                        {
                            book.View_Issue_Book();
                        }
                        break;
                        case 3:
                        {
                            book.View_Student_issue();
                        }
                        break;

                        case 4:
                        {
                            book.Modify();
                        }
                        break;
                        case 5:
                        {
                            book.Delete();
                        }
                        break;
                        case 6:
                        {
                            book.Return_issued_book();
                        }
                        break;
                        case 7:
                        {
                            cout << "Going to Librarian section " << endl;
                        }
                        break;
                        case 8:
                        {
                            cout << "Exiting..." << endl;
                            terminate();
                        }
                        break;
                        default:
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    } while (choice != 7);
                }
                break;
                case 5:
                {
                    cout << "Go to main" << endl;
                }
                break;
                case 6:
                {
                    cout << "Enter Password to Change password" << endl;
                    cin >> Enteredpassword;
                    book.change_password(Enteredpassword);
                }
                break;
                case 7:
                {
                    cout << "Close Application" << endl;
                    terminate();
                }
                break;

                default:
                    cout << "Invalid option " << endl;
                    break;
                }
            } while (option != 5);
            break;
        }
        case 2:
        {
            do
            {

                cout << "---------------------------" << endl;
                cout << "------Student section------" << endl;
                cout << "---------------------------" << endl;
                cout << "1. View Booklist" << endl;
                cout << "2. Search for a Book" << endl;
                cout << "3. Go to main" << endl;
                cout << "4. Close Application" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter choice : ";
                cin >> choice;
                cout << "---------------------------" << endl;
                switch (choice)
                {

                case 1:
                {
                    book.Display();
                }
                break;
                case 2:
                {
                    book.view_specific_record();
                }
                break;
                case 3:
                {
                    cout << "Go to main" << endl;
                }
                break;
                case 4:
                {
                    cout << "Close Application" << endl;
                    terminate();
                }
                break;
                default:
                    cout << "Invalid option entered " << endl;
                    break;
                }

            } while (choice != 3);
            break;
        }
        case 3:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "Invalid option  " << endl;
            break;
        }
    } while (op != 3);
    return 0;
}