
#include "Sensor.h"

// Constructor de la clase Sensor
// Explicación para principiantes: Inicializa los atributos 'pin' y 'handler' usando una "lista de inicialización".
// El puntero eventHandler se guarda en la variable miembro 'handler'.
Sensor::Sensor(int pin, EventHandler* eventHandler)
    : pin(pin), handler(eventHandler) {}

// Método que se llama cuando ocurre un evento en el sensor
// Explicación para principiantes: Si hay un manejador (handler) registrado (es decir, no es nullptr), 
// le pasamos el evento para que lo procese. Esto propaga el evento "hacia arriba" (por ejemplo, del botón al dispositivo).
void Sensor::on(Event event) {
    if (handler != nullptr) {
        handler->on(event);
    }
}

// Método para cambiar dinámicamente el manejador de eventos del sensor
void Sensor::setHandler(EventHandler* eventHandler) {
    handler = eventHandler;
}
