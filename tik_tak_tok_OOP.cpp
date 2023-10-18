
#include <iostream>
#include <string>
using namespace std;
class Game
{
private:
    string game[10];

public:
    Game()
    {
        for (int i = 0; i < 10; i++)
        {
            game[i] = " ";
        }
        game[9] = "  ";
    }
    void play()
    {        
        for (int i = 0; i < 9; i++)
        {
            if (i % 2 == 0)
            {
                cout << "player 1" << endl;
                input_player1();
                cout << "--------------------" << endl;
                Display();
                cout << "---------- ----------" << endl;
                if (i > 3)
                {
                    int boolvalue = checking_winner();
                    if (boolvalue == 1)
                    {
                        cout << "Player 1 win " << endl;
                        cout << "--------------------" << endl;
                        return;
                    }
                }
            }
            else
            {
                cout << "player 2" << endl;
                input_player2();
                cout << "--------------------" << endl;
                Display();
                cout << "--------------------" << endl;
                if (i > 4)
                {
                    int boolvalue = checking_winner();
                    if (boolvalue == 1)
                    {
                        cout << "player 2 win " << endl;
                        cout << "--------------------" << endl;
                        return;
                    }
                }
            }
        }

        cout << "Game draw" << endl;
    }

    void Display()
    {
        cout << " " << game[1] << " | " << game[2] << " | "
             << " " << game[3] << "\n"
             << "___ ___ ___"
             << "\n\n"
             << " " << game[4] << " | " << game[5] << " | "
             << " " << game[6] << "\n"
             << "___ ___ ___"
             << "\n\n"
                " "
             << game[7] << " | " << game[8] << " | "
             << " " << game[9] << "\n";
    }

    void input_player1()
    {

        cout << "where you want to enter 'O' " << endl;
        int position;
        cin >> position;
        while (position > 9)
        {
            cout << "Invalid \n enter again";
            cin >> position;
            cout << endl;
        }

        while (game[position] == "X" || game[position] == "O")
        {
            cout << "already exist enter again" << endl;
            cin >> position;
        }
        game[position] = 'O';
    }
    void input_player2()
    {

        cout << "where you want to enter 'X' " << endl;
        int position;
        cin >> position;
        while (position > 9)
        {
            cout << "Invalid \n enter again";
            cin >> position;
            cout << endl;
        }
        while (game[position] == "X" || game[position] == "O")
        {
            cout << "already exist enter again" << endl;
            cin >> position;
        }
        game[position] = 'X';
    }
    bool checking_winner()
    {
        if (((game[1] == game[2] && game[2] == game[3]) || (game[1] == game[4] && game[4] == game[7]) || (game[1] == game[5] && game[5] == game[9]) || (game[2] == game[5] && game[5] == game[8]) || (game[3] == game[5] && game[5] == game[7]) || (game[4] == game[5] && game[5] == game[6]) || (game[7] == game[8] && game[8] == game[9])))
        {
            return true;
        }     
        
    }
};

int main()
{
    Game player;
    cout << "\n";
    cout << " " << 1 << " | " << 2 << " | "<< " " << 3 << "\n"
         << "___ ___ ___"<< "\n\n"
         << " " << 4 << " | " << 5 << " | "<< " " << 6 << "\n"
         << "___ ___ ___"<< "\n\n"
         << " " << 7 << " | " << 8 << " | " << " " << 9 << "\n\n";
    player.play();
    cout << "Game END" << endl;

    return 0;
}
