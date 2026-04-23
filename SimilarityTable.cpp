#include "SimilarityTable.h"
#include <iostream>
#include <iomanip>

using namespace std;

void SimilarityTable::run(const string &filename)
{
    ifstream fin(filename.c_str());
    if (!fin)
    {
        cerr << "Error: cannot open " << filename << endl;
        return;
    }

    int n;
    fin >> n;
    fin.close();

    cout << "=============================" << endl;
    cout << "  PART 2: Similarity Table" << endl;
    cout << "=============================" << endl;
    cout << "Number of strings: " << n << endl << endl;

    buildIndex(filename, n);
    printTable(filename, n);
}

void SimilarityTable::buildIndex(const string &filename, int numStrings)
{
    ifstream fin(filename.c_str());
    string line;
    getline(fin, line);

    for (int i = 0; i < numStrings; i++)
    {
        offsets.push_back(fin.tellg());
        getline(fin, line);
    }

    fin.close();
}

string SimilarityTable::getStringAt(const string &filename, int index)
{
    ifstream fin(filename.c_str());
    fin.seekg(offsets[index]);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

char SimilarityTable::getRating(const string &A, const string &B)
{
    int lenA = (int)A.size();
    int lenB = (int)B.size();

    int shorter = (lenA < lenB) ? lenA : lenB;
    int longer  = (lenA > lenB) ? lenA : lenB;

    if (longer == 0) return 'H';

    int lcsLen = solver.lcsLength2Row(A, B);

    double lenRatio = (double)shorter / (double)longer;
    double lcsRatio = (double)lcsLen  / (double)shorter;

    if (lenRatio >= 0.90 && lcsRatio >= 0.90)
        return 'H';

    if (lenRatio >= 0.80 && lcsRatio >= 0.80)
        return 'M';

    if (lenRatio >= 0.60 && lcsRatio >= 0.50)
        return 'L';

    return 'D';
}

void SimilarityTable::printTable(const string &filename, int numStrings)
{
    cout << "   ";
    for (int j = 1; j <= numStrings; j++)
        cout << setw(2) << setfill('0') << j << " ";
    cout << endl;

    for (int i = 1; i <= numStrings; i++)
    {
        cout << setw(2) << setfill('0') << i << " ";

        string A = getStringAt(filename, i - 1);

        for (int j = 1; j <= numStrings; j++)
        {
            if (j <= i)
            {
                cout << " - ";
            }
            else
            {
                string B = getStringAt(filename, j - 1);
                cout << " " << getRating(A, B) << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}