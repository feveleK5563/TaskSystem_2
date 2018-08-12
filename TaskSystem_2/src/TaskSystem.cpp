#include "TaskSystem.h"
#include <algorithm>

TaskSystem::TaskSystem() {}

TaskSystem::~TaskSystem()
{
	AllDeleteTask();
}

//�X�V
bool TaskSystem::Update()
{
	bool isHaveTask;
	if (isHaveTask = AllUpdate()) //�S�Ẵ^�X�N��Update���Ă�
	{
		AddTask();			//�ǉ��\��̃^�X�N��ǉ�����
		StateDeleteTask();	//��Ԃ�Delete�̃^�X�N���폜����
		SortTask();			//priority����ɏ����Ƀ\�[�g����
	}
	return isHaveTask;
}

//�`��
void TaskSystem::Draw()
{
	for (auto& it : task)
	{
		if (it->GetTaskState() != TaskState::Kill)
			it->Draw();
	}
}

//�^�X�N��ǉ�����
void TaskSystem::AddTask(std::shared_ptr<TaskAbstract> createObj)
{
	if (createObj != nullptr)
	{
		addTask.emplace_back(createObj);
		taskData[addTask.back()->GetGroupName()].emplace_back(createObj);
	}
}

//�C���X�^���X�𓾂�
TaskSystem& TaskSystem::GetInstance()
{
	static TaskSystem ts;
	return ts;
}

//�w�肵���O���[�v���̃^�X�N�����݂��Ă��邩���ׁA��������true��Ԃ�
bool TaskSystem::FindTask(const std::string& groupName)
{
	return taskData.count(groupName);
}

//�w�肵���O���[�v���̃^�X�N�̏�Ԃ�Kill�ɂ���
void TaskSystem::KillTask(const std::string& groupName)
{
	if (!taskData.count(groupName))
		return;

	for (auto it : taskData[groupName])
	{
		it->KillMe();
	}
}

//�o�^����Ă���^�X�N�̏�Ԃ�S��Kill�ɂ���
void TaskSystem::AllKillTask()
{
	for (auto map : taskData)
	{
		for (auto it : map.second)
		{
			it->KillMe();
		}
	}
}

//�o�^�ρA�o�^�\��̃^�X�N��S�ċ����폜����(�f�X�g���N�^�ŌĂ΂��)
void TaskSystem::AllDeleteTask()
{
	task.clear();
	task.emplace_back();

	addTask.clear();
	addTask.emplace_back();

	taskData.clear();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//�S�Ẵ^�X�N��Update���Ă�
bool TaskSystem::AllUpdate()
{
	//����^�X�N�����݂��Ȃ������ꍇ��false��Ԃ�
	if (addTask.empty() && task.empty())
	{
		return false;
	}

	//��ɓo�^�\��^�X�N��Update���Ă�
	for (auto& it : addTask)
	{
		it->Update();
	}

	//�o�^�ς݃^�X�N��Update���Ă�
	for (auto& it : task)
	{
		switch (it->GetTaskState())
		{
		case TaskState::Active:	//��Ԃ��ʏ�̏ꍇ�͕��ʂɍX�V
			it->Update();
			break;

		case TaskState::Kill:	//��Ԃ��폜�v�����̏ꍇ�͏I���������Ă�
			it->Finalize();
			it->SetTaskState(TaskState::Delete);
			break;
		}
	}
	return true;
}

//�ǉ��\��̃^�X�N��ǉ�����
void TaskSystem::AddTask()
{
	if (addTask.empty())
		return;

	task.insert(task.end(), addTask.begin(), addTask.end());
	addTask.clear();
	addTask.shrink_to_fit();
}

//��Ԃ�Delete�̃^�X�N���폜����
void TaskSystem::StateDeleteTask()
{
	auto deleteCondition =		//�폜���������(��Ԃ�Delete�̎��ɍ폜)
		[](std::shared_ptr<TaskAbstract>& obj)
	{
		return (obj->GetTaskState() == TaskState::Delete);
	};

	{//�I�u�W�F�N�g�̍폜
		const auto& removeIt = std::remove_if(task.begin(), task.end(), deleteCondition);
		task.erase(removeIt, task.end());
		task.shrink_to_fit();
	}

	//�f�[�^�̍폜
	for (auto it = taskData.begin();
		 it != taskData.end();)
	{
		const auto& removeIt = std::remove_if(it->second.begin(), it->second.end(), deleteCondition);
		it->second.erase(removeIt, it->second.end());
		it->second.shrink_to_fit();

		if ((int)it->second.size() == 0)
		{
			it = taskData.erase(it);
			continue;
		}
		++it;
	}
}

//priority����ɏ����Ƀ\�[�g����
void TaskSystem::SortTask()
{
	std::sort(task.begin(), task.end(), 
		[](std::shared_ptr<TaskAbstract>& left, std::shared_ptr<TaskAbstract>& right)
		{
			return (left->GetPriority() < right->GetPriority());
		}
	);
}