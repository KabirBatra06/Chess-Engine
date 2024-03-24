#ifndef _CHESSBOARD_H__
#define _CHESSBOARD_H__

#include "ChessPiece.hh"
#include "KingPiece.hh"
#include <list>
#include <vector>
#include <sstream>

namespace Student {
  class ChessBoard {
    private:
      int numRows = 0;
      int numCols = 0;
      Color turn = White;
      /**
       * @brief
       * A 2D vector of pointers to ChessPiece objects.
       * board.at(row) returns the entire row.
       * board.at(row).at(col) returns a pointer to a ChessPiece object.
       * *(board.at(row).at(col)) returns the ChessPiece object itself.
       */
      std::vector<std::vector<ChessPiece*>> board;
      std::list<ChessPiece*> blackPieces;
      std::list<ChessPiece*> whitePieces;
      KingPiece* blackKing = nullptr;
      KingPiece* whiteKing = nullptr;
      /**
       * @brief
       * Deletes the piece at a certain spot if it exists. Else, ignore.
       * @param row
       * The row number of the piece to be deleted.
       * @param column
       * The column number of the piece to be deleted.
       */
      void removeChessPiece(int row, int column);
      /**
       * @brief
       * Forcefully moves a piece without any checks at all.
       * @param fromRow
       * The row number of the piece to be moved.
       * @param fromColumn
       * The column number of the piece to be moved.
       * @param toRow
       * The row number of the destination.
       * @param toColumn
       * The column number of the destination.
       */
      void forceMove(int fromRow, int fromColumn, int toRow, int toColumn);

    public:
      /**
       * @brief
       * Allocates memory on the heap for the board.
       * Remember to initialise all pointers to nullptr.
       * @param numRow
       * Number of rows of the chess board.
       * @param numCol
       * Number of columns of the chessboard
       */
      ChessBoard(int numRow, int numCol);

      /**
       * @brief
       * Clones a true copy of the chess board.
       * @param other
       * The chess board to be copied from.
       */
      ChessBoard(ChessBoard& other);

      /**
       * @brief
       * Deallocates all memory on the heap that was allocated for the board.
       * Remember to use the correct delete statement (delete vs delete[]).
       */
      virtual ~ChessBoard();

      /**
       * @return
       * Number of rows in chess board.
       */
      int getNumRows() { return numRows; }

      /**
       * @return
       * Number of columns in chess board.
       */
      int getNumCols() { return numCols; }

      /**
       * @return
       * Pointer to a piece.
       */
      ChessPiece* getPiece(int r, int c) { return board.at(r).at(c); }

      /**
       * @brief
       * Allocates memory for a new chess piece and assigns its
       * address to the corresponding pointer in the 'board' variable.
       * Remove any existing piece first before adding the new piece.
       * @param col
       * Color of the piece to be created.
       * @param ty
       * Type of the piece to be created.
       * @param startRow
       * Starting row of the piece to be created.
       * @param startColumn
       * Starting column of the piece to be created.
       */
      void createChessPiece(Color col, Type ty, int startRow, int startColumn);

      /**
       * @brief
       * Checks if a piece, regardless of color or type, exists at the position.
       * @param row
       * The row of the position to be checked.
       * @param column
       * The column of the position to be checked.
       * @return
       * True if a piece exists at that position,
       * and false if no piece exists or out of bounds.
       */
      bool isOccupied(int row, int column);

      /**
       * @brief
       * Checks if a piece matching the intended colour, regardless of type,
       * exists at the position.
       * @param row
       * The row of the position to be checked.
       * @param column
       * The column of the position to be checked.
       * @return
       * True if a piece matching the intended colour exists at that position,
       * and false if out of bounds and otherwise.
       */
      bool isOccupiedWithColor(int row, int column, Color color);

      /**
       * @brief
       * Performs the move if the move is valid.
       * Account for the turn, staying within bounds and validity of the move.
       * @param fromRow
       * The row of the piece to be moved.
       * @param fromColumn
       * The column of the piece to be moved.
       * @param toRow
       * The row of the destination position.
       * @param toColumn
       * The column of the destination position.
       * @return
       * A boolean indicating whether move was executed successfully.
       */
      bool movePiece(int fromRow, int fromColumn, int toRow, int toColumn);

      /**
       * @brief
       * Checks if a move is valid without accounting for turns.
       * @param fromRow
       * The row of the piece to be moved.
       * @param fromColumn
       * The column of the piece to be moved.
       * @param toRow
       * The row of the destination position.
       * @param toColumn
       * The column of the destination position.  
       * @return
       * Returns true if move may be executed without accounting for turn.
       */
      bool isValidMove(int fromRow, int fromColumn, int toRow, int toColumn);

      /**
       * @brief
       * Checks if the piece at a position is under threat.
       * @param row
       * Row of piece being checked.
       * @param column
       * Column of piece being checked.
       * @return
       * Returns true if a piece exists at the stated position, and an opponent
       * piece may move to the position.
       */
      bool isPieceUnderThreat(int row, int column);

      /**
       * @brief
       * Experiment with potential future moves.
       * @param fromRow
       * Row of piece being moved
       * @param fromColumn
       * Column of piece being moved
       * @param toRow
       * Row of the destination position
       * @param toColumn
       * Column of the destination position
       * @return
       * Returns true if no King exists, or the King is not under threat.
       */
      bool isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn);

      /**
       * @brief
       * Returns an output string stream displaying the layout of the board.
       * An ostringstream is used to automatically handle formatting of integers
       * and special characters into their string representations.
       * @return
       * An output stream containing the full board layout.
       */
      std::ostringstream displayBoard();
  };
}

#endif
