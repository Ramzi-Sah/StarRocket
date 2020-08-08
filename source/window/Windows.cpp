#include "Windows.hpp"

ImGuiIO* Windows::io;
void Windows::init(ImGuiIO* _io) {
    io = _io;
};

void Windows::imguiDebug() {
    static bool show_demo_window = true;
    if (show_demo_window) {
        ImGui::ShowDemoWindow(&show_demo_window);
    };
};
void Windows::overlay(float deltaTime) {
    static bool show_overlay = true;

	// calculate fps
	static int FPS = 0;
	static int nbrFrames = 0;
	static float fpsTime = 0.0f;

	if (fpsTime > 1) {
        FPS = nbrFrames;
		nbrFrames = 0;
		fpsTime = 0.0f;
	} else {
		fpsTime += deltaTime;
		nbrFrames++;
	};

    if (show_overlay) {
        // debug overlay panel
        static const float DISTANCE = 10.0f;
        static int corner = 1;
        ImVec2 window_pos = ImVec2((corner & 1) ? io->DisplaySize.x - DISTANCE : DISTANCE, (corner & 2) ? io->DisplaySize.y - DISTANCE : DISTANCE);
        ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
        ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
        ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
        ImGui::Begin("debug overlay", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav);

        ImGui::Text("%s V%.2f", Config::Window::title.c_str(), Config::Window::version);
        // ImGui::Separator();
        ImGui::Text("FPS: %i (%.2f ms)", FPS, deltaTime*1000);

        ImGui::End();
    };
};

void Windows::leftPanel() {
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(io->DisplaySize.x / 2 - 5, io->DisplaySize.y));
    ImGui::Begin("leftPanel", NULL, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav);

    ImGui::Text("test");

    ImGui::End();
}

void Windows::rightPanel() {
    ImGui::SetNextWindowPos(ImVec2(io->DisplaySize.x / 2 + 5, 0.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(io->DisplaySize.x / 2 - 5, io->DisplaySize.y));
    ImGui::Begin("rightPanel", NULL, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav);

    ImGui::Text("test");

    ImGui::End();
}
