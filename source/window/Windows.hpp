#ifndef SR_WINDOWS
#define SR_WINDOWS

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "../config.hpp"
#include "../serial/Communication.hpp"

class Windows {
private:
    static ImGuiIO* io;

public:
    static void init(ImGuiIO* _io);

    static void imguiDebug();
    static void overlay(float deltaTime);

    static void leftPanel();
    static void rightPanel();
};

#endif
