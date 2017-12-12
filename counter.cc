// Griffin Jones
// Character and Line Counter

///
/// @file counter.cc
/// Counts the characters and lines in a text file
///

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int charSize(char *pName);
int countLine(char *pName);
int countChar(char *pName);

///
/// @param argc: The number of command line parameters used
/// @param argv: An array of the command line parameters entered
///
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    cout << countLine ((char *)"Griffin\nJones\nIs\nA\nPerson") << endl;
    cout << countChar ((char *)"Athensss") << endl;
  }

  else if (argc == 2)
  {
    ifstream fin;
    fin.open(argv[1]);

    if (fin.fail())
    {
      cout << "Failed to open";
      return 0;
    }

    char *pName;
    fin >> pName;
    fin.close();

    countLine (pName);
    countChar (pName);
  }

  return 0;
}

///
/// Calculates the size of the character array
/// @param pName: Any character string that needs to be counted
/// @return: the size of the character array
///
int charSize(char *pName)
{
  size_t n = sizeof(pName) / sizeof(pName[0]);
  return n;
}

///
/// Counts the number of lines in the text
/// @param pName: The entire file referenced, or the text "Ohio University"
/// @return: the number of '\n' characters plus one
///
int countLine(char *pName)
{
  int count = 1;
  for (int i = 0; i < charSize(pName); i++)
  {
    if (pName[i] == '\n') count++;
  }
  return count;
}

///
/// Counts the characters in the text
/// @param pName: The entire text file referenced, or the text "Athens"
/// @return: the number of characters in the array (same as charSize)
///
int countChar(char *pName)
{
  return charSize(pName);
}
