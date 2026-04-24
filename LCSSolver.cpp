/***************************************************************
  Student Name: Vansh Sharma
  File Name: LCSSolver.cpp
  Assignment number: 5

 Implements LCS algorithms using full DP and a 2-row optimized 
 approach.
***************************************************************/
#include "LCSSolver.h"
#include <algorithm>

using namespace std;

string LCSSolver::lcsFullTable(const string &X, const string &Y)
{
    int m = (int)X.size();
    int n = (int)Y.size();

    vector< vector<int> > c(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i - 1][j] >= c[i][j - 1])
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i][j - 1];
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (c[i - 1][j] >= c[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int LCSSolver::lcsLength2Row(const string &X, const string &Y)
{
    int m = (int)X.size();
    int n = (int)Y.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                curr[j] = prev[j - 1] + 1;
            else if (prev[j] >= curr[j - 1])
                curr[j] = prev[j];
            else
                curr[j] = curr[j - 1];
        }
        prev = curr;
        fill(curr.begin(), curr.end(), 0);
    }

    return prev[n];
}