#include "ChessBoard.hh"
#include "ChessPiece.hh"

//class ChessBoard;
using Student::ChessPiece;
//using Student::ChessBoard;

ChessPiece::ChessPiece(ChessBoard& board, Color color, int row, int column): mBoard{board}, mColor{color}, mRow{row}, mColumn{column}
{
    
}

Color ChessPiece::getColor()
{
    return mColor;
}

Type ChessPiece::getType()
{
    return mType;
}

int ChessPiece::getRow()
{
    return mRow;
}

int ChessPiece::getColumn()
{
    return mColumn;
}

void ChessPiece:: setPosition(int row, int column)
{
    mRow = row;
    mColumn = column;
}
