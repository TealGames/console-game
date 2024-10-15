#include "Piece.hpp"
#include "Color.hpp"
#include "Position2D.hpp"

//Piece::MoveResult::MoveResult(Utils::Position2D newPos, bool validMove, 
//	const Piece* const capturedPiece, std::string info) :
//	moveAttempt(newPos), validMove(validMove), capturedPiece(capturedPiece), moveInfo(info)
//{
//
//}
//
//bool Piece::MoveResult::DidCapturePiece() const 
//{
//	return capturedPiece != nullptr;
//}

Piece::Piece(const ColorTheme color, const std::vector<Utils::Vector2D> moves,
	const std::vector<Utils::Vector2D> captureDirs, const Utils::Position2D pos)
	: color(color), _moveDirs(moves), _captureDirs(captureDirs), _pos(pos), pos(_pos), 
	_isCaptured(false){}

Piece::Piece(const ColorTheme color, const std::vector<Utils::Vector2D> moves,
	const Utils::Position2D pos)
	: color(color), _moveDirs(moves), _captureDirs{}, _pos(pos), pos(_pos),
	_isCaptured(false) {}

bool Piece::HasDifferentCaptureMove()
{
	return _captureDirs.size() > 0;
}

//Piece::MoveResult Piece::TryMove(Utils::Position2D newPos)
//{
//	if (newPos == pos)
//		return { newPos, false, nullptr, "Moved to current position" };
//	return 
//}

void Piece::SetCaptured(bool isCaptured)
{
	_isCaptured = isCaptured;
}

void Piece::SetPos(Utils::Position2D newPos)
{
	_pos = newPos;
}