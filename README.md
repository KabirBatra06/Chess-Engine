# Chess
```
  01234567
  --------
0|♜       |
1|      ♙ |
2|♖       |
3|        |
4|        |
5|♖    ♝  |
6|        |
7|        |
  --------
```

# Goal
In this project, I develop a simplified chess game.  
I implement 4 types of pieces: a Pawn ♟, Rook ♜, Bishop ♝, King ♚.  
The pieces will move as per normal chess rules.  
The chess board need not necessarily be 8x8.
Some simplifications have been made. For example: 
- (i) Pawns do not get promoted to other pieces.
- (ii) Castling is not allowed.
- (iii) En Passant pawn capture is not allowed.

# Concepts Used

- inheritance
- constructor member initialiser list
- abstract class
- namespace
- virtual methods and polymorphism
- C++ containers: specifically, list and vector

# Components
## ChessBoard
- The ChessBoard class defines the board which is a rectangle with M rows and N columns. M and N are 8 in standard chess, but the code works for more general numbers.
- The rows and columns are 0-indexed
- The initial state of the board can be arbitrary, and is read from a configuration file. If the initial state is as per the start of a standard chess game, black pieces are initially in rows 0 and 1, while white pieces are initially in rows N-2 and N-1.
- Contains information about the positions of all chess pieces.
- Returns status of a position, i.e. whether it is occupied.
- Allows players to execute a valid move.

## ChessPiece
- This is an abstract class detailing which methods to implement in derived chess pieces.
- The variables and methods common for all chess pieces should be defined here.

## PawnPiece ♟
- This class implements the Pawn.
- A black piece can move in increasing row number (downwards in the figure).
- A white piece can move in decreasing row number (upwards in the figure).
- A black piece on row 1 can move 1 or 2 steps along the same column.
- A white piece on  row n-2 can move 1 or 2 steps along the same column.
- In all other cases, a pawn can only move 1 step forward along the same column.
- A pawn can consume another piece by moving to a diagonally adjacent square with a higher row number for a black piece, or a lower row number for a white piece.

## RookPiece ♜
- This class implements the Rook.
- A Rook can move horizontally or vertically with no limit to distance.

## BishopPiece ♝
- This class implements the Bishop.
- A Bishop can move diagonally with no limit to distance.

## KingPiece ♚
- This class implements the King.  
- A King can move horizontally, vertically and diagonally by one step.
- For the first two milestones, do not worry about the King. For the final submission however, you must ensure that when a player makes a move, it does not leave her King in a position where it is under “check”.

## Checking Move Validity
I check for move validity following the rules of chess for the subset of pieces being implemented. Checks include:
- Ensuring the piece that moves is of the correct color.
- The piece should not move to the same spot.
- The piece should not move out of bounds.
- Like in chess, the piece should not be obstructed by another piece between its initial and final position.
- The final position should not contain another piece of the same color.

# Config file
The test file consists of the initial setup.
```
<number of points awarded to this test>
<number of rows> <number of columns>
<b: black, w: white> <r: rook, p: pawn, b: bishop> <row> <column>
```
Followed by a ‘~’ and then the tests to be executed. Three possible tests may be invoked. We describe the tests below::
```
movePiece <current row> <current column> <target row> <target column>
```
This tests whether your code correctly handles an attempt to move a piece located at <current row> and <current column> to <target row> and <target column>. Note that the move may not be legal, and if so, your code should correctly handle it. If the move is legal, the state of the chess board after the move must be correct. Note that if this is a legal move, subsequent tests relate to the new state of the board (thus this step may affect the state of the board, and consequently impact the results of future steps).
```
isValidScan
```
Calls isValidMove() from every position to every other position on the chess board for all pieces. To pass this test, your code must produce the correct result for every move queried.
```
underThreatScan
```
Calls isPieceUnderThreat for all chess pieces. This test passes if your code returns the correct result for isPieceUnderThreat for every chess piece for that board state.  

Below is a config file format.
```
0
4 4
b k 0 0
w k 2 0
b b 0 3
b p 1 2
~
// call isValid from every spot to every other spot
isValidScan
// call isPieceUnderThreat from every spot to every other spot
underThreatScan
// move white king diagonally
movePiece 2 0 3 1
// move black pawn two steps as it is in row 1 (starting row for black pawn)
movePiece 1 2 3 2
// move white king diagonally
movePiece 3 1 2 2
// move black bishop diagonally
movePiece 0 3 3 0
// invalid move as no piece exists at (0, 3) after the previous step
movePiece 0 3 1 0
// next round of isValid calls from every spot to every other spot
isValidScan
```
