//
//  client.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 30/06/23.
//

#include "client.hpp"

Client::Client(GLFWwindow* window)
{
    this-> window = window;
    //this -> run();
}

void Client::run() {
    NetworkHandler networkHandler(false);
    
    while(!glfwWindowShouldClose(window)) {
        for (auto const& event : networkHandler.PollEvent()) {
            switch (event.type) {
                case ENET_EVENT_TYPE_RECEIVE: {
                    printf ("Recieved \"%s\"\n", event.packet -> data);
                    unsigned char* d;
                    memcpy(&d, &(event.packet -> data), sizeof(event.packet -> data));
                    std::cout << d << std::endl;
                    enet_packet_destroy (event.packet);
                    std::string m = "reply";
                    ENetPacket * packet = enet_packet_create (m.c_str(),
                                                              strlen (m.c_str()) + 1,
                                                              ENET_PACKET_FLAG_RELIABLE);
                    enet_peer_send(networkHandler.getServer(), 0, packet);
                    break;
                }
                case ENET_EVENT_TYPE_DISCONNECT:
                    printf ("disconnected.\n");
                    event.peer -> data = NULL;
                    break;
                case ENET_EVENT_TYPE_NONE:
                    break;
                case ENET_EVENT_TYPE_CONNECT:
                    break;
            }
        }
        
        processInput(window);
        
        renderer.processRendering();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
