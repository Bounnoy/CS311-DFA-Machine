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
  int accept1 = 2, accept2 = 3, accept3 = 5, accept4 = 8;

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
        cout << "\t \t Accept" << endl;
      else
        cout << "\t \t Reject" << endl;

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
      if (input - '0' >= 0 && input - '0' <= 9) return 2;
      if (input == '+' || input == '-') return 1;
      if (input == '.') return 3;
      break;
    case 1:
      if (input - '0' >= 0 && input - '0' <= 9) return 2;
      if (input == '.') return 4;
      break;
    case 2:
      if (input - '0' >= 0 && input - '0' <= 9) return 2;
      if (input == '.') return 3;
      break;
    case 4:
      if (input - '0' >= 0 && input - '0' <= 9) return 5;
      break;
    case 3:
    case 5:
      if (input - '0' >= 0 && input - '0' <= 9) return 5;
      if (input == 'e'|| input == 'E') return 7;
      break;
    case 7:
      if (input - '0' >= 0 && input - '0' <= 9) return 8;
      if (input == '+'|| input == '-') return 9;
      break;
    case 8:
    case 9:
      if (input - '0' >= 0 && input - '0' <= 9) return 8;
      break;
  }

  return 10;
}
