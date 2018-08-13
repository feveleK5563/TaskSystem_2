#pragma once
#include <vector>
#include <memory>
#include <string>
#include <map>

enum struct TaskState
{
	Ready,		//����
	Active,		//�ʏ�
	Stop,		//��~
	Kill,		//���ŗv��
	Delete,		//����
}; 

class TaskAbstract
{
private:
	const std::string	groupName;	//�O���[�v��
	const std::string	taskName;	//�^�X�N��
	float				priority;	//�`��D��x
	TaskState			taskState;	//���

public:

	//�R���X�g���N�^
	TaskAbstract(	const std::string& groupName,
					const std::string& taskName,
					float priority,
					TaskState state = TaskState::Active);

	//�f�X�g���N�^
	virtual ~TaskAbstract() {};
	
	virtual void Initialize() = 0;	//����������
	virtual void Finalize() = 0;	//�I������
	virtual void Update() = 0;		//�X�V
	virtual void Draw() = 0;		//�`��

	void KillMe();	//�������E��

	void SetPriority(float priority);		//�`��D��x��ݒ�
	void SetTaskState(TaskState taskState);	//�^�X�N�̏�Ԃ�ݒ�

	const std::string&	GetGroupName();	//�^�X�N�̃O���[�v�����擾
	const std::string&	GetTaskName();	//�^�X�N�����擾
	const float&		GetPriority();	//�`��D��x���擾
	const TaskState&	GetTaskState();	//�^�X�N�̏�Ԃ��擾
};