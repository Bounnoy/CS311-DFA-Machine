// DFA Recognizer Program
// by Bounnoy Phanthavong & Nick Battalia
//
// This program takes in strings from a file and determines whether or not it's a valid
// floating point number. It will display the results as either pass or fail on each string.

#include <iostream>
#include <fstream>
using namespace std;

int transition(int q, char input);

int main(int argc, char * argv[])
{
  // Initial state.
  int q = 0;

  // List of accept states.
  int accept1 = 3, accept2 = 4, accept3 = 6, accept4 = 9;

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

  // Load file.
  ifstream file;
  file.open(filename);

  // Check if file exists.
  if (file.fail())
  {
    cerr << endl << "Error retrieving file." << endl;
    return 1;
  }

  // Read file.
  char input;

  while (file >> input)
  {
    q = transition(q, input);

    cout << input;

    if (file.peek() == '\n')
    {
      // Check if string ends in accept state.
      if (q == accept1 || q == accept2 || q == accept3 || q == accept4)
        cout << "\t \t Pass" << endl;
      else
        cout << "\t \t Fail" << endl;

      file.ignore();
      q = 0; // Go back to initial state.
    }
  }

  // Close file.
  file.close();

  return 0;
}

// Transition function for the DFA.
int transition(int q, char input)
{
  // Each case represents being in that state.
  switch (q)
  {
    case 0:
      if (input - '0' >= 0 && input - '0' <= 9) return 3;
      if (input == '+') return 2;
      if (input == '-') return 1;
      if (input == '.') return 4;
      break;
    case 1:
    case 2:
      if (input - '0' >= 0 && input - '0' <= 9) return 3;
      if (input == '.') return 5;
      break;
    case 3:
      if (input - '0' >= 0 && input - '0' <= 9) return 3;
      if (input == '.') return 4;
      break;
    case 4:
    case 5:
    case 6:
      if (input - '0' >= 0 && input - '0' <= 9) return 6;
      if (input == 'e') return 7;
      if (input == 'E') return 8;
      break;
    case 7:
    case 8:
      if (input - '0' >= 0 && input - '0' <= 9) return 9;
      if (input == '+') return 10;
      if (input == '-') return 11;
      break;
    case 9:
    case 10:
    case 11:
      if (input - '0' >= 0 && input - '0' <= 9) return 9;
      break;
  }

  return 12;
}
