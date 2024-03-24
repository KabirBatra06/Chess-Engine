#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
  class RookPiece : public ChessPiece {
    private:
      /**
       * Usage of this method is optional.
       * If used, it should be called by isValidMove() and contain checks on the
       * intended vertical movement to determine if the move can be performed.
      */
      bool isValidRowMove(int toRow);
      /**
       * Usage of this method is optional.
       * If used, it should be called by isValidMove() and contain checks on the
       * intended horizontal movement to determine if the move can be performed.
      */
      bool isValidColumnMove(int toColumn);

    public:
      /**
       * Constructor for RookPiece. No default constructor should exist.
       * The arguments passed in here can be assigned to the member variables of
       * ChessPiece using a constructor member initialiser list.
      */
      RookPiece(ChessBoard& board, Color color, int startRow, int startColumn);
      /**
       * Move validation for RookPiece.
       * This method should be called by the isValidMove() of ChessBoard.
      */
      virtual bool canMoveToLocation(int toRow, int toColumn);
      /**
       * Returns a unicode representation of Rook "\uXXX" based on colour.
      */
      virtual const char* toString();
  };
}

#endif
