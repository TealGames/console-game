#include <format>
#include "BoardManager.hpp"
#include "Position2D.hpp"
#include "Vector2D.hpp"
#include "HelperFunctions.hpp"

MoveResult::MoveResult(Utils::Position2D pos, bool isValid, std::string info = "") 
	:attemptedPos(pos), isValidMove(isValid), info(info)
{}

std::array<std::array<Tile, boardDimension>, boardDimension> tiles;
std::unordered_map<ColorTheme, std::array<Piece&, colorPieces>> allPieces;

void CreatePieces(const ColorTheme color, bool overrideExisting)
{
	bool alreadyExist = Utils::IterableHas(allPieces, color);
	if (alreadyExist && !overrideExisting)
	{
		std::string err= std::format("Tried to create pieces for color {} but no override is allowed!", color);
		Utils::Log(Utils::LogType::Error, err);
		return;
	}

	
}

void ResetBoard()
{

}

MoveResult TryMove(const Piece&, const Utils::Position2D&)
{

}