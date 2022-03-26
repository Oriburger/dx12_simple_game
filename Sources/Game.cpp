#include "Game.h"

Game::Game()
{
	mIsRunning = true;
	mWindow = nullptr;
}

bool Game::Initialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);

	if (sdlResult != 0)
	{
		SDL_Log("Unable to initalize SDL : %s", SDL_GetError());
		return false; 
	}
	
	mWindow = SDL_CreateWindow(
		"Oriburger Game (TEST) ",
		100,  //윈도우 좌측 상단 x좌표
		100,  //윈도우 좌측 상단 y좌표
		1024, //윈도우 너비
		768,  //윈도우 높이
		0	  //Flag
	);

	if (!mWindow)      
	{
		SDL_Log("Failed to create winodw : %s", SDL_GetError());
		return false;
	}
	return true;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}