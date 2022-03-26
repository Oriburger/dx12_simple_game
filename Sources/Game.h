#pragma once
#include <SDL.h>

class Game
{
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	bool mIsRunning;

public:
	Game();
	
	bool Initialize();
	void RunLoop();
	void Shutdown();
};