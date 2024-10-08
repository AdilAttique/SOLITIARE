#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <cstdlib>

const int WINDOW_WIDTH = 1366;
const int WINDOW_HEIGHT = 760;
const float PI = 3.14159265f;

struct Particle {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Color color;
    float lifetime;

    Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float lifetime)
        : velocity(velocity), color(color), lifetime(lifetime)
    {
        shape.setRadius(2.0f);
        shape.setPosition(position);
        shape.setFillColor(color);
    }

    void update(float dt) {
        shape.move(velocity * dt);
        lifetime -= dt;

        if (lifetime < 0.5f) {
            sf::Color newColor = shape.getFillColor();
            newColor.a = static_cast<sf::Uint8>(255 * (lifetime / 0.5f));
            shape.setFillColor(newColor);
        }
    }

    bool isDead() const {
        return lifetime <= 0.0f;
    }
};

class Firework {
public:
    std::vector<Particle> particles;
    bool exploded = false;

    Firework(sf::Vector2f position) {
        explode(position);
    }

    void explode(sf::Vector2f position) {
        exploded = true;
        int particleCount = 200;  

        for (int i = 0; i < particleCount; ++i) {
            float angle = static_cast<float>(rand() % 360) * PI / 180.0f;
            float speed = static_cast<float>((rand() % 100) + 100);

            sf::Vector2f velocity(std::cos(angle) * speed, std::sin(angle) * speed);
            sf::Color color(rand() % 255, rand() % 255, rand() % 255);

            particles.push_back(Particle(position, velocity, color, 5.0f));  
        }
    }

    void update(float dt) {
        for (auto& particle : particles) {
            particle.update(dt);
        }

        particles.erase(std::remove_if(particles.begin(), particles.end(),
            [](Particle& p) { return p.isDead(); }), particles.end());
    }

    void draw(sf::RenderWindow& window) {
        for (auto& particle : particles) {
            window.draw(particle.shape);
        }
    }

    bool isFinished() const {
        return particles.empty();
    }
};