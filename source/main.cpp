/*
	File: main.cpp
	Author: USTHB Starrocket Team

	Description:
		program main entry point
*/
#define STB_IMAGE_IMPLEMENTATION

#include "window/Display.hpp"
#include "window/GUI.hpp"

// delta time
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
float currentFrame = 0.0f; // temp Time of frame

int main() {
	std::cout << Config::Window::title << " V" << Config::Window::version << '\n';

	// init window
	Display::init();

	// init GUI
	GUI::init(Display::window);

	// main program loop
	while (!glfwWindowShouldClose(Display::window)) {
		// calculate delta time
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// clear last frame
		glClearColor(0.0f, 0.0f, 0.0f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT);

		// update GUI
		GUI::update(deltaTime);

		// swap openGL buffers
    	glfwSwapBuffers(Display::window);

		// handle glfw events
        glfwPollEvents();
	};

	// dispose everything and close program
	glfwTerminate();

	return 0;
};
