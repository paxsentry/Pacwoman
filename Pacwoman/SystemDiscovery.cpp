//#include <iostream>
//#include <SFML\System.hpp>
//
//int main()
//{
//    sf::Time time;
//    sf::Clock clock;
//
//    sf::Time time1 = sf::seconds(1.2);
//    sf::Time time2 = sf::milliseconds(1200);
//    sf::Time time3 = sf::microseconds(1000000);
//
//    time = time1 + time2 - time3;
//
//    auto timeInSeconds = time.asSeconds();
//    auto timeInMilliSeconds = time.asMilliseconds();
//    auto timeInMicroSeconds = time.asMicroseconds();
//
//    std::cout << timeInSeconds << std::endl;
//    std::cout << timeInMilliSeconds << std::endl;
//    std::cout << timeInMicroSeconds << std::endl;
//
//    sf::Vector2<int> vector;
//    vector.x = 4;
//    vector.y = 2;
//
//    std::cout << vector.x << vector.y << std::endl;
//
//    vector += sf::Vector2<int>(3, 6);
//    vector *= -1;
//
//    // Vector = direction + magnitude
//
//    sf::Vector2i intVector;
//    sf::Vector2u uintVector;
//    sf::Vector2f floatVector;
//
//    sf::Vector3i vector3;
//    vector3.z = 8;
//
//    sf::String string = "Piece of text";
//
//    sf::String foreign = L"יבב"; // L is needed to force wchar_t
//
//                                 // std::cout << "Hello PacWoman" << std::endl;
//
//    return EXIT_SUCCESS;
//}