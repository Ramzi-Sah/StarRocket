#ifndef SR_CONSOLE
#define SR_CONSOLE

#include <iostream>
#include <vector>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

/*
// bad idea
struct ConsoleMessage {
    std::string time;
    std::string type;
    std::string sender;
    std::string content;

    ConsoleMessage(std::string _time, std::string _type, std::string _sender, std::string _content) {
        time = _time;
        type = _type;
        sender = _sender;
        content = _content;
    };
};
*/
class Console {
private:
    static std::vector<std::string> messages;

public:
    static void render();
    static void addMessage(std::string msg);
    static void clear();
};

#endif
