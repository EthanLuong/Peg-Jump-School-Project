/* pegJump.cpp

   Author: *** Your name(s) here. ***
   Program: #3, Peg Jump
   CS 141, Spring 2019
 
   Description:
          This program represents a peg jumping puzzle  A
        move is made by a peg jumping over another peg into an empty
        spot, where the jumped peg is then removed from the board. The
        game ends when there are no more valid moves to make. The object
        is to eliminate as many pegs as possible.
				
		Sample output:
		
			Welcome to the peg jump puzzle! 
			Enter '-' to exit, or '+' for instructions. 

							A B C         
							D E F         
					G H I J K L M     
					N O P * Q R S     
					T U V W X Y Z     
							1 2 3         
							4 5 6         

			1. Enter the peg to move: +

			Welcome to the peg jump puzzle. The board starts out with a 
			single blank position, represented by the '*'.  To make a 
			move, select the letter of a peg.  A peg must be able to 
			jump over an adjacent peg into a blank position for a move 
			to be valid.  The jumped peg is then removed from the board. 
			The game is over when there are no valid moves left. At any 
			point enter '-' to exit, or '+' for instructions. 

			1. Enter the peg to move: E

							A B C         
							D * F         
					G H I * K L M     
					N O P E Q R S     
					T U V W X Y Z     
							1 2 3         
							4 5 6         

			2. Enter the peg to move: w

							A B C         
							D * F         
					G H I W K L M     
					N O P * Q R S     
					T U V * X Y Z     
							1 2 3         
							4 5 6         

			3. Enter the peg to move: 5

							A B C         
							D * F         
					G H I W K L M     
					N O P * Q R S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			4. Enter the peg to move: 2
			*** Invalid move, please retry. *** 
			4. Enter the peg to move: r

							A B C         
							D * F         
					G H I W K L M     
					N O P R * * S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			5. Enter the peg to move: R

							* * *         
							* 1 *         
					* * * * * * *     
					* * * + * * *     
					* * * * * * *     
							* 2 *         
							* * *         

			There is more than one possible move.  Which move do you want? 1

							A B C         
							D R F         
					G H I * K L M     
					N O P * * * S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			6. Enter the peg to move: -

			Exiting...

			27 pieces remaining. Ouch!
 */

#include <iostream>
#include <cctype>     // For toupper()
using namespace std;


//-------------------------------------------------------------------------------------
void displayInstructions()
{
    cout << endl
         << "Welcome to the peg jump puzzle. The board starts out with a \n"
         << "single blank position, represented by the '*'.  To make a \n"
         << "move, select the letter of a peg.  A peg must be able to \n"
         << "jump over an adjacent peg into a blank position for a move \n"
         << "to be valid.  The jumped peg is then removed from the board. \n"
         << "The game is over when there are no valid moves left. At any \n"
         << "point enter '-' to exit, or '+' for instructions. \n"
         << endl;
}


//-------------------------------------------------------------------------------------

void displayBoard(char board[]){ //loops and displays board
  int i;
  for(i = 0; i < 120; ++i){
    if(board[i] =='#'){
       cout << "  ";
    }
    if(board[i] != '#'){
      cout << board[i] << ' ';
    }
    if((i+1)%11 == 0){
      cout << endl;
    }
    
  }
  cout << endl;
}

//--------------------------------------------------------------------------------------

int findIndex(char board[], char searchChar){ //Finds index of a character
  int i;
  int index = -1;
  for(i = 0; i < 120; ++i){
    if (board[i] == searchChar){
      index = i;
      break;
    }
  }
  
  return index;
}
//--------------------------------------------------------------------------------------
int checkValidMove(char board[], int index){ //Returns a unique number for each possible moves. Returns 0 if there is no possible move
  int temp = 0;
// *** Arvan: Follow the DRY (“Don’t Repeat Yourself) principle.
// *** Arvan: Don't use hard coded values
  if(board[index - 2] == '*'){
    if(board[index - 1] != '*'){
      temp += 1;
    }
    
  }
  if(board[index - 22] == '*'){
    if(board[index - 11] != '*'){
      temp += 10;
    }
  }
  if(board[index + 2] == '*'){
    if(board[index + 1] != '*'){
      temp += 100;
    }
  }
  if(board[index + 22] == '*'){
    if(board[index + 11] != '*'){
      temp += 1000;
    }
  }
  if(board[index] == '*' || board[index] == '#'){
    temp = 0;
  }
  
  return temp;
}

//--------------------------------------------------------------------------------------
int checkBoard(char board[]){  //Returns number of remaining pegs
  int i;
  int pegs = 0;
  for(i = 0; i < 121; i++){
    if(board[i] != '#' && board[i] != '*'){
      pegs += 1;
    }
  }
  return pegs;
}

//---------------------------------------------------------------------------------------

void makeMove(char board[], int index, int targetIndex){ //Handles making a move. 
  char currPiece = board[index];
  board[targetIndex] = currPiece;
  board[index + ((targetIndex - index) / 2)] = '*';
  board[index] = '*';
}

int main()
{
    //Variable declarations
    int turnNumber = 1;
    char userInput;
    int index;
    int movePiece;
    int i;
  
    char board[] = {
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','A','B','C','#','#','#','#',
            '#','#','#','#','D','E','F','#','#','#','#',
            '#','#','G','H','I','J','K','L','M','#','#',
            '#','#','N','O','P','*','Q','R','S','#','#',
            '#','#','T','U','V','W','X','Y','Z','#','#',
            '#','#','#','#','1','2','3','#','#','#','#',
            '#','#','#','#','4','5','6','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#'
          };
    
    cout << "Welcome to the peg jump puzzle! \n"
         << "Enter '-' to exit, or '+' for instructions. "
         << endl;
     
    displayBoard(board); 
    // Main loop to play the game
    while(true){
        // Prompt for and get move
        
        cout << turnNumber << ". Enter the peg to move: ";
        cin >> userInput;
        userInput = toupper(userInput);
      
        // Check for '-' to exit, and '+' for displaying instructions
				if(userInput == '-'){
          cout << "Exiting..." << endl;
          break;
        }
        else if(userInput == '+'){
          displayInstructions();
          continue;
        }
     
        index = findIndex(board, userInput);  //Finds index of input char
        movePiece = checkValidMove(board, index); //Assigns unique number based on number and type of possible moves
      
        // Check if move is valid
				if(movePiece == 0 || index == -1){
          cout << "*** Invalid move, please retry. *** " << endl;
          continue;
        }
      
// *** Arvan: Don't use hard coded values
// *** Arvan: This section could have been done using functions.
         if(movePiece - 1 != 0 && movePiece - 10 != 0 && movePiece - 100 != 0 && movePiece - 1000 != 0){
          //TODO: add multiple moves
          int temp = 49; //ascii for 1
          char multipleMoveNumber;
          int multipleMoveIndex;
          
          char multipleBoard[] = { //Resets board each time this is called
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','*','*','*','#','#','#','#',
            '#','#','#','#','*','*','*','#','#','#','#',
            '#','#','*','*','*','*','*','*','*','#','#',
            '#','#','*','*','*','*','*','*','*','#','#',
            '#','#','*','*','*','*','*','*','*','#','#',
            '#','#','#','#','*','*','*','#','#','#','#',
            '#','#','#','#','*','*','*','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#',
            '#','#','#','#','#','#','#','#','#','#','#'
          };
          
          multipleBoard[index] = '+';
          
// *** Arvan: Don't use hard coded values
          if(movePiece % 100 >= 10){           //Places numbers in possible move slots
            multipleBoard[index - 22] = temp;
            temp += 1;   
          }
          if (movePiece % 10 >= 1){
            multipleBoard[index - 2] = temp;
            temp += 1;
          }
          if(movePiece % 1000 >= 100) {
            multipleBoard[index + 2] = temp;
            temp += 1;
          }
          if(movePiece % 10000 >= 1000){
            multipleBoard[index + 22] = temp;   
          }
          
          while(true){
            displayBoard(multipleBoard);
            cout << "There is more than one possible move.  Which move do you want? ";
            cin >> multipleMoveNumber;
            cout << endl;
            
            if(multipleMoveNumber > temp){  //Checks if input is valid
              cout << "Invalid move" << endl;
              continue;
            }
            
            multipleMoveIndex = findIndex(multipleBoard, multipleMoveNumber);
            makeMove(board, index, multipleMoveIndex);
            break;
          }   
        }
        else {
          switch(movePiece){    //Makes move based on possible move
// *** Arvan: Don't use hard coded values
            case 1:
              makeMove(board, index, index - 2);
              break;
            case 10:
              makeMove(board, index, index - 22);
              break;
            case 100:
              makeMove(board, index, index + 2);
              break;
            case 1000:
              makeMove(board, index, index + 22);
              break;
          }
        }
				// Increment move number and display the board
				turnNumber += 1;
				displayBoard(board);
        //Check if there are any valid moves left breaks loop if there isn't
        bool validMovesLeft = false;
        for(i = 0; i < 121; i++){
          if(checkValidMove(board,i) != 0){
            validMovesLeft = true;
          }    
        }
        if (!validMovesLeft){
          break;
        }
    }
  

    cout << endl << checkBoard(board) << " pieces remaining. ";      //Check pieces remaining and display end message
    switch(checkBoard(board)){
      case 1:
        cout << "Excellent!";
        break;
      case 2:
        cout << "Good!";
        break;
      case 3:
        cout << "OK.";
        break;
      case 4:
        cout << "Needs Improvement.";
        break;
      default:
        cout << "Ouch!";
        break;
    }
    
    cout << endl;
  
    return 0;
}//end main()