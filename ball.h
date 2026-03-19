#pragma once 

#include <SFML/Graphics.hpp>

//The ball class has several properties that will be manipulated in the physics engine. 
// Radius, Color, Position, Veloctiy. SFML already has position, color and radius. The only thing 
// I need to include is the velocity along the x and y axis. 

class Ball {
public:

	sf::CircleShape ball;
	sf::Vector2f velocity;

	Ball(float radius, sf::Color color, sf::Vector2f startPos, sf::Vector2f startVel)
		:ball(radius)
	{

		ball.setRadius(radius);
		ball.setFillColor(color);
		ball.setPosition(startPos);
		velocity = startVel;

	};


	void update(sf::Vector2f newVel, sf::Vector2f newPos) {
	
		velocity = newVel;
		ball.setPosition(newPos);
	
	};

	
	void draw(sf::RenderWindow& window){
        
		window.draw(ball);
		
	};

};

