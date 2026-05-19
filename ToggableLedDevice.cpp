
#include "ToggableLedDevice.h"
#include <Arduino.h> // Incluye Serial y printf de Arduino

// Constructor de ToggableLedDevice
// Explicación para principiantes: Inicializa los componentes internos pasándole los pines de hardware.
// Al pasar 'this' como segundo argumento, le estamos diciendo al botón y al LED que el "manejador" (handler)
// de sus eventos y comandos es este mismo objeto ToggableLedDevice. ¡Esto conecta los componentes!
ToggableLedDevice::ToggableLedDevice(int buttonPin, int ledPin, bool initialLedState) 
    : button(buttonPin, this), led(ledPin, initialLedState, this) {}

// Método llamado cuando el botón le notifica un evento al dispositivo
// Explicación para principiantes: Si el evento recibido indica que el botón fue presionado (BUTTON_PRESSED_EVENT),
// entonces enviamos un comando al LED para que conmute (cambie de encendido a apagado, o viceversa).
void ToggableLedDevice::on(Event event) {
    if (event == Button::BUTTON_PRESSED_EVENT) {
        led.handle(Led::TOGGLE_LED_COMMAND); // Le da la orden al LED de conmutar.
    }
}

// Método llamado cuando se ejecuta un comando en el dispositivo (para reportes o logs)
// Explicación para principiantes: Cuando el LED ejecuta con éxito el comando (cambiar estado, encender, apagar),
// propaga ese comando de vuelta a este manejador. Aquí simplemente lo usamos para imprimir el nuevo estado en consola.
void ToggableLedDevice::handle(Command command) {
    if (command == Led::TOGGLE_LED_COMMAND || 
        command == Led::TURN_ON_COMMAND || 
        command == Led::TURN_OFF_COMMAND) {
        Serial.printf("LED state: %d\n", led.getState()); // Imprime en consola: LED state: 0 (o 1)
    }
}

// Retorna la instancia de Led interna.
Led& ToggableLedDevice::getLed() {
    return led;
}

// Método puente para disparar externamente el evento del botón (por ejemplo, desde la interrupción física ISR del sketch.ino)
void ToggableLedDevice::triggerButtonEvent(Event event) {
    button.on(event); // Delega la llamada al botón interno para que este inicie la cadena de eventos.
}