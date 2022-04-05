#include <iostream>

#include "OpenGLContainer.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Config.hpp"

int main() {
    OpenGLContainer openGlContainer(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE);
    openGlContainer.run();

    return 0;
}
