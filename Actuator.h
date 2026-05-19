#ifndef ACTUATOR_H
#define ACTUATOR_H


#include "CommandHandler.h"

/**
 * @brief Clase base Actuator que implementa la interfaz CommandHandler.
 * 
 * Explicación para principiantes: Un "Actuador" es cualquier componente de salida que realiza una acción física 
 * en el mundo real (por ejemplo: un LED, un servomotor, un relé para encender un motor).
 * Hereda de CommandHandler porque recibe comandos u órdenes para saber qué acción ejecutar.
 */
class Actuator : public CommandHandler {
protected:
    int pin; ///< Pin GPIO físico asignado a este actuador en la placa.
    CommandHandler* handler; ///< Puntero al manejador de comandos opcional que recibirá la confirmación o propagación de los comandos.

public:
    /**
     * @brief Constructor de la clase Actuator.
     * @param pin El pin GPIO físico para el actuador.
     * @param commandHandler Puntero a un CommandHandler para procesar o propagar los comandos (por defecto: nullptr / nulo).
     */
    Actuator(int pin, CommandHandler* commandHandler = nullptr);

    /**
     * @brief Maneja un comando propagándolo al manejador asignado.
     * @param command El comando que se va a procesar.
     */
    void handle(Command command) override;

    /**
     * @brief Asigna o actualiza el manejador de comandos para este actuador.
     * @param commandHandler Puntero al nuevo CommandHandler.
     */
    void setHandler(CommandHandler* commandHandler);
};

#endif // ACTUATOR_H