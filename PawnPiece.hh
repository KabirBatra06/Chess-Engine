#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
  class PawnPiece : public ChessPiece {
    private:
      /**
       * Usage of this method is optional.
       * If used, it should be called by isValidMove() and contain checks on the
       * intended diagonal movement to determine if the move can be performed.
       * This can only be performed during consumption of an opponent piece.
      */
      bool isValidDiagonalMove(int toRow, int toColumn);
      /**
       * Usage of this method is optional.
       * If used, it should be called by isValidMove() and contain checks on the
       * intended vertical movement to determine if the move can be performed.
       * Row position determines if the piece may move 2 steps forward.
      */
      bool isValidRowMove(int toRow);

    public:
      /**
       * Constructor for PawnPiece. No default constructor should exist.
       * The arguments passed in here can be assigned to the member variables of
       * ChessPiece using a constructor member initialiser list.
      */
      PawnPiece(ChessBoard& board, Color color, int startRow, int startColumn);
      /**
       * Move validation for PawnPiece.
       * This method should be called by the isValidMove() of ChessBoard.
      */
      virtual bool canMoveToLocation(int toRow, int toColumn);
      /**
       * Returns a unicode representation of Pawn "\uXXX" based on colour
      */
      virtual const char* toString();
  };
}

#endif
