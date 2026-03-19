
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <tuple>
#include "ball.h"
#include "engine.h"
#include "Force.h"
using namespace std;


int main()
{
    // window objects 
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "ballPhysics");

    sf::Clock clock;


    Engine engine;



    Ball ball2(33.f, sf::Color::Green, { 300, 200 }, { 0.f, 0.f });
    Ball ball1(25.f, sf::Color::Red, {50, 50}, {0.f, 0.f});
    Ball ball3(15.f, sf::Color::Blue, {678, 78}, {0.f, 0.f});
    Ball ball4(46.f, sf::Color::Yellow, { 456, 98 }, { 0.f, 0.f });




    Earth earth{ {0.f, 200.f} };

    while (window.isOpen()){

        float dt = clock.restart().asSeconds();

        //Listening for input
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
              }
        }


        //updates
        engine.applyForce(earth, ball1, dt);
        engine.applyForce(earth, ball2, dt);
        engine.applyForce(earth, ball3, dt);
        engine.applyForce(earth, ball4, dt);

        //draw

        window.clear();
        ball1.draw(window);
        ball2.draw(window);
        ball3.draw(window);
        ball4.draw(window);
        window.display();
     


    }
   
   
    
    return 0;
}


