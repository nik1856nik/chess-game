#ifndef PIECES_H
#define PIECES_H

#include "Position.h"
#include <vector>
#include <memory>
#include <string>

// Color enum
enum class Color { WHITE, BLACK };

// Abstract base class for all pieces (Abstraction & Polymorphism)
class Piece {
protected:
    Color color;
    Position position;
    bool hasMoved;
    char symbol;
    int value;

public:
    Piece(Color c, Position pos, char sym, int val) 
        : color(c), position(pos), hasMoved(false), symbol(sym), value(val) {}
    
    virtual ~Piece() = default;
    
    // Pure virtual function (Abstraction)
    virtual bool isValidMove(const Position& to, class Board& board) const = 0;
    virtual char getSymbol() const { 
        return color == Color::WHITE ? symbol : (char)std::tolower(symbol); 
    }
    virtual std::string getName() const = 0;
    
    Color getColor() const { return color; }
    Position getPosition() const { return position; }
    int getValue() const { return value; }
    void setPosition(const Position& pos) { position = pos; hasMoved = true; }
    bool hasMovedBefore() const { return hasMoved; }
    void setHasMoved(bool moved) { hasMoved = moved; }
    
    // Template function for type checking
    template<typename T>
    bool isType() const {
        return dynamic_cast<const T*>(this) != nullptr;
    }
};
// Pawn class
class Pawn : public Piece {
public:
    Pawn(Color c, Position pos) : Piece(c, pos, 'P', 1) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "Pawn"; }
};

// Rook class
class Rook : public Piece {
public:
    Rook(Color c, Position pos) : Piece(c, pos, 'R', 5) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "Rook"; }
};

// Knight class
class Knight : public Piece {
public:
    Knight(Color c, Position pos) : Piece(c, pos, 'N', 3) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "Knight"; }
};

// Bishop class
class Bishop : public Piece {
public:
    Bishop(Color c, Position pos) : Piece(c, pos, 'B', 3) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "Bishop"; }
};

// Queen class
class Queen : public Piece {
public:
    Queen(Color c, Position pos) : Piece(c, pos, 'Q', 9) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "Queen"; }
};

// King class
class King : public Piece {
public:
    King(Color c, Position pos) : Piece(c, pos, 'K', 0) {}
    bool isValidMove(const Position& to, class Board& board) const override;
    std::string getName() const override { return "King"; }
};

#endif