#include <iostream>
#include <windows.h>
using namespace std;

//function using color for a line
typedef enum{
    BLACK = 0, BLUE = 1, GREEN = 2, AQUA = 3, RED = 4, PURPLE = 5, YELLOW = 6, WHITE = 7, GRAY = 8, LIGHT_BLUE = 9, LIGHT_GREEN = 10, LIGHT_AQUA = 11, LIGHT_RED = 12, LIGHT_PUURPLE = 13, LIGHT_YELLOW = 14, LIGHT_WHITE = 15
}
ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground){
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
       return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}

//in-app functions
string play_with_me (string);

string play_with_friend (string);

char choose_type_of_play (string);

char choose_type_of_play_again (char);

string wrong_choes (string, string);

//main function
int main()
{
	//start (start messages)
	cout << endl << "Hello and Wellcom My Friend" << endl << endl;
	cout << "Im just a game for fun and i try to make you happy" << endl;
	//end (start messages)

	Sleep(1500);
	//player name
	string player_name;
	cout << endl << "Please Enter your Name First: ";
	setTextColor(LIGHT_BLUE);
	cin >> player_name;
	setTextColor(WHITE);

	cout << "Hello >>> ";
	setTextColor(BLUE);
	cout << player_name;
	setTextColor(WHITE);
	cout << " <<<";
	char play_again;

	Sleep(1500);

	do {
	cout << endl << "Do You Want To Playing With Me? 'y/n': ";
	choose_type_of_play(player_name);

	Sleep(1500);

	cout << "Do you want to play again? y/n: ";
	cin >> play_again;
	
	//if input is wrong
	if (play_again != 'y' && play_again != 'n'){
		play_again = choose_type_of_play_again(play_again);
	}

	} while (play_again == 'y');

	setTextColor(AQUA);
	cout << "Thanks For Playing Game" << endl;
	Sleep(1500);
	cout << "GoodBye " << player_name;
	setTextColor(WHITE);

	return 0;
}

//play with robot(pvb)
string play_with_me (string player_name){
	cout << endl << ">> Ok ";
	setTextColor(BLUE);
	cout << player_name;
	setTextColor(WHITE);
	cout << ", you chose play with me. let's get started" << endl;

	//points
	int pp = 0;
	int rp = 0;

	int endp = 0;
	int endr = 0;
	
	int botchose;
	string chose1, chose2;

	for (int i = 1; i <= 3; i++){

		pp = 0;
		rp = 0;

		//messages
		string choose = ", it's your turn, choose your Option:";
		string options = "-->> 'Sang', 'Kaghaz', 'Gheychi'? ";

		cout << endl << "'";
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << "' VS ";
		setTextColor(RED);
		cout << "Robot." << endl;
		setTextColor(WHITE);
		
		//game
		cout << ">>> Round " << i << " <<<" << endl << endl;
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << choose << endl << options << endl;
		setTextColor(LIGHT_PUURPLE);
		cin >> chose1;
		if (chose1 != "Sang" && chose1 != "Gheychi" && chose1 != "Kaghaz"){
			chose1 = wrong_choes(player_name, chose1);
		}

		setTextColor(WHITE);


		//bot options
		botchose = rand() % (3 - 1 + 1) + 1;
		switch (botchose)
		{
		case 1:
			chose2 = "Sang";
			break;
		case 2:
			chose2 = "Kaghaz";
			break;
		case 3:
			chose2 = "Gheychi";
			break;
		default:
			break;
		}

		//if playe-1 win
		if (chose1 == "Kaghaz" && chose2 == "Sang")
			pp++;

		else if (chose1 == "Sang" && chose2 == "Gheychi")
			pp++;

		else if (chose1 == "Gheychi" && chose2 == "Kaghaz")
			pp++;

		//if Robot Win
		if (chose2 == "Kaghaz" && chose1 == "Sang")
			rp++;

		else if (chose2 == "Sang" && chose1 == "Gheychi")
			rp++;

		else if (chose2 == "Gheychi" && chose1 == "Kaghaz")
			rp++;
		
		//show the robot's chose
		setTextColor(GRAY);
		cout << endl << "The bot chose option --> '" << chose2 << "'" << endl;
		setTextColor(WHITE);

		//result
		if (pp > rp){
			cout << "The End of >>> Round " << i << " <<<" << endl;
			setTextColor(GREEN);
			cout << "The winner of this round of the competition is --> '";
			setTextColor(BLUE);
			cout << player_name;
			setTextColor(GREEN);
			cout << "'" << endl;
			setTextColor(WHITE);
			endp++;
		}
		else if (pp < rp){
			cout << "The End of Round " << i << endl;
			setTextColor(RED);
			cout << "The winner of this round of the competition is --> 'Robot'" << endl;
			setTextColor(WHITE);
			endr++;
		}

		//if draw
		else if (chose1 == chose2){
			setTextColor(YELLOW);
			cout << endl << ">>> Draw <<<" << endl;
			setTextColor(WHITE);
		}
	}
	setTextColor(GRAY);
	cout << endl << "Good Work ";
	setTextColor(BLUE);
	cout << player_name << endl;
	setTextColor(WHITE);

	//output of this function(Choose winner)
	string winner;

	//if player-1 win
	if (endp > endr){
		cout << endl << "The Winner of this game is ---> '";
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << "' with '" << endp << "' Points" << endl;
		cout << "The Points of '";
		setTextColor(RED);
		cout << "Robot";
		setTextColor(WHITE);
		cout << "' is --> " << endr << endl;
		winner = player_name;
	}

	//if player-2 win
	else if (endp < endr){
		cout << endl << "The Winner of this game is -->";
		setTextColor(RED); 
		cout << "'Robot'";
		setTextColor(WHITE);
		cout << " with '" << endr << "' Points" << endl;
		cout << "The Points of '";
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << "' is --> '" << endp << "'" << endl;
		winner = "Robot";
	}

	//if draw
	else if (endp == endr){
		cout << "Nice Try. This game have no Winner. '";
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << "' and";
		setTextColor(RED);
		cout << " 'Robot' ";
		setTextColor(WHITE);
		cout << "is ";
		setTextColor(YELLOW);
		cout << "Draw" << endl;
		setTextColor(WHITE);
	}

	return winner;
}

//play with friend(pvp)
string play_with_friend (string player_name){

	
	//The name of the player's friend
	cout << endl << "Ok ";
	setTextColor(BLUE);
	cout << player_name;
	setTextColor(WHITE);
	cout << ", You chose to play with your friend.\nPlease Enter your friend's name here: ";
	setTextColor(AQUA);
	string friend_name;
	cin >> friend_name;
	setTextColor(WHITE);
	cout << "Nice ";
	setTextColor(BLUE);
	cout << player_name;
	cout << ", ";
	setTextColor(AQUA);
	cout << friend_name;
	setTextColor(WHITE);
	cout << ", Let's Get Started.";

	cout << endl << endl;
	
	//points
	int pp = 0;
	int fp = 0;

	int endp = 0;
	int endf = 0;

	//messages
	string choose = " it's your turn, choose your Option: ";
	string options = "'Sang', 'Kaghaz', 'Gheychi'? ";

	string chose1;
	string chose2;

	for (int i = 1; i <= 3; i++){

		pp = 0;
		fp = 0;

		//turn player-1
		cout << "Round " << i << endl;
		setTextColor(BLUE);
		cout << player_name;
		setTextColor(WHITE);
		cout << choose << options;
		setTextColor(PURPLE);
		cin >> chose1;
		setTextColor(WHITE);
		if (chose1 != "Sang" && chose1 != "Kaghaz" && chose1 != "Gheychi"){
			chose1 = wrong_choes(player_name, chose1);
		}

		//clear
		

		//turn player-2
		cout << "Round " << i << endl;
		setTextColor(AQUA);
		cout << friend_name;
		setTextColor(WHITE);
		cout << ", Your friend made his choice." << endl;
		cout << choose << options;
		setTextColor(PURPLE);
		cin >> chose2;
		setTextColor(WHITE);
		if (chose2 != "Sang" && chose1 != "Kaghaz" && chose1 != "Gheychi"){
			chose2 = wrong_choes(friend_name, chose2);
		}

		//Check the results round i

		//if playe-1 win
		if (chose1 == "Kaghaz" && chose2 == "Sang")
			pp++;

		else if (chose1 == "Sang" && chose2 == "Gheychi")
			pp++;

		else if (chose1 == "Gheychi" && chose2 == "Kaghaz")
			pp++;

		//if player-2 win
		else if (chose2 == "Kaghaz" && chose1 == "Sang")
			fp++;

		else if (chose2 == "Sang" && chose1 == "Gheychi")
			fp++;

		else if (chose2 == "Gheychi" && chose1 == "Kaghaz")
			fp++;
		
		//result
		if (pp > fp){
			cout << "The End of Round " << i << endl << "The winner of this round of the competition is: ";
			setTextColor(BLUE);
			cout << player_name;
			setTextColor(WHITE);
			cout << endl;
			endp++;
		}
		else if (pp < fp){
			cout << "The End of Round " << i << endl << "The winner of this round of the competition is: ";
			setTextColor(BLUE);
			cout << friend_name;
			setTextColor(WHITE);
			cout << endl;
			endf++;
		}

		//if draw
		else if (chose1 == chose2){
			setTextColor(YELLOW);
			cout << endl << ">>> Draw <<<" << endl;
			setTextColor(WHITE);
		}
	}


	cout << endl << "Good Work ";
	cout << player_name;
	cout << " and ";
	cout << friend_name;
	cout << endl;

	//output of this function(Choose winner)
	string winner;

	//if player-1 win
	if (endp > endf){
		cout << endl << "The Winner of this game is: '";
		cout << player_name;
		cout << "' with " << endp << " Points" << endl;
		winner = player_name;
	}

	//if player-2 win
	else if (endp < endf){
		cout << endl << "The Winner of this game is: '";
		cout << friend_name;
		cout << "' with " << endf << " Points" << endl;
		winner = friend_name;
	}

	//if draw
	else if (endp == endf){
		cout << "Nice Try guys. This game have no Winner. ";
		cout << player_name;
		cout << " and ";
		cout << friend_name;
		cout << " is Draw." << endl;
	}
	
	return winner;
}

char choose_type_of_play (string player_name){


//choose type of play
	char type_of_play;
	
	
	do {
	cin >> type_of_play;	
	//play with robot
	if (type_of_play == 'y')
	play_with_me(player_name);
	
	//play with friend
	if (type_of_play == 'n')
	string winner_of_pvp = play_with_friend(player_name);

	//if input is wrong
	if (type_of_play != 'y' && type_of_play != 'n'){
		cout << "I'm Sorry, please Enter y or n: ";
	}

	} while(type_of_play != 'y' && type_of_play != 'n');

	return type_of_play;
}

char choose_type_of_play_again (char play_again){
	while(play_again != 'y' && play_again != 'n'){
		cout << "Dear, Please Enter 'y' or 'n': ";
		cin >> play_again;
	}
	return play_again;
}

string wrong_choes (string playerName, string chose){
	while (chose != "Sang" && chose != "Gheychi" && chose != "Kaghaz"){
		setTextColor(LIGHT_RED);
		cout << playerName << " Dear, Please Enter 'Sang' or 'Kaghaz' or 'Gheychi'." << endl;
		setTextColor(YELLOW);
		cout << "Note that the first letter of each word must be capitalized!" << endl;
		setTextColor(WHITE);
		cout << "According to the mentioned points, please write your choice: ";
		setTextColor(PURPLE);
		cin >> chose;
		setTextColor(WHITE);
	}
	setTextColor(WHITE);
	return chose;
}