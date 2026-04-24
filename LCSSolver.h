/***************************************************************
  Student Name: Vansh Sharma
  File Name: LCSSolver.h
  Assignment number: 5

 Declares the LCSSolver class and its functions for computing LCS.
***************************************************************/
#ifndef LCSSOLVER_H
#define LCSSOLVER_H

#include <string>
#include <vector>

using namespace std;

class LCSSolver
{
public:
    string lcsFullTable(const string &X, const string &Y);
    int lcsLength2Row(const string &X, const string &Y);
};

#endif