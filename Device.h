#ifndef DEVICE_H
#define DEVICE_H


#include "EventHandler.h"
#include "CommandHandler.h"

/**
 * @brief Clase abstracta Device que hereda de EventHandler y CommandHandler.
 * 
 * Explicación para principiantes: En C++, la herencia múltiple permite a una clase adoptar varios comportamientos.
 * `Device` representa un dispositivo IoT completo. Para ser un dispositivo funcional, debe ser capaz de reaccionar 
 * a lecturas físicas (por eso es un EventHandler) y ejecutar órdenes en sus componentes (por eso es un CommandHandler).
 */
class Device : public EventHandler, public CommandHandler {
public:
    /**
     * @brief Maneja un evento recibido por el dispositivo.
     * @param event El evento que se va a procesar (ej. botón presionado).
     */
    virtual void on(Event event) override = 0;

    /**
     * @brief Maneja un comando emitido al dispositivo.
     * @param command El comando que se va a ejecutar.
     */
    virtual void handle(Command command) override = 0;

    virtual ~Device() = default; ///< Destructor virtual para asegurar una correcta liberación de recursos al heredar de esta clase.
};

#endif // DEVICE_H
