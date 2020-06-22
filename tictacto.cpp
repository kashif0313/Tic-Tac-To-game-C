#include <iostream>
using namespace std;
//Array for the board    board[] = {abcde}
//   board[0]
char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
//Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;
int xPlayerPoints=0;
int oPlayerPoints=0;
int drawpoints=0;
int startgame();
void startagain(int again);
int startGameAgain;
int startgameturn();
void resetarray();
int endpoint = 20;
//Function to show the current status of the gaming board

void display_board()
{

	//Rander Game Board LAYOUT
	cout << "                                          PLAYER : 1    PLAYER : 2  \n";
	cout << "                                            [X]           [O]     \n\n";
	cout << "                                            _________________\n";
	cout << "                                           |     |     |     |\n";
	cout << "                                           |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |\n";
	cout << "                                           |_____|_____|_____|\n";
	cout << "                                           |     |     |     |\n";
	cout << "                                           |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |\n";
	cout << "                                           |_____|_____|_____|\n";
	cout << "                                           |     |     |     |\n";
	cout << "                                           |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |\n";
    cout << "                                           |_____|_____|_____|\n";
	//cout << "                                          Choose between 0 and 10 !! \n";
}

//Function to get the player input and update the board

void player_turn()
{
	if (turn == 'X')
    {
		cout << "Player : 1 [X] turn : ";
		cin >> choice;
	}
	else if (turn == 'O')
	{
		cout << "Player : 2 [O] turn : ";
		cin >> choice;
	}
	//Taking input from user
	//updating the board according to choice and reassigning the turn Start



	//switch case to get which row
	// 7and column will be update

	switch (choice)
	{
	case 1: {row = 0; column = 0; break;}
	case 2: {row = 0; column = 1; break;}
	case 3: {row = 0; column = 2; break;}
	case 4: {row = 1; column = 0; break;}
	case 5: {row = 1; column = 1; break;}
	case 6: {row = 1; column = 2; break;}
	case 7: {row = 2; column = 0; break;}
	case 8: {row = 2; column = 1; break;}
	case 9: {row = 2; column = 2; break;}
	default:
		{cout << "Invalid Move\n";}
	}

	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
		//updating the position for 'X' symbol if
		//it is not already occupied
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		//updating the position for 'O' symbol if
		//it is not already occupied
		board[row][column] = 'O';
		turn = 'X';
	}
	else
	{
		//if input position already filled
		cout << "Box already filled!n Please choose another!!\n";
		player_turn();
	}
	/* Ends */
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover()
{
	//checking the win for Simple Rows and Simple Column
	for (int i = 0; i<3; i++)
    {
	if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
		return false;

	//checking the win for both diagonal

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;
    }
	//Checking the game is in continue mode or not
	for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
		return true;

	//Checking the if game already draw

        }

    }

draw = true;
	return false;
}

//Program Main Method

int main()
{
    cout <<"                                    -----FUNDAMENTAL OF PROGRAMMING PROJECT----\n";
	cout << "                                        T I C K -- T A C -- T O E -- G A M E\n\n";
	cout << "NOTE:|~This is a two player game.\n     |\n     |~Who succeeds in placing three of their marks in a \n     | horizontal, vertical, or diagonal row wins the game.\n     |\n";
	cout << "     |~Choose between 0 and 10 !!  \n\n ";
	startgame();

}
int startgame()
{

    do
	{
		display_board();
		player_turn();
		gameover();
	}while (gameover());
	startgameturn();
}
int startgameturn()
{
	if (turn == 'X' && draw == false)
	{

		cout << "\nCongratulations! Player with 'O' has won the game\nNow player O gets 10 points.\n";
        oPlayerPoints= 10+oPlayerPoints;
        cout<<"\npoints = "<<oPlayerPoints<<"\n";

        if(xPlayerPoints >= endpoint || oPlayerPoints >= endpoint)
        {
            cout<<"\nGame End\n";
             cout<<"\npress 1 to start or 2 to end this game";
             cin>>startGameAgain;
             startagain(startGameAgain);
            return false;
        }



        else
        {

                do
            {
                resetarray();
                startgame();
            }while(oPlayerPoints< endpoint);
        }


	}
      if (turn == 'O' && draw == false)
	{

		cout << "\nCongratulations! Player with 'X' has won the game\nNow player X gets 10 points.\n";
		xPlayerPoints=10+xPlayerPoints;
		cout<<"\npoints = "<<xPlayerPoints;
		if(oPlayerPoints >= endpoint || xPlayerPoints >= endpoint)
        {
             cout<<"\nGame End\n";
             cout<<"\npress 1 to start or 2 to end this game";
             cin>>startGameAgain;
             startagain(startGameAgain);
            return 0;
        }
        else
        {

                do
            {
                resetarray();
                startgame();
            }while(xPlayerPoints< endpoint);
        }





	}
    if ( draw== true)
		{
		    cout << "GAME DRAW!!!\nBoth X and O gets 5 points\n";
		    drawpoints=5;
		    oPlayerPoints=oPlayerPoints+drawpoints;
		    xPlayerPoints=xPlayerPoints+drawpoints;
		    cout<<"\nplayer x points = "<<xPlayerPoints;
		    cout<<"\nplayer o points = "<<oPlayerPoints;
		    cout<<"\n";
            draw=false;
            resetarray();
            startgame();
        }

}
void startagain(int again)
{
    switch(again)
    {
        case 1:
        {
            resetarray();
            startgame();
            row=0;
            column=0;
            break;
        }
        case 2:
            {
                break;
            }
        default:
        {
            break;
        }
    }

}
void resetarray()
{
            board[0][0]='1';
            board[0][1]='2';
            board[0][2]='3';
            board[1][0]='4';
            board[1][1]='5';
            board[1][2]='6';
            board[2][0]='7';
            board[2][1]='8';
            board[2][2]='9';
}
