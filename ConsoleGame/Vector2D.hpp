#pragma once

namespace Utils 
{
	class Vector2D
	{
	private:
		double _x;
		double _y;

		static double CalcDirection(const Vector2D&);
		static double CalcMagnitude(const Vector2D&);
		static Vector2D Normalize(const Vector2D&);

	public:
		const double &x;
		const double &y;

		static const Vector2D UP;
		static const Vector2D DOWN;
		static const Vector2D LEFT;
		static const Vector2D RIGHT;
		
		Vector2D(double, double);
		Vector2D(const Vector2D&);

		double GetDirection() const;
		double GetMagnitude() const;
		Vector2D GetNormalized() const;

		Vector2D operator+(const Vector2D&) const;
		Vector2D operator-(const Vector2D&) const;
		Vector2D operator*(const Vector2D&) const;
		Vector2D operator*(const double) const;
		Vector2D operator/(const Vector2D&) const;
	};
}
