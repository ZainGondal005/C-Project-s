#include "person.h"

void save(char[], person[], int);
void fun_import(char[]);
void exist(std::fstream &);

int main(int argc, char *argv[])
{
    char filename[20] = "person_data.bin";
    person *obj_person = new person[10];
    char name_file[20];
    int new_person = 0;
    int choice;
    int option;
    int count;

    std::fstream myfile(filename, std::ios::binary | std::ios::in);
    if (!myfile.is_open())
    {
        std::cout << "File does not exist\n"
                  << std::endl;
    }
    else
    {
        std::cout << "In exist part" << std::endl;
        exist(myfile);
    }
    if (argc == 3)
    {
        strcpy(name_file, argv[2]);

        if (argv[1] == "import")
        {
            std::cout << "import function";
            fun_import(name_file);
        }
    }
    else
    {
    }
    if (argc == 2)
    {
        std::string help = argv[1];
        if (argv[1] == "help")
        {
            std::cout << "This help message.\nThis program like project mangement system that perform the CRUD opertion, use binary file and .csv file to store data\n";
        }
    }
    else
    {
    }
    do
    {
        std::cout << "------ Project Managent System ------" << std::endl;
        std::cout << "1. Add Project" << std::endl;
        std::cout << "2. View specific Project" << std::endl;
        std::cout << "3. update the specific record" << std::endl;
        std::cout << "4. Delete Project" << std::endl;
        std::cout << "5. Display Project's" << std::endl;
        std::cout << "6. Save to File" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Enter option   ";
        std::cin >> option;
        std::cout << "----------------------" << std::endl;
        std::cout << std::endl;

        switch (option)
        {
        case 1:
        {
            if (new_person >= 10)
            {
                std::cout << "You Reached at a maximum limit\nYou cannot add more Project's\n";
                option = 7;
            }
            else
            {
                obj_person[new_person].set_project();
                new_person++;
                std::cout << "Data stored successfully" << std::endl;
                std::cout << "------------------------------------" << std::endl;
            }
        }
        break;
        case 2:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to view this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;
                    choice = choice - 1;
                }
                std::cout << "-------  Data of Project's -------\n";
                obj_person[choice].print();
            }

            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 3:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to update this " << obj_person[i].getproject_name() << " record under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;
                    choice = choice - 1;
                }
                std::cout << "-------  Data of Project's -------\n";
                obj_person[choice].set_project();
                if (count != 0)
                {
                    save(filename, obj_person, new_person);
                    std::cout << "Data updated successfully" << std::endl;
                }
            }

            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 4:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to Delete this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;

                    choice = choice - 1;
                }
            }
            obj_person[choice] = obj_person[choice + 1];
            new_person--;
            std::cout << "Project's deleted successfully" << std::endl;
            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 5:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "-------  Data of Project's  " << i + 1 << "-------\n"
                              << std::endl;
                    std::cout << obj_person[i];
                }
            }
            std::cout << "------------------------------------" << std::endl;
        }

        break;
        case 6:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time\nNO data is saved into binary file" << std::endl;
            }
            else
            {
                count++;
                save(filename, obj_person, new_person);
                std::cout << "Data stored in binary file successfully" << std::endl;
                std::cout << "------------------------------------" << std::endl;
            }
        }
        break;
        case 7:
        {
            std::cout << "Exiting Program..." << std::endl;
        }
        break;

        default:
        {
            std::cout << "Invalid option" << std::endl;
        }
        break;
        }
    } while (option != 7);
    if (argc == 3)
    {
        strcpy(name_file, argv[2]);

        if (argv[1] == "export")
        {
            // std::cout << "export function";
            if (new_person == 0)
            {
                std::cout << " There is zero data at this time" << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    obj_person[i].fun_export(name_file);
                }
                std::cout << "Data export to file successfully\n";
            }
        }
        // else
        // {
        //     std::cout << "give proper command to export file\n";
        // }
    }
    delete[] obj_person;
    return 0;
}
void fun_import(char name_file[])
{
    std::ifstream file1(name_file, std::ios::in);

    if (!file1.is_open())
    {
        std::cout << "File is not open " << std::endl;
        return;
    }
    else
    {
        std::string line;
        while (getline(file1, line))
        {
            std::cout << line << std::endl;
        }
        file1.close();
    }
}
void exist(std::fstream &file)
{

    person p1;

    int newperson;

    while (file.read((char *)&p1, sizeof(person)))
    {
        std::cout << "--------  Data of Project's --------\n";
        if (file.good())
        {
            std::cout << p1;
        }
    }

    file.close();
    std::cout << "------------------------------------" << std::endl;
}
void save(char filename[], person std1[], int new_person)
{
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File is not open " << std::endl;
    }
    else
    {

        file.write((char *)&std1, sizeof(person) * new_person);

        file.close();

        std::ifstream filt(filename, std::ios::binary);
        person *p1 = new person[10];
        filt.read((char *)p1, sizeof(person) * new_person);

        filt.close();
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Data stored in bianary file is this \n";
        std::cout << "------------------------------------" << std::endl;
        if (new_person == 0)
        {
            std::cout << " There are zero projects at this time." << std::endl;
        }
        else
        {
            for (int i = 0; i < new_person; i++)
            {
                std::cout << "--------  Data of Project's  " << i + 1 << "--------\n"
                          << std::endl;

                std::cout << p1[i];
            }
        }
    }
}
