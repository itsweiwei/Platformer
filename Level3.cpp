#include "Level3.h"

#define LEVEL3_WIDTH 100
#define LEVEL3_HEIGHT 8
#define LV3_ENEMY_COUNT 5

unsigned int level3_data[] =
{
	3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 1, 1, 1, 1,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

void Level3::Initialize() {
	GLuint mapTextureID = Util::LoadTexture("tileset.png");
	state.map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, level3_data, mapTextureID, 1.0f, 4, 1);

	state.player.entityType = PLAYER;
	state.player.livesCount = 3;
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
	state.enemiesList[2].position = glm::vec3(15.0f, -3.0f, 0);
	state.enemiesList[2].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[2].velocity = glm::vec3(-3.0f, 0, 0);
	state.enemiesList[2].cols = 6;
	state.enemiesList[2].rows = 1;
	state.enemiesList[2].animIndices = new int[6];

	for (int i = 0; i < 6; i++) {
		state.enemiesList[2].animIndices[i] = i;
	}

	state.enemiesList[2].animFrames = 6;
	state.enemiesList[2].textureID = Util::LoadTexture("ghost.png");

	state.enemiesList[3].entityType = ENEMY_PATROL;
	state.enemiesList[3].isStatic = false;
	state.enemiesList[3].width = 1.0f;
	state.enemiesList[3].height = 1.0f;
	state.enemiesList[3].position = glm::vec3(45.0f, -4.0f, 0);
	state.enemiesList[3].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[3].velocity = glm::vec3(-3.0f, 0, 0);
	state.enemiesList[3].cols = 6;
	state.enemiesList[3].rows = 1;
	state.enemiesList[3].animIndices = new int[6];

	for (int i = 0; i < 6; i++) {
		state.enemiesList[3].animIndices[i] = i;
	}

	state.enemiesList[3].animFrames = 6;
	state.enemiesList[3].textureID = Util::LoadTexture("ghost.png");

	state.enemiesList[4].entityType = ENEMY_JUMP;
	state.enemiesList[4].isStatic = false;
	state.enemiesList[4].width = 1.0f;
	state.enemiesList[4].height = 1.0f;
	state.enemiesList[4].position = glm::vec3(63, 0, 0);
	state.enemiesList[4].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[4].cols = 3;
	state.enemiesList[4].rows = 1;
	state.enemiesList[4].animIndices = new int[3];

	for (int i = 0; i < 3; i++) {
		state.enemiesList[4].animIndices[i] = i;
	}

	state.enemiesList[4].animFrames = 3;
	state.enemiesList[4].textureID = Util::LoadTexture("slime.png");

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

void Level3::Update(float deltaTime) {
	if (state.player.isActive) {
		state.player.Update(deltaTime, state.enemiesList, LV3_ENEMY_COUNT, state.map);
		//state.player.CheckCollision(&(state.key));
	}

	for (int i = 0; i < LV3_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Update(deltaTime, NULL, 0, state.map);
		}
	}

	if (state.player.position.x > 100) {
		state.nextLevel = 0;
	}
}

void Level3::Render(ShaderProgram* program) {
	state.map->Render(program);
	state.player.Render(program);
	/*if (state.key.isActive) {
		state.key.Render(program);
	}*/
	for (int i = 0; i < LV3_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Render(program);
		}
	}
}
