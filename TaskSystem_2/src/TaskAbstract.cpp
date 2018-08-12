#include "TaskAbstract.h"

TaskAbstract::TaskAbstract(	const std::string& groupName,
							float priority,
							TaskState state):
	groupName(groupName),
	priority(priority),
	taskState(state) {}

//�������E��
void TaskAbstract::KillMe()
{
	taskState = TaskState::Kill;
}

//�`��D��x��ݒ�
void TaskAbstract::SetPriority(float priority)
{
	this->priority = priority;
}
//�^�X�N�̏�Ԃ�ݒ�
void TaskAbstract::SetTaskState(TaskState taskState)
{
	this->taskState = taskState;
}


//�^�X�N�̃O���[�v�����擾
const std::string& TaskAbstract::GetGroupName()
{
	return groupName;
}
//�`��D��x���擾
const float& TaskAbstract::GetPriority()
{
	return priority;
}
//�^�X�N�̏�Ԃ��擾
const TaskState& TaskAbstract::GetTaskState()
{
	return taskState;
}