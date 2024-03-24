#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "RookPiece.hh"


using Student::ChessBoard;

Student::RookPiece::RookPiece(ChessBoard &board, Color color, int startRow, int startColumn):ChessPiece{board, color, startRow, startColumn}
{
	mType = Rook;
}

bool Student::RookPiece::isValidRowMove(int toRow)
{
    //check range of row
    if((toRow < 0) || (toRow >= mBoard.getNumRows()))
    {
        //std::cout<<"1\n";
        return false;
    }

    // if there is a piece in the way
    if(mRow > toRow)
    {   
        //std::cout<<"2\n";     
        for(int i = toRow+1; i < mRow; i++)
        {
            if(mBoard.isOccupied(i, mColumn))
            {
                //std::cout<<"3\n";
                return false;
            }
        }

    }
    else
    {
        //std::cout<<"4\n";
        for(int i = mRow+1 ; i < toRow ; i++)
        {
            if(mBoard.isOccupied(i, mColumn))
            {
                //std::cout<<"5\n";
                return false;
            }
        }

    }
    return true;
}

bool Student::RookPiece::isValidColumnMove(int toColumn)
{
    if((toColumn < 0) || (toColumn >= mBoard.getNumCols()))
    {
        return false;
    }

    // if there is a piece in the way
    if(mColumn > toColumn)
    {
        for(int i = toColumn+1; i < mColumn; i++)
        {
            if(mBoard.isOccupied(mRow, i))
            {
                return false;
            }   
        }
    }
    else
    {
        for(int i = mColumn+1; i < toColumn; i++)
        {
            if(mBoard.isOccupied(mRow, i))
            {
                return false;
            }   
        }
    }

    return true;
}

bool Student::RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    // is the piece stationary
    if(((toRow == mRow) && (toColumn == mColumn)))
    {
        //std::cout<<"1\n";
        return false;
    }

    //if a piece of the same color already exists at the location
    if(mBoard.isOccupiedWithColor(toRow, toColumn, mColor))
    {
        //std::cout<<"2\n";
		return false;
    } 

    if((toRow == mRow) && isValidColumnMove(toColumn))
    {
        return true;
    }
    else if((toColumn == mColumn) && isValidRowMove(toRow))
    {
        return true;
    }
    else
    {
        //std::cout<<"3\n";
        return false;
    }
}

const char* Student::RookPiece::toString()
{
    if(mColor == Black)
    {
        return("\u265C");
    }
    else
    {
        return("\u2656");
    }
}