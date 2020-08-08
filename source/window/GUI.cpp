#include "GUI.hpp"

ImGuiContext* GUI::context;
ImGuiIO* GUI::io;
ImGuiStyle* GUI::style;
void GUI::init(GLFWwindow* window) {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    context = ImGui::CreateContext();

    // getVars
    io = &ImGui::GetIO();
    style = &ImGui::GetStyle();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150 core");

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // ovverride styles to our theme
    setTheme();

    // init windows
    Windows::init(io);
};

void GUI::update(float deltaTime) {
	// feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // windows
    Windows::leftPanel();
    Windows::rightPanel();




    // for debug
    Windows::imguiDebug();
    // Windows::overlay(deltaTime);

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
};

bool GUI::isHovered() {
    return ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow);
};

//------------------------------------------------------------------------------
void GUI::setTheme() {
    // set font
    ImFont* font = io->Fonts->AddFontFromFileTTF("data/fonts/Roboto-Regular.ttf", 15.0f);

    /*------------------------------------ sizes ------------------------------------*/
    style->WindowPadding = ImVec2(10.0f, 10.0f);
    style->FramePadding = ImVec2(10.0f, 5.0f);
    style->ItemSpacing = ImVec2(10.0f, 5.0f);
    style->ItemInnerSpacing = ImVec2(10.0f, 5.0f);
    style->TouchExtraPadding = ImVec2(0.0f, 0.0f);
    style->IndentSpacing = 20.0f;
    style->ScrollbarSize = 15.0f;
    style->GrabMinSize = 10.0f;

    style->WindowBorderSize = 0.0f;
    style->ChildBorderSize = 0.0f;
    style->PopupBorderSize = 0.0f;
    style->FrameBorderSize = 0.0f;
    style->TabBorderSize = 0.0f;

    style->WindowRounding = 0.0f;
    style->ChildRounding = 0.0f;
    style->FrameRounding = 5.0f;
    style->PopupRounding = 5.0f;
    style->ScrollbarRounding = 0.0f;
    style->GrabRounding = 0.0f;
    style->TabRounding = 4.0f;

    style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style->ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style->SelectableTextAlign = ImVec2(0.0f, 0.0f);
    style->DisplaySafeAreaPadding = ImVec2(3.0f, 3.0f);

    /*------------------------------------ colors ------------------------------------*/
    #define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
    #define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
    #define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
    #define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
    #define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

    style->Colors[ImGuiCol_Text]                  = TEXT(0.78f);
    style->Colors[ImGuiCol_TextDisabled]          = TEXT(0.28f);
    style->Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    style->Colors[ImGuiCol_ChildWindowBg]         = BG( 0.58f);
    style->Colors[ImGuiCol_PopupBg]               = BG( 0.9f);
    style->Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
    style->Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style->Colors[ImGuiCol_FrameBg]               = BG( 1.00f);
    style->Colors[ImGuiCol_FrameBgHovered]        = MED( 0.78f);
    style->Colors[ImGuiCol_FrameBgActive]         = MED( 1.00f);
    style->Colors[ImGuiCol_TitleBg]               = LOW( 1.00f);
    style->Colors[ImGuiCol_TitleBgActive]         = HI( 1.00f);
    style->Colors[ImGuiCol_TitleBgCollapsed]      = BG( 0.75f);
    style->Colors[ImGuiCol_MenuBarBg]             = BG( 0.47f);
    style->Colors[ImGuiCol_ScrollbarBg]           = BG( 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrabHovered]  = MED( 0.78f);
    style->Colors[ImGuiCol_ScrollbarGrabActive]   = MED( 1.00f);
    style->Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style->Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style->Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style->Colors[ImGuiCol_Button]                = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style->Colors[ImGuiCol_ButtonHovered]         = MED( 0.86f);
    style->Colors[ImGuiCol_ButtonActive]          = MED( 1.00f);
    style->Colors[ImGuiCol_Header]                = MED( 0.76f);
    style->Colors[ImGuiCol_HeaderHovered]         = MED( 0.86f);
    style->Colors[ImGuiCol_HeaderActive]          = HI( 1.00f);
    style->Colors[ImGuiCol_Separator]             = TEXT(0.8f);
    style->Colors[ImGuiCol_SeparatorHovered]      = MED( 0.78f);
    style->Colors[ImGuiCol_SeparatorActive]       = MED( 1.00f);
    style->Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
    style->Colors[ImGuiCol_ResizeGripHovered]     = MED( 0.78f);
    style->Colors[ImGuiCol_ResizeGripActive]      = MED( 1.00f);
    style->Colors[ImGuiCol_PlotLines]             = TEXT(0.63f);
    style->Colors[ImGuiCol_PlotLinesHovered]      = MED( 1.00f);
    style->Colors[ImGuiCol_PlotHistogram]         = TEXT(0.63f);
    style->Colors[ImGuiCol_PlotHistogramHovered]  = MED( 1.00f);
    style->Colors[ImGuiCol_TextSelectedBg]        = MED( 0.43f);
};
