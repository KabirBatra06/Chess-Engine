#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Bishop chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
  class BishopPiece: public ChessPiece {
    private:
      /**
       * Usage of this method is optional.
       * If used, it should be called by isValidMove() and contain checks on the
       * intended diagonal movement to determine if the move can be performed.
      */
      bool isValidDiagonalMove(int toRow, int toColumn);

    public:
      /**
       * Constructor for BishopPiece. No default constructor should exist.
       * The arguments passed in here can be assigned to the member variables of
       * ChessPiece using a constructor member initialiser list.
      */
      BishopPiece(ChessBoard& board, Color color, int startRow, int startColumn);
      /**
       * Move validation for BishopPiece.
       * This method should be called by the isValidMove() of ChessBoard.
       * Implementation is needed for BishopPiece to become a non-abstract class.
      */
      virtual bool canMoveToLocation(int toRow, int toColumn);
      /**
       * Returns a unicode representation of Bishop "\uXXX" based on colour
      */
      virtual const char* toString();
  };
}

#endif
