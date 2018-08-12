#include "TimeCounter.h"

TimeCounter::TimeCounter():
	cntTime(0),
	endTime(-1),
	addVol(1),
	isTimeEnd(false) {}

TimeCounter::TimeCounter(int endTime):
	cntTime(0),
	endTime(endTime),
	addVol(1),
	isTimeEnd(false) {}

TimeCounter::TimeCounter(int endTime, int addVol):
	cntTime(0),
	endTime(endTime),
	addVol(addVol),
	isTimeEnd(false){}

//�o�ߎ��Ԃ�0�ɂ���
void TimeCounter::ResetCntTime()
{
	cntTime = 0;
	isTimeEnd = false;
}

//�I�����Ԃ�ݒ肷��
void TimeCounter::SetEndTime(int endTime)
{
	this->endTime = endTime;
	isTimeEnd = false;
}

//���Ԃ𑪂�
void TimeCounter::Run()
{
	if (endTime >= 0 &&
		cntTime >= endTime)
	{
		cntTime = endTime;
		isTimeEnd = true;
		return;
	}

	cntTime += addVol;
}

//���݂̌o�ߎ��Ԃ�Ԃ�
const int& TimeCounter::GetNowCntTime() const
{
	return cntTime;
}

//�c�莞��(�I������-�o�ߎ���)��Ԃ�
int TimeCounter::GetRemainingTime() const
{
	return endTime - cntTime;
}

//�I�����Ԃ�Ԃ�
const int& TimeCounter::GetEndTime() const
{
	return endTime;
}

//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
const bool& TimeCounter::IsTimeEnd() const
{
	return isTimeEnd;
}

//-----------------------------------------------------------------------------

TimeCounterF::TimeCounterF() :
	cntTime(0.f),
	endTime(-1.f),
	addVol(1.f),
	isTimeEnd(false) {}

TimeCounterF::TimeCounterF(float endTime):
	cntTime(0.f),
	endTime(endTime),
	addVol(1.f),
	isTimeEnd(false) {}

TimeCounterF::TimeCounterF(float endTime, float addVol):
	cntTime(0.f),
	endTime(endTime),
	addVol(addVol),
	isTimeEnd(false) {}


//�o�ߎ��Ԃ�0.f�ɂ���
void TimeCounterF::ResetCntTime()
{
	cntTime = 0.f;
	isTimeEnd = false;
}

//�I�����Ԃ�ݒ肷��
void TimeCounterF::SetEndTime(float endTime)
{
	this->endTime = endTime;
	isTimeEnd = false;
}

//���Ԃ𑪂�
void TimeCounterF::Run()
{
	if (endTime >= 0.f &&
		cntTime >= endTime)
	{
		cntTime = endTime;
		isTimeEnd = true;
		return;
	}

	cntTime += addVol;
}

//���݂̌o�ߎ��Ԃ�Ԃ�
const float& TimeCounterF::GetNowCntTime() const
{
	return cntTime;
}

//�c�莞��(�I������-�o�ߎ���)��Ԃ�
float TimeCounterF::GetRemainingTime() const
{
	return endTime - cntTime;
}

//�I�����Ԃ�Ԃ�
const float& TimeCounterF::GetEndTime() const
{
	return endTime;
}

//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
const bool& TimeCounterF::IsTimeEnd() const
{
	return isTimeEnd;
}