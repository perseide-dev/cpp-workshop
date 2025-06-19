# Practicas de taller de C++

Este repositorio contiene una coleccion de practicas en C++ centradas en sistemas de gestion de inventario.

## Practica 4 - Sistema Basico de Inventario

### Descripcion
Un sistema sencillo de gestion de inventario que utiliza matrices estaticas que:
- Almacena los ID y nombres de los articulos
- Controla los niveles y limites de existencias
- Calcula precios unitarios y valores totales
- Proporciona alertas de existencias cuando los niveles estan por debajo de los limites

### Diagrama de flujo
```mermaid
flowchart TD
A[Inicio] --> B[Declarar R = 4]
B --> C[Ingresar numero de articulos n]
C --> D[Crear matrices itemID, itemName, matriz m1]
D --> E[Inicializar totales]
E --> F[Bucle de entrada]
F --> G[Calcular totales de articulos]
G --> H[Comprobar alertas de existencias]
H --> I[Mostrar tabla]
I --> J[Calcular y mostrar totales]
J --> K[Fin]
```

## Practica 5 - Inventario con Memoria Dinamica

### Descripcion
Una version mejorada de la Practica 4 con asignacion dinamica de memoria:
- Utiliza matrices dinamicas para los datos de los articulos
- Implementa una gestion adecuada de la memoria
- Mantiene la misma funcionalidad que la Practica 4
- Incluye limpieza de memoria

### Diagrama de flujo
```mermaid
flowchart TD
A[Inicio] --> B[Declarar R = 4]
B --> C[Ingresar numero de articulos n]
C --> D[Asignar memoria dinamica]
D --> E[Bucle de entrada]
E --> F[Calcular totales]
F --> G[Alertas de stock]
G --> H[Mostrar tabla]
H --> I[Mostrar totales]
I --> J[Liberar memoria]
J --> K[Fin]
```

## Practica 6 - Inventario con Matriz Fija

### Descripcion
Una variacion que utiliza matrices de tamano fijo:
- Utiliza matrices 2D para la informacion de los articulos
- Implementa la gestion de existencias
- Calcula los valores del inventario
- Proporciona alertas de stock

### Diagrama de flujo
```mermaid
flowchart TD
A[Inicio] --> B[Inicializar matrices]
B --> C[Datos de entrada]
C --> D[Procesar elementos]
D --> E[Mostrar alertas]
E --> F[Mostrar tabla]
F --> G[Calcular totales]
G --> H[Fin]
```

## Practica 7 - Inventario Dinamico Avanzado

### Descripcion
La version mas sofisticada con:
- Gestion totalmente dinamica de la memoria
- Organizacion mejorada de los datos
- Interfaz de usuario mejorada
- Seguimiento completo del inventario

### Diagrama de flujo
```mermaid
flowchart TD
A[Inicio] --> B[Inicializar sistema]
B --> C[Asignar memoria dinamica]
C --> D[Ingresar datos del articulo]
D --> E[Procesar inventario]
E --> F[Mostrar alertas]
F --> G[Mostrar resumen]
G --> H[Limpieza de memoria]
H --> I[Fin]
```

## Caracteristicas Comunes en Todas las Practicas

- Seguimiento del nivel de existencias
- Calculo de precios
- Alertas de inventario
- Visualizacion de datos en tablas
- Calculo del valor total
