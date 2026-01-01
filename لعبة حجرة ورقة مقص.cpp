#include<iostream>
using namespace std;
enum enchoices { stone = 1,paper=2,scissor=3 };
int randomnumber(int from,int to)
{
	int random = 0;
	random = rand() % (to - from + 1) + from;
	return random;
}
int askround()
{
	int round;
	do {
		cout << "how many rounds from 1 to 10" << endl;
		cin >> round;
	} while (round < 1 || round>10);
	
	return round;
}
int computerchoice()
{
	int comp= randomnumber(1, 3);
	return comp;
}
void printroundresults( int playerchoice,int comp)
{

	
	
		if (playerchoice == enchoices::stone)
		{
			cout << "player choice: " << "stone" << endl;
			cout << "comuter choice: " << comp;
			cout << endl;

		}
		else if (playerchoice == enchoices::paper)
		{
			cout << "player choice: " << "Paper" << endl;
			cout << "comuter choice: " << comp;
			cout << endl;

		}
		else if (playerchoice== enchoices::scissor)
		{
			cout << "player choice: " << "Scissors" << endl;
			cout << "computer choice: " << comp;
			cout << endl;

		}

}
void roundwinner(int playerchoice, int comp, int& wontimes, int& losetimes, int& drawtimes)
{

	if (playerchoice == enchoices::paper && comp == 1)
	{
		system("color 2f");
		cout << "round winner  :[plyer]" << endl;
		wontimes++;
	}
	else if (playerchoice == comp)
	{
		system("color 6f");
		cout << "round winner  :[no winner]" << endl;
		drawtimes++;
	}
	else if (playerchoice == enchoices::paper && comp == 3)
	{
		system("color 4f");
		cout << "\a";
		cout << "round winner  :[comuter]" << endl;
		losetimes++;
	}

	else if (playerchoice == enchoices::stone && comp == 2)
	{
		system("color 4f");
		cout << "\a";
		cout << "round winner  :[comuter]" << endl;
		losetimes++;
	}
	else if (playerchoice == enchoices::stone && comp == 3)
	{
		system("color 2f");
		cout << "round winner  :[player]" << endl;
		wontimes++;
	}
	else if (playerchoice == enchoices::scissor && comp == 1)
	{
		system("color 4f");
		cout << "\a";
		cout << "round winner  :[comuter]" << endl;
		losetimes++;
	}
	else if (playerchoice == enchoices::scissor && comp == 2)
	{
		system("color 2f");
		cout << "round winner  :[player]" << endl;
		wontimes++;
	}
}
void chosefrom1to3(int& round, int playerchoice[10],int& wontimes,int& losetimes,int& drawtimes)
{
	for (int i = 0;i < round;i++)
	{
		do {
				cout << "round:[" << i + 1 << "] begins" << endl;
				cout << "your choice: [1]Stone. [2]Paper. [3]Scissors " << endl;
				cout << "____________round  [" << i + 1 << "]_______________" << endl;
				cin >> playerchoice[i];
				
		} while (playerchoice[i] < 1 || playerchoice[i]>3);
		int comp = computerchoice();
		printroundresults(playerchoice[i], comp);
		roundwinner(playerchoice[i],comp, wontimes, losetimes, drawtimes);
	}
	
}

void gameover(int round, int wontimes, int losetimes,int drawtimes)
{
	cout << "__________________________________________________________" << endl;
	cout << "                      ***Game Over***                     " << endl;
	cout << "____________________________________________________________" << endl;
	cout << "_______________________(Game Results)_______________________" << endl;
	cout << "Game rounds        :" << round << endl;
	cout << "player won times   :" << wontimes << endl;
	cout << "computer won times :" << losetimes << endl;
	cout << "draw times         :" << drawtimes << endl;
	if (wontimes > losetimes)
	{
		cout << "final winner       :" << "player" << endl;
	}
	else if (losetimes > wontimes )
	{
		cout << "final winner       :" << "computer" << endl;
	}
	else 
	{
		cout << "final winner       :" << "no winner" << endl;
	}
}
void startgame()
{
	system("color 07");
	
	int playerchoice[10];
	int wontimes = 0, losetimes = 0, drawtimes = 0;
	int round = askround();
	

	chosefrom1to3(round, playerchoice, wontimes, losetimes, drawtimes);
	
	gameover(round, wontimes, losetimes, drawtimes);


}
int main()
{
	srand((unsigned)time(NULL));
	
	char playagain ;
	do {
		startgame();
		cout << "do you want to play again? (Y/N) " << endl;
		cin >> playagain;

	} while (playagain == 'y' || playagain == 'Y');
	
		cout << "game finished" << endl;
	
}