#ifndef _MATHS_H_
#define _MATHS_H_
#include <math.h>
struct Vector2
{
	float x, y;

	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float a_x, float a_y)
	{
		x = a_x;
		y = a_y;
	}
	float Distance(Vector2 &other)
	{
		return(sqrtf(((x - other.x)*(x - other.x)) + ((y - other.y)*(y - other.y))));
	}
	float Dot(Vector2 &other)
	{
		return ((x*other.x) + (y*other.y));
	}
	void Zero()
	{
		x = 0;
		y = 0;
	}
	Vector2 operator * (Vector2 &other)
	{
		Vector2 temp;
		temp.y = y * other.y;
		temp.x = x * other.x;
		return temp;
	}
	Vector2 operator * (float &value)
	{
		Vector2 temp;
		temp.y = y * value;
		temp.x = x * value;
		return temp;
	}
	Vector2 operator + (Vector2 &other)
	{
		Vector2 temp;
		temp.y = y + other.y;
		temp.x = x + other.x;
		return temp;

	}
	void operator *= (Vector2 &other)
	{
		y *= other.y;
		x *= other.x;
	

	}
	void operator += (Vector2 &other)
	{
		y += other.y;
		x += other.x;
	}
	void operator = (Vector2 &other)
	{
		y = other.y;
		x = other.x;
	}
};

#endif
