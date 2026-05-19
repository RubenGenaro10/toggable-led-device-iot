
#include "Actuator.h"

// Constructor de la clase Actuator
// Explicación para principiantes: Inicializa los atributos 'pin' y 'handler' (manejador de comandos) del actuador.
Actuator::Actuator(int pin, CommandHandler* commandHandler)
    : pin(pin), handler(commandHandler) {}

// Método para procesar un comando recibido por el actuador
// Explicación para principiantes: Si el actuador tiene registrado un manejador de comandos (handler != nullptr),
// se propaga el comando a ese manejador para realizar acciones adicionales o llevar el registro.
void Actuator::handle(Command command) {
    if (handler != nullptr) {
        handler->handle(command);
    }
}

// Método para cambiar o actualizar dinámicamente el manejador de comandos
void Actuator::setHandler(CommandHandler* commandHandler) {
    handler = commandHandler;
}
