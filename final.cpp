/* David P. Lopez
   Final Project
   COP1334
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void squarePattern(int side);
void squareFILLPattern(int side);
void xPattern(int size);
void XFILLPattern(int side);
void circlePattern(int circle_radius);
void circleFILLPattern(int circle_radius);
void compoundXPattern(int side);
void FILLEDCompoundXPattern(int side);

void addtochoices(int input);
void givemostusedfunction();


//define variables & pointer for counter, array, and top choices
int counter = 0;
int arraysize = 2;
int *choicearray;
int max1 = 0;
int max2 = 0;
int max1shape = -1;
int max2shape = -1;

int main()
{
	//create new array to hold top choices by user
	choicearray = new int[arraysize];

	//declare filestream variables to output to file
	ofstream outFile;

	//Declare Variables
	int input;
	int side;
	int size;
	int fill;

	//Enumerate Shapes
	enum Shapes {SQUARE, X, CIRCLE, XSQUARE, TERMINATE};

	//Declare enum variables
	Shapes Square = SQUARE;
	Shapes xX = X;
	Shapes Circle = CIRCLE;
	Shapes CompoundX = XSQUARE;
	Shapes CloseProgram = TERMINATE;


	//open output files
	outFile.open("FinalOUTPUT.txt");

	//Loop Menu
	while(true)
	{
		cout << endl;
		cout << "Welcome to my Final Project." << endl;
		cout << "Please choose a shape from my Enum menu below:" << endl;
		cout << endl;
		//enumeration menu
		cout << static_cast<int>(Square + 1) << ") Square" << endl;
		cout << static_cast<int>(xX + 1) << ") X Pattern" <<  endl;
		cout << static_cast<int>(Circle + 1) << ") Circle" <<  endl;
		cout << static_cast<int>(CompoundX + 1) << ") Compund X inside of a Square" <<  endl;
		cout << static_cast<int>(CloseProgram + 1) << ") Terminate Program" << endl;
		cout << endl;
		cout << "Your selection is item number: ";

		//read user input
		cin >> input;
		cout << endl;
		cout << endl;


		/*i spent 4 hours trying to build a while loop to validate the input data that for some reason was not being handled by the default case in my switch statement only to learn......
		that i had the .clear and the .ignore functions reversed. The order they are in below is correct and this now functions well for validation
		I am including this validation with the while loop validation i created below for redundancy to ensure I earn 100% on this project!! :)
		In the interest of learning to write more efficient code, I would like feedback on which method is the best way to handle the validation of the input data.
		*/

		
		while(!cin >> input)
		{
			cout << "...You have caused a MAJOR MALFUNCTION..." << endl;
			cout << "Please enter an integer between 1 and 5 to execute the Program: ";
			cin >> input;

			cin.clear();
			cin.ignore(100, '\n');
		}
		

		/*
		I CANNOT FIGURE OUT HOW TO HANDLE/VALIDATE INPUT INTEGERS BETWEEN 6 & 11111111111

		ANYTIME AN INPUT IS ENTERED WHICH BEGINS WITH AN INT OF 1 THE PROGRAM GETS CONFUSED AND THINKS THE USER IS SELECTING 1 WHICH RESULTS IN THE...
		PROGRAM NOT KNOWING HOW TO HANDLE THE REMAINING DIGITS.

		HOWEVER, ONCE YOU ENTER A CONSECUTIVE SET OF INT'S OF 1, BEYOND THE RANGE OF A TYPE INT, SUCH AS 1111111111111111111111111... THEN THE PROGRAM 
		VALIDATES THE DATA AS AN INPUT NOT OF TYPE INT AND THE PROGRAM OPERATES AS NORMAL.....
		*/

		switch(input)
			{

			case 1: //Calls pattern function for square
				cout << "Enter a positive integer to determine the size\n";
				cout << "of the sides of the square.\n\n";
				cin >> side;

				cout << "Do you want a FILLED Square? Enter '1' for YES or '2' for NO:\n";
				cout << endl;
				cout << "Your selection to FILL this shape is: "; 
				cin >> fill;
				cout << endl;
				cout << endl;

				if (cin && fill == 1) //fills pattern
					if (side > 75 || side < 5) //validates data and makes sure input stays within the correct parameter
						squareFILLPattern(20); //sets data to an acceptable input
					else
						squareFILLPattern(side);
				else if (cin && fill == 2)
					if (side > 75 || side < 5)//validates data and makes sure input stays within the correct parameter
						squarePattern(20); //sets data to an acceptable input
					else
						squarePattern(side);
				else
				{
					cin.sync();
					cin.clear();
				}
				addtochoices(1); //calls function for #1 selection
				break;


			case 2: //Calls pattern function for X
				cout << "Enter an integer to determine the size of the X pattern: " << endl;
				cin >> size;

				cout << "Do you want a FILLED X Pattern? Enter '1' for YES or '2' for NO:\n";
				cout << endl;
				cout << "Your selection to FILL this shape is: "; 
				cin >> fill;
				cout << endl;
				cout << endl;

				if (cin && fill == 1) //fills pattern
					XFILLPattern(size);
				else if (cin && fill == 2)
				{
					if(size > 55 || size <= 1)//validates data and makes sure input stays within the correct parameter
					{
						size = 10; //sets the data to an acceptable parameter
						cout << "Your size input exceeded our predefined max values." << endl;
						cout << "Your default size is 10." << endl;
						cout << endl;
					}

					if(size % 2 == 0) //makes sure the center of the X is perfect
					{
						xPattern(size + 1);	
					}
					else
						xPattern(size);				
				}
				else
				{
					cin.sync();
					cin.clear();
				}
				addtochoices(2); //calls function for #2 selection
				break;


			case 3: //Calls pattern function for Circle
				cout << "Enter a positive integer Greater than 6 and smaller than 30," << endl;
				cout << "to determine the Radius of the Circle: " << endl;
				cin >> size;

				cout << "Do you want a FILLED Circle? Enter '1' for YES or '2' for NO:\n";
				cout << endl;
				cout << "Your selection to FILL this shape is: "; 
				cin >> fill;
				cout << endl;
				cout << endl;

				if(size > 30 || size <= 7) //validates data and makes sure input stays within the correct parameter
					{
						size = 15; //sets data to a valid input
						cout << "Your size input exceeded our predefined max values." << endl;
						cout << "Your default size is 15." << endl;
						cout << endl;
					}

				if (cin && fill == 1) //fills the shape
					circleFILLPattern(size);
				else if (cin && fill == 2)
					circlePattern(size);
				else
				{
					cin.sync();
					cin.clear();
				}
				addtochoices(3); //calls function for #3 selection
				break;


			case 4: //Calls pattern function with X inside of a Square
				cout << "Enter an integer between 1 and 35 to determine the size\n";
				cout << "of the sides of the square.\n\n";
				cin >> side;

				cout << "Do you want a FILLED Compound Pattern? Enter '1' for YES or '2' for NO:\n";
				cout << endl;
				cout << "Your selection to FILL this shape is: "; 
				cin >> fill;
				cout << endl;
				cout << endl;

				if(side > 35 || side <= 1) //validates data and makes sure input stays within the correct parameter
					{
						side = 15; //sets to a valid input only if orignial input is outside of the expected parameters
						cout << "Your size input exceeded our predefined max values." << endl;
						cout << "Your default size is 15." << endl;
						cout << endl;
					}

				if (cin && fill == 1) //fills the shape
					FILLEDCompoundXPattern(side);
				else if (cin && fill == 2)
					if(side % 2 == 0)
					{
						compoundXPattern(side + 1);	
					}
					else
						compoundXPattern(side);
				else
				{
					cin.sync();
					cin.clear();
				}
				addtochoices(4); //calls function for #4 selection
				break;

			case 5: //Terminates Program

				//calls function and reports most used selections
				givemostusedfunction();

				cout << "Top Shape Selected:      " << max1shape+1 << " Qty of Selections: " << max1 << endl;
				cout << "2nd Most Shape Selected: " << max2shape+1 << " Qty of Selections: " << max2 << endl;
				outFile << "Top Shape Selected:      " << max1shape+1 << " Qty of Selections: " << max1 << endl;
				outFile << "2nd Most Shape Selected: " << max2shape+1 << " Qty of Selections: " << max2 << endl;
				
				return 0; 
				break;

			//any erroneous input that gets through data validation in function is handled here	
			default:
				cin.sync(); //i spent 4 hours trying to build a while loop to validate this data that for some reason was not being handled by this default only to learn......
				cin.clear(); //that i had the .clear and the .ignore functions reversed. The order they are in is correct and this now functions well for validation
				cin.ignore(10, '\n'); //I am including this validation with the while loop validation i created above for redundancy to ensure I earn 100% on this project!! :)
				break;
			}		

	}

	//close file
	outFile.close();

	return 0;
}

//Square Pattern
void squarePattern(int side)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

	for (int row = 1; row <= side; row++)
	{
		for (int col = 1; col <= side; col++)
		{
			if (row > 1 && row < side && col > 1 && col < side)
			{	
				cout << " ";
				outFile << " ";
			}
			else
			{
				cout << "*";//prints square
				outFile << "*";
			}
		}		
		cout << "\n";
		outFile << "\n";
	}
}

//Square Filled Pattern
void squareFILLPattern(int side)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

	for (int row = 1; row <= side; row++)
	{
		for (int col = 1; col <= side; col++)
		{
			if (row > 1 && row < side && col > 1 && col < side)
			{
				cout << "*"; //Fills interior of Square
				outFile << "*";
			}
			else
			{
				cout << "*";
				outFile << "*";
			}
		}		
		cout << "\n";
		outFile << "\n";
	}
}


//X pattern
void xPattern(int size)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

	for(int rows = 1; rows <= size; rows++)
    {
    	for(int cols = 1; cols <= size; cols++)
    	{
    		if(rows == cols || cols == (size + 1) - rows)
    		{
    			cout << "*"; // prints X
    			outFile << "*";
    		}
    		else 
    		{
    			cout << " ";
    			outFile << " ";
    		}
    	}
    	cout << endl;
    	outFile << endl;
    }
}

//X Filled Pattern
void XFILLPattern(int side)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);	

	for (int row = 1; row <= side; row++)
	{
		for (int col = 1; col <= side; col++)
		{
			if (row > 1 && row < side && col > 1 && col < side)
			{
				cout << "*"; //Fills interior of X
				outFile << "*";
			}
			else
			{
				cout << "*";
				outFile << "*";
			}
		}		
		cout << "\n";
		outFile << "\n";
	}
}


//Circle Pattern
void circlePattern(int circle_radius)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

    int radius = circle_radius;
    float console_ratio = 4.0/3.0;
    float a = console_ratio * radius;
    float b = radius;

    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -console_ratio * radius; x <= console_ratio * radius; x++)
        {
            float d = (x/a) * (x/a) + (y/b) * (y/b);

			if (d > 0.90 && d < 1.1) //circumfence of circle to fill within radius edge
            {
            	cout << "*";
            	outFile << "*";
            }
            else
            {
            	cout << " ";
            	outFile << " ";
            }
        }
        cout << endl;
        outFile << endl;
    }
}

//Circle FILLED Pattern
void circleFILLPattern(int circle_radius)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

    int radius = circle_radius;
    float console_ratio = 4.0/3.0;
    float a = console_ratio * radius;
    float b = radius;

    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -console_ratio * radius; x <= console_ratio * radius; x++)
        {
            float d = (x/a) * (x/a) + (y/b) * (y/b);

            if (d >= 0 && d < .9) //filled circle conditional to fill from center to outer boundary
            {
            	cout << "*";
            	outFile << "*";
            }
            else
            {
            	cout << " ";
            	outFile << " ";
            }
        }
        cout << endl;
        outFile << endl;
    }
}


//Compound Square with X
void compoundXPattern(int side)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

	for (int row = 0; row <= side; row++)
	{
		for (int col = 1; col <= side; col++) 
		{
			//Square manipulator
			if (row > 0 && row < side && col > 1 && col < side)
			{
				cout << " ";
				outFile << " ";
			}
			else
			{
				cout << "*";
				outFile << "*";
			}

			//X manipulator
			if(row > 0 && col > 0 && col < side && row < side && (row == col || col == side  - row))
			{
    			cout << "*";
    			outFile << "*";
    		}
    		else 
    		{
    			cout << " ";  
    			outFile << " ";				
    		}

		}		
		cout << "\n";
		outFile << "\n";
	}	
}

//Filled Compound Pattern
void FILLEDCompoundXPattern(int side)
{
	//declare filestream variables to output to file
	ofstream outFile;
	//open output files
	outFile.open("FinalOUTPUT.txt", fstream::app);

	for (int row = 1; row <= side; row++)
	{
		for (int col = 1; col <= side; col++)
		{
			if (row > 1 && row < side && col > 1 && col < side)
			{
				cout << "*"; //Fills interior of Square
				outFile << "*";
			}
			else
			{
				cout << "*";
				outFile << "*";
			}
		}		
		cout << "\n";
		outFile << "\n";
	}
}


//Array Function
void addtochoices(int input)
{
	if (counter + 1 > arraysize)
	{
		int *temp = new int[arraysize]; //creates new temporary array to hold values

		arraysize *= 2; //doubles the size of the array called in main to store values held in temp array

		for (int i = 0;i < counter; i++) //iterates through array & copies values to temp array
		{
			temp[i] = choicearray[i];
			//cout << "Copying from array to temp : " << temp[i] << endl;
		}

		choicearray = new int[arraysize]; //creates new array to hold choices transferred from temp array

		for (int i = 0; i < counter; i++) //iterates through temp array and copies to array
		{
			//cout << "Copying from temp to array : " << temp[i] << endl;
			choicearray[i] = temp[i];
		}
	}

	cout << endl;
	cout << endl;
	cout << "Shape Selection: " << input << endl; //out puts data inputted
	cout << endl;

	choicearray[counter] = input; //assigns input to array

	counter++;
}

//outputs the selection most used that is stored in array
void givemostusedfunction()
{
	int choicecounters[] = {0,0,0,0};

	for (int i = 0; i < counter; i++) //iterates through the shapes with the highest selections in choicearray[]
	{
		choicecounters[choicearray[i] - 1]++;
	}

	for (int i = 0; i < 4; i++) //iterates through the array of values
	{
		if (choicecounters[i] > max1 && choicecounters[i] > max2) //tests for largest values of i
		{			
			max2 = max1;
			max2shape = max1shape;
			max1 = choicecounters[i];
			max1shape = i;//assigns most used shape to max2shape
		}		
		else if (choicecounters[i] < max1 && choicecounters[i] > max2)
		{			
			max2 = choicecounters[i];
			max2shape = i;
		}		
		else if (choicecounters[i] > max2)
		{
			max2 = choicecounters[i];
			max2shape = i; //assigns 2nd most used shape to max2shape
		}		
	}
}
