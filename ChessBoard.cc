#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include "ChessPiece.hh"


using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol)
{
  numRows = numRow;
  numCols = numCol;

  board = std::vector<std::vector<ChessPiece *>>(numRows, std::vector<ChessPiece *>(numCols, nullptr));
}

ChessBoard::ChessBoard(ChessBoard& other) 
{
  if(this == &other)
  {
    return;
  }

  numRows = other.getNumRows();
  numCols = other.getNumCols();
  turn = other.turn;

  board = std::vector<std::vector<ChessPiece *>>(numRows, std::vector<ChessPiece *>(numCols, nullptr));

  ChessPiece* p;

  for(int i = 0; i < numRows; i++)
  {
    for(int j = 0; j < numCols; j++)
    {
      p = other.getPiece(i, j);
      if(p != nullptr)
      {
        createChessPiece(p->getColor(), p->getType(), p->getRow(), p->getColumn());
      }
    }
  }
}

ChessBoard::~ChessBoard() 
{
  for(int i = 0; i < numRows; i++)
  {
    for(int j = 0; j < numCols; j++)
    {
      delete(board.at(i).at(j));
    }
  }

  whitePieces.clear();
  blackPieces.clear();
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) 
{

  if(isOccupied(startRow, startColumn) == true)
  {
    removeChessPiece(startRow, startColumn);
  } 

  if(ty == Rook){
    ChessPiece *newrook = new RookPiece(*this, col, startRow, startColumn);
    board[startRow][startColumn] = newrook;

    if(col == White)
    {
      whitePieces.push_back(newrook);
    }
    else if(col == Black)
    {
      blackPieces.push_back(newrook);
    }

  }
  else if(ty == Bishop){
    ChessPiece* newbishop = new BishopPiece(*this, col, startRow, startColumn);
    board[startRow][startColumn] = newbishop;

    if(col == White)
    {
      whitePieces.push_back(newbishop);
    }
    else if(col == Black)
    {
      blackPieces.push_back(newbishop);
    }

  }
  else if(ty == Pawn){
    ChessPiece* newpawn = new PawnPiece(*this, col, startRow, startColumn);
    board[startRow][startColumn] = newpawn;

    if(col == White)
    {
      whitePieces.push_back(newpawn);
    }
    else if(col == Black)
    {
      blackPieces.push_back(newpawn);
    }

  }
  else if(ty == King)
  {

    if(col == White)
    {
      whiteKing = new KingPiece(*this, col, startRow, startColumn);
      board[startRow][startColumn] = whiteKing;
      whitePieces.push_back(whiteKing);
    }
    else if(col == Black)
    {
      blackKing = new KingPiece(*this, col, startRow, startColumn);
      board[startRow][startColumn] = blackKing;
      blackPieces.push_back(blackKing);
    }

  }

}

bool ChessBoard::isOccupied(int row, int column)
{
  if(row >= getNumRows() || column >= getNumCols() || (row < 0) || (column < 0))
  {
    return false;
  }

  if(board.at(row).at(column) == nullptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void ChessBoard::removeChessPiece(int row, int column) 
{
  if(isOccupied(row, column) == true)
  {
    whitePieces.remove_if([row, column](Student::ChessPiece* piece){return (piece->getRow() == row && piece->getColumn() == column);});
    blackPieces.remove_if([row, column](Student::ChessPiece* piece){return (piece->getRow() == row && piece->getColumn() == column);});

    delete(board.at(row).at(column));
    board.at(row).at(column) = nullptr;
  }
  else
  {
    board.at(row).at(column) = nullptr;
  }

}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color) {
  if(isOccupied(row, column) == true){
    
    if((board.at(row).at(column))->getColor() == color){
      return true;
    }
    else
    {
      return false;
    }
  }

  return false;
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn) 
{
  ChessPiece *p = getPiece(fromRow, fromColumn);

  if(p == NULL)
  {
    return;
  }

  createChessPiece(p->getColor(), p->getType(), toRow, toColumn);

  removeChessPiece(fromRow, fromColumn);

}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) 
{
  if(isValidMove(fromRow, fromColumn, toRow, toColumn) == true)
  {
    if(turn == getPiece(fromRow, fromColumn)->getColor())
    {
      if(getPiece(fromRow, fromColumn)->getColor() == White)
      {
        turn = Black;
      }
      else
      {
        turn = White;
      }

      forceMove(fromRow, fromColumn, toRow, toColumn);
      return true;
    }
    return false;
  }

  return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) 
{
  ChessPiece *p = getPiece(fromRow, fromColumn);

  if(p == nullptr)
  {
    return false;
  }

  if(p->canMoveToLocation(toRow, toColumn) && isKingSafeAfterMove(fromRow, fromColumn, toRow, toColumn))
  {
    return true;
  }
  return false;
}

bool ChessBoard::isPieceUnderThreat(int row, int column) 
{

  if(row >= getNumRows() || column >= getNumCols() || (row < 0) || (column < 0))
  {
    return false;
  }

  ChessPiece *p = getPiece(row, column);

  if(p == nullptr)
  {
    return false;
  }

  Color a = p->getColor();

  if(a == Black)
  {
    std::list<ChessPiece*>::iterator i;

    for(i = whitePieces.begin(); i != whitePieces.end(); i++)
    {
      if((*i)->canMoveToLocation(row, column) == true)
      {
        return true;
      } 
    }   
  }
  else
  {
    std::list<ChessPiece*>::iterator i;
    for(i = blackPieces.begin(); i != blackPieces.end(); i++)
    {
      if((*i)->canMoveToLocation(row, column) == true)
      {
        return true;
      }
    }
  }
  return false;
}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn) 
{
  ChessPiece* p = getPiece(fromRow, fromColumn);
  Color temp_color2 = p->getColor();
  ChessPiece* temp = getPiece(toRow, toColumn);
  ChessPiece* king_used;

  if(temp_color2 == White && whiteKing == nullptr)
  {
    return true;
  }
  if(temp_color2 == Black && blackKing == nullptr)
  {
    return true;
  }


  Type temp_type;
  Color temp_color;

  if(temp != NULL)
  {
    temp_type = temp->getType();
    temp_color = temp->getColor();
  }

  if(p == NULL)
  {
    return true;
  }

  forceMove(fromRow, fromColumn, toRow, toColumn);

  if(temp_color2 == White)
  {
    king_used = whiteKing;
  }
  else
  {
    king_used = blackKing;
  }

  if(isPieceUnderThreat(king_used->getRow(), king_used->getColumn()))
  {
    forceMove(toRow, toColumn, fromRow, fromColumn);

    if(temp != NULL)
    {
      createChessPiece(temp_color, temp_type, toRow, toColumn);
    }
    return false;
  } 

  forceMove(toRow, toColumn, fromRow, fromColumn);
  if(temp != NULL)
  {
    createChessPiece(temp_color, temp_type, toRow, toColumn);
  }
  return true;

}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
  // top scale
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << i;
  }
  outputString << std::endl << "  ";
  // top border
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl;

  for(int row = 0; row < numRows; row++) {
    outputString << row << "|";
    for(int column = 0; column < numCols; column++) {
      ChessPiece* piece = board.at(row).at(column);
      outputString << (piece == nullptr ? " " : piece->toString());
    }
    outputString << "|" << std::endl;
  }

  // bottom border
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl << std::endl;

  return outputString;
}