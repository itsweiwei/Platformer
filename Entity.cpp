#include "Entity.h"

Entity::Entity()
{
	entityType = PLATFORM;
	isStatic = true;
	isActive = true;
	hasKey = false;
	position = glm::vec3(0);
	jumpCount = 2;
	speed = 0;
	animTime = 0;
	animIndex = 0;
	width = 1;
	height = 1;
}

bool Entity::CheckCollision(Entity* other)
{
	if (isStatic == true) return false;
	if (isActive == false || other->isActive == false) return false;

	float xdist = fabs(position.x - other->position.x) - ((width + other->width) / 2.0f);
	float ydist = fabs(position.y - other->position.y) - ((height + other->height) / 2.0f);

	if (xdist < 0 && ydist < 0)
	{
		if (entityType == PLAYER && other->entityType == KEY) {
			other->isActive = false;
			hasKey = true;
		}
		return true;
	}

	return false;
}

void Entity::CheckCollisionsY(Entity* objects, int objectCount)
{
	for (int i = 0; i < objectCount; i++)
	{
		Entity* object = &objects[i];

		if (CheckCollision(object))
		{
			float ydist = fabs(position.y - object->position.y);
			float penetrationY = fabs(ydist - (height / 2) - (object->height / 2));
			if (velocity.y > 0) {
				position.y -= penetrationY;
				velocity.y = 0;
				collidedTop = true;
			}
			else if (velocity.y < 0) {
				position.y += penetrationY;
				velocity.y = 0;
				collidedBottom = true;
				if (entityType == PLAYER && object->entityType == ENEMY_PATROL) {
					object->isStatic = true;
					object->isActive = false;
				}
				else {
					livesCount--;
					Respawn();
				}
			}
		}
	}
}

void Entity::CheckCollisionsX(Entity* objects, int objectCount)
{
	for (int i = 0; i < objectCount; i++)
	{
		Entity* object = &objects[i];

		if (CheckCollision(object))
		{
			float xdist = fabs(position.x - object->position.x);
			float penetrationX = fabs(xdist - (width / 2) - (object->width / 2));
			if (velocity.x > 0) {
				position.x -= penetrationX;
				velocity.x = 0;
				collidedRight = true;
			}
			else if (velocity.x < 0) {
				position.x += penetrationX;
				velocity.x = 0;
				collidedLeft = true;
			}
			if (entityType == PLAYER && livesCount > 0 && (object->entityType == ENEMY_PATROL || object->entityType != ENEMY_JUMP)) {
				livesCount--;
				Respawn();
			}
		}
	}
}


void Entity::Jump()
{
	if (jumpCount > 0 && isActive)
	{
		velocity.y = 5.0f;
		jumpCount--;
	}
}

void Entity::Respawn() {
	if (livesCount > 0) {
		position = glm::vec3(5.0f, 0, 0);
	}
	if (livesCount <= 0) {
		isStatic = true;
		isActive = false;
	}
}

void Entity::CheckCollisionsY(Map* map)
{
	// Probes for tiles
	glm::vec3 top = glm::vec3(position.x, position.y + (height / 2), position.z);
	glm::vec3 top_left = glm::vec3(position.x - (width / 2), position.y + (height / 2), position.z);
	glm::vec3 top_right = glm::vec3(position.x + (width / 2), position.y + (height / 2), position.z);

	glm::vec3 bottom = glm::vec3(position.x, position.y - (height / 2), position.z);
	glm::vec3 bottom_left = glm::vec3(position.x - (width / 2), position.y - (height / 2), position.z);
	glm::vec3 bottom_right = glm::vec3(position.x + (width / 2), position.y - (height / 2), position.z);

	float penetration_x = 0;
	float penetration_y = 0;

	if (map->IsSolid(top, &penetration_x, &penetration_y) && velocity.y > 0) {
		position.y -= penetration_y;
		velocity.y = 0;
		collidedTop = true;
	}
	else if (map->IsSolid(top_left, &penetration_x, &penetration_y) && velocity.y > 0) {
		position.y -= penetration_y;
		velocity.y = 0;
		collidedTop = true;
	}
	else if (map->IsSolid(top_right, &penetration_x, &penetration_y) && velocity.y > 0) {
		position.y -= penetration_y;
		velocity.y = 0;
		collidedTop = true;
	}

	if (map->IsSolid(bottom, &penetration_x, &penetration_y) && velocity.y < 0) {
		position.y += penetration_y;
		velocity.y = 0;
		jumpCount = 2;
		collidedBottom = true;
	}
	else if (map->IsSolid(bottom_left, &penetration_x, &penetration_y) && velocity.y < 0) {
		position.y += penetration_y;
		velocity.y = 0;
		collidedBottom = true;
	}
	else if (map->IsSolid(bottom_right, &penetration_x, &penetration_y) && velocity.y < 0) {
		position.y += penetration_y;
		velocity.y = 0;
		collidedBottom = true;
	}
}

void Entity::CheckCollisionsX(Map* map)
{
	// Probes for tiles
	glm::vec3 left = glm::vec3(position.x - (width / 2), position.y, position.z);
	glm::vec3 right = glm::vec3(position.x + (width / 2), position.y, position.z);

	float penetration_x = 0;
	float penetration_y = 0;

	if (map->IsSolid(left, &penetration_x, &penetration_y) && velocity.x < 0) {
		position.x += penetration_x;
		velocity.x = 0;
		collidedLeft = true;
	}

	if (map->IsSolid(right, &penetration_x, &penetration_y) && velocity.x > 0) {
		position.x -= penetration_x;
		velocity.x = 0;
		collidedRight = true;
	}

	if (entityType == ENEMY_PATROL) {
		if (collidedRight) {
			velocity.x = -2.0f;
		}
		else if (collidedLeft) {
			velocity.x = 2.0f;
		}
	}
}



void Entity::Update(float deltaTime, Entity* objects, int objectCount, Map* map)
{
	collidedTop = false;
	collidedBottom = false;
	collidedLeft = false;
	collidedRight = false;

	velocity += acceleration * deltaTime;

	animTime += deltaTime;

	if (animTime >= 0.25f)
	{
		animTime = 0;
		animIndex++;
		if (animIndex >= animFrames)
		{
			animIndex = 0;
		}
	}

	position.y += velocity.y * deltaTime;        // Move on Y
	CheckCollisionsY(map);
	CheckCollisionsY(objects, objectCount);    // Fix if needed

	if (entityType == PLAYER && position.y < -10.0f) {
		livesCount--;
		Respawn();
	}

	if (entityType == ENEMY_JUMP && position.y < -10.0f) {
		velocity.y = 12.0f;
	}

	position.x += velocity.x * deltaTime;        // Move on X
	CheckCollisionsX(map);
	CheckCollisionsX(objects, objectCount);    // Fix if needed
}

void Entity::DrawSpriteFromTextureAtlas(ShaderProgram* program, int index)
{
	float u = (float)(index % cols) / (float)cols;
	float v = (float)(index / cols) / (float)rows;

	float width = 1.0f / (float)cols;
	float height = 1.0f / (float)rows;

	float texCoords[] = { u, v + height, u + width, v + height, u + width, v,
		u, v + height, u + width, v, u, v };

	float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };

	glBindTexture(GL_TEXTURE_2D, textureID);

	glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, vertices);
	glEnableVertexAttribArray(program->positionAttribute);

	glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
	glEnableVertexAttribArray(program->texCoordAttribute);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(program->positionAttribute);
	glDisableVertexAttribArray(program->texCoordAttribute);
}

void Entity::Render(ShaderProgram* program) {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	if (entityType == KEY) {
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 0.5f, 1.0f));
	}
	modelMatrix = glm::translate(modelMatrix, position);
	program->SetModelMatrix(modelMatrix);
	DrawSpriteFromTextureAtlas(program, animIndices[animIndex]);
}

