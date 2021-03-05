#include "Battle.h"

Battle::Battle() {
    // Creating window
    window = glfwCreateWindow(640, 640, "Tales - OpenGL", NULL, NULL);
    if (!window) {  glfwTerminate(); exit(EXIT_FAILURE); }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glEnable(GL_MULTISAMPLE);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Making it the focused window for glfw
    glfwMakeContextCurrent(window);

    // Enabling openGL to do stuff
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_ALPHA_TEST);

    // Initializing glew
    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);

    // Setting the functions that happens every input
    glfwSetWindowUserPointer(window, this);

    input_default();

    // Testing stuff to be removed
    Unit* u = new Unit("Anna");
    Sprite* sprite = new Sprite("Anna");;
    field->add_unit(u, 2, 2);
    sprites["Anna1"] = sprite;

    sprite = new Sprite("Anna");
    *sprite += glm::vec3(0, 0, 1);
    sprites["Anna2"] = sprite;
    //
}

Battle::~Battle() {
    glfwDestroyWindow(window);
}

void Battle::init() {
    // Main game loop
    while (!glfwWindowShouldClose(window)) {
        double start_time = glfwGetTime();

        GLint windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();

        gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

        glMatrixMode(GL_MODELVIEW_MATRIX);
        if (-1 < mx || mx < 1) cam.rotate(glm::vec3(0, -mx/200, 0));
        cam.update();

        for (auto& o : objects)
            o->render();

        cam.cursor = glm::vec3(cam.cursor.pos.x, field->at(cam.cursor.pos).y, cam.cursor.pos.z);
        cam.goal = cam.cursor.pos;

        field->render();

        for (auto& s : sprites)
            s.second->render();

        inputs();

        glfwSwapInterval(1);
        glfwSwapBuffers(window);
        glfwPollEvents();

        double end_time = glfwGetTime();

        while (end_time - start_time < 1/60)
            end_time = glfwGetTime();
    }
}

void Battle::input_default() {
    glfwSetKeyCallback(window, DefaultKeyCall);
    glfwSetScrollCallback(window, DefaultScrollCall);
    inputs = [&]() {
        glfwGetCursorPos(window, &mx, &my);
        glfwSetCursorPos(window, 0, 0);

        glm::vec3 vec = glm::vec3(
            2* (float)(glfwGetKey(window, GLFW_KEY_A) - glfwGetKey(window, GLFW_KEY_D)) / 15,
            0,
            2* (float)(glfwGetKey(window, GLFW_KEY_W) - glfwGetKey(window, GLFW_KEY_S)) / 15);
        if (vec.x == 0 && vec.y == 0 && vec.z == 0) {
            cam.cursor = field->at(cam.cursor.pos);
        } else cam += vec;
    };
}

void Battle::DefaultKeyCall(GLFWwindow* w, int key, int scancode, int action, int mods) {
    Battle* b = (Battle*)glfwGetWindowUserPointer(w);
    
    switch (key) {
    case GLFW_KEY_ESCAPE:
        exit(0);
        break;
    case GLFW_KEY_TAB:
        auto monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        glfwSetWindowMonitor(w, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        break;
    }
}

void Battle::DefaultScrollCall(GLFWwindow* w, double sx, double sy) {
    Battle* b = (Battle*)glfwGetWindowUserPointer(w);

    b->cam.distance -= sy;

    if (b->cam.distance < b->cam.min_zoom) b->cam.distance = b->cam.min_zoom;
    if (b->cam.distance > b->cam.max_zoom) b->cam.distance = b->cam.max_zoom;
}
