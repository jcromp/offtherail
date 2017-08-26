#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

#include "libs/Shader.h"

#include "entities/Camera.h"
#include "entities/Particles.h"

enum Screens {
	MAIN_MENU,
	CHOOSE,
	GAME
};

// struct GLState{
// 	Shader shaders[MAX_SHADERS];
// 	int shaderCount;
// };

struct Input {
	bool a_pressed;
	bool d_pressed;
	bool w_pressed;
	bool s_pressed;
	bool space_pressed;
	bool enter_pressed;
	bool escape_pressed;
};

struct PlatformState {
	GLFWwindow* window;
	Input input;

	bool windowResized;
	int screenWidth;
	int screenHeight;

	float currTime;
	float prevTime;
	float deltaTime;
};


struct GameState {
	bool game_started;
	bool quit_game;
	
	Screens current_screen;
	
	// /* PARTICLE STATE */
	int particle_count;
	Particle* particles;
	Shader particleShader;
	unsigned int Particle_VBO;
	unsigned int Particle_VAO;

	// /* MENU SCREEN STATE */
	// bool start_active;
	// bool exit_active;

	Camera camera;
	
	/* TRAIN STATE */
	// void *train;
};

struct State {
	GameState game_state;
	PlatformState platform;
};

struct GameAPI {

	void (*init)(State* s);

	void (*finalize)(State *s);

	void (*reload)(State *s);

	void (*unload)(State *s);

	void (*updateAndRender)(State *s);

	bool (*shouldClose)(State *s);
};

extern const struct GameAPI GAME_API;

#endif