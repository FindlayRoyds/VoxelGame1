//
//  rendering.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 20/06/23.
//

#ifndef renderer_hpp
#define renderer_hpp
#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "shader.h"

class Renderer {
private:
    Shader shaderProgram;
    unsigned int VAO;
public:
    Renderer();
    void processRendering();
};

#endif /* renderer_hpp */
