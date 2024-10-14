#pragma once
#include <vector>
#include <string>
#include "Vector2D.hpp"
#include "Position.hpp"

class Piece 
{
public:
	enum class PieceColor
	{
		White,
		Black,
	};

	class MoveResult
	{
	public:
		const Utils::Position newPos;
		const bool validMove;
		const Piece* const capturedPiece;
		const std::string moveInfo;

		bool DidCapturePiece() const;

		MoveResult(Utils::Position, bool, const Piece* const, std::string = "");
	};

private:
	const std::vector<const Utils::Vector2D> _moveDirs;
	Utils::Position _pos;

public:
	const PieceColor color;
	const Utils::Position pos;
	
	Piece(const PieceColor color, const std::vector<const Utils::Vector2D>, const Utils::Position pos);
	MoveResult TryMove(Utils::Position);
};