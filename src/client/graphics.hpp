//
//  graphics.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 20/06/23.
//

#ifndef graphics_hpp
#define graphics_hpp

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* initializeWindow(int screenWidth, int screenHeight);
void terminate();

#endif /* graphics_hpp */
