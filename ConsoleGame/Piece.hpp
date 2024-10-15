#pragma once
#include <vector>
#include <string>
#include "Vector2D.hpp"
#include "Color.hpp"
#include "Position2D.hpp"

class Piece 
{

	/*class MoveResult
	{
	public:
		const Utils::Position2D moveAttempt;
		const bool validMove;
		const Piece* const capturedPiece;
		const std::string moveInfo;

		bool DidCapturePiece() const;

		MoveResult(Utils::Position2D, bool, const Piece* const, std::string = "");
	};*/

private:
	const std::vector<Utils::Vector2D> _moveDirs;
	const std::vector<Utils::Vector2D> _captureDirs;
	Utils::Position2D _pos;
	bool _isCaptured;

	bool HasDifferentCaptureMove();
	
public:
	const ColorTheme color;
	const Utils::Position2D& pos;
	
	Piece(const ColorTheme color, const std::vector<Utils::Vector2D>,
		const std::vector<Utils::Vector2D>,const Utils::Position2D pos);

	Piece(const ColorTheme color, const std::vector<Utils::Vector2D>,
		const Utils::Position2D pos);

	/*MoveResult TryMove(Utils::Position2D);*/
	void SetCaptured(bool);
	void SetPos(const Utils::Position2D);
};