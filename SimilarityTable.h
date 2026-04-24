/***************************************************************
  Student Name: Vansh Sharma
  File Name: SimilarityTable.h
  Assignment number: 5

 Declares the SimilarityTable class for comparing multiple strings.
***************************************************************/
#ifndef SIMILARITYTABLE_H
#define SIMILARITYTABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "LCSSolver.h"

using namespace std;

class SimilarityTable
{
public:
    void run(const string &filename);

private:
    LCSSolver solver;
    vector<streampos> offsets;

    void buildIndex(const string &filename, int numStrings);
    string getStringAt(const string &filename, int index);
    char getRating(const string &A, const string &B);
    void printTable(const string &filename, int numStrings);
};

#endif