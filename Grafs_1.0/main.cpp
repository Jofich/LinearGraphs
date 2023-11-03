#include <iostream>
#include <SFML/Graphics.hpp>
#include <wtypes.h>



int main()
{
    int W = 600, H = 600;

    const int n_points = 100;

    int long long a = 0, b = 100;

   

    RECT desktop;
    
    const HWND hDesktop = GetDesktopWindow();
    
    GetWindowRect(hDesktop, &desktop);
    
    int horizontal = desktop.right;
    int vertical = desktop.bottom;

    sf::RenderWindow window(sf::VideoMode(W, H), "My window");

    sf::Vertex lines[n_points] = {};

    sf::Vertex oyx[4] = {
       //oy
       sf::Vector2f(sf::Vector2f(W/2,0)),
       sf::Vector2f(sf::Vector2f(W/2,H)),
       //ox
       sf::Vector2f(sf::Vector2f(0,H/2)),
       sf::Vector2f(sf::Vector2f(W,H/2)),
    };

    double pos_x, y;
    int i = 0;

    for (pos_x = -W/2; pos_x < W /2 ; pos_x += W / n_points) {
        y =  pos_x;
        lines[i] = sf::Vector2f(sf::Vector2f(pos_x + W/2, ( - y + H / 2) ));
        std::cout << pos_x << " " << y << " " << i << "\n";
        i += 1;
        
    }

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();

        window.draw(lines, n_points,sf::Lines);
        window.draw(oyx, 5, sf::Lines);

        //set pos at centre
        window.setPosition(sf::Vector2i(horizontal / 2 - W / 2, vertical / 2 - H / 2));

        window.display();
    }
    
}