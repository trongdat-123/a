#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 100
int n;
int X[MAX], Y[MAX];
int mark[MAX][MAX];

const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void print()
{
    for (int j = 1; j <= n * n; ++j)
    {
        cout << X[j] << " " << Y[j] << endl;
    }
    exit(0);
}
bool check(int xx, int yy)
{
    if (mark[xx][yy] == 1)
    {
        return false;
    }
    if (xx < 1 || xx > n || yy < 1 || yy > n)
    {
        return false;
    }
    return true;
}
void TRY(int k)
{
    for (int i = 0; i < 8; i++)
    {

        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];

        if (check(xx, yy))
        {
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;
            if (k == n * n)
            {
                print();
            }
            else
            {
                TRY(k + 1);
            }
            mark[xx][yy] = 0;
        }
    }
}
int main()
{
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}