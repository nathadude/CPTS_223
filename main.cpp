/*
CPTS223 - PA1 - Nathaniel Anderson
First, I would like to apologize as my ability to code in C++ is not up to par, so this is unfinished.
I figured I would turn something in rather than nothing, thank you.

ADVANTAGES/DISADVANTAGES LINKED LIST:
Welcome to my matching game! In this project you will have to match linux commands with their respective definitions, via multiple choice.
This project uses a singly linked list to load all commands and definitions into the game. Linked lists are useful in many ways, but do not come without their caveats. 
One advantage of a linked list is they are dynamic, meaning you do not need to specify the size before hand. This also means they can grow and shrink at command!
One downside to this though is that traversal is difficult and not as intuitive. Because linked lists do not support random access this makes it difficult to traverse/search
the list quickly and efficiently. This affects our program adversely in that it is less inuitive to search for the commands in the list to present to the user, thus making
process time longer.

ADVANTAGES/DISADVANTAGES ARRAY:
This project also uses an array to store the profiles of the players in order to save and load games. 
The array is handy for a quick solution to make a space to store multiple data entries, as well as making easy to index through the array and 
grab values. For the sake of our project it works quite well for what it needs to do, with a few downsides of course.
Because the size of the array is pre-determined it is not ideal in the case that you do not know for sure how many data entries you will have.
In our case, we do not know for certain how many people or how many times people will create a profile.
This makes it hard to predict how big our array is supposed to be initially, thus leading to the chance of wasting memory.
*/

#include <iostream>
#include <fstream>
#include "cassert"
#include "LinkedList.h"

using namespace std;

void gameRules();
void playGame(int points);
void removeCommand();

Stack<LinuxComm, string> linkedList; //list is constructed for the reading of the csv file
int profiles[20]; //where the profiles will be stored
LinuxComm command; //construction of the command class


int main()
{
   
    //This is where we load commands and definitions into the nodes as we build a list
    ifstream fin;
    fin.open("commands.csv");
    assert(!fin.fail());

    do {

        fin >> command;
        linkedList.push(command, command.getCommand()); //Nodes are being created by using the command.csv contents
        
    } while (!fin.eof());
    //close and clearing the file to keep it clean
    fin.close();
    fin.clear();

    bool exitCheck = false;
    do
    {
        int option;

        cout << "Welcome to the Matching Game!" << endl
            << "Type in a number followed by the enter key to pick one of these options: \n"
            << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n"
            << endl;

        cin >> option;

        //menu switch for when the user enters a number to pick from the menu
        switch (option) {
        case 1: gameRules();
            break;

        case 2: playGame(0);
            break;

        case 3: //This is where i'd put my load file function
            break;

        case 4: //This is where I'd put my addCommand function
            break;

        case 5: removeCommand();
            break;

        case 6: /*linkedList.clear();*/ exitCheck = true; cout << "Have a nice day! :)";
            break;

        //default for when the user does not enter a valid option
        default:
            cout << "Sorry, " << option << " is not a valid option. Please try entering a number 1 - 6"; 
        }
    } while (exitCheck == false);
}

void gameRules() //where the game rules are output
{
    cout << "*GAME RULES*\nThe rules are simple:\nYou will be shown a command from a list of Linux commands.\n"
        "You must then pick one of three options to define the shown command.\n"
        "If you get it right, you get +1 points! :)\n"
        "If you get it wrong, you get -1 points... :(\n"
        "But do not fret as the game will carry on either way!\n"
        "Good luck! ;)\n";
}

void playGame(int points)
{
    string playerName;
    cout << "Please enter player name: ";
    cin >> playerName;

    cout << "Hello, " << playerName << ", sorry to say this game is unfinished..." << endl;
}

void removeCommand()
{
    string searchTerm;
    cout << endl << "Please enter the command you wish to remove: " << endl;
    cin >> searchTerm;
    //linkedList.search(searchTerm);
}