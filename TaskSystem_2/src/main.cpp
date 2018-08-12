#include <crtdbg.h>
#include "GameSystem.h"


int main()
{
	//アイコン変更
	//SetWindowIconID(4210);

	//メモリリーク検出 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameSystem gs;
	gs.Initialize();

	gs.MainLoop();

	gs.Finalize();
	return 0;
}
