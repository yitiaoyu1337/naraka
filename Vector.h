#pragma once
#include <cmath>
#define CHECK_VALID( _v ) 0
#define Assert(x)


class Vector3
{
public:
	float x, y, z;
	Vector3(void);
	Vector3(float X, float Y, float Z);
	inline float	DistTo(const Vector3& vOther) const;
	inline float	Length() const;

};
inline Vector3::Vector3(void) { x = y = z = 0.0f; }
inline Vector3::Vector3(float X, float Y, float Z)
{
	x = X; y = Y; z = Z;
	CHECK_VALID(*this);
}
float Vector3::DistTo(const Vector3& vOther) const
{
	Vector3 delta;

	delta.x = x - vOther.x;
	delta.y = y - vOther.y;
	delta.z = z - vOther.z;

	return delta.Length();
}
inline float Vector3::Length(void) const
{
	CHECK_VALID(*this);

	float root = 0.0f;

	float sqsr = x * x + y * y + z * z;

	root = (float)sqrt(sqsr);

	return root;
}



class Vector2
{
public:
	float x, y;
	Vector2(void);
	Vector2(float X, float Y);
	bool IsValid() const;

};
inline unsigned long& FloatBits(float& f)
{
	return *reinterpret_cast<unsigned long*>(&f);
}
inline bool IsFinite(float f)
{
	return ((FloatBits(f) & 0x7F800000) != 0x7F800000);
}
inline bool Vector2::IsValid() const
{
	return IsFinite(x) && IsFinite(y);
}
inline Vector2::Vector2(void)
{
#ifdef _DEBUG
	// Initialize to NAN to catch errors
	//x = y = float_NAN;
#endif
	x = y = 0.0f;
}
inline Vector2::Vector2(float X, float Y)
{
	x = X; y = Y;
	Assert(IsValid());
}



typedef struct _D3DMATRIXEx {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};
} D3DMATRIXEx;

class Vector4
{
public:
	float x, y, w, h;
};

