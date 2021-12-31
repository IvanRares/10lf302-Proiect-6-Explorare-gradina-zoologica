#include"Game.h"

void ShowControls()
{
	std::cout << "Controls:" << std::endl;
	std::cout << "[W, A, S, D]: move camera" << std::endl;
	std::cout << "[C]: activate camera collisions" << std::endl;
	std::cout << "[V]: activate free camera look" << std::endl;
}

int main()
{
	ShowControls();
	Game game("Gradina Zoo", 1920, 1080, true);
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