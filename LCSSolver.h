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