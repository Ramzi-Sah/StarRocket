#ifndef SR_DISPLAY
#define SR_DISPLAY

#include <iostream>
#include <random>

#include <glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include "../config.hpp"

class Display {
private:
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

public:
    static void init();

    // window pointer
    static GLFWwindow* window;
};

#endif
