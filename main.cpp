#include <iostream>
#include <map>
#include <random>
#include <ctime>
using namespace std;
class Game
{
private:
    string player1, player2;
    map<int, string> XO;

public:
    Game() {};
    Game(string player1, string player2);
    void gameBoard();
    void play();
    void checkWin();
};
int main()
{
    string player1, player2, choice;
    cout << " -- TIC TAC TOE -- " << endl;
    cout << " ----------------- " << endl;
    cout << " Enter your name : " << endl;
    getline(cin, player1);
    while (true)
    {
        cout << " Enter you want to play against Human / Bot : " << endl;
        cin >> choice;
        for (char &c : choice)
        {
            c = tolower(c);
        }
        if (choice == "human")
        {
            cout << " Enter your name : " << endl;
            cin.ignore();
            getline(cin, player2);
            break;
        }
        else if (choice == "bot")
        {
            player2 = "Bot";
            break;
        }
        else
        {
            cout << " Invalid choice " << endl;
        }
    }
    cout << " ----------------- " << endl;
    cout << player1 << " ( X ) vs " << player2 << " ( O )" << endl;
    Game game(player1, player2);
    game.play();
    return 0;
}
Game::Game(string player1, string player2)
{
    this->player1 = player1;
    this->player2 = player2;
}
void Game::gameBoard()
{
    cout << " ----------------- " << endl;
    cout << "     " << XO[1] << " | " << XO[2] << " | " << XO[3] << "      " << endl;
    cout << "    ---+---+---     " << endl;
    cout << "     " << XO[4] << " | " << XO[5] << " | " << XO[6] << "      " << endl;
    cout << "    ---+---+---     " << endl;
    cout << "     " << XO[7] << " | " << XO[8] << " | " << XO[9] << "      " << endl;
    cout << " ----------------- " << endl;
}
void Game::play()
{
    int move;
    mt19937 gen(static_cast<unsigned>(std::time(0)));
    uniform_int_distribution<int> dist(1, 9);
    for (int i = 1; i <= 9; i++)
    {
        XO[i] = to_string(i);
    }
    gameBoard();
    for (int i = 1; i <= 5; i++)
    {
        cout << " " << this->player1 << "'s turn : " << endl;
        while (true)
        {
            cin >> move;
            if (XO[move] == "X" || XO[move] == "O")
            {
                cout << " Invalid move , try again . " << endl;
            }
            else
            {
                XO[move] = "X";
                gameBoard();
                checkWin();
                break;
            }
        }
        if (i == 5)
        {
            break;
        }
        cout << " " << this->player2 << "'s turn : " << endl;
        if (this->player2 == "Bot")
        {
            while (true)
            {
                move = dist(gen);
                if (XO[move] == "X" || XO[move] == "O")
                {
                }
                else
                {
                    XO[move] = "O";
                    gameBoard();
                    checkWin();
                    break;
                }
            }
        }
        else
        {
            while (true)
            {
                cin >> move;
                if (XO[move] == "X" || XO[move] == "O")
                {
                    cout << " Invalid move , try again . " << endl;
                }
                else
                {
                    XO[move] = "O";
                    gameBoard();
                    checkWin();
                    break;
                }
            }
        }
    }
    cout << " Game Draw ." << endl;
}
void Game::checkWin()
{
    if (XO[1] == XO[2] && XO[2] == XO[3])
    {
        if (XO[1] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[4] == XO[5] && XO[5] == XO[6])
    {
        if (XO[4] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[7] == XO[8] && XO[8] == XO[9])
    {
        if (XO[7] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[1] == XO[4] && XO[4] == XO[7])
    {
        if (XO[1] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[2] == XO[5] && XO[5] == XO[8])
    {
        if (XO[2] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[3] == XO[6] && XO[6] == XO[9])
    {
        if (XO[3] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[1] == XO[5] && XO[5] == XO[9])
    {
        if (XO[1] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else if (XO[3] == XO[5] && XO[5] == XO[7])
    {
        if (XO[3] == "X")
        {
            cout << " " << this->player1 << " wins ." << endl;
            exit(0);
        }
        else
        {
            cout << " " << this->player2 << " wins ." << endl;
            exit(0);
        }
    }
    else
    {
    }
}