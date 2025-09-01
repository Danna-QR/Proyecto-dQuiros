#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
/// </summary>
/// </summary>
/// </summary>
/// </summary>
void game::showPrincipalWindow()
{
       sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Close);

        // --- Botón ---
       sf::RectangleShape button(sf::Vector2f(200, 80));
       button.setFillColor(sf::Color::Blue);
       button.setPosition(300, 400);
        
          // --- Cargar la textura (imagen de fondo) --- 


       sf::Texture backgroundTexture;
       if (!backgroundTexture.loadFromFile("assets/play.png")) {
         std::cout << "Error: no se pudo cargar la imagen\n";
           //return -1;
       }

       // --- Crear sprite con esa textura ---
       sf::Sprite background(backgroundTexture);


      

        // --- Texto del botón ---
        // sf::Font font;  if (!font.loadFromFile("arial.ttf")) {std::cout << "Error cargando fuente\n";}
        //sf::Text buttonText("Abrir segunda pantalla", font, 20);
        //buttonText.setPosition(310, 425);

        bool abrirOtraVentana = false;


        // --- Cargar la textura (imagen de fondo) --- 
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("assets/principal.jpg")) {
            std::cout << "Error: no se pudo cargar la imagen\n";
            //return -1;
        }

        // --- Crear sprite con esa textura ---
        sf::Sprite background(backgroundTexture);


        // --- Ajustar al tamaño de la ventana ---
        background.setScale(
            float(window.getSize().x) / backgroundTexture.getSize().x,
            float(window.getSize().y) / backgroundTexture.getSize().y
        );

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Detectar clic izquierdo
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        abrirOtraVentana = true;
                    }
                }
            }

            window.clear();
            window.draw(background);
            window.draw(button);
            window.draw(buttonText);
            window.display();

            // Si se presionó el botón -> abrir función
            if (abrirOtraVentana) {
                window.close();     // cerrar menú
                //showBoardWindow();  // llamar a la función de la segunda pantalla
            }
        }
}
