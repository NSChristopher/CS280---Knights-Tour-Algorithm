import java.io.Console;

import org.omg.CORBA.IntHolder;

/**
 * Main
 */
public class Main {
    public static void main(String[] args) {

        int[][] visited = new int[8][8];

        visited[0][0] = 1;
        
        knightTour(visited, 0, 0, 1);
    }
    
    static int[] movesRow = {2,2,-2,-2,1,1,-1,-1};
    static int[] movesColumn = {1,-1,1,-1,2,-2,2,-2};
    
    public static boolean knightTour(int[][] visited, int row, int col, int move) 
    {
        if(move == 64)
        {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    System.out.print(visited[row][col] + ", ");
                }
                System.out.println();
            }
            return true;
        }

        for (int i = 0; i < visited.length; i++)
        {
            int rowNew = row + movesRow[i];
            int colNew = col + movesColumn[i];
            if(validateMove(visited, rowNew, colNew))
            {
                move++;
                visited[rowNew][colNew] = move;
                if(knightTour(visited, row, col, move))
                {
                    return true;
                }
                move--;
                visited[rowNew][colNew] = 0;
            }
        }
        return false;
    }

    static boolean validateMove(int[][] visited, int rowNew, int colNew)
    {
        if((rowNew >= 0 && rowNew <=8)&&(colNew >= 0 && colNew <=8)&&(visited[rowNew][colNew] == 0))
        {
            return true;
        }
        else 
            return false;
    }
    
}
