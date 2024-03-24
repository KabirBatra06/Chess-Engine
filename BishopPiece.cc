#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "BishopPiece.hh"


using Student::BishopPiece;
//using Student::ChessBoard;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int startRow, int startColumn):ChessPiece{board, color, startRow, startColumn}
{
	mType = Bishop;
}

bool BishopPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    if(abs(toRow - mRow) != abs(toColumn - mColumn))
    {
        return false;
    }
	
	// check if there is a piece in the way
	int itr_row;
    int itr_col;

    if(mRow > toRow) // up
    {
        //std::cout<<"1\n";
        if(mColumn > toColumn) // left and up
        {
            //std::cout<<"2\n";
            itr_row = mRow-1;
            for(itr_col = mColumn-1; itr_col > toColumn; itr_col--)
            {
                if(mBoard.isOccupied(itr_row, itr_col))
                {   
                    //std::cout<<"3\n";
                    return false;
                }
                itr_row--;
            }

        }
        else // right and up
        {
            //std::cout<<"4\n";
            itr_row = mRow-1;
            for(itr_col = mColumn+1; itr_col < toColumn; itr_col++)
            {
                if(mBoard.isOccupied(itr_row, itr_col))
                {   
                    //std::cout<<"5\n";
                    return false;
                }
                itr_row--;
            }
        }
    }
    else // down bad
    {
        //std::cout<<"6\n";
        if(mColumn > toColumn) // left and down
        {
            //std::cout<<"7\n";
            itr_row = mRow+1;
            for(itr_col = mColumn-1; itr_col > toColumn; itr_col--)
            {
                if(mBoard.isOccupied(itr_row, itr_col))
                {   
                    //std::cout<<"8\n";
                    return false;
                }
                itr_row++;
            }
        }
        else // right and down
        {
            //std::cout<<"9\n";
            itr_row = mRow+1;
            for(itr_col = mColumn+1; itr_col < toColumn; itr_col++)
            {
                if(mBoard.isOccupied(itr_row, itr_col))
                { 
                    //std::cout<<"10\n";  
                    return false;
                }
                itr_row++;
            }
        }
    }

	return true;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    int n = mBoard.getNumRows();
    int ncol = mBoard.getNumCols();
	
    if((toRow < 0) || (toColumn < 0) || (toRow >= n) || (toColumn >= ncol) || ((toRow == mRow) && (toColumn == mColumn)))
    {
        return false;
    }

    //if a piece of the same color already exists at the location
    if(mBoard.isOccupiedWithColor(toRow, toColumn, mColor))
    {
		return false;
    } 

	if(isValidDiagonalMove(toRow, toColumn))
	{
		return true;
	}
	return false;
}

const char* BishopPiece::toString()
{
	if(mColor == Black)
    {
        return("\u265D");
    }
    else
    {
        return("\u2657");
    }
}