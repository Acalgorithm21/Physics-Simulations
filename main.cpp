
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"
#include "engine.h"
#include "Force.h"
#include "SimulationReport.h"
#include "timeTracker.h"
using namespace std;


int main()
{
    // window objects 
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "ballPhysics");

    //Stores balls
    std::vector<Ball> balls;

    SimulationReport report;

    //create then stores balls
    Ball ball2(33.f, sf::Color::Green, { 300, 200 }, { 0.f, 0.f });
    balls.push_back(ball2);
    Ball ball1(25.f, sf::Color::Red, {50, 50}, {0.f, 0.f});
    balls.push_back(ball1);
    Ball ball3(15.f, sf::Color::Blue, {678, 78}, {0.f, 0.f});
    balls.push_back(ball3);
    Ball ball4(46.f, sf::Color::Yellow, { 456, 98 }, { 0.f, 0.f });
    balls.push_back(ball4);
    Ball ball5(57.3f, sf::Color::Magenta, {346, 52}, {0.f, 0.f});
    balls.push_back(ball5);

    //generates engine
    Engine engine;

    //dt clock
    sf::Clock clock;

    //Force struct earth
    Earth earth{ {0.f, 200.f} };

    timeTracker tracker(1, balls, report);
    tracker.start();

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
        engine.applyForce(earth, ball5, dt);

        //draw

        window.clear();
        ball1.draw(window);
        ball2.draw(window);
        ball3.draw(window);
        ball4.draw(window);
        ball5.draw(window);
        window.display();
     


    }
    tracker.stop();
    report.closeReport();
    return 0;
}


