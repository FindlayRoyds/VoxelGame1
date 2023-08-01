//
//  client.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 30/06/23.
//

#ifndef client_hpp
#define client_hpp

#include <stdio.h>
#include <enet/enet.h>
#include <chrono>
#include <thread>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"
#include "input.hpp"
#include "eventHandler.hpp"

class Client {
public:
    Client(GLFWwindow* window);
    void run();
private:
    GLFWwindow* window;
    Renderer renderer;
    EventHandler eventHandler;
};

#endif /* client_hpp */
