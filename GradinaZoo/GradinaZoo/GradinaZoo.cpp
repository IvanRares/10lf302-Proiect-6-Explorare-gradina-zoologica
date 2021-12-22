#include"Game.h"

int main()
{
	Game game("Gradina Zoo", 1280, 720, true);
	//Main loop

	while (!game.GetWindowShouldClose())
	{
		game.Update();
		game.Render();
	}

	//End of program
	glfwTerminate();

	return 0;
}