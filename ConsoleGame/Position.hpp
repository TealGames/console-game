#pragma once
namespace Utils 
{
	class Position
	{
	private:
		double _x;
		double _y;

	public:
		const double& x;
		const double& y;

		Position(double, double);
		Position();
	};
}