#pragma once
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include "TaskAbstract.h"

class TaskSystem
{
private:
	std::vector<std::shared_ptr<TaskAbstract>> task;
	std::vector<std::shared_ptr<TaskAbstract>> addTask;
	std::unordered_map<std::string, std::vector<std::shared_ptr<TaskAbstract>>> taskData;

public:
	TaskSystem();
	~TaskSystem();

	bool Update();											//�X�V(�^�X�N�����݂��Ȃ������ꍇfalse���Ԃ�)
	void Draw();											//�`��
	void AddTask(std::shared_ptr<TaskAbstract> createObj);	//�^�X�N��ǉ�����

	bool FindTask(const std::string& groupName);	//�w�肵���O���[�v���̃^�X�N�����݂��Ă��邩���ׁA��������true��Ԃ�
	void KillTask(const std::string& groupName);	//�w�肵���O���[�v���̃^�X�N�̏�Ԃ�Kill�ɂ���
	void AllKillTask();								//�o�^����Ă���^�X�N�̏�Ԃ�S��Kill�ɂ���
	void AllDeleteTask();							//�o�^����Ă���^�X�N��S�ċ����폜����(�f�X�g���N�^�ŌĂ΂��)
	
	//�w�肵���O���[�v���̓��A�擪�݂̂�n��
	template<class T>
	std::shared_ptr<const T> GetTaskOne(const std::string& groupName)
	{
		std::shared_ptr<const T> cpyTask;

		if (taskData.count(groupName))
		{
			cpyTask = std::static_pointer_cast<const T>(taskData[groupName].front());
		}

		return cpyTask;
	}

	//�w�肵���O���[�v���̃^�X�N���܂Ƃ߂ēn��
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<const T>>> GetTaskGroup(const std::string& groupName)
	{
		std::shared_ptr<std::vector<std::shared_ptr<const T>>> gd;

		if (taskData.count(groupName))
		{
			gd = std::make_shared<std::vector<std::shared_ptr<const T>>>();

			gd->reserve(taskData[groupName].size() * sizeof(gd));

			for (auto it : taskData[groupName])
			{
				gd->emplace_back(std::static_pointer_cast<const T>(it));
			}
		}

		return gd;
	}

	//�C���X�^���X�𓾂�
	static TaskSystem& GetInstance();

private:
	bool AllUpdate();		//�S�Ẵ^�X�N��Update���Ă�(�^�X�N�����݂��Ȃ������ꍇfalse���Ԃ�)
	void AddTask();			//�ǉ��\��̃^�X�N��ǉ�����
	void StateDeleteTask();	//��Ԃ�Delete�̃^�X�N���폜����
	void SortTask();		//priority����ɏ����Ƀ\�[�g����
};

namespace TS
{
	static TaskSystem& taskSystem = TaskSystem::GetInstance();
}