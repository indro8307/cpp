/******************************************************************************

vector_2d

Description: vector of vectors / 2D vector

Output:
        12      12      12      12      12      12      12      12      12      12      12      12
        1       2       3       4       5       6       7       8       9       10      11      12
        12      24      36      48      60      72      84      96      108     120     132     144


*******************************************************************************/
#if 0

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector<int> > vectors_2d(3,vector<int>(12));
    for(int row=0;row<vectors_2d.size();row++)
    {
        for(int col=0;col<vectors_2d[row].size();col++)
        {
            if(row==0)
                vectors_2d[row][col] = 12;

            else if(row==1)
                vectors_2d[row][col] = col+1;

            else
                vectors_2d[row][col] = vectors_2d[0][col] * vectors_2d[1][col];
        }
    }
    for(int row=0;row<vectors_2d.size();row++)
    {
        for(int col=0;col<vectors_2d[row].size();col++)
        {
            cout<< '\t' << vectors_2d[row][col] <<flush;
        }
        cout<<endl;
    }

}
#endif
