/***************************************************************
  Student Name: Vansh Sharma
  File Name: main.cpp
  Assignment number: 5

 Runs the program by computing LCS and generating the similarity table.
 ***************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "LCSSolver.h"
#include "SimilarityTable.h"

using namespace std;

/***************************************************************
 * Function: main
 * Runs the program: computes LCS and prints similarity table.
 ***************************************************************/
int main()
{
    cout << "=============================" << endl;
    cout << "  PART 1: Two-String LCS" << endl;
    cout << "=============================" << endl;

    ifstream fin("twoStrings.txt");
    if (!fin)
    {
        cerr << "Error: cannot open twoStrings.txt" << endl;
        return 1;
    }

    string X, Y;
    getline(fin, X);
    getline(fin, Y);
    fin.close();

    cout << "String 1:" << endl;
    cout << X << endl << endl;

    cout << "String 2:" << endl;
    cout << Y << endl << endl;

    LCSSolver solver;
    string lcs = solver.lcsFullTable(X, Y);

    cout << "LCS (length " << lcs.size() << "):" << endl;
    cout << lcs << endl << endl;

    cout << endl;

    SimilarityTable table;
    table.run("multiStrings.txt");

    return 0;
}