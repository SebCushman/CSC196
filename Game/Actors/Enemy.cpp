#include "Enemy.h"
#include "Math/Math.h"
#include <fstream>

bool nc::Enemy::Load(const std::string& filename)
{
    bool success = false;

    std::ifstream stream(filename);
    if (stream.is_open())
    {
        success = true;

        // load the base actor members
        nc::Actor::Load(stream);

        // stream into thrust
        stream >> m_thrust;
        stream.close();
    }

    return success;

}

void nc::Enemy::Update(float dt)
{
        nc::Vector2 direction = m_target->GetTransform().position - m_transform.position;
        nc::Vector2 enemyVelocity = direction.Normalized() * m_thrust;
        m_transform.position = m_transform.position + (enemyVelocity * dt);
        m_transform.angle = std::atan2(direction.y, direction.x) + nc::DegreesToRadians(90.0f);

        if (m_transform.position.x > 800) m_transform.position.x = 0;
        if (m_transform.position.x < 0) m_transform.position.x = 800;
        if (m_transform.position.y > 600) m_transform.position.y = 0;
        if (m_transform.position.y < 0) m_transform.position.y = 600;
}
