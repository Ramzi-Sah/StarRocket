#ifndef SR_GUI
#define SR_GUI

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "../config.hpp"
#include "Windows.hpp"

class GUI {
private:
    static ImGuiContext* context;
    static ImGuiIO* io;
    static ImGuiStyle* style;

    static void setTheme();
    static bool isHovered();

public:
    static void init(GLFWwindow* window);
    static void update(float deltaTime);
};

#endif
