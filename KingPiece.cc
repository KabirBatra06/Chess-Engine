#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "KingPiece.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int startRow, int startColumn):ChessPiece(board, color, startRow, startColumn)
{
	mType = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn)
{
    int n = mBoard.getNumRows();
    int ncol = mBoard.getNumCols();

    // Check if out of bouunds
    if((toRow < 0) || (toRow >= n) || (toColumn < 0) || (toColumn >= ncol) || ((toRow == mRow) && (toColumn == mColumn)))
    {
        return false;
    }

    // check if occupied with same color
    if(mBoard.isOccupiedWithColor(toRow, toColumn, mColor))
    {
        return false;
    }

    if(((abs(mRow - toRow) == 1) || (abs(mRow - toRow) == 0)) && ((abs(mColumn - toColumn) == 1) || (abs(mColumn - toColumn) == 0)) )
    {
        return true;
    }
    return false;
}

const char* KingPiece::toString()
{
    if(mColor == Black)
    {
        return("\u265A");
    }
    else
    {
        return("\u2654");
    }
}