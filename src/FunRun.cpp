#include <SFML/Graphics.hpp>
#include "GameManager.h"


#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#else
#pragma comment(lib, "sfml-main.lib")
#endif


int main()
{
	GameManager game(1200, 300, "FunRun");
	game.run();


	return 0;
}

