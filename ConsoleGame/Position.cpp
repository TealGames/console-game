#include "Position.hpp"

namespace Utils 
{
	Position::Position(double x, double y) 
		: _x(x), _y(y), x(_x), y(_y) {}

	Position::Position()
		:_x(0), _y(0), x(_x), y(_y) {}
}