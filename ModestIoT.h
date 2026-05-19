#ifndef MODEST_IOT_H
#define MODEST_IOT_H


// --- IMPORTACIÓN DE COMPONENTES DEL FRAMEWORK ---
// Explicación para principiantes: Incluir estos encabezados permite que cualquier archivo que incluya "ModestIoT.h"
// tenga acceso a todas las clases y estructuras del framework de una sola vez, simplificando el desarrollo.

#include "EventHandler.h"   // Manejo de Eventos (entrada de sensores)
#include "CommandHandler.h" // Manejo de Comandos (salida de actuadores)
#include "Sensor.h"         // Clase base para Sensores (lectura de señales)
#include "Actuator.h"       // Clase base para Actuadores (acción física)
#include "Button.h"         // Sensor específico de Botón
#include "Led.h"            // Actuador específico de LED
#include "Device.h"         // Clase base que unifica Sensores y Actuadores en un Dispositivo

#endif // MODEST_IOT_H
