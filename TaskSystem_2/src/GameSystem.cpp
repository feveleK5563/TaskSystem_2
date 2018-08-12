#include "GameSystem.h"
#include "TaskSystem.h"
#include "Task_TaskOne.h"

GameSystem::GameSystem(){}

//-----------------------------------------------------------------------------
//初期化処理
void GameSystem::Initialize()
{
	//タスクを生成する
	FirstCreateTask();
}

//-----------------------------------------------------------------------------
//メインループ
void GameSystem::MainLoop()
{
	while (Run())
	{
		//タスクが存在しなかった場合は終了する
		if (!TS::taskSystem.Update())
			break;

		TS::taskSystem.Draw();
	}
	TS::taskSystem.AllDeleteTask();
}

//-----------------------------------------------------------------------------
//終了処理
void GameSystem::Finalize()
{

}

//-----------------------------------------------------------------------------
//ループを回す際の判定処理
bool GameSystem::Run()
{
	//「特定キーが押されていないとき」等の判定式を書く
	return true;
}

//-----------------------------------------------------------------------------
//最初に作成するタスク
void GameSystem::FirstCreateTask()
{
	//ゲーム開始時に作成するタスクをここに入力
	TaskOne::Task::Create();
}