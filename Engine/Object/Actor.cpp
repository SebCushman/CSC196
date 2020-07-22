#include "pch.h"
#include "Actor.h"
#include <fstream>

namespace nc {
    bool nc::Actor::Load(const std::string& filename)
    {
        bool success = false;

        // open stream
     // check if stream is open
        std::ifstream stream(filename);
        if (stream.is_open()) {
         // set success to true
            success = true;

         // stream >> into transform
            /*stream >> m_transform.position;
            stream >> m_transform.scale;
            stream >> m_transform.angle;*/
            Load(stream);

            stream.close();
        }

        /*std::string shapename;
        stream >> shapename;
        m_shape.Load(shapename);*/

        return success;
    }

    void Actor::Load(std::istream& stream)
    {
        stream >> m_transform;

        std::string shapename;
        std::getline(stream, shapename);
        m_shape.Load(shapename);
    }


    void nc::Actor::Update(float dt)
    {

    }

    void nc::Actor::Draw(Core::Graphics& graphics)
    {
        nc::Actor::GetShape().Draw(graphics, nc::Actor::GetTransform());
        //nc::Actor::GetTransform();        
    }
}