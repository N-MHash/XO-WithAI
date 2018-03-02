//X O
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;


void display_board();
void play();
void player_turn();

bool draw = false;
bool gameover();

string turn;
string board[4][4] = {{"00","01","02","03"}, {"10","11","12","13"}, {"20","21","22","23"},{"30","31","32","33"}};

int row = 0, column = 0;

//"X " weight
int r0, r1, r2, r3, c0, c1, c2, c3, d1, d2;

//"O " weight
int r00,r11,r22,r33,c00,c11,c22,c33,d11,d22;

void check_r();
void check_c();
void check_d1();
void check_d2();
void check_rr();
void check_cc();
void check_d11();
void check_d22();

int main()
{
    cout << "Tic Tac Toe Game\n";
    Sleep(1000);
    cout << "Player [X] vs. CPU [O]\n";
    Sleep(1000);
    cout << "\nGame starts in..\n";
    Sleep(1000);
    cout << "3\n";
    Sleep(1000);
    cout << "2\n";
    Sleep(1000);
    cout << "1\n";
    Sleep(1000);
    cout << "Have Fun!\n\n";
    Sleep(1500);
    turn = "X ";

    while (!gameover())
    {
        play:
            display_board();
            player_turn();
            gameover();
    }

    if (turn == "O " && !draw)
    {
        display_board();
        cout << endl << endl << "Player 1 [X] Wins! Game Over!\n";
    }

    else if (turn == "X " && !draw)
    {
        display_board();
        cout << endl << endl << "Player 2 [O] Wins! Game Over!\n";
    }

    else
    {
        display_board();
        cout << endl << endl << "It's a draw! Game Over!\n";
    }
}

void display_board()
{
    cout << string(100, '\n');
    cout << "-------------------------------" << endl << endl;
    cout << "     |     |     |" << endl;
    cout << "  " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2]  << " |  " << board[0][3]<< endl;
    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;
    cout << "  " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2]  << " |  " << board[1][3]<< endl;
    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;
    cout << "  " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2]  << " |  " << board[2][3]<< endl;
    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;
    cout << "  " << board[3][0] << " |  " << board[3][1] << " |  " << board[3][2]  << " |  " << board[3][3]<< endl;
    cout << "     |     |     |" << endl;
    cout<<endl;
    cout<<endl;
}

void player_turn()
{
    string choice;

    if (turn == "X ")
    {
        cout << "Player turn [X]: ";
        cin >> choice;

        if (choice == "00")
        {
            row = 0;
            column = 0;
        }
        else if (choice == "01")
        {
           row = 0;
           column = 1;
        }
        else if (choice == "02")
        {
           row = 0;
           column = 2;
        }
        else if (choice == "03")
        {
           row = 0;
           column = 3;
        }
        else if (choice == "10")
        {
           row = 1;
           column = 0;
        }
        else if (choice == "11")
        {
           row = 1;
           column = 1;
        }
        else if (choice == "12")
        {
           row = 1;
           column = 2;
        }
        else if (choice == "13")
        {
           row = 1;
           column = 3;
        }
        else if (choice == "20")
        {
           row = 2;
           column = 0;
        }
        else if (choice == "21")
        {
           row = 2;
           column = 1;
        }
        else if (choice == "22")
        {
           row = 2;
           column = 2;
        }
        else if (choice == "23")
        {
           row = 2;
           column = 3;
        }
        else if (choice == "30")
        {
           row = 3;
           column = 0;
        }
        else if (choice == "31")
        {
           row = 3;
           column = 1;
        }
        else if (choice == "32")
        {
           row = 3;
           column = 2;
        }
        else if (choice == "33")
        {
           row = 3;
           column = 3;
        }
        else
        {
            cout << "You didn't enter a correct number! Try again\n";
            player_turn();
        }

        if (board[row][column] != "X " && board[row][column] != "O ")
        {
            board[row][column] = "X ";
            turn = "O ";
        }
        else
        {
            cout << "The cell you chose is used! Try again\n";
            player_turn();
        }
    }

    else if (turn == "O ")
    {
        srand(time(NULL)); //Random Seed
        cout << "CPU's turn.. ";
        play();
    }
}

bool gameover()
{
    for (int i = 0; i < 4; i++)//Check for a win
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]&& board[i][2] == board[i][3])
            || (board[0][i] == board[1][i] && board[1][i] == board[2][i]&& board[2][i] == board[3][i])
            || (board[0][0] == board[1][1] && board[1][1] == board[2][2]&& board[2][2] == board[3][3])
            || (board[0][3] == board[1][2] && board[1][2] == board[2][1]&& board[2][1] == board[3][0]))
        {
            return true;
        }
    }

    for (int i = 0; i < 4; i++)//Check for draw
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != "X " && board[i][j] != "O ")
            {
                return false;
            }
        }
    }

    draw = true;
    return true;
}

void check_r()
{
    r0 = 0;
    for(int c = 0; c < 4; c++)
    {
        if(board[0][c]=="O ")
        {
            r0++;
        }
    }

    r1 = 0;
    for(int c = 0; c < 4; c++)
    {
        if (board [1][c] == "O ")
        {
            r1++;
        }
    }

    r2 = 0;
    for(int c = 0; c < 4; c++)
    {
        if (board [2][c] == "O ")
        {
            r2++;
        }
    }

    r3 = 0;
    for(int c = 0; c < 4; c++)
    {
        if (board [3][c] == "O ")
        {
            r3++;
        }
    }
}


void check_c()
{
    c0 = 0;
    for(int r = 0; r < 4; r++)
    {
        if(board[r][0] == "O ")
        {
            c0++;
        }
    }

    c1 = 0;
    for(int r = 0; r < 4; r++)
    {
        if (board [r][1] == "O "){

            c1++;
           // c11=c1;
        }
    }

    c2 = 0;
    for(int r = 0; r < 4; r++)
    {

        if (board [r][2] == "O "){
            c2++;
        }
    }

    c3 = 0;
    for(int r = 0; r < 4; r++)
    {

        if (board [r][3] == "O "){
            c3++;
        }
    }
}

void check_d1()
{
    d1 = 0;
    for (int r = 0, c = 0; c < 4; r++, c++)
    {
        if(board[r][c] == "O ")
        {
            d1++;
        }
    }
}

void check_d2()
{
    d2 = 0;
    for (int r = 0, c = 3; c > 0; r++,c--)
    {
        if(board[r][c] == "O ")
        {
            d2++;
        }
    }
}


//-----------------------------------------------------------------------------
void check_rr()
{
    r00 = r0;
    for (int c = 0; c < 4; c++)
    {
        if(board[0][c] == "X ")
            r00--;
    }

    r11 = r1;
    for (int c = 0; c < 4; c++)
    {
        if (board [1][c] == "X ")
            r11--;
    }

    r22 = r2;
    for (int c = 0; c < 4; c++)
    {
        if (board [2][c] == "X ")
            r22--;
    }

    r33 = r3;
    for (int c = 0; c < 4; c++)
    {
        if (board [3][c] == "X ")
            r33--;
    }
}


void check_cc()
{
    c00 = c0;
    for (int r = 0; r < 4; r++)
    {
        if(board[r][0] == "X ")
            c00--;
    }

    c11 = c1;
    for(int r = 0; r < 4; r++)
    {
        if (board [r][1] == "X ")
            c11--;
    }

    c22 = c2;
    for(int r = 0; r < 4; r++)
    {
        if (board [r][2] == "X ")
            c22--;
    }

    c33 = c3;
    for(int r = 0; r < 4; r++)
    {
        if (board [r][3] == "X ")
            c33--;
    }
}

void check_d11()
{
    d11 = d1;
    for (int r = 0, c = 0; c < 4; r++, c++)
    {
        if(board[r][c] == "X ")
            d11--;
    }
}


void check_d22()
{
    d22 = d2;
    for (int r = 0, c = 3; c > 0; r++, c--)
    {
        if(board[r][c] == "X ")
            d22--;
    }
}


void play()
{
    check_r();
    check_c();
    check_rr();
    check_cc();
    check_d1();
    check_d2();
    check_d11();
    check_d22();

    do
    {
        if(r00 == 3)
        {
            row = 0;

            for(int w = 0; w < 4; w++)
            {
                if (board[0][w] != "O " && board[0][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }
        //**************************
        else if(r11 == 3)
        {
            row = 1;

            for(int w = 0; w < 4; w++)
            {
                if (board[1][w] != "O " && board[1][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }
        //***********************************

        else if(r22 == 3)
        {
            row = 2;

            for(int w = 0; w < 4; w++)
            {
                if (board[2][w] != "O " && board[2][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }

        //************************************
        else if(r33 == 3)
        {
            row = 3;

            for(int w = 0; w < 4; w++)
            {
                if (board[3][w] != "O " && board[3][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }
        //********************************
        else if(c00 == 3)
        {
            column = 0;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][0] != "O " && board[w][0] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //********************************

        else if(c11 == 3)
        {
            column = 1;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][1] != "O " && board[w][1] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //***********************************
        else if(c22 == 3)
        {
            column = 2;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][2] != "O " && board[w][2] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //*******************

        else if(c33 == 3)
        {
            column = 3;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][3] != "O " && board[w][3] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //***************************
        else if (d11 == 3)
        {
            for(int w = 0, a = 0; a < 4; w++, a++)
            {
                if (board[w][a] != "O " && board[w][a] != "X ")
                {
                    row = w;
                    column = a;
                }
                else
                    continue;
            }
        }

        //***************************************

        else if (d22 == 3)
        {
            for(int w = 0, a = 3; w < 4, a > -1; w++, a--)
            {
                if (board[w][a] != "O " && board[w][a] != "X ")
                {
                    row = w;
                    column = a;
                }
                else
                    continue;
            }
        }
        //************************************

        else if(r00 == -3)
        {
            row = 0;

            for(int w = 0; w < 4; w++)
            {
                if (board[0][w] != "O " && board[0][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }

        //**************************
        else  if(r11 == -3)
        {
            row = 1;

            for(int w = 0; w < 4; w++)
            {
                if (board[1][w] != "O " && board[1][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }
        //***********************************

        else if(r22 == -3)
        {
            row = 2;

            for(int w = 0; w < 4; w++)
            {
                if (board[2][w] != "O " && board[2][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }

        //************************************
        else if(r33 == -3)
        {
            row = 3;

            for(int w = 0; w < 4; w++)
            {
                if (board[3][w] != "O " && board[3][w] != "X ")
                {
                    column = w;
                }
                else
                    continue;
            }
        }
        //********************************
         else if(c00 == -3)
        {
            column = 0;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][0] != "O " && board[w][0] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //********************************
        else if(c11 == -3)
        {
            column = 1;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][1] != "O " && board[w][1] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }

        //***********************************
        else if(c22 == -3)
        {
            column = 2;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][2] != "O " && board[w][2] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //*******************

        else if(c33 == -3)
        {
            column = 3;

            for(int w = 0; w < 4; w++)
            {
                if (board[w][3] != "O " && board[w][3] != "X ")
                {
                    row = w;
                }
                else
                    continue;
            }
        }
        //***************************
        else   if (d11 == -3)
        {
            for(int w = 0, a = 0; w < 4, a < 4; w++, a++)
            {
                if (board[w][a] != "O " && board[w][a] != "X ")
                {
                        row = w;
                        column = a;
                }
                else
                    continue;
            }
        }
        //***************************************
        else if (d22 == -3)
        {
            for(int w = 0, a = 3; w < 4, a > -1; w++, a--)
                {
                    if (board[w][a] != "O " && board[w][a] != "X ")
                    {
                        row = w;
                        column = a;
                    }
                    else
                        continue;
                }
        }
        else
        {
            row = rand() % 4;
            column = rand() % 4;
        }

    }while(board[row][column] == "X " || board[row][column] == "O ");

    board[row][column] = "O ";

    turn = "X ";
}


