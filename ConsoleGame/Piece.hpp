#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>
#include "Vector2D.hpp"
#include "Color.hpp"
#include "Position2D.hpp"

class Piece 
{
public:
	enum class PieceType
	{
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King
	};

private:
	struct PieceMoveInfo 
	{
		double value;
		const std::vector<Utils::Vector2D>& moveDirs;
		const std::vector<Utils::Vector2D>& captureDirs;
	};

	const std::vector<Utils::Vector2D>& _moveDirs;
	const std::vector<Utils::Vector2D>& _captureDirs;
	//Note: infinity means any value
	static const std::unordered_map<PieceType, PieceMoveInfo> pieceMoves;

	Utils::Position2D _pos;
	bool _isCaptured;

	bool HasDifferentCaptureMove();
	static bool HasPieceTypeDefined(const PieceType);
	
public:
	const ColorTheme color;
	const Utils::Position2D& pos;
	
	Piece(const ColorTheme, const PieceType);
	Piece(const ColorTheme color, const std::vector<Utils::Vector2D>,
		const std::vector<Utils::Vector2D>,const Utils::Position2D pos);

	Piece(const ColorTheme color, const std::vector<Utils::Vector2D>,
		const Utils::Position2D pos);

	void SetCaptured(bool);
	void SetPos(const Utils::Position2D);

	static double GetValueForPiece(const PieceType);
	static std::vector<Utils::Vector2D> GetMoveDirsForPiece(const PieceType);
	static bool DoesMoveDeltaMatchPieceMoves(const PieceType, 
		const Utils::Vector2D&, const Utils::Vector2D&);
};