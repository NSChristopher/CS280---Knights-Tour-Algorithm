#include <bits/stdc++.h>
using namespace std;

int validate(int newRow, int newColumn, int visited[8][8])
{
    return (!(newRow < 0 || newRow > 7 || newColumn < 0 || newColumn > 7)
            && visited[newRow][newColumn] == -1);
}

int knightTour(int visited[8][8], int movesRow[8], int movesColumn[8], int row, int col, int move)
{
    int k, newRow, newColumn;
    if (move == 64) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++)
                cout << " " << setw(2) << visited[x][y] << " ";
            cout << endl;
        }
        return 1;
    }

    for (k = 0; k < 8; k++) {
        newRow = row + movesRow[k];
        newColumn = col + movesColumn[k];
        if (validate(newRow, newColumn, visited)) {
            visited[newRow][newColumn] = move;
            if (knightTour(visited, movesRow, movesColumn, newRow, newColumn, move + 1)
                == 1)
                return 1;
            else
                visited[newRow][newColumn] = -1;
        }
    }
    return 0;
}
int main()
{
    int visited[8][8];
    
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            visited[x][y] = -1;
            
    int movesRow[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int movesColumn[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    visited[0][0] = 0;

    knightTour(visited, movesRow, movesColumn ,0, 0, 1);
    return 0;
}