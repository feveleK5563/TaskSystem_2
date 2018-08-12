#pragma once

//���Ԍv������
class TimeCounter
{
private:
	int cntTime;	//�o�ߎ���
	int endTime;	//�I������
	int addVol;		//���Z�����
	bool isTimeEnd;	//�I�����Ԉȏ�v�����Ă��邩�ۂ�

public:
	//�R���X�g���N�^(�I�����Ԑݒ�͖���)
	TimeCounter();
	//�R���X�g���N�^(�I�����Ԃ��w��(-1�Ŗ���))
	TimeCounter(int endTime);
	//�R���X�g���N�^(�I�����ԂƉ��Z�ʂ��w��)
	TimeCounter(int endTime, int addVol);

	//�o�ߎ��Ԃ�0�ɂ���
	void ResetCntTime();

	//�I�����Ԃ�ݒ肷��(-1�Ŗ���)
	void SetEndTime(int endTime);

	//���Ԃ𑪂�
	//�I�����Ԃ��L���̏ꍇ�A���̎��Ԉȏ�ɂȂ������~����
	void Run();

	//���݂̌o�ߎ��Ԃ�Ԃ�
	const int& GetNowCntTime() const;

	//�c�莞��(�I������-�o�ߎ���)��Ԃ�
	int GetRemainingTime() const;

	//�I�����Ԃ�Ԃ�
	const int& GetEndTime() const;

	//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
	const bool& IsTimeEnd() const;
};

//-----------------------------------------------------------------------------

//���Ԍv������(float�o�[�W����)
class TimeCounterF
{
private:
	float	cntTime;	//�o�ߎ���
	float	endTime;	//�I������
	float	addVol;		//���Z�����
	bool	isTimeEnd;	//�I�����Ԉȏ�v�����Ă��邩�ۂ�

public:
	//�R���X�g���N�^(�I�����Ԑݒ�͖���)
	TimeCounterF();
	//�R���X�g���N�^(�I�����Ԃ��w��(-1.f�Ŗ���))
	TimeCounterF(float endTime);
	//�R���X�g���N�^(�I�����ԂƉ��Z�ʂ��w��)
	TimeCounterF(float endTime, float addVol);

	//�o�ߎ��Ԃ�0.f�ɂ���
	void ResetCntTime();

	//�I�����Ԃ�ݒ肷��(-1.f�Ŗ���)
	void SetEndTime(float endTime);

	//���Ԃ𑪂�
	//�I�����Ԃ��L���̏ꍇ�A���̎��Ԉȏ�ɂȂ������~����
	void Run();

	//���݂̌o�ߎ��Ԃ�Ԃ�
	const float& GetNowCntTime() const;

	//�c�莞��(�I������-�o�ߎ���)��Ԃ�
	float GetRemainingTime() const;

	//�I�����Ԃ�Ԃ�
	const float& GetEndTime() const;

	//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
	const bool& IsTimeEnd() const;
};