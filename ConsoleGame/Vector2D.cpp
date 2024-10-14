#include <cmath>
#include "Vector2D.hpp"

namespace Utils
{
	const Vector2D Vector2D::UP(0, 1);
	const Vector2D Vector2D::DOWN(0, -1);
	const Vector2D Vector2D::LEFT(-1, 0);
	const Vector2D Vector2D::RIGHT(1,0);

	Vector2D::Vector2D(double xComp, double yComp) 
		: _x(xComp), _y(yComp), x(_x), y(_y)
	{

	}

	Vector2D::Vector2D(const Vector2D& vec) 
		: _x(vec.x), _y(vec.y), x(_x), y(_y)
	{

	}

	double Vector2D::CalcDirection(const Vector2D &vec)
	{
		if (vec.x == 0) return vec.y;
		else if (vec.y == 0) return vec.x;
		return std::atan2(vec.y, vec.x);
	}

	double Vector2D::CalcMagnitude(const Vector2D &vec)
	{
		return std::sqrt(std::pow(vec.x, 2)+std::pow(vec.y, 2));
	}

	Vector2D Vector2D::Normalize(const Vector2D &vec) 
	{
		double magnitude = CalcMagnitude(vec);
		Vector2D unit(vec.x/magnitude, vec.y/magnitude);
		return unit;
	}

	/// <summary>
	/// Gets the direction of the vector in radians
	/// </summary>
	/// <returns></returns>
	double Vector2D::GetDirection() const
	{
		return CalcDirection(*this);
	}

	double Vector2D::GetMagnitude() const
	{
		return CalcMagnitude(*this);
	}

	Vector2D Vector2D::GetNormalized() const 
	{
		return Normalize(*this);
	}

	Vector2D Vector2D::operator+(const Vector2D& otherVec) const
	{
		Vector2D resultant(x + otherVec.x, y + otherVec.y);
		return resultant;
	}

	Vector2D Vector2D::operator-(const Vector2D& otherVec) const
	{
		Vector2D resultant(x - otherVec.x, y - otherVec.y);
		return resultant;
	}

	Vector2D Vector2D::operator*(const Vector2D& otherVec) const
	{
		Vector2D resultant(x * otherVec.x, y * otherVec.y);
		return resultant;
	}

	Vector2D Vector2D::operator*(const double scalar) const
	{
		Vector2D resultant(x * scalar, y * scalar);
		return resultant;
	}

	Vector2D Vector2D::operator/(const Vector2D& otherVec) const
	{
		Vector2D resultant(x / otherVec.x, y / otherVec.y);
		return resultant;
	}
}