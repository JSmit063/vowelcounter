/*

Vowel Counter Program
By Justin Smith
ITCS 2530 V0801

This program is executed in the command line. The user enters the program name and a file name of their choosing. 
The program runs through the file and check for vowel characters, both uppercase and lowercase and adds them up. It
then outputs the totals for each vowel and the total of all vowels.

There is some commented out code at the bottom that was used for debugging purposes and writing the program.

*/

#include <fstream> // Used for file input/output
#include <string> // Used for string variable
#include <iostream> // Need for input/output streams
#include <iomanip> // Format Manipulation of output

using namespace std;

int main(int argc, char *argv[])
{
    // Variable initialization
    int vowelA = 0;
    int vowelE = 0;
    int vowelI = 0;
    int vowelO = 0;
    int vowelU = 0;
    char c;
    string fileName;
    fileName = argv[1];

    ifstream fs; // file stream variable

    fs.open(fileName); // Open file input/output

    
    if (!fs) // Check to see if file opens ok
    {
        cout << "Could not open file. Program is exiting" << endl; // If file not open, exit the program
        system("pause");
        return -1;
    }

    cout << setw(80) << left << setfill('#') << "#" << endl;
    cout << setw(21) << left << setfill('#') << "#";
    cout << "  Welcome to my Letter Count Program  ";
    cout << setw(21) << right << setfill('#') << "#" << endl;
    cout << setw(80) << left << setfill('#') << "#" << endl << endl;

    cout << "Analyzing file '" << fileName << "'..." << endl << endl; // Outputs the name of the file the program is using

    // This while loop will iterate until the end of file is reached
    // Inputs the character read from the file into char c in the expression
    // Everytime one of the characters specified is found, increment the appropriate variable
    while (!fs.eof() && fs >> c)
    {
        
        // If / else structure to increment our found characters.
        if (c == 'A' || c == 'a')
            vowelA++;
        else if (c == 'E' || c == 'e')
            vowelE++;
        else if (c == 'I' || c == 'i')
            vowelI++;
        else if (c == 'O' || c == 'o')
            vowelO++;
        else if (c == 'U' || c == 'u')  
            vowelU++;
    }
    
    // The block of code below uses format manipulators to show output of the totals for each variable
    cout << setw(80) << left << setfill('.');
    cout << "The number of A's: " << vowelA << endl;
    cout << setw(80) << left << setfill('.');
    cout << "The number of E's: " << vowelE << endl;
    cout << setw(80) << left << setfill('.');
    cout << "The number of I's: " << vowelI << endl;
    cout << setw(80) << left << setfill('.');
    cout << "The number of O's: " << vowelO << endl;
    cout << setw(80) << left << setfill('.');
    cout << "The number of U's: " << vowelU << endl;
    cout << setw(80) << left << setfill('.');
    // Show the totals for all variables added up
    // I was going to assign the totals in a separate statement but decided to do it in the output as I do not need to do anything else with the total amount
    cout << "The vowel count is: " << vowelA + vowelE + vowelI + vowelO + vowelU << endl;
    
    // Close the file stream
    fs.close();

    system("pause");
    
    return 0;

    /*
    Code unused in the final program

    // const string FILE_NAME = "Constitution_of_the_United_States.txt";

    // For Debugging 
    }
    for (int i = 0; i < argc; i++)
    {
        cout << i << ":" << argv[i] << endl;
    }
    */
}


