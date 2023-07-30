//
//  event.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/07/23.
//

#ifndef event_hpp
#define event_hpp

#include <stdio.h>
#include <json/json.hpp>
#include <string>

class Event {
public:
    Event();
    virtual void process(nlohmann::json eventData);
protected:
    std::string eventName;
};

#endif /* event_hpp */
