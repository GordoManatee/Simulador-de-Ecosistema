# Simulador de un ecosistema

## Contexto
Se busca simular un ecosistema cerrado donde interactúan los depredadores y las presas. Para abordarlo, intente identificar correctamente las clases necesarias que modelan la dinámica biológica deacuerdo a las ecuaciones de Lotka-Volterra. La clase principal es "Simulation", encargada de iniciar y controlar la ejecución de la simulación en un número determinado de pasos. Esta clase contiene una instancia de "Ecosystem", que representa el entorno donde se desarrollan las interacciones entre las especies. Dentro del ecosistema, se encuentran las clases "Predator" y "Prey", cada una con atributos y métodos que describen su comportamiento específico. Por ejemplo, el depredador tiene una tasa de éxito al cazar y un número mínimo para asegurar su supervivencia, mientras que la presa posee una tasa de crecimiento y mecanismos de protección. Además, existe la clase "Population", que agrupa los datos de población de ambos organismos y permite simular su evolución conjunta.

### Cosas que puede hacer
- Simular la evolución de las poblaciones durante un número determinado de ciclos (pasos de tiempo).
- Permitir al usuario modificar parámetros como tasas de natalidad de las presas, tasa de caza de los depredadores.
- Mostrar gráficamente en consola cómo cambian los números poblacionales en cada iteración.
- Ajustar los valores iniciales de cada especie para observar diferentes comportamientos.

## Descripción 
Este proyecto es una simulación en C++ diseñada para modelar las interacciones entre poblaciones de depredadores y presas en un ecosistema cerrado. La simulación aprovecha los principios de la programación orientada a objetos para crear clases que representan cada población y aplica el **modelo de Lotka-Volterra** para calcular los cambios a lo largo del tiempo. Este proyecto proporciona una simulación simple basada en consola donde los usuarios pueden observar los cambios poblacionales basados en parámetros ajustables para las tasas de natalidad, mortalidad y depredación. 

### Razones por las que lo hice
Este proyecto nació del interés por combinar ecología y programación orientada a objetos. El modelo Lotka-Volterra es uno de los ejemplos más clásicos y accesibles dentro de la biología matemática, y llevarlo a código C++ permitió trabajar tanto la parte matemática como la estructuración lógica del software. Además, sirvió para practicar conceptos como herencia, encapsulamiento y polimorfismo, al representar a las especies como clases con características y comportamientos únicos.
Otra motivación fue mostrar de forma visual cómo pequeñas variaciones en los parámetros pueden generar comportamientos completamente distintos, algo fundamental para la teoría del caos y la modelación de sistemas biológicos.

## Características 
- **Modelado Orientado a Objetos**: Las poblaciones de depredadores y presas se modelan con clases separadas.
- **Simulación por Intervalos de Tiempo**: Avanza en pequeños intervalos de tiempo discretos para mostrar los cambios poblacionales en cada intervalo.
- **Salida por Consola**: Visualiza las actualizaciones de población con cada ciclo de simulación.
- **Sin Dependencias Externas**: Utiliza únicamente la biblioteca estándar de C++, lo que la hace portátil y fácil de compilar.

 ## Fundamentos del Modelo 
 La simulación se basa en las **ecuaciones de Lotka-Volterra**, un par de ecuaciones diferenciales que describen la dinámica depredador-presa. 
 - **Crecimiento de la presa**: La población de presas aumenta de manera proporcional a su población actual y disminuye con la actividad de caza de los depredadores.
 - **Mortalidad de los depredadores**: La población de depredadores crece en función de la disponibilidad de presas y disminuye debido a la mortandad natural.

### Ecuaciones 
1. **Crecimiento de la presa**: dP/dt = α⋅P − β⋅P⋅C
2. **Crecimiento de los depredadores**: dC/dt = δ⋅P⋅C − γ⋅C
Donde:
   - **P**: Población de presas
   - **C**: Población de depredadores
   - **α**: Tasa de natalidad de presas
   - **β**: Tasa de depredación - **δ**: Tasa de reproducción de depredadores
   - **γ**: Tasa de mortalidad de depredadores
              
## Estructura del Código 
- **Predador.h**: Define la clase **Predador**, incluyendo parámetros como tasas de reproducción y mortalidad.
- **Presa.h**: Define la clase **Presa**, incluyendo parámetros como tasas de natalidad y depredación.
- **Ecosistema.h**: Gestiona las interacciones entre depredadores y presas, aplicando las ecuaciones de Lotka-Volterra.
- **main.cpp**: Ejecuta la simulación, inicializando parámetros.

## Posibles problemas
En cuanto a los posibles problemas que harían que el proyecto deje de funcionar, se pueden identificar varios riesgos comunes en este tipo de simulaciones, como generar errores matemáticos, por ejemplo, divisiones por cero, en los cálculos de tasas o actualizaciones de población, lo cual es un problema bastante grave. También es importante considerar que las poblaciones podrían descender por debajo de cero, lo que no tiene sentido biológico ni lógico, así que es necesario incluir restricciones que eviten este tipo de resultados, para que la simulación sea lo más realista posible. Otro problema que podría surgir, es si no se controlan bien las condiciones de ejecución del método "run()" en la clase Simulation, ya que esto podría causar un ciclo infinito y detener el programa, lo que sería un desastre. Si los objetos que forman parte del ecosistema no son correctamente inicializados, se podrían producir errores donde no se tenga ninguna referencia.

---![UML](https://github.com/user-attachments/assets/e9480b21-8f07-4f89-a3a5-775a4fc079aa)
