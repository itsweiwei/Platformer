#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#include <vector>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_mixer.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#include "Util.h"

#include "Effects.h"

#include "Entity.h"
#include "Map.h"

#include "Scene.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"


SDL_Window* displayWindow;
bool gameIsRunning = true;
int currentLvl = 0;
ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;

Effects* effects;

Mix_Music* music;
Mix_Chunk* jumpSound;

GLuint fontTextureID;

Scene* currentScene;
Scene* sceneList[4];

void SwitchToScene(Scene* scene) {
	currentScene = scene;
	currentScene->Initialize();
}


void Initialize() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	displayWindow = SDL_CreateWindow("Platformer!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
	glewInit();
#endif

	glViewport(0, 0, 640, 480);

	program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

	fontTextureID = Util::LoadTexture("font.png");


	viewMatrix = glm::mat4(1.0f);
	modelMatrix = glm::mat4(1.0f);
	projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

	program.SetProjectionMatrix(projectionMatrix);
	program.SetViewMatrix(viewMatrix);
	program.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	glUseProgram(program.programID);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glClearColor(0, 0, 0, 1.0f);

	sceneList[0] = new MainMenu();
	sceneList[1] = new Level1();
	sceneList[2] = new Level2();
	sceneList[3] = new Level3();

	SwitchToScene(sceneList[0]);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

	jumpSound = Mix_LoadWAV("jump.wav");

	effects = new Effects(projectionMatrix, viewMatrix);
}

void ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
		case SDL_WINDOWEVENT_CLOSE:
			gameIsRunning = false;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				Mix_PlayChannel(-1, jumpSound, 0);
				currentScene->state.player.Jump();
				break;
			case SDLK_LEFT:
				currentScene->state.player.facingLeft = true;
				break;
			case SDLK_RIGHT:
				currentScene->state.player.facingLeft = false;
			}
			break;
		}
	}

	currentScene->state.player.velocity.x = 0;

	// Check for pressed/held keys below
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_LEFT])
	{
		currentScene->state.player.velocity.x = -3.0f;
	}
	else if (keys[SDL_SCANCODE_RIGHT]){
		currentScene->state.player.velocity.x = 3.0f;
	}
}

#define FIXED_TIMESTEP 0.0166666f
float lastTicks = 0;
float accumulator = 0.0f;

void Update() {
	float ticks = (float)SDL_GetTicks() / 1000.0f;
	float deltaTime = ticks - lastTicks;
	lastTicks = ticks;

	deltaTime += accumulator;
	if (deltaTime < FIXED_TIMESTEP) {
		accumulator = deltaTime;
		return;
	}

	while (deltaTime >= FIXED_TIMESTEP) {

		currentScene->Update(FIXED_TIMESTEP);
		effects->Update(FIXED_TIMESTEP);


		deltaTime -= FIXED_TIMESTEP;
	}

	accumulator = deltaTime;

	viewMatrix = glm::mat4(1.0f);

	if (currentScene->state.player.position.x > 5) {
		viewMatrix = glm::translate(viewMatrix, glm::vec3(-currentScene->state.player.position.x, 3.75, 0));
	}
	else {
		viewMatrix = glm::translate(viewMatrix, glm::vec3(-5, 3.75, 0));
	}

	viewMatrix = glm::translate(viewMatrix, effects->viewTranslate);
}


void Render() {
	glUseProgram(program.programID);

	glClear(GL_COLOR_BUFFER_BIT);

	program.SetViewMatrix(viewMatrix);

	currentScene->Render(&program);

	if (currentScene->state.player.livesCount <= 0) {
		Util::DrawText(&program, fontTextureID, "Game Over", 1.0f, 0.01f, glm::vec3(currentScene->state.player.position.x -	4.0f, -3.75f, 0));
	}

	if (currentScene->state.nextLevel == 0 && currentScene->state.player.position.x > 60) {
		Util::DrawText(&program, fontTextureID, "You Win!", 1.0f, 0.01f, glm::vec3(currentScene->state.player.position.x - 4.0f, -3.75f, 0));
	}

	effects->Render();
	SDL_GL_SwapWindow(displayWindow);
}

void Shutdown() {
	Mix_FreeChunk(jumpSound);
	Mix_FreeMusic(music);
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	Initialize();

	while (gameIsRunning) {
		if (currentScene->state.nextLevel >= 0) SwitchToScene(sceneList[currentScene->state.nextLevel]);
		ProcessInput();
		Update();
		Render();
	}

	Mix_HaltMusic();

	Shutdown();
	return 0;
}
