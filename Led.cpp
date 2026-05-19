
#include "Led.h"
#include <Arduino.h> // Incluye la biblioteca de Arduino para controlar pines (pinMode, digitalWrite)

// Inicializa las instancias estáticas de comandos con sus respectivos IDs únicos.
const Command Led::TOGGLE_LED_COMMAND = Command(TOGGLE_LED_COMMAND_ID);
const Command Led::TURN_ON_COMMAND = Command(TURN_ON_COMMAND_ID);
const Command Led::TURN_OFF_COMMAND = Command(TURN_OFF_COMMAND_ID);

// Constructor de la clase Led
// Explicación para principiantes: Llama al constructor de la clase base 'Actuator' e inicializa el atributo 'state'.
// Luego configura el pin físico como SALIDA (OUTPUT) y escribe el estado inicial del LED en dicho pin.
Led::Led(int pin, bool initialState, CommandHandler* commandHandler)
    : Actuator(pin, commandHandler), state(initialState) {
    pinMode(pin, OUTPUT);     // Configura el pin del LED como salida digital.
    digitalWrite(pin, state); // Escribe el estado inicial en el pin (0 para apagado, 1 para encendido).
}

// Método para manejar comandos dirigidos al LED
// Explicación para principiantes: Compara el comando recibido con los predefinidos y realiza la acción física adecuada.
void Led::handle(Command command) {
    if (command == TOGGLE_LED_COMMAND) {
        state = !state;           // Invierte el estado actual (si era true pasa a false, y viceversa).
        digitalWrite(pin, state); // Actualiza el pin físico con el nuevo estado conmutado.
    } else if (command == TURN_ON_COMMAND) {
        state = true;
        digitalWrite(pin, state); // Enciende físicamente el LED.
    } else if (command == TURN_OFF_COMMAND) {
        state = false;
        digitalWrite(pin, state); // Apaga físicamente el LED.
    }
    Actuator::handle(command); // Propaga el comando a un manejador superior (si está registrado) para auditoría o reportes.
}

// Retorna el estado actual del LED (true = ENCENDIDO, false = APAGADO)
bool Led::getState() const {
    return state;
}

// Cambia el estado del LED directamente y actualiza el hardware pin
void Led::setState(bool newState) {
    state = newState;
    digitalWrite(pin, state);
}