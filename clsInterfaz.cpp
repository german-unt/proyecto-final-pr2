#include <iostream>
#include "clsInterfaz.h"
#include "funciones.h"

using namespace std;

///


void mostrarRankingSFML(actividad *Vrank, int *Vcont, int cant) {
    // 1. Crear la ventana: 800x600 píxeles, título de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ranking de Actividades");

    // 2. Cargar fuente: SFML necesita una fuente .ttf para dibujar texto
    sf::Font font;
    if (!font.loadFromFile("/home/facu/Escritorio/proyecto-final-pr2/DejaVuSans-Bold.ttf")) {
        return; // Si no encuentra el archivo, salimos para evitar errores
    }

    // 3. Bucle principal de la ventana (se mantiene abierta mientras esto sea true)
    while (window.isOpen()) {
        // Manejo de eventos: detecta si el usuario cerró la ventana con la X
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        /* 4. Limpiar ventana antes de dibujar cada cuadro (frame)
            window.clear(sf::Color::Black);
        */
        // 1. Fondo verde oscuro
        window.clear(sf::Color(0, 100, 0));

        // --- DIBUJAR TÍTULO ---
        sf::Text titulo;
        titulo.setFont(font);
        titulo.setCharacterSize(30);
        titulo.setFillColor(sf::Color::White);
        titulo.setString("RANKING DE ACTIVIDADES");


        // Rectángulo del título
        sf::RectangleShape rectTitulo(sf::Vector2f(500, 50));
        rectTitulo.setFillColor(sf::Color(0, 50, 0)); // Un verde aún más oscuro para el recuadro
        rectTitulo.setOutlineThickness(2);
        rectTitulo.setOutlineColor(sf::Color::White);
        rectTitulo.setPosition(150, 40);
        window.draw(rectTitulo);

        // Centrado: restamos el ancho del texto al ancho total (800) y dividimos por 2
        titulo.setPosition((800 - titulo.getLocalBounds().width) / 2, 50);
        window.draw(titulo);

        // --- DIBUJAR LISTA ---
        float yPos = 120; // Posición vertical inicial para el primer elemento

        for(int i = 0; i < cant; i++) {
            // Solo mostramos si tiene inscriptos para que el ranking sea limpio
            if(Vcont[i] > 0) {
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);

                // Construcción de la cadena: unimos los datos del ranking
                string linea = "#" + to_string(i + 1) + " " + Vrank[i].getNombreActividad() +
                               " - Inscritos: " + to_string(Vcont[i]);

                text.setString(linea);

                // Centrado dinámico para cada línea según su longitud
                float xLinea = (800 - text.getLocalBounds().width) / 2;
                text.setPosition(xLinea, yPos);

                window.draw(text);

                yPos += 40; // Sumamos 40 píxeles para que la siguiente línea no se superponga
            }
        }

        // 5. Mostrar lo dibujado en pantalla (actualiza la imagen)
        window.display();
    }
}
