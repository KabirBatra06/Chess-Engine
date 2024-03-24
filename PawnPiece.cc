#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"


Student::PawnPiece::PawnPiece(ChessBoard &board, Color color, int startRow, int startColumn):ChessPiece(board, color, startRow, startColumn)
{
	mType = Pawn;
}

bool Student::PawnPiece::isValidDiagonalMove(int toRow, int toColumn)
{

    if(mBoard.getPiece(mRow, mColumn)->getColor() == Black)
    {
            
        if((toRow - mRow == 1) && (abs(toColumn - mColumn) == 1)){
            return true;
        }
        return false;  
    }

    if(mBoard.getPiece(mRow, mColumn)->getColor() == White)
    {

        if((mRow - toRow == 1) && abs(toColumn - mColumn) == 1){
            return true;
        }
        return false;
    }

    return false;
}

bool Student::PawnPiece::isValidRowMove(int toRow)
{
    int n = mBoard.getNumRows();

    if(mBoard.getPiece(mRow, mColumn)->getColor() == Black)
    {
        
        if(mRow >= toRow)
        {
            return false;
        }

        if(mRow == 1)
        {
            if((toRow - mRow) > 2) 
            {
                return false;
            }

            if(mBoard.isOccupied(mRow+1, mColumn))
            {
                return false;
            }
            return true;
        }

        if((toRow - mRow) > 1)
        { 
            return false;
        }
        else
        {
            return true;
        }
    }

    if(mBoard.getPiece(mRow, mColumn)->getColor() == White)
    {
        if(mRow <= toRow)
        {
            return false;
        }
        
        if(mRow == (n - 2))
        {
            if((mRow - toRow) > 2)
            {
                return false;
            }

            if(mBoard.isOccupied(mRow-1, mColumn))
            {
                return false;
            }
            return true;
        }
        if((mRow - toRow) > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
       
    }
    return false;
}

bool Student::PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
    int n = mBoard.getNumRows();
    int ncol = mBoard.getNumCols();

    // Check if out of bouunds
    if((toRow < 0) || (toRow >= n) || (toColumn < 0) || (toColumn >= ncol) || ((toRow == mRow) && (toColumn == mColumn)))
    {
        return false;
    }

    //check if piece obstruction.
    bool piece_exist_diag;
    if(mColor == Black)
    {
        piece_exist_diag = mBoard.isOccupiedWithColor(toRow, toColumn, White);
    }
    else if(mColor == White)
    {
        piece_exist_diag = mBoard.isOccupiedWithColor(toRow, toColumn, Black);
    }

    bool forward_blockage = mBoard.isOccupied(toRow, toColumn);
    
    if((isValidRowMove(toRow) && (toColumn == mColumn) && (!forward_blockage)) || (isValidDiagonalMove(toRow, toColumn) && (piece_exist_diag)))
    {
        return true;
    }
    return false;
}
    

const char* Student::PawnPiece::toString()
{
    if(mColor == Black)
    {
        return("\u265F");
    }
    else
    {
        return("\u2659");
    }
}