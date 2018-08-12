#include "GameSystem.h"
#include "TaskSystem.h"
#include "Task_TaskOne.h"

GameSystem::GameSystem(){}

//-----------------------------------------------------------------------------
//����������
void GameSystem::Initialize()
{
	//�^�X�N�𐶐�����
	FirstCreateTask();
}

//-----------------------------------------------------------------------------
//���C�����[�v
void GameSystem::MainLoop()
{
	while (Run())
	{
		//�^�X�N�����݂��Ȃ������ꍇ�͏I������
		if (!TS::taskSystem.Update())
			break;

		TS::taskSystem.Draw();
	}
	TS::taskSystem.AllDeleteTask();
}

//-----------------------------------------------------------------------------
//�I������
void GameSystem::Finalize()
{

}

//-----------------------------------------------------------------------------
//���[�v���񂷍ۂ̔��菈��
bool GameSystem::Run()
{
	//�u����L�[��������Ă��Ȃ��Ƃ��v���̔��莮������
	return true;
}

//-----------------------------------------------------------------------------
//�ŏ��ɍ쐬����^�X�N
void GameSystem::FirstCreateTask()
{
	//�Q�[���J�n���ɍ쐬����^�X�N�������ɓ���
	TaskOne::Task::Create();
}