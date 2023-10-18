#include <iostream>
#include <string>
using namespace std;

void player1_checking_winner(string array[])
{
    if (((array[1] == array[2] && array[2] == array[3]) || (array[1] == array[4] && array[4] == array[7]) || (array[1] == array[5] && array[5] == array[9]) || (array[2] == array[5] && array[5] == array[8]) || (array[3] == array[5] && array[5] == array[7]) || (array[4] == array[5] && array[5] == array[6]) || (array[7] == array[8] && array[8] == array[9])))
    {
        cout << "player 1 WINS " << endl;
        terminate();
    }
}
void player2_checking_winner(string array[])
{
    if (((array[1] == array[2] && array[2] == array[3]) || (array[1] == array[4] && array[4] == array[7]) || (array[1] == array[5] && array[5] == array[9]) || (array[2] == array[5] && array[5] == array[8]) || (array[3] == array[5] && array[5] == array[7]) || (array[4] == array[5] && array[5] == array[6]) || (array[7] == array[8] && array[8] == array[9])))
    {
        cout << "player 2 WINS " << endl;
        terminate();
    }
}
void player1_turn(string array[], int postion_player1)
{
    array[postion_player1] = 'X';
    if (postion_player1 == 1 || postion_player1 == 2 || postion_player1 == 3 || postion_player1 == 4 || postion_player1 == 5 || postion_player1 == 6 || postion_player1 == 7 || postion_player1 == 8 || postion_player1 == 9)
    {
        cout << " " << array[1] << " "
             << "|"
             << " " << array[2] << " "
             << "|"
             << " " << array[3] << "\n"
             << "--- --- --- \n"
             << " " << array[4] << " "
             << "|"
             << " " << array[5] << " "
             << "|"
             << " " << array[6] << "\n"
             << "--- --- --- \n"
             << " " << array[7] << " "
             << "|"
             << " " << array[8] << " "
             << "|"
             << " " << array[9] << endl;
    }
}
void player2_turn(string array[], int postion_player2)
{

    array[postion_player2] = 'O';
    if (postion_player2 == 1 || postion_player2 == 2 || postion_player2 == 3 || postion_player2 == 4 || postion_player2 == 5 || postion_player2 == 6 || postion_player2 == 7 || postion_player2 == 8 || postion_player2 == 9)
    {
        cout << " " << array[1] << " "
             << "|"
             << " " << array[2] << " "
             << "|"
             << " " << array[3] << "\n"
             << "--- --- --- \n"
             << " " << array[4] << " "
             << "|"
             << " " << array[5] << " "
             << "|"
             << " " << array[6] << "\n"
             << "--- --- --- \n"
             << " " << array[7] << " "
             << "|"
             << " " << array[8] << " "
             << "|"
             << " " << array[9] << endl;
    }
}
int main()
{
    string array[10] = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int postion_player1;
    int postion_player2;
    cout << "  1 | 2 | 3 \n --- --- --- \n  4 | 5 | 6  \n --- --- --- \n  7 | 8 | 9\n";
    cout << "enter a number at position 1-9" << endl;
    for (int i = 0 + 1; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            cout << "player 2" << endl;
            cin >> postion_player2;
            player2_turn(array, postion_player2);
            if (i > 4)
            {
                player2_checking_winner(array);
            }
        }
        else
        {

            cout << "player 1 " << endl;
            cin >> postion_player1;
            player1_turn(array, postion_player1);
            if (i > 3)
            {
                player1_checking_winner(array);
            }
        }
    }
    cout << "DRAW " << endl;

    return 0;
}
