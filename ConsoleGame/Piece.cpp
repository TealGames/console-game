#include "Piece.hpp"

Piece::MoveResult::MoveResult(Utils::Position newPos, bool validMove, 
	const Piece* const capturedPiece, std::string info= "") :
	newPos(newPos), validMove(validMove), capturedPiece(capturedPiece), moveInfo(info)
{

}

bool Piece::MoveResult::DidCapturePiece() const 
{
	return capturedPiece != nullptr;
}

Piece::Piece(const PieceColor color, const std::vector<const Utils::Vector2D> moves, const Utils::Position pos)
	: color(color), _moveDirs(moves), _pos(pos), pos(_pos) {}

Piece::MoveResult Piece::TryMove(Utils::Position newPosition)
{

}