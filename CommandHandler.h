#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H


/**
 * @brief Representa un comando con un identificador único.
 * 
 * Explicación para principiantes: Un Comando (Command) es una instrucción u orden para que el sistema realice una acción específica
 * (por ejemplo: "apagar el LED", "encender el LED", "conmutar el LED"). Cada comando tiene un identificador numérico único (id).
 */
struct Command {
    int id; ///< Identificador único para el tipo de comando.

    // Constructor explícito. Permite crear un comando pasando su ID (ej. Command(1)).
    explicit Command(int commandId) : id(commandId) {}
    
    // Sobrecarga de operador == para comparar si dos comandos son idénticos de forma simple: commandA == commandB
    bool operator==(const Command& other) const { return id == other.id; }
};

/**
 * @brief Interfaz abstracta para manejar comandos.
 * 
 * Explicación para principiantes: Al igual que EventHandler, esta clase define un "contrato" en C++.
 * Cualquier clase que herede de CommandHandler debe obligatoriamente implementar el método `handle(Command command)`.
 * Esto permite dar órdenes a los componentes de salida (actuadores como el LED) de forma estandarizada.
 */
class CommandHandler {
public:
    /**
     * @brief Método virtual puro para procesar un comando.
     * @param command El comando u orden que se solicita ejecutar.
     * 
     * Toda clase que herede de CommandHandler debe definir este método con su propia lógica de ejecución.
     */
    virtual void handle(Command command) = 0; 
    
    virtual ~CommandHandler() = default; ///< Destructor virtual para asegurar una correcta liberación de memoria en clases heredadas.
};

#endif // COMMAND_HANDLER_H