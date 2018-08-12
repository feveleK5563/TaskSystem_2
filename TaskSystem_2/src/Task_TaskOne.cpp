#include "Task_TaskOne.h"

#include <iostream>
#include "Task_TaskTwo.h"

namespace TaskOne
{
	std::weak_ptr<Resource> Resource::instance;
	//----------------------------------------------
	//���\�[�X�̃R���X�g���N�^
	Resource::Resource()
	{

	}
	//----------------------------------------------
	//���\�[�X�̃f�X�g���N�^
	Resource::~Resource()
	{
		
	}
	//----------------------------------------------
	//���\�[�X�̐���
	std::shared_ptr<Resource> Resource::Create()
	{
		auto sp = instance.lock();
		if (!sp)
		{
			sp = std::make_shared<Resource>();
			instance = sp;
		}
		return sp;
	}

	//��������������������������������������������������������������������������������������������
	//��������������������������������������������������������������������������������������������

	//----------------------------------------------
	//�^�X�N�̃R���X�g���N�^
	Task::Task():
		TaskAbstract(defGroupName, defPriority),
		res(Resource::Create())
	{
	}
	//----------------------------------------------
	//�^�X�N�̃f�X�g���N�^
	Task::~Task()
	{

	}
	//----------------------------------------------
	//�^�X�N�̐���
	std::shared_ptr<Task> Task::Create()
	{
		std::shared_ptr<Task> task = 
			std::make_shared<Task>();
		TS::taskSystem.AddTask(task);

		task->Initialize();
		return task;
	}

	//��������������������������������������������������������������������������������������������
	//��������������������������������������������������������������������������������������������

	//----------------------------------------------
	//����������
	//----------------------------------------------
	void Task::Initialize()
	{
		std::cout << "�^�X�N1�𐶐�\n" << std::endl;
	}

	//----------------------------------------------
	//�I������
	//----------------------------------------------
	void Task::Finalize()
	{
		std::cout << "�^�X�N1���폜\n" << std::endl;
	}

	//----------------------------------------------
	//�X�V
	//----------------------------------------------
	void Task::Update()
	{
		std::cout << " 0 �� �I�� \n 1 �� �^�X�N2�𐶐����A�^�X�N1���폜" << std::endl;
		int hoge;
		std::cin >> hoge;

		switch (hoge)
		{
		case 0:
			//�S�Ẵ^�X�N���폜����ƏI������
			TS::taskSystem.AllKillTask();
			break;

		case 1:
			TaskTwo::Task::Create();
			KillMe();
			break;

		default:
			std::cout << "���̂����c�i�_�ǂ݁j\n" << std::endl;
			break;
		}
	}

	//----------------------------------------------
	//�`��
	//----------------------------------------------
	void Task::Draw()
	{
		std::cout << "�^�X�N1�̕`��\n" << std::endl;
	}
}