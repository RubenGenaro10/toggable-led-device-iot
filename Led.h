#ifndef LED_H
#define LED_H


#include "Actuator.h"

/**
 * @brief Clase concreta Led que hereda de Actuator.
 * 
 * Explicación para principiantes: Un LED es un componente físico de salida (un diodo emisor de luz).
 * Como recibe instrucciones para actuar (encenderse, apagarse), es un tipo de `Actuator`.
 */
class Led : public Actuator {
private:
    bool state; ///< Estado actual del LED (true = ENCENDIDO, false = APAGADO).

public:
    // Identificadores únicos de comando
    static const int TOGGLE_LED_COMMAND_ID = 0; ///< Identificador único para el comando de conmutar (cambiar estado).
    static const int TURN_ON_COMMAND_ID = 1; ///< Identificador único para el comando de encender.
    static const int TURN_OFF_COMMAND_ID = 2; ///< Identificador único para el comando de apagar.
    
    // Objetos Command predefinidos
    static const Command TOGGLE_LED_COMMAND; ///< Comando predefinido para conmutar el LED.
    static const Command TURN_ON_COMMAND; ///< Comando predefinido para encender el LED.
    static const Command TURN_OFF_COMMAND; ///< Comando predefinido para apagar el LED.

    /**
     * @brief Constructor del actuador Led.
     * @param pin El pin GPIO físico para el LED (se configurará como OUTPUT en el archivo .cpp).
     * @param initialState Estado inicial del LED (por defecto: false / APAGADO).
     * @param commandHandler Puntero a un CommandHandler opcional para propagar comandos (por defecto: nullptr / nulo).
     */
    Led(int pin, bool initialState = false, CommandHandler* commandHandler = nullptr);

    /**
     * @brief Maneja los comandos para controlar el estado del LED.
     * @param command El comando que se solicita ejecutar (ej. TOGGLE_LED_COMMAND).
     */
    void handle(Command command) override;

    /**
     * @brief Obtiene el estado actual del LED.
     * @return true si el LED está ENCENDIDO, false si está APAGADO.
     * 
     * Explicación para principiantes: 'const' después de una función miembro significa que este método no modifica el estado interno del objeto Led.
     */
    bool getState() const;

    /**
     * @brief Establece el estado del LED directamente.
     * @param newState El nuevo estado deseado (true = ENCENDIDO, false = APAGADO).
     */
    void setState(bool newState);
};

#endif // LED_H