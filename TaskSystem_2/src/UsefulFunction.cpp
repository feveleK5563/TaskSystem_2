#include "UsefulFunction.h"

namespace UF
{
	//���|�C���^�����S��delete����
	template<class T>void SafeDelete(T& t)
	{
		if (t != nullptr)
		{
			delete t;
			t = nullptr;
		}
	}

	//���|�C���^�����S��delete����(�z���)
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

	//�͈͓��Ń����_���Ȓl���w������擾����
	int GetRand(int lowerLimit, int upperLimit)
	{
		std::uniform_int_distribution<> randRange(lowerLimit, upperLimit);
		return randRange(mtrand);
	}
}