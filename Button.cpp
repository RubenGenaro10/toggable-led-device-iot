
#include "Button.h"
#include <Arduino.h> // Incluye la biblioteca base de Arduino para poder usar pinMode e INPUT_PULLUP.

// Inicializamos el evento estático predefinido del botón pasándole su identificador único.
const Event Button::BUTTON_PRESSED_EVENT = Event(BUTTON_PRESSED_EVENT_ID);

// Constructor de la clase Button
// Explicación para principiantes: Llama al constructor de la clase base 'Sensor' pasándole el pin y el eventHandler.
// Luego ejecuta pinMode(pin, INPUT_PULLUP) para configurar el hardware.
Button::Button(int pin, EventHandler* eventHandler)
    : Sensor(pin, eventHandler) {
    // Configura el pin del botón como entrada con resistencia de pull-up interna.
    // Esto hace que el pin lea HIGH (1) por defecto, y LOW (0) cuando se presiona físicamente el botón para cerrarlo a tierra (GND).
    pinMode(pin, INPUT_PULLUP);
}
