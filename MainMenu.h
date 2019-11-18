#include "Scene.h"

class MainMenu : public Scene {

public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
	void StartGame();
};
