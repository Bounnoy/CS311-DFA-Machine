// DFA Recognizer Program
// by Bounnoy Phanthavong & Nick Battalia
//
// This program takes in strings from a file and determines whether or not it's a valid
// floating point number. It will display the results as either pass or fail on each string.

#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
  // Check number of command line parameters.
  if (argc > 2) {
    cerr  << "Too many parameters." << endl
          << "Usage: " << argv[0] << " or " << argv[0] << " filename.txt" << endl;
    return 1;
  }

  // Set filename.
  char filename[100];
  if (argv[1])
    strcpy(filename,argv[1]);
  else
  {
    do
    {
      cout << endl << "Please enter a filename: ";
      cin.get(filename,100,'\n');
      cin.clear();
      cin.ignore(100,'\n');
    } while (strlen(filename) == 0);
  }

  cout << "Filename: " << filename << endl;

  return 0;
}
