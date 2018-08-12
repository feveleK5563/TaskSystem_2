#pragma once
#include <random>
#include <memory>
#include <vector>

namespace UF
{
	//生ポインタを安全にdeleteする
	template<class T> void SafeDelete(T& t);
	//生ポインタを安全にdeleteする(配列版)
	template<class T> void SafeDeleteArr(T& t);

	//範囲内でランダムな値を指定個数分取得する
	int GetRand(int lowerLimit, int upperLimit);
};