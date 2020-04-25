// Source Link --> https://www.gamedev.net/forums/topic/644428-simple-console-based-minesweeper-game/

#include <iostream>
#include <vector>
#include <queue>




#include "Game.h" 

int main(){
	
	srand(time(NULL));
	
	//sets mines and number values
	array place;

	//alias tracks reveals location
	array alias;

	
	//Generate Array
	for(int i = 0; i < w; i++)
	{	

		place.push_back(vector<char>(h, 'o'));
		alias.push_back(vector<char>(h, '-'));
	}
	int mineCount = 0;


	//to distribute mines
	do
	{

		if(spread(place))
			mineCount++;
	}while(mineCount != m);


	int w_in, h_in;
	do
	{
		//Aliased
		cout << "   0123456789" << endl;
		cout << "   ||||||||||" << endl;

		//loop through rows
		for(int i = 0; i < w; i++)
		{
			//output row indices
			cout << i << " /";

			//loop through columns
			for(int j = 0; j < h; j++)
			{

				if(alias[i][j] == '-')
					cout << '-';
				else
					cout << place[i][j];
			}
			cout << endl;
		}

		//User input
		cout << "Test Location x" << endl;  
		cin >> w_in; 
		cout << "Test Location y" << endl; 
		cin >> h_in;
		
		
		//flip the location input
		if(flip(place, alias, w_in, h_in))
		{
			cout << "o,.....,o , Game Over!" << endl;
			 break;
		}

		//test win
		if(countalias(alias) == m)
		{
			cout << "You win, Congratulations!" << endl;
			break;
		}

	}while(1);

	place.clear();
	alias.clear();

	cout << endl;
	
}