#ifndef TOGGABLE_LED_DEVICE_H
#define TOGGABLE_LED_DEVICE_H


#include "Device.h"
#include "Button.h"
#include "Led.h"

/**
 * @brief Clase concreta ToggableLedDevice que representa el sistema completo de LED conmutable.
 * 
 * Explicación para principiantes: Esta clase junta todos los componentes (el Botón como sensor de entrada y 
 * el LED como actuador de salida) y define las reglas de cómo interactúan entre sí. Hereda de `Device`.
 */
class ToggableLedDevice : public Device {
private:
    Button button; ///< Instancia del sensor de botón de entrada.
    Led led; ///< Instancia del actuador de LED de salida.

public:
    // Pines GPIO de hardware asignados por defecto para el ESP32
    static const int BUTTON_PIN = 26; ///< Pin GPIO por defecto para el botón (Pin 26).
    static const int LED_PIN = 27; ///< Pin GPIO por defecto para el LED (Pin 27).

    /**
     * @brief Constructor con pines configurables y estado inicial del LED.
     * @param buttonPin Pin GPIO para el botón (por defecto BUTTON_PIN = 26).
     * @param ledPin Pin GPIO para el LED (por defecto LED_PIN = 27).
     * @param initialLedState Estado inicial del LED (por defecto false / APAGADO).
     */
    ToggableLedDevice(int buttonPin = BUTTON_PIN, int ledPin = LED_PIN, bool initialLedState = false);

    /**
     * @brief Maneja eventos ocurridos en el botón (por ejemplo, cuando el botón es presionado).
     * @param event El evento que se va a procesar.
     * override sirve para indicar que este método está sobreescribiendo un método virtual de la clase padre Device.
     */
    void on(Event event) override;

    /**
     * @brief Maneja comandos enviados al dispositivo (por ejemplo, registrar los cambios de estado del LED).
     * @param command El comando que se va a procesar.
     */
    void handle(Command command) override;

    /**
     * @brief Proporciona acceso a la instancia interna del LED.
     * @return Referencia al objeto Led.
     */
    Led& getLed();

    /**
     * @brief Dispara un evento del botón de forma externa (por ejemplo, desde la Rutina de Servicio de Interrupción - ISR).
     * @param event El evento que se va a disparar.
     */
    void triggerButtonEvent(Event event);
};

#endif // TOGGABLE_LED_DEVICE_H