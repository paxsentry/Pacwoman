//#include <SFML/Window.hpp>
//#include <iostream>
//#include <Windows.h>
//#include <string>
//
//int main()
//{
//    /*int style = sf::Style::Fullscreen;*/
//
//    sf::Window window(sf::VideoMode::getFullscreenModes().front(), "Building games with SFML", sf::Style::Fullscreen);
//
//    /*auto fullScreenModes = sf::VideoMode::getFullscreenModes();
//    std::string res{};
//    for (auto &videoMode : fullScreenModes) {
//    res = videoMode.width + videoMode.height + videoMode.bitsPerPixel;
//    }
//
//    OutputDebugStringA(res.c_str());*/
//
//    /*  window.setTitle("Hello from SFML");
//    sf::VideoMode videoMode;
//    videoMode.width = 640;
//    videoMode.height = 480;
//    videoMode.bitsPerPixel = 32;
//
//    auto desktopMode = sf::VideoMode::getDesktopMode();
//
//    std::cout << desktopMode.width << std::endl;
//    std::cout << desktopMode.height << std::endl;
//    std::cout << desktopMode.bitsPerPixel << std::endl;*/
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
//
//        window.display();
//
//        sf::sleep(sf::seconds(1.f / 60.f));
//    }
//    return EXIT_SUCCESS;
//}