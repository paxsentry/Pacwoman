//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 800), "Building games with SFML");
//
//    sf::RectangleShape rectangle;
//    rectangle.setSize(sf::Vector2f(200, 100));
//    rectangle.setFillColor(sf::Color::Green);
//    rectangle.setOutlineThickness(2);
//    rectangle.setOutlineColor(sf::Color::Red);
//
//    sf::CircleShape circle;
//    circle.setRadius(20);
//    circle.setFillColor(sf::Color::Blue);
//    circle.setOutlineThickness(4);
//    circle.setOutlineColor(sf::Color::Yellow);
//
//    sf::ConvexShape customShape;
//    customShape.setPointCount(3);
//    customShape.setPoint(0, sf::Vector2f(0, 0));
//    customShape.setPoint(1, sf::Vector2f(150, 30));
//    customShape.setPoint(2, sf::Vector2f(0, 60));
//    customShape.setFillColor(sf::Color::Magenta);
//
//    rectangle.setPosition(10, 10);
//    circle.setPosition(400, 20);
//    customShape.setPosition(250, 250);
//
//    sf::Image image;
//    image.loadFromFile("Assets/sfml.png");
//
//    sf::Texture texture;
//    texture.loadFromImage(image);
//
//    sf::Sprite sprite(texture);
//    sf::Sprite sprite2(texture);
//
//    sprite2.setPosition(250, 250);
//    sprite2.setRotation(45);
//
//    sf::Font font;
//    font.loadFromFile("Assets/font.otf");
//
//    sf::Text text;
//    text.setFont(font);
//    text.setString("Hello world!");
//    text.setColor(sf::Color::Blue);
//    text.setPosition(550, 10);
//    text.setCharacterSize(32);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                window.close();
//        }
//        window.clear();
//
//        window.draw(rectangle);
//        window.draw(circle);
//        window.draw(customShape);
//
//        window.draw(sprite);
//        window.draw(sprite2);
//
//        window.draw(text);
//
//        window.display();
//
//        window.setFramerateLimit(60);
//        sf::sleep(sf::seconds(1.f / 60.f));
//    }
//    return EXIT_SUCCESS;
//}