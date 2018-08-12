#pragma once
#include <math.h>

namespace Math
{
	static const float PI = 3.1415926535897932384626433832795028841971f;

	//�ʓx�@�ϊ�
	float ToRadian(float val);
	//�x���@�ϊ�
	float ToDegree(float val);

	//�񎟌��x�N�g���N���X
	class Vec2
	{
	public:
		float x, y;

		Vec2();
		Vec2(const Vec2& setVec);
		Vec2(float setX, float setY);

		Vec2&	operator =(const Vec2& vec);
		Vec2	operator +(const Vec2& vec) const;
		Vec2	operator -(const Vec2& vec) const;
		Vec2	operator *(float mul) const;
		Vec2	operator /(float div) const;
		Vec2&	operator +=(const Vec2& vec);
		Vec2&	operator -=(const Vec2& vec);
		Vec2&	operator *=(float mul);
		Vec2&	operator /=(float div);
	};

	//�����蔻��@�\����`�N���X
	class Box2D
	{
	public:
		int x, y, w, h;
		int baseX, baseY;

		Box2D();
		Box2D(const Box2D& setBox);
		Box2D(int setX, int setY, int setW, int setH);

		bool IsHit(const Box2D& box) const;
		bool IsIn(const Box2D& box) const;

		void Offset(int setX, int setY);
		void Offset(const Vec2& vec);

		Box2D OffsetCpy(int setX, int setY) const;
		Box2D OffsetCpy(const Vec2& vec) const;

		Box2D&	operator =(const Box2D& box);
		Box2D	operator +(const Box2D& box) const;
		Box2D	operator -(const Box2D& box) const;
		Box2D	operator *(int mul) const;
		Box2D	operator /(int div) const;
		Box2D&	operator +=(const Box2D& box);
		Box2D&	operator -=(const Box2D& box);
		Box2D&	operator *=(int mul);
		Box2D&	operator /=(int div);
	};
}