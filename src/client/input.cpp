//
//  input.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 20/06/23.
//

#include "input.hpp"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
