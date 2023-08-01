//
//  main.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 17/06/23.
//

#include "client/graphics.hpp"
#include "client/client.hpp"
#include "server/server.hpp"

void initialiseClient()
{
    GLFWwindow* window = initializeWindow(800, 600);
    Client client(window);
}

void initialiseServer()
{
    Server server;
}

int main(int argc, char **argv)
{
    
    std::thread serverThread(initialiseServer);
    initialiseClient();
    
    serverThread.detach();
    return 0;
}
