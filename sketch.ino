
#include "ModestIoT.h"
#include "ToggableLedDevice.h"

// --- CONFIGURACIÓN DE PARÁMETROS CONSTANTES ---
// Explicación para principiantes: #define define constantes que el compilador reemplaza antes de compilar el código.
#define LED_INITIAL_STATE false ///< Estado inicial del LED (false = APAGADO).
#define DEBOUNCE_DELAY_MS 200 ///< Tiempo de rebote (debounce) en milisegundos para evitar múltiples lecturas falsas al presionar el botón.

// Instanciamos (creamos) el objeto de nuestro dispositivo IoT.
// Este objeto encapsula el botón, el LED y la lógica que los une.
ToggableLedDevice device; ///< Instancia de la clase ToggableLedDevice.

/**
 * @brief ISR (Rutina de Servicio de Interrupción) para disparar eventos de botón presionado con eliminación de rebote.
 * 
 * Explicación para principiantes: Una interrupción física detiene momentáneamente lo que la CPU está haciendo para 
 * ejecutar esta función de inmediato cuando el pin del botón cambia de estado.
 * Se ejecuta cuando el pin del botón detecta un flanco de bajada (FALLING), es decir, pasa de HIGH (voltaje alto/suelto)
 * a LOW (voltaje bajo/presionado).
 * La eliminación de rebote (debouncing) asegura que solo se procese un evento por pulsación real, ya que los botones físicos
 * generan ruidos eléctricos oscilantes muy rápidos que podrían interpretarse como múltiples pulsaciones.
 */
void IRAM_ATTR triggerButtonPressedEvent() {
    static unsigned long lastPress = 0; // Almacena el tiempo de la última pulsación válida.
    unsigned long now = millis();       // Obtiene el tiempo actual desde que se encendió la placa (en milisegundos).
    
    // Si ha pasado suficiente tiempo (200 ms) desde la última pulsación, se considera una pulsación válida.
    if (now - lastPress > DEBOUNCE_DELAY_MS) {
        // Le notificamos a nuestro dispositivo que ocurrió un evento de botón presionado.
        device.triggerButtonEvent(Button::BUTTON_PRESSED_EVENT);
        lastPress = now; // Actualizamos el tiempo de la última pulsación válida.
    }
}

/**
 * @brief Función de configuración inicial del sistema.
 * 
 * Se ejecuta una sola vez al encender o reiniciar el microcontrolador.
 */
void setup() {
    Serial.begin(115200); // Inicializa la comunicación serial para poder imprimir mensajes de depuración en la computadora.
    Serial.printf("LED initial state: %d\n", device.getLed().getState()); // Reporta el estado inicial del LED en la terminal serial.
    
    // Configura la interrupción física en el pin del botón.
    // digitalPinToInterrupt: Traduce el número del pin GPIO al canal de interrupción del hardware.
    // triggerButtonPressedEvent: La función (ISR) que se llamará inmediatamente cuando ocurra el evento.
    // FALLING: Indica que la interrupción se dispara cuando el voltaje del pin cae (de 1 a 0, al presionar el botón).
    attachInterrupt(digitalPinToInterrupt(ToggableLedDevice::BUTTON_PIN), triggerButtonPressedEvent, FALLING);
}

/**
 * @brief Bucle principal de ejecución.
 * 
 * Se ejecuta repetidamente de manera infinita después de que termina setup().
 */
void loop() {
    // ¡No se necesita hacer sondeo (polling) constante aquí!
    // Las interrupciones del hardware (ISR) y la arquitectura de eventos del framework
    // se encargan de manejar todo automáticamente de forma asíncrona.
}
