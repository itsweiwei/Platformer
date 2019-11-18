#include "Level1.h"

#define LEVEL1_WIDTH 100
#define LEVEL1_HEIGHT 8
#define LV1_ENEMY_COUNT 3

unsigned int level1_data[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void Level1::Initialize() {
	GLuint mapTextureID = Util::LoadTexture("tileset.png");
	state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, level1_data, mapTextureID, 1.0f, 4, 1);
	state.player.entityType = PLAYER;
	state.player.livesCount = 1;
	state.player.isStatic = false;
	state.player.width = 1.0f;
	state.player.height = 1.0f;
	state.player.position = glm::vec3(5, 0, 0);
	state.player.acceleration = glm::vec3(0, -9.81f, 0);
	state.player.cols = 4;
	state.player.rows = 1;
	state.player.animIndices = new int[4];

	for (int i = 0; i < 4; i++) {
		state.player.animIndices[i] = i;
	}

	state.player.animFrames = 4;
	state.player.textureID = Util::LoadTexture("pinkbean.png");

	state.enemiesList[0].entityType = ENEMY_PATROL;
	state.enemiesList[0].isStatic = false;
	state.enemiesList[0].width = 1.0f;
	state.enemiesList[0].height = 1.0f;
	state.enemiesList[0].position = glm::vec3(45, 0, 0);
	state.enemiesList[0].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[0].velocity = glm::vec3(-2.0f, 0, 0);
	state.enemiesList[0].cols = 5;
	state.enemiesList[0].rows = 1;
	state.enemiesList[0].animIndices = new int[5];

	for (int i = 0; i < 5; i++) {
		state.enemiesList[0].animIndices[i] = i;
	}

	state.enemiesList[0].animFrames = 5;
	state.enemiesList[0].textureID = Util::LoadTexture("mushmom.png");

	state.enemiesList[1].entityType = ENEMY_JUMP;
	state.enemiesList[1].isStatic = false;
	state.enemiesList[1].width = 1.0f;
	state.enemiesList[1].height = 1.0f;
	state.enemiesList[1].position = glm::vec3(73, 0, 0);
	state.enemiesList[1].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[1].cols = 3;
	state.enemiesList[1].rows = 1;
	state.enemiesList[1].animIndices = new int[3];

	for (int i = 0; i < 3; i++) {
		state.enemiesList[1].animIndices[i] = i;
	}

	state.enemiesList[1].animFrames = 3;
	state.enemiesList[1].textureID = Util::LoadTexture("slime.png");

	state.enemiesList[2].entityType = ENEMY_PATROL;
	state.enemiesList[2].isStatic = false;
	state.enemiesList[2].width = 1.0f;
	state.enemiesList[2].height = 1.0f;
	state.enemiesList[2].position = glm::vec3(85, 0, 0);
	state.enemiesList[2].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[2].velocity = glm::vec3(-2.0f, 0, 0);
	state.enemiesList[2].cols = 5;
	state.enemiesList[2].rows = 1;
	state.enemiesList[2].animIndices = new int[5];

	for (int i = 0; i < 5; i++) {
		state.enemiesList[2].animIndices[i] = i;
	}

	state.enemiesList[2].animFrames = 5;
	state.enemiesList[2].textureID = Util::LoadTexture("mushmom.png");

	/*state.key.entityType = KEY;
	state.key.isStatic = false;
	state.key.isActive = true;
	state.key.width = 0.5f;
	state.key.height = 0.5f;
	state.key.position = glm::vec3(68, -2, 0);
	state.key.acceleration = glm::vec3(0);
	state.key.cols = 1;
	state.key.rows = 1;
	state.key.animIndices = new int[1]{ 0 };
	state.key.animFrames = 1;
	state.key.textureID = Util::LoadTexture("pinkholycup.png");*/

	state.nextLevel = -1;
}

void Level1::Update(float deltaTime) {
	if (state.player.isActive) {
		state.player.Update(deltaTime, state.enemiesList, LV1_ENEMY_COUNT, state.map);
		//state.player.CheckCollision(&(state.key));
	}

	for (int i = 0; i < LV1_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Update(deltaTime, NULL, 0, state.map);
		}
	}

	if (state.player.position.x > 100) {
		state.nextLevel = 2;
	}
}

void Level1::Render(ShaderProgram* program) {
	state.map->Render(program);
	state.player.Render(program);
	/*if (state.key.isActive) {
		state.key.Render(program);
	}*/
	for (int i = 0; i < LV1_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Render(program);
		}
	}
}
