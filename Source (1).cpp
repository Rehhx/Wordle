/**************************************************************
* Programmer Name: Emanuel && Peter
* File Name:  startBattle.cpp
* Date of Last Modification:  12/8/21
* Description: The game battleship, made as a functioning file
			   for Visual Studio for Project 5.
**************************************************************/
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;


//Declaration of Variables, such as grid, ship size and valid inputs//
const char battleShip = 'B';
const char water = 'w';
const int GRID_SIZETOP = 12;
const int GRID_SIZELEFT = 12;
int biggestShip = 5;
int lessBig = 4;
int crusierShip = 3;
int subramineShip = 3;
int destroyerShip = 2;
char userPosition;
int userValid = 0;


//Print the grid on the screen - This is intended for the first player - The ships beyond this point are also for the first player//
void fillGrid(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void fillGrid2(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void fillGrid3(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void fillGrid4(char grid[GRID_SIZELEFT][GRID_SIZETOP]);

//function to print the grid - Both the first and second players board and the scoring board//
void printGrid(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void printGrid2(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void printGrid3(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void printGrid3(char grid[GRID_SIZELEFT][GRID_SIZETOP]);
void printGrid4(char grid[GRID_SIZELEFT][GRID_SIZETOP]);


//Function to print things onto the grid for both players - this time with ships, and also their valid placements//
int validAirCraft(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, const char battleShip, int valid);
void placeAircraft(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, const char battleShip);
int validBattleship(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int BattleShip, char userPosition, const char battleShip, int valid);
void placeBattleship(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int BattleShip, char userPosition, const char battleShip);
int validCruiser(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int cruiserShip, char userPosition, const char battleShi, int valid);
void placeCruiser(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int curiser, char userPosition, const char battleShip);
int validSubramine(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShi, int valid);
void placeSubramine(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShip);
int validDestroyer(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip, int valid);
void placeDestroyer(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip);

//Second Players ships with valid checking//
void placeAircraft2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, const char battleShip);
int validAircraft2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, const char battleShip, int valid);
void placeBattleship2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int BattleShip, char userPosition, const char battleShip);
int validBattleship2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int BattleShip, char userPosition, const char battleShip, int valid);
void placeCruiser2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int curiser, char userPosition, const char battleShip);
int validCruiser2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int crusierShip, char userPosition, const char battleShip, int valid);
void placeSubramine2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShip);
int validSubramine2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShi, int valid);
void placeDestroyer2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip);
int validDestroyer2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip, int valid);

int main(void) {
	//Starting screen - Getting ready to play battleship.//
	cout << "Welcome to BattleShip!!" << endl;
	cout << "You will also want to enlarge the command window this is on as well!" << endl;
	Sleep(2000);
	cout << "Player One Please be ready to place down the ships" << endl;
	Sleep(7000);
	char theSea[GRID_SIZELEFT][GRID_SIZETOP];
	fillGrid(theSea);
	printGrid(theSea);
	int shipRow = 0;
	int shipCol = 0;
	//Player Ones placement screen//
	cout << "To place down your ships Please Enter the Row and Column of where you want your ship to be at. " << endl;
	cout << "This will be done by you entering your chosen row, pressing the Enter key, and then doing the same for the column of your choice" << endl;
	cout << "On the Left hand Side are the rows and on the top is the Columns." << endl;
	cout << "Place the AirCraft Carrier (This ship needs 5 free spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow;
	cout << "Enter a Column:";
	cin >> shipCol;

	//Checking for valid input location for ship//
	while ((shipRow <= 0) || (shipCol <= 0) || (shipRow > 10) || (shipCol > 10)) {
		cout << "Invalid Row or Column! Enter a row again:";
		cin >> shipRow;
		cout << "Now Enter the Column:";
		cin >> shipCol;
	}
	//Choosing cardinal direction//
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West:";

	cin >> userPosition;
	userValid = 0;

	userValid = validAirCraft(theSea, shipRow, shipCol, biggestShip, userPosition, battleShip, userValid);

	while (userValid <= 0) {
		//Output in case of data being invalid//
		cout << "Invalid Position! Please Enter a diffrent position:";
		cin >> userPosition;
		userValid = validAirCraft(theSea, shipRow, shipCol, biggestShip, userPosition, battleShip, userValid);
	
	}
	placeAircraft(theSea, shipRow, shipCol, biggestShip, userPosition, battleShip);

	printGrid(theSea);
	cout << "Place the BattleShip. (This ship needs 4 free spaces in a straight line.)";
	cout << "Enter a row:";
	cin >> shipRow;
	cout << "Enter a Column:";
	cin >> shipCol;

	while ((shipRow <= 0) || (shipCol <= 0) || (shipRow > 10) || (shipCol > 10)) {
		//Invalid location Output//
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow;
		cout << "Now Enter the Column:";
		cin >> shipCol;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validBattleship(theSea, shipRow, shipCol, biggestShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {
		//Invalid output for positioning//
		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validBattleship(theSea, shipRow, shipCol, biggestShip, userPosition, battleShip, userValid);
		cout << userValid << endl;
	}
	//Puts battleship on the screen//
	placeBattleship(theSea, shipRow, shipCol, lessBig, userPosition, battleShip);
	printGrid(theSea);

	cout << "Place the Cruiser. (This ship needs 3 free spaces in a straight line.)";
	cout << "Enter a row:";
	cin >> shipRow;

	cout << "Enter a Column:";
	cin >> shipCol;

	while ((shipRow <= 0) || (shipCol <= 0) || (shipRow > 10) || (shipCol > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow;
		cout << "Now Enter the Column:";
		cin >> shipCol;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validCruiser(theSea, shipRow, shipCol, crusierShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {
		//Invalid location for cruiser output//
		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validCruiser(theSea, shipRow, shipCol, crusierShip, userPosition, battleShip, userValid);
	}
	placeCruiser(theSea, shipRow, shipCol, crusierShip, userPosition, battleShip);
	printGrid(theSea);
	//Placing Submarine for Player One//
	cout << "Place the Subramine Ship(This ship needs 3 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow;

	cout << "Enter a Column:";
	cin >> shipCol;
	while ((shipRow <= 0) || (shipCol <= 0) || (shipRow > 10) || (shipCol > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow;
		cout << "Now Enter the Column:";
		cin >> shipCol;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validSubramine(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {

		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validSubramine(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip, userValid);
	}
	placeSubramine(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip);
	printGrid(theSea);
	//Placment of Destroyer for Player One//
	cout << "Placing the Destroyer Ship (This Ship needs 2 spaces in a straight line.)";
	cout << "Enter a row:";
	cin >> shipRow;

	cout << "Enter a Column:";
	cin >> shipCol;
	while ((shipRow <= 0) || (shipCol <= 0) || (shipRow > 10) || (shipCol > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow;
		cout << "Now Enter the Column:";
		cin >> shipCol;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validDestroyer(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {
		//Invalid position output//
		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validDestroyer(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip, userValid);
	}
	placeDestroyer(theSea, shipRow, shipCol, subramineShip, userPosition, battleShip);

	//Prints all the ships onto the grid the final time and 'saves' it//
	printGrid(theSea);
	//PLAYER 2 WAIT TIME AND TRANSITION//
	system("CLS");
	cout << "Please Hand the Device to Player Two" << endl;
	cout << "In 5 seconds, player two will be able to place their ships." << endl;
	Sleep(5000);
	cout << "Player two, you may now place your ships!";
	Sleep(500);
	system("CLS");

	//Print Grid 2nd player - (This is where the ships with a 2 at the end are used) //
	char theSea2[GRID_SIZELEFT][GRID_SIZETOP];
	fillGrid2(theSea2);
	printGrid2(theSea2);
	int shipRow2 = 0;
	int shipCol2 = 0;
	cout << "To place down your ships Please Enter the Row and Column of where you want your ship to be at. " << endl;
	cout << "This will be done by you entering your chosen row, pressing the Enter key, and then doing the same for the column of your choice" << endl;
	cout << "On the Left hand Side are the rows and on the top is the Columns." << endl;
	cout << "Placing the AirCraft Carrier (This ship needs 5 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow2;

	cout << "Enter a Column:";
	cin >> shipCol2;
	while ((shipRow2 <= 0) || (shipCol2 <= 0) || (shipRow2 > 10) || (shipCol2 > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow2;
		cout << "Now Enter the Column:";
		cin >> shipCol2;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;

	cin >> userPosition;
	userValid = 0;
	userValid = validAircraft2(theSea2, shipRow2, shipCol2, biggestShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {
		//Invalid direction output//
		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validAircraft2(theSea2, shipRow2, shipCol2, biggestShip, userPosition, battleShip, userValid);
	}
	placeAircraft2(theSea2, shipRow2, shipCol2, biggestShip, userPosition, battleShip);
	printGrid2(theSea2);
	cout << "Placing the BattleShip  (This ship needs 4 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow2;

	cout << "Enter a Column:";
	cin >> shipCol2;
	while ((shipRow2 <= 0) || (shipCol2 <= 0) || (shipRow2 > 10) || (shipCol2 > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow2;
		cout << "Now Enter the Column:";
		cin >> shipCol2;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;

	// West Doesnt work on battleship//
	// solution just copy and paste what I did in player one!!//
	userValid = validBattleship2(theSea2, shipRow2, shipCol2, lessBig, userPosition, battleShip, userValid);
	while (userValid <= 0) {

		 cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validBattleship2(theSea2, shipRow2, shipCol2, biggestShip, userPosition, battleShip, userValid);
	}
	placeBattleship2(theSea2, shipRow2, shipCol2, lessBig, userPosition, battleShip);
	printGrid2(theSea2);

	//Placement of Cruiser for Player Two//
	cout << "Placing the Cruiser (This ship needs 3 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow2;

	cout << "Enter a Column:";
	cin >> shipCol2;
	while ((shipRow2 <= 0) || (shipCol2 <= 0) || (shipRow2 > 10) || (shipCol2 > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow2;
		cout << "Now Enter the Column:";
		cin >> shipCol2;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validCruiser2(theSea2, shipRow2, shipCol2, crusierShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {

		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validCruiser2(theSea2, shipRow2, shipCol2, crusierShip, userPosition, battleShip, userValid);
	}
	placeCruiser2(theSea2, shipRow2, shipCol2, crusierShip, userPosition, battleShip);
	printGrid2(theSea2);

	//Placement of Submarine for Player Two//
	cout << "Placing the Subramine (This ship needs 3 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow2;

	cout << "Enter a Column:";
	cin >> shipCol2;
	while ((shipRow2 <= 0) || (shipCol2 <= 0) || (shipRow2 > 10) || (shipCol2 > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow2;
		cout << "Now Enter the Column:";
		cin >> shipCol2;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validSubramine2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {
		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validSubramine2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip, userValid);
	}
	placeSubramine2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip);
	printGrid2(theSea2);

	//Placement of Destroyer for Player Two//
	cout << "Placing the Destroyer Ship (This ship needs 2 spaces in a straight line.)";
	cout << "Enter a Row:";
	cin >> shipRow2;

	cout << "Enter a Column:";
	cin >> shipCol2;
	while ((shipRow2 <= 0) || (shipCol2 <= 0) || (shipRow2 > 10) || (shipCol2 > 10)) {
		cout << "Invalid Row or Column! Enter a row  again:";
		cin >> shipRow2;
		cout << "Now Enter the Column:";
		cin >> shipCol2;
	}
	cout << "Do you want it Place North, East, South or West of your input" << endl;
	cout << "Please Enter N for North, E for East, S for South , W for West" << endl;
	cin >> userPosition;
	userValid = 0;
	userValid = validDestroyer2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip, userValid);
	while (userValid <= 0) {

		cout << "Invalid Position! Please Enter a diffirent position:";
		cin >> userPosition;
		userValid = validDestroyer2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip, userValid);
	}
	placeDestroyer2(theSea2, shipRow2, shipCol2, subramineShip, userPosition, battleShip);

	printGrid2(theSea2);
	char theSea3[GRID_SIZELEFT][GRID_SIZETOP];
	char theSea4[GRID_SIZELEFT][GRID_SIZETOP];
	fillGrid3(theSea3); // player one
	fillGrid4(theSea4); // player two 
	//Booleans for True/False for player victories, as well as other variables for keeping score//
	bool victory1 = false;
	bool victory2 = false;
	char hit = 'H';
	char miss = 'M';
	int user1Hit = 0;
	int user2Hit = 0;

	system("CLS");
	cout << "Please Hand the Device to Player one" << endl;
	cout << "Player One please wait" << endl;
	Sleep(3000);
	/*--------------- Older Comments -----------------*/
	// (theSea[GRID_SIZELEFT][GRID_SIZETOP] == 'B'
	// (theSea2[GRID_SIZELEFT][GRID_SIZETOP] == 'B'
	// make sperate valid checks because they overlap!!
	// fix the while loop because it isn't working 

	/**************************************************************
* Programmer Name:Peter 
* Description:Shooting your missles until someone sinks 
**************************************************************/
	//Loop to keep fighting until all ships have been hit - Also swaps between first and second player//
	while ((user1Hit <= 16) && (user2Hit <= 16)) {
		cout << "Admiral (Player One), Be Prepared to launch your attack!";
		cout << endl;
		Sleep(2000);
		printGrid3(theSea3);
		
		cout << "Enter a row and Column to shoot at. ";
		cin >> shipRow >> shipCol;
		if (theSea3[shipRow][shipCol] == 'H') {
			cout << "Enter a Diffrent Row and Column; You already shot that area Admiral!" << endl;
			cin >> shipRow >> shipCol;
			Sleep(1000);
		}
		if (theSea2[shipRow][shipCol] == 'B') {
			cout << "You scored a direct hit on the enemy!";
			theSea3[shipRow][shipCol] = hit;
			theSea2[shipRow][shipCol] = 'w';
			user1Hit = user1Hit + 1;

			Sleep(1000);
		}

		else {
			cout << "It appears our attack on that sector had poor intelligence Admiral, as no enemy was seen or hit in that engagement!" << endl;
			Sleep(1000);
			theSea3[shipRow][shipCol] = miss;
		}
		printGrid3(theSea3);
		
		Sleep(1000);
		system("CLS");
		cout << "Give Device to Player two" << endl;
		cout << "Player two Please wait" << endl;
		Sleep(1000);
		system("CLS");

		//Switches over from player ones grid to player twos//
		cout << "Admiral (Player Two), Be Prepared to launch your attack!" << endl;
		
		Sleep(2000);
		printGrid4(theSea4);
		cout << "Enter a row and Column to shoot at. ";
		cin >> shipRow >> shipCol;
		if (theSea4[shipRow][shipCol] == 'H') {
			cout << "Enter a Diffrent Row and Column; You already shot that area Admiral!" << endl;
			cin >> shipRow >> shipCol;
		}
		if (theSea[shipRow][shipCol] == 'B') {
			cout << "You scored a direct hit on the enemy!";
			theSea4[shipRow][shipCol] = hit;
			theSea[shipRow][shipCol] = 'S';
			user2Hit = user2Hit + 1;

			Sleep(1000);
		}

		else {
			cout << "It appears our attack on that sector had poor intelligence Admiral, as no enemy was seen or hit in that engagement!" << endl;
			theSea4[shipRow][shipCol] = miss;
			Sleep(1000);
		}
		
		Sleep(2000);
		printGrid4(theSea4);
		
		system("CLS");

		cout << "Give the device to Player One." << endl;
		Sleep(2000);
	}
	if (user1Hit >= 17) {
		cout << "Congratulations, Player One Won!" << endl;
		cout << "You have sank all of Player's Two Ships" << endl;
		
	}
	else if (user2Hit >= 17) {
		cout << "Congratulations, Player Two Won!" << endl;
		cout << "You have sank all of Player's One Ships" << endl;
	
	}
	return 0;
}

// fill the sea with "water"
/**************************************************************
* Programmer Name:Emanuel 
* Description:Fill the Grid 
**************************************************************/
void fillGrid(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	for (int i = 0; i < GRID_SIZELEFT; i++) {

		for (int j = 0; j < GRID_SIZETOP; j++) {
			grid[0][1] = '1';
			grid[0][2] = '2';
			grid[0][3] = '3';
			grid[0][4] = '4';
			grid[0][5] = '5';
			grid[0][6] = '6';
			grid[0][7] = '7';
			grid[0][8] = '8';
			grid[0][9] = '9';
			grid[0][10] = '10';
			grid[1][0] = '1';
			grid[2][0] = '2';
			grid[3][0] = '3';
			grid[4][0] = '4';
			grid[5][0] = '5';
			grid[6][0] = '6';
			grid[7][0] = '7';
			grid[8][0] = '8';
			grid[9][0] = '9';
			grid[10][0] = '10';
			grid[11][1] = '-';
			grid[11][2] = '-';
			grid[11][3] = '-';
			grid[11][4] = '-';
			grid[11][5] = '-';
			grid[11][6] = '-';
			grid[11][7] = '-';
			grid[11][8] = '-';
			grid[11][9] = '-';
			grid[11][10] = '-';
			grid[11][11] = '|';
			grid[1][11] = '|';
			grid[2][11] = '|';
			grid[3][11] = '|';
			grid[4][11] = '|';
			grid[5][11] = '|';
			grid[6][11] = '|';
			grid[7][11] = '|';
			grid[8][11] = '|';
			grid[9][11] = '|';
			grid[10][11] = '|';
			grid[11][11] = '|';


			if ((i > 0) && (i <= 10)) {
				grid[i][j] = water;

			}
		}
	}
}

//print the grid on the screen
void printGrid(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	system("CLS");
	for (int row = 0; row < GRID_SIZELEFT; row++) {
		for (int col = 0; col < GRID_SIZETOP; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}

}


/**************************************************************
* Programmer Name:Emanuel
* Description: All the int valid Ships check if its invalid or not for the position of the ship 
* The void functions places the ships 
**************************************************************/
int validAirCraft(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, char battleShip, int userValid) {
	int validRow = row;
	int validCol = col;

	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 0; i < aircraftCarrier; ++i) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}

		}




	}



	else if (userPosition == 'S') {

		for (int i = 0; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}


		}
	}
	else if (userPosition == 'E') {

		for (int i = 0; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}

		}


	}
	else if (userPosition == 'W') {

		for (int i = 0; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}


		}
	}







	return userValid;
}
void placeAircraft(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, char battleShip) {
	string notValid = "Input Not Valid ";

	if (userPosition == 'N') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			if (row < 1) {


			}
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}
int validBattleship(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int BattleShip, char userPosition, const char battleShip, int valid) {
	int validRow = row;
	int validCol = col;

	userValid = 1;
	if (userPosition == 'N') {
		for (int i = 0; i < BattleShip; i++) {
			if (i >= 2) {
				validRow = validRow - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}

	else if (userPosition == 'S') {
		for (int i = 0; i < BattleShip; i++) {
			if (i >= 2) {
				validRow = validRow + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < BattleShip; i++) {
			if (i >= 2) {
				validCol = validCol + 1;
			}
		
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	else if (userPosition == 'W') {

		
		for (int i = 0; i < BattleShip; i++) {
			if (i >= 2) {
				validCol = validCol - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	return userValid;
}


void placeBattleship(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int realBattleShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;
		}
	}
	else if (userPosition == 'S') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}

int validCruiser(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int cruiserShip, char userPosition, const char battleShi, int valid) {
	int validRow = row;
	int validCol = col;

	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 0; i < crusierShip; i++) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}


		}





	}
	


	else if (userPosition == 'S') {

		for (int i = 0; i < cruiserShip; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'E') {

		for (int i = 0; i < cruiserShip; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {

		for (int i = 0; i < cruiserShip; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}

			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}







	return userValid;
}
void placeCruiser(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int curiserShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < curiserShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}
int validSubramine(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShi, int valid) {
	int validRow = row;
	int validCol = col;

	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 0; i < subramineShip; i++) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}





	}



	else if (userPosition == 'S') {

		for (int i = 0; i < subramineShip; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'E') {

		for (int i = 0; i < subramineShip; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {

		for (int i = 0; i < subramineShip; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}


	return userValid;
}
void placeSubramine(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}

}
int validDestroyer(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip, int valid) {
	int validRow = row;
	int validCol = col;

	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 0; i < destroyerShip; i++) {
			if (i >= 2) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}



		}




	}



	else if (userPosition == 'S') {

		for (int i = 0; i < destroyerShip; i++) {
			if (i >= 2) {
				validRow = validRow + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}
	else if (userPosition == 'E') {

		for (int i = 0; i < destroyerShip; i++) {
			if (i >= 2) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {

		for (int i = 0; i < destroyerShip; i++) {
			if (i >= 2) {
				validCol = validCol - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}


	return userValid;
}

void placeDestroyer(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}

}

//Draw the grid and fill the spaces valid for ships with water//
void fillGrid2(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	for (int i = 0; i < GRID_SIZELEFT; i++) {

		for (int j = 0; j < GRID_SIZETOP; j++) {
			grid[0][1] = '1';
			grid[0][2] = '2';
			grid[0][3] = '3';
			grid[0][4] = '4';
			grid[0][5] = '5';
			grid[0][6] = '6';
			grid[0][7] = '7';
			grid[0][8] = '8';
			grid[0][9] = '9';
			grid[0][10] = '10';
			grid[1][0] = '1';
			grid[2][0] = '2';
			grid[3][0] = '3';
			grid[4][0] = '4';
			grid[5][0] = '5';
			grid[6][0] = '6';
			grid[7][0] = '7';
			grid[8][0] = '8';
			grid[9][0] = '9';
			grid[10][0] = '10';
			grid[11][1] = '-';
			grid[11][2] = '-';
			grid[11][3] = '-';
			grid[11][4] = '-';
			grid[11][5] = '-';
			grid[11][6] = '-';
			grid[11][7] = '-';
			grid[11][8] = '-';
			grid[11][9] = '-';
			grid[11][10] = '-';
			grid[11][11] = '|';
			grid[1][11] = '|';
			grid[2][11] = '|';
			grid[3][11] = '|';
			grid[4][11] = '|';
			grid[5][11] = '|';
			grid[6][11] = '|';
			grid[7][11] = '|';
			grid[8][11] = '|';
			grid[9][11] = '|';
			grid[10][11] = '|';
			grid[11][11] = '|';

			if ((i > 0) && (i <= 10)) {
				grid[i][j] = water;
			}
		}
	}
}

//Print the grid on the screen - This is intended for the second player - The ships beyond this point (labeled with a 2) are also the second player//
void printGrid2(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	system("CLS");
	for (int row = 0; row < GRID_SIZELEFT; row++) {
		for (int col = 0; col < GRID_SIZETOP; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}
//Cardinal Directions for Aircraft Carrier - Checking to ensure valid location//
int validAircraft2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, char battleShip, int valid) {
	int validRow = row;
	int validCol = col;
	userValid = 1;
	if (userPosition == 'N') {
		for (int i = 1; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'S') {
		for (int i = 1; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'E') {
		for (int i = 1; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'W') {

		for (int i = 1; i < aircraftCarrier; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	return userValid;
}
//Cardinal Directions for Aircraft Carrier//
void placeAircraft2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int aircraftCarrier, char userPosition, char battleShip) {
	string notValid = "Input Not Valid ";

	if (userPosition == 'N') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			if (row < 1) {

			}
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < aircraftCarrier; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}
//Cardinal Directions for Battleship - Checking to ensure valid location//
int validBattleship2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int realBattleShip, char userPosition, const char battleShip, int valid) {
	int validRow = row;
	int validCol = col;
	userValid = 1;
	if (userPosition == 'N') {
		for (int i = 1; i < realBattleShip; i++) {
			if (i >= 2) {
				validRow = validRow - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}

	else if (userPosition == 'S') {
		for (int i = 1; i < realBattleShip; i++) {
			if (i >= 2) {
				validRow = validRow + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	else if (userPosition == 'E') {
		for (int i = 1; i < realBattleShip; i++) {
			if (i >= 2) {
				validCol = validCol + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	else if (userPosition == 'W') {
	
		for (int i = 1; i < realBattleShip; i++) {
			if (i >= 2) {
				validCol = validCol - 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol > 10) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	return userValid;
}
//Cardinal Directions for Battleship//
void placeBattleship2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int realBattleShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;
		}
	}
	else if (userPosition == 'S') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < realBattleShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}
//Cardinal Directions for cruiser - Checking to ensure valid location//
int validCruiser2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int crusierShip, char userPosition, const char battleShip, int valid) {
	int validRow = row;
	int validCol = col;
	userValid = 1;
	if (userPosition == 'N') {
		for (int i = 1; i < crusierShip; i++) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {
				userValid = 0;
			}
		}
	}
	else if (userPosition == 'S') {
		for (int i = 1; i < crusierShip; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'E') {
		
		for (int i = 1; i < crusierShip; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {
		
		for (int i = 1; i < crusierShip; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;
			}
		}
	}
	return userValid;
}
//Cardinal Directions for cruiser//
void placeCruiser2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int curiserShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < curiserShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;
		}
	}
	else if (userPosition == 'S') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < crusierShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}
}
//Cardinal Directions for submarine - Checking to ensure valid location//
int validSubramine2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShi, int valid) {
	int validRow = row;
	int validCol = col;
	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 1; i < subramineShip; i++) {
			if (i >= 1) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}





	}



	else if (userPosition == 'S') {

		for (int i = 1; i < subramineShip; i++) {
			if (i >= 1) {
				validRow = validRow + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'E') {

		for (int i = 1; i < subramineShip; i++) {
			if (i >= 1) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {

		for (int i = 1; i < subramineShip; i++) {
			if (i >= 1) {
				validCol = validCol - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}


	return userValid;
}
//Cardinal Directions for submarine//
void placeSubramine2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int subramineShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 0; i < subramineShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}

}
//Cardinal Directions for second destroyer class ship - Checking to ensure a valid location//
int validDestroyer2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip, int valid) {
	int validRow = row;
	int validCol = col;
	userValid = 1;
	if (userPosition == 'N') {

		for (int i = 1; i < destroyerShip; i++) {
			if (i >= 2) {
				validRow = validRow - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}
	}
	else if (userPosition == 'S') {

		for (int i = 1; i < destroyerShip; i++) {
			if (i >= 2) {
				validRow = validRow + 1;
			}
			if ((validRow > 10) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}
	else if (userPosition == 'E') {

		for (int i = 1; i < destroyerShip; i++) {
			if (i >= 2) {
				validCol = validCol + 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}
		}

	}
	else if (userPosition == 'W') {

		for (int i = 1; i < destroyerShip; i++) {
			if (i >= 2) {
				validCol = validCol - 1;
			}
			if ((validRow >= 11) || (validRow <= 0) || (validCol >= 11) || (validCol <= 0)) {

				userValid = 0;

			}

		}
	}


	return userValid;
}
//Cardinal Directions for second destroyer class ship//
void placeDestroyer2(char grid[GRID_SIZELEFT][GRID_SIZETOP], int row, int col, int destroyerShip, char userPosition, const char battleShip) {
	if (userPosition == 'N') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			row = row - 1;

		}

	}
	else if (userPosition == 'S') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			row = row + 1;
		}
	}
	else if (userPosition == 'E') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			col = col + 1;
		}
	}
	else if (userPosition == 'W') {
		for (int i = 1; i < destroyerShip; i++) {
			grid[row][col] = battleShip;
			col = col - 1;
		}
	}

}

//Printing scoring board for player one//
void printGrid3(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	system("CLS");
	for (int row = 0; row < GRID_SIZELEFT; row++) {
		for (int col = 0; col < GRID_SIZETOP; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}

}

//Printing scoring board for player two//
void printGrid4(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	system("CLS");
	for (int row = 0; row < GRID_SIZELEFT; row++) {
		for (int col = 0; col < GRID_SIZETOP; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}

}

//Drawing of a 10 x 10 grid - 11 by 11 including row and column labels and borders.//
void fillGrid3(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	for (int i = 0; i < GRID_SIZELEFT; i++) {

		for (int j = 0; j < GRID_SIZETOP; j++) {
			grid[0][1] = '1';
			grid[0][2] = '2';
			grid[0][3] = '3';
			grid[0][4] = '4';
			grid[0][5] = '5';
			grid[0][6] = '6';
			grid[0][7] = '7';
			grid[0][8] = '8';
			grid[0][9] = '9';
			grid[0][10] = '10';
			grid[1][0] = '1';
			grid[2][0] = '2';
			grid[3][0] = '3';
			grid[4][0] = '4';
			grid[5][0] = '5';
			grid[6][0] = '6';
			grid[7][0] = '7';
			grid[8][0] = '8';
			grid[9][0] = '9';
			grid[10][0] = '10';
			grid[11][1] = '-';
			grid[11][2] = '-';
			grid[11][3] = '-';
			grid[11][4] = '-';
			grid[11][5] = '-';
			grid[11][6] = '-';
			grid[11][7] = '-';
			grid[11][8] = '-';
			grid[11][9] = '-';
			grid[11][10] = '-';
			grid[11][11] = '|';
			grid[1][11] = '|';
			grid[2][11] = '|';
			grid[3][11] = '|';
			grid[4][11] = '|';
			grid[5][11] = '|';
			grid[6][11] = '|';
			grid[7][11] = '|';
			grid[8][11] = '|';
			grid[9][11] = '|';
			grid[10][11] = '|';
			grid[11][11] = '|';


			if ((i > 0) && (i <= 10)) {
				grid[i][j] = water;

			}
		}
	}
}

//Drawing of a 10 x 10 grid - 11 by 11 including row and column labels and borders.//
void fillGrid4(char grid[GRID_SIZELEFT][GRID_SIZETOP]) {
	for (int i = 0; i < GRID_SIZELEFT; i++) {

		for (int j = 0; j < GRID_SIZETOP; j++) {
			grid[0][1] = '1';
			grid[0][2] = '2';
			grid[0][3] = '3';
			grid[0][4] = '4';
			grid[0][5] = '5';
			grid[0][6] = '6';
			grid[0][7] = '7';
			grid[0][8] = '8';
			grid[0][9] = '9';
			grid[0][10] = '10';
			grid[1][0] = '1';
			grid[2][0] = '2';
			grid[3][0] = '3';
			grid[4][0] = '4';
			grid[5][0] = '5';
			grid[6][0] = '6';
			grid[7][0] = '7';
			grid[8][0] = '8';
			grid[9][0] = '9';
			grid[10][0] = '10';
			grid[11][1] = '-';
			grid[11][2] = '-';
			grid[11][3] = '-';
			grid[11][4] = '-';
			grid[11][5] = '-';
			grid[11][6] = '-';
			grid[11][7] = '-';
			grid[11][8] = '-';
			grid[11][9] = '-';
			grid[11][10] = '-';
			grid[11][11] = '|';
			grid[1][11] = '|';
			grid[2][11] = '|';
			grid[3][11] = '|';
			grid[4][11] = '|';
			grid[5][11] = '|';
			grid[6][11] = '|';
			grid[7][11] = '|';
			grid[8][11] = '|';
			grid[9][11] = '|';
			grid[10][11] = '|';
			grid[11][11] = '|';


			if ((i > 0) && (i <= 10)) {
				grid[i][j] = water;

			}
		}
	}
}