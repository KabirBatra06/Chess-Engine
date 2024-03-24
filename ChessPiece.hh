#ifndef _CHESSPIECE_H__
#define _CHESSPIECE_H__

#include "Chess.h"

namespace Student {
  class ChessBoard;

  class ChessPiece {
    protected:
      ChessBoard& mBoard;
      Color mColor;
      Type mType;
      int mRow;
      int mColumn;

    public:
      /**
       * @brief
       * Constructor for ChessPiece.
       * @param board
       * The board to which the piece belongs.
       * @param color
       * The colour of the piece.
       * @param row
       * Starting row of the piece.
       * @param column
       * Starting column of the piece.
       */
      ChessPiece(ChessBoard& board, Color color, int row, int column);
      /**
       * @brief
       * Default destructor for ChessPiece.
       * Does nothing special.
       */
      virtual ~ChessPiece() {}

      /**
       * @return
       * Colour of piece.
       */
      Color getColor();

      /**
       * @return
       * Type of piece.
       */
      Type getType();

      /**
       * @return
       * Current row number of piece.
       */
      int getRow();

      /**
       * @return
       * Current column number of piece.
       */
      int getColumn();

      /**
       * @brief Sets row and column numbers of piece.
       * @param row
       * The new row number of the piece.
       * @param column
       * The new column number of the piece.
       */
      virtual void setPosition(int row, int column);

      /**
       * @brief
       * A pure virtual method to be implemented in the derived classes.
       * Determines if movement from current position to new position is valid.
       * @param toRow
       * The row of the destination position.
       * @param toColumn
       * The column of the destination position.
       * @return
       * A boolean indicating if a move from current to destination is valid.
       */
      virtual bool canMoveToLocation(int toRow, int toColumn) = 0;

      /**
       * @brief
       * A pure virtual method to be implemented in the derived classes.
       * Returns a unicode string representation of the piece.
       * @return
       * A unicode representation of the piece.
       */
      virtual const char* toString() = 0;
  };  
}

#endif
