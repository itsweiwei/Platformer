#include "MainMenu.h"

#define MENU_WIDTH 10
#define MENU_HEIGHT 8

unsigned int mainmenu_data[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void MainMenu::Initialize() {
	GLuint mapTextureID = Util::LoadTexture("mainmenu.png");
	state.map = new Map(MENU_WIDTH, MENU_HEIGHT, mainmenu_data, mapTextureID, 1.0f, 4, 1);

	state.player.entityType = PLAYER;
	state.player.livesCount = 1;
	state.player.isStatic = false;
	state.player.width = 1.0f;
	state.player.height = 1.0f;
	state.player.position = glm::vec3(1, 0, 0);
	state.player.acceleration = glm::vec3(0, -9.81f, 0);
	state.player.cols = 4;
	state.player.rows = 1;
	state.player.animIndices = new int[4];

	for (int i = 0; i < 4; i++) {
		state.player.animIndices[i] = i;
	}

	state.player.animFrames = 4;
	state.player.textureID = Util::LoadTexture("pinkbean.png");

	state.nextLevel = -1;
}

void MainMenu::Update(float deltaTime) {
	state.player.Update(deltaTime, NULL, 0, state.map);

	if (state.player.position.x > 10.0f) {
		state.nextLevel = 1;
	}
}

void MainMenu::Render(ShaderProgram* program) {
	state.player.Render(program);
	state.map->Render(program);
	Util::DrawText(program, Util::LoadTexture("font.png"), "Move right!", 0.7f, 0, glm::vec3( 1.0f, -3.75f, 0));
}
