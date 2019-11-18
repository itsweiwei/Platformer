#include "Level2.h"

#define LEVEL2_WIDTH 60
#define LEVEL2_HEIGHT 8
#define LV2_ENEMY_COUNT 4

unsigned int level2_data[] =
{
	0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3
};

void Level2::Initialize() {
	GLuint mapTextureID = Util::LoadTexture("tileset.png");
	state.map = new Map(LEVEL2_WIDTH, LEVEL2_HEIGHT, level2_data, mapTextureID, 1.0f, 4, 1);
	state.player.entityType = PLAYER;
	state.player.isStatic = false;
	state.player.width = 1.0f;
	state.player.height = 1.0f;
	state.player.livesCount = 3;
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
	state.enemiesList[0].position = glm::vec3(15, 0, 0);
	state.enemiesList[0].acceleration = glm::vec3(0, -9.81, 0);
	state.enemiesList[0].velocity = glm::vec3(-2.0f, 0, 0);
	state.enemiesList[0].cols = 6;
	state.enemiesList[0].rows = 1;
	state.enemiesList[0].animIndices = new int[6];

	for (int i = 0; i < 6; i++) {
		state.enemiesList[0].animIndices[i] = i;
	}

	state.enemiesList[0].animFrames = 6;
	state.enemiesList[0].textureID = Util::LoadTexture("ghost.png");

	state.enemiesList[1].entityType = ENEMY_JUMP;
	state.enemiesList[1].isStatic = false;
	state.enemiesList[1].width = 1.0f;
	state.enemiesList[1].height = 1.0f;
	state.enemiesList[1].position = glm::vec3(53, 0, 0);
	state.enemiesList[1].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[1].cols = 3;
	state.enemiesList[1].rows = 1;
	state.enemiesList[1].animIndices = new int[3];

	for (int i = 0; i < 3; i++) {
		state.enemiesList[1].animIndices[i] = i;
	}

	state.enemiesList[1].animFrames = 3;
	state.enemiesList[1].textureID = Util::LoadTexture("slime.png");

	state.enemiesList[2].entityType = ENEMY_JUMP;
	state.enemiesList[2].isStatic = false;
	state.enemiesList[2].width = 1.0f;
	state.enemiesList[2].height = 1.0f;
	state.enemiesList[2].position = glm::vec3(48, -5, 0);
	state.enemiesList[2].acceleration = glm::vec3(0, -9.81f, 0);
	state.enemiesList[2].cols = 3;
	state.enemiesList[2].rows = 1;
	state.enemiesList[2].animIndices = new int[3];

	for (int i = 0; i < 3; i++) {
		state.enemiesList[2].animIndices[i] = i;
	}

	state.enemiesList[2].animFrames = 3;
	state.enemiesList[2].textureID = Util::LoadTexture("slime.png");

	state.nextLevel = -1;

	state.enemiesList[3].entityType = ENEMY_PATROL;
	state.enemiesList[3].isStatic = false;
	state.enemiesList[3].width = 1.0f;
	state.enemiesList[3].height = 1.0f;
	state.enemiesList[3].position = glm::vec3(48.0f, -3.0f, 0);
	state.enemiesList[3].acceleration = glm::vec3(0, 0, 0);
	state.enemiesList[3].velocity = glm::vec3(-2.0f, 0, 0);
	state.enemiesList[3].cols = 6;
	state.enemiesList[3].rows = 1;
	state.enemiesList[3].animIndices = new int[6];

	for (int i = 0; i < 6; i++) {
		state.enemiesList[3].animIndices[i] = i;
	}

	state.enemiesList[3].animFrames = 6;
	state.enemiesList[3].textureID = Util::LoadTexture("ghost.png");
}

void Level2::Update(float deltaTime) {
	state.player.Update(deltaTime, state.enemiesList, 1, state.map);

	for (int i = 0; i < LV2_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Update(deltaTime, NULL, 0, state.map);
		}
	}

	if (state.player.position.x > 60) {
		state.nextLevel = 3;
	}
}

void Level2::Render(ShaderProgram* program) {
	state.map->Render(program);
	state.player.Render(program);
	for (int i = 0; i < LV2_ENEMY_COUNT; i++) {
		if (state.enemiesList[i].isActive) {
			state.enemiesList[i].Render(program);
		}
	}
}
