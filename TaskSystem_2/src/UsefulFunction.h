#pragma once
#include <random>
#include <memory>
#include <vector>

namespace UF
{
	//���|�C���^�����S��delete����
	template<class T> void SafeDelete(T& t);
	//���|�C���^�����S��delete����(�z���)
	template<class T> void SafeDeleteArr(T& t);

	//�͈͓��Ń����_���Ȓl���w������擾����
	int GetRand(int lowerLimit, int upperLimit);
};