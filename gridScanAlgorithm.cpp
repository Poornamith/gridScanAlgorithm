/*
===================================================================================
		Program for GRID FOLLOWING ROBOT
===================================================================================

*works with EVEN x-co-ordinates grids only.
*Snake mode
	 _   _   _   _
	| | | | | | | |
	| | | | | | | |
	| | | | | | | |
	| | | | | | | |
	| | | | | | | |
	| |_| |_| |_| |
	^	      x

===================================================================================
							(copywrite) © Poornamith
									the PAH inv
									2015-10-01
						www.poornamith.azurewebsites.net
===================================================================================
*/

#include <iostream>
#include <conio.h>

using namespace std;


//grid co-ordinates
unsigned short x = 10, y = 7;

//robot co-ordinates
short newX = 0, newY = 0;

//display
void display(int valNewX, int valNewY);

//movements
void locomotion(int valNewX, int valNewY);
void leftTurn();	//90degree turns
void rightTurn();
void forward();
void reverse();
void stop();

void main()
{
	/*	grid follow
		(x,y)
		start co-ordinate (0,0)

		end co-oridnate (x-1,0)	 or		(x-1,y-1)
						(even,even)		(odd,odd)

		right turn (x varies ,y-1)

		left turn (x varies ,0)
	*/

	for (newX = 0; newX < x; newX++)
	{
		//upwards loop
		if (((newX + 1) % 2))
		{
			for (newY = 0; newY < y; newY++)
			{
				//sensor grabs a junction
				display(newX, newY);
				/*
				if(a node)
					write in EEPROM
				*/
				locomotion(newX, newY);
			}
		}
		//downwards loop
		else
		{
			for (newY = (y-1); newY >= 0; newY--)
			{
				//sensor grabs a junction
				display(newX, newY);
				/*
				if(a node)
					write in EEPROM
				*/
				locomotion(newX, newY);
			}
		}
		cout << endl;
	}
	cout << "\n\nEND OF SCAN\n\n";

	//goto the (0,0) co-ordinate
	//if x-even matrix
	newY = 0;
	rightTurn();
	cout << endl;
	for (newX = (x - 2); newX >= 0; newX--)
	{
		//sensor grabs a junction
		display(newX, newY);
		if ((newX == 0) && (newY == 0))
		{
			leftTurn();
			stop();
		}
		else
			forward();
	}


	cout << "\n\nEND";

	getch();
}


//display co-ordinates
void display(int valNewX, int valNewY)
{
	cout << "(" << valNewX << "," << valNewY << ")";
}

//movements handler
void locomotion(int valNewX, int valNewY)
{
	if (valNewY == (y - 1))
		rightTurn();
	else if ((valNewX == (x - 1)) && (valNewY == 0)) //only for x-even
		stop();
	else if ((valNewX != 0) && (valNewY == 0))
		leftTurn();

	else
		forward();
}
void leftTurn()
{
	cout << " LEFT ";
}
void rightTurn()
{
	cout << " RIGHT ";
}
void forward()
{
	cout << " FW ";
}
void reverse()
{
	cout << " RV ";
}
void stop()
{
	cout << " STOP ";
}
