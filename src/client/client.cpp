//
//  client.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 30/06/23.
//

#include "client.hpp"

Client::Client(GLFWwindow* window)
: eventHandler(this)
{
    this-> window = window;
    //this -> run();
}

void Client::run()
{
    while(!glfwWindowShouldClose(window)) {
        eventHandler.pollEvents();
        
        processInput(window);
        
        renderer.processRendering();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
