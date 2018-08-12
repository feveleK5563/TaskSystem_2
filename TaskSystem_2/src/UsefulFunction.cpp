#include "UsefulFunction.h"

namespace UF
{
	//生ポインタを安全にdeleteする
	template<class T>void SafeDelete(T& t)
	{
		if (t != nullptr)
		{
			delete t;
			t = nullptr;
		}
	}

	//生ポインタを安全にdeleteする(配列版)
	template<class T>void SafeDeleteArr(T& t)
	{
		if (t != nullptr)
		{
			delete[] t;
			t = nullptr;
		}
	}

	std::random_device rd;
	std::mt19937 mtrand(rd());

	//範囲内でランダムな値を指定個数分取得する
	int GetRand(int lowerLimit, int upperLimit)
	{
		std::uniform_int_distribution<> randRange(lowerLimit, upperLimit);
		return randRange(mtrand);
	}
}