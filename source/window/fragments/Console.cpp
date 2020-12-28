#include "Console.hpp"

std::vector<std::string> Console::messages;
void Console::render() {
    ImGui::Separator();

    static bool autoScroll = true;

    // clear button
    if(ImGui::Button("clear")) {
        clear();
    };

    ImGui::SameLine();

    // auto scroll checkbox
    ImGui::Checkbox("Auto-Scroll", &autoScroll);

    ImGui::Separator();

    ImGui::BeginChild("Console", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    for (int i = 0; i < messages.size(); i++) {
        ImGui::Text(std::to_string(i).c_str());
        ImGui::SameLine();
        ImGui::Text(std::string(" | ").c_str());
        ImGui::SameLine();
        ImGui::Text((" " + messages[i]).c_str());
    };

    if (autoScroll)
        ImGui::SetScrollHereY(1.0f);

    ImGui::EndChild();

};

void Console::addMessage(std::string msg) {
    messages.push_back(msg);
};

// void Console::addMessage(ConsoleMessage msg) {
//     messages.push_back(msg);
// };

void Console::clear() {
    messages.clear();
};
