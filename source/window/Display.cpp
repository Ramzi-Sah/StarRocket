#include "Display.hpp"

GLFWwindow* Display::window;

void Display::init() {
    // init glfw
    if (!glfwInit()) {
        std::cout << "ERROR: init failed." << std::endl;
        exit(2);
    };

    // setting some glfw attribs
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    // GLFWwindow is a struct containing window attribs
    window = glfwCreateWindow(Config::Window::width, Config::Window::height, Config::Window::title.c_str(), NULL, NULL);
    if (!window) {
        std::cout << "ERROR: can't open a window." << std::endl;
        exit(3);
    };

    // register glfw functions
    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // set openGL context
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR: Failed to initialize OpenGL, install your graphics card drivers." << std::endl;
        exit(4);
    };

    // set icon
    GLFWimage icons[1];
    icons[0].pixels = stbi_load("data/textures/icon.png", &icons[0].width, &icons[0].height, nullptr, 0);
    glfwSetWindowIcon(window, 1, icons);
	stbi_image_free(icons[0].pixels);

    //--------------------- openGL render configs ------------------------------
    // default polygone mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT, GL_LINE, GL_FILL

    // enable cull face
    glEnable(GL_CULL_FACE); // enable face culling

    // anti aliasing
    glEnable(GL_MULTISAMPLE);
};

/*---------------------------- callback events ------------------------------------*/
void Display::error_callback(int error, const char* description) {
    fprintf(stderr, "glfw Error: %s\n", description);
};

void Display::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // set openGL viewPort
    glViewport(0, 0, width, height);

    // std::cout << "width: " << width << " | height:" << height<< '\n';
};

// user input
void Display::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // std::cout << "key: " << key << " | action:" << action<< '\n';

    // escape
    if (action == 1) {
        if (key == 256) {

        };
    };
};

void Display::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    // std::cout << "xpos: " << xpos << " | ypos:" << ypos<< '\n';

};

void Display::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    // std::cout << "button: " << button << " | action:" << action << '\n';

    if (action == 1) {
        if (button == 0) {

        };
    };
};
