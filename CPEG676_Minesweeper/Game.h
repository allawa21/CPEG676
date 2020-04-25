


#include <iostream>
#include <vector>
using namespace std;

/*--------------
w-> width, h -> height, m->mines
'*'-> mine , 'o',-> empty, '1'-> one neighbouring mine
i-> row index, j-> column index, ii-> adjacet row index, jj->adjacent column index
----------------
*/

const int w = 10, h = 10, m = 6;



//a vector of vector array
typedef vector<vector<char> > array;



//Spreads mines, returs true if placed, and false if not.
bool spread(array& place){
	
	//Generate random location
	int i = rand() % w, j = rand() % h;
	
	
	//Tests if mine is added
	if(place[i][j] != '*')
	{
		place[i][j] = '*';
		
		
		//sets number values for adjacent cells
		for(int ii = i-1; ii <= i+1; ii++)
			for(int jj = j-1; jj <= j+1; jj++)
			
			
				if(ii >= 0 && ii < w && jj >= 0 && jj < h)
					if(place[ii][jj] != '*') 
						if(place[ii][jj] == 'o')
							place[ii][jj] = '1'; //adjacent initial incdex = 1
					
						else
						
							place[ii][jj]++; //adjacent index iteration
							
		return true;
	}
	//Location contains a mine
	return false;
}



//Flips location
bool flip(array& place, array& alias, int i, int j)
{
	
	//test for mine
	if(place[i][j] == '*')
		return true;

	if(place[i][j] == 'o'){
		
		
		//to hold cells that are not adjacent to a mine
		queue<pair<int, int> > free_space;
		free_space.push(make_pair(i, j));



		while(!free_space.empty())
		{
			//next location in queue
			pair<int, int> next = free_space.front();
			
			//To itereate adjacent cells
			for(int ii = next.first-1; ii <= next.first+1; ii++)
			{	for(int jj = next.second-1; jj <= next.second+1; jj++)
				{
					
					//test if adjacent cell is within border
					if(ii >= 0 && ii < w && jj >= 0 && jj < h)
					{	
						
						//add adjacent to queue to be flipped
						if(place[ii][jj] == 'o' && alias[ii][jj] == '-')
							
							free_space.push(make_pair(ii, jj));


					alias[ii][jj] = 'o';

					}
				}
			}
			free_space.pop();
		}
	}

	return false;
}




/*counts wether reamining unflipped are mines, 
if all are mines then it is a win case
*/
int countalias(array& alias){
	
	int count = 0;
	
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
		
		
			if(alias[i][j] == '-') count++;

	return count;
}