#ifndef SENSOR_H
#define SENSOR_H


#include "EventHandler.h"

/**
 * @brief Clase base Sensor que implementa la interfaz EventHandler.
 * 
 * Explicación para principiantes: Un "Sensor" es cualquier componente de entrada del cual leemos información
 * (por ejemplo: un botón, un sensor de temperatura, un sensor de movimiento). 
 * Esta clase hereda de EventHandler porque el sensor puede recibir y propagar eventos.
 */
class Sensor : public EventHandler {
protected:
    int pin; ///< Pin GPIO físico asignado a este sensor en la placa.
    EventHandler* handler; ///< Puntero al manejador de eventos opcional que procesará los eventos generados por este sensor.

public:
    /**
     * @brief Constructor de la clase Sensor.
     * @param pin El pin GPIO físico para el sensor.
     * @param eventHandler Puntero a un EventHandler para recibir eventos (por defecto: nullptr / nulo).
     * 
     * Explicación para principiantes: Un constructor es la función que inicializa un objeto cuando es creado.
     */
    Sensor(int pin, EventHandler* eventHandler = nullptr);

    /**
     * @brief Maneja un evento propagándolo al manejador asignado.
     * @param event El evento que se va a procesar.
     * 
     * Explicación para principiantes: 'override' indica que estamos implementando la función que prometimos en EventHandler.
     */
    void on(Event event) override;

    /**
     * @brief Asigna o actualiza el manejador de eventos para este sensor.
     * @param eventHandler Puntero al nuevo EventHandler.
     */
    void setHandler(EventHandler* eventHandler);
};

#endif // SENSOR_H