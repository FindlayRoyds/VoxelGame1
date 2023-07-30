//
//  eventHandler.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 5/07/23.
//

#include "eventHandler.hpp"

EventHandler::EventHandler(bool isServer) : networkHandler(isServer) {
    this -> isServer = isServer;
}

void EventHandler::pollEvents() {
    for (auto const& event : networkHandler.PollEvent()) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                std::cout << "A new client connected" << std::endl;
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                std::cout << "A packet was recieved" << std::endl;
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                std::cout << "A peer was disconnected" << std::endl;
                break;
            case ENET_EVENT_TYPE_NONE:
                std::cout << "None type event recieved" << std::endl;
                break;
        }
    }
}
