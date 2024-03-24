#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
  class KingPiece: public ChessPiece {
    public:
      /**
       * Constructor for KingPiece. No default constructor should exist.
       * The arguments passed in here can be assigned to the member variables of
       * ChessPiece using a constructor member initialiser list.
      */
      KingPiece(ChessBoard& board, Color color, int startRow, int startColumn);
      /**
       * Move validation for KingPiece.
       * This method should be called by the isValidMove() of ChessBoard.
       * Implementation is needed for KingPiece to become a non-abstract class.
      */
      virtual bool canMoveToLocation(int toRow, int toColumn);
      /**
       * Returns a unicode representation of King "\uXXX" based on colour
      */
      virtual const char* toString();
  };
}

#endif
