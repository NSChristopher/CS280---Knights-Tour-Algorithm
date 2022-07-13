public class Main {
    public static void main(String[] args) {

        int[][] visited = new int[8][8];
        for (int x = 0; x < 8; x++)
            for (int y = 0; y < 8; y++)
                visited[x][y] = -1;

        visited[0][0] = 0;
        
        knightTour(visited, 0, 0, 1);
    }
    
    static int[] movesRow = { 2, 1, -1, -2, -2, -1, 1, 2 };
    static int[] movesColumn = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    public static boolean knightTour(int[][] visited, int row, int col, int move) 
    {
        if(move == 64)
        {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(visited[i][j] > 9)
                        System.out.print(visited[i][j] + ", ");
                    else
                        System.out.print(" " + visited[i][j] + ", ");
                }
                System.out.println();
            }
            return true;
        }

        for (int i = 0; i < 8; i++)
        {
            int rowNew = row + movesRow[i];
            int colNew = col + movesColumn[i];
            if(validateMove(visited, rowNew, colNew))
            {
                visited[rowNew][colNew] = move;
                if(knightTour(visited, rowNew, colNew, move + 1))
                    return true;
                else
                    visited[rowNew][colNew] = -1;
            }
        }
        return false;
    }

    static boolean validateMove(int[][] visited, int rowNew, int colNew)
    {
        return (!(rowNew < 0 || rowNew > 7 || colNew < 0 || colNew > 7)&&(visited[rowNew][colNew] == -1));
    }
}
