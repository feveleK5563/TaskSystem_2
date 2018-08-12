#include "Task_TaskOne.h"

#include <iostream>
#include "Task_TaskTwo.h"

namespace TaskOne
{
	std::weak_ptr<Resource> Resource::instance;
	//----------------------------------------------
	//リソースのコンストラクタ
	Resource::Resource()
	{

	}
	//----------------------------------------------
	//リソースのデストラクタ
	Resource::~Resource()
	{
		
	}
	//----------------------------------------------
	//リソースの生成
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

	//☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
	//★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆

	//----------------------------------------------
	//タスクのコンストラクタ
	Task::Task():
		TaskAbstract(defGroupName, defPriority),
		res(Resource::Create())
	{
	}
	//----------------------------------------------
	//タスクのデストラクタ
	Task::~Task()
	{

	}
	//----------------------------------------------
	//タスクの生成
	std::shared_ptr<Task> Task::Create()
	{
		std::shared_ptr<Task> task = 
			std::make_shared<Task>();
		TS::taskSystem.AddTask(task);

		task->Initialize();
		return task;
	}

	//◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆
	//◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇

	//----------------------------------------------
	//初期化処理
	//----------------------------------------------
	void Task::Initialize()
	{
		std::cout << "タスク1を生成\n" << std::endl;
	}

	//----------------------------------------------
	//終了処理
	//----------------------------------------------
	void Task::Finalize()
	{
		std::cout << "タスク1を削除\n" << std::endl;
	}

	//----------------------------------------------
	//更新
	//----------------------------------------------
	void Task::Update()
	{
		std::cout << " 0 → 終了 \n 1 → タスク2を生成し、タスク1を削除" << std::endl;
		int hoge;
		std::cin >> hoge;

		switch (hoge)
		{
		case 0:
			//全てのタスクを削除すると終了する
			TS::taskSystem.AllKillTask();
			break;

		case 1:
			TaskTwo::Task::Create();
			KillMe();
			break;

		default:
			std::cout << "あのさぁ…（棒読み）\n" << std::endl;
			break;
		}
	}

	//----------------------------------------------
	//描画
	//----------------------------------------------
	void Task::Draw()
	{
		std::cout << "タスク1の描画\n" << std::endl;
	}
}