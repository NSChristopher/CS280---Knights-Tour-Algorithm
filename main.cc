#include <bits/stdc++.h>
using namespace std;
 
int solveKTUtil(int x, int y, int movei, int visited[8][8],
                int xMove[], int yMove[]);

int validate(int x, int y, int visited[8][8])
{
    return (!(rowNew < 0 || rowNew > 7 || colNew < 0 || colNew > 7)
            && visited[x][y] == -1);
}

int solveKnightTour()
{
    int visited[8][8];
    
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            visited[x][y] = -1;
            
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    visited[0][0] = 0;

    if (solveKTUtil(0, 0, 1, visited, xMove, yMove) == 0) {
        cout << "No solution";
        return 0;
    }
    else {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++)
                cout << " " << setw(2) << visited[x][y] << " ";
            cout << endl;
        }
    }
    return 1;
}

int knightTourUtil(int x, int y, int movei, int visited[8][8],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == 8 * 8)
        return 1;

    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (validate(next_x, next_y, visited)) {
            visited[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, visited,
                            xMove, yMove)
                == 1)
                return 1;
            else
                visited[next_x][next_y] = -1;
        }
    }
    return 0;
}
int main()
{
    solveKT();
    return 0;
}