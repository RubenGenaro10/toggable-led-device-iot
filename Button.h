#ifndef BUTTON_H
#define BUTTON_H


#include "Sensor.h"

/**
 * @brief Clase concreta Button que hereda de Sensor.
 * 
 * Explicación para principiantes: La clase `Button` representa un pulsador físico conectado a la placa.
 * Dado que un botón lee información externa (si está presionado o no), es un tipo de `Sensor`.
 */
class Button : public Sensor {
public:
    // Explicación para principiantes: 'static const' define una constante compartida por todas las instancias de esta clase.
    static const int BUTTON_PRESSED_EVENT_ID = 0; ///< Identificador único para el evento de botón presionado.
    static const Event BUTTON_PRESSED_EVENT; ///< Objeto evento predefinido que representa que el botón fue pulsado.

    /**
     * @brief Constructor del sensor de Botón.
     * @param pin El pin GPIO físico para el botón (se configurará como INPUT_PULLUP en el archivo .cpp).
     * @param eventHandler Puntero al EventHandler opcional para recibir los eventos del botón (por defecto: nullptr / nulo).
     * 
     * Explicación para principiantes: INPUT_PULLUP activa una resistencia interna de la placa que mantiene el pin en HIGH (alto/3.3V)
     * por defecto, y cuando el botón se presiona, el voltaje cae a LOW (bajo/0V).
     */
    Button(int pin, EventHandler* eventHandler = nullptr);
};

#endif // BUTTON_H