#include <crtdbg.h>
#include "GameSystem.h"


int main()
{
	//�A�C�R���ύX
	//SetWindowIconID(4210);

	//���������[�N���o 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameSystem gs;
	gs.Initialize();

	gs.MainLoop();

	gs.Finalize();
	return 0;
}
