////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void descartarEntrada (void)
//
//  USO:
//
//    Ignora cualquier dato que se encuentre actualmente en el flujo de entrada.
//
//  DETALLES:
//
//    Similar a vaciar el buffer, asegura que el programa no procese entradas
//    previas no deseadas.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////

void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void)
//
//  USO:
//
//    Limpia todo el contenido visual de la terminal.
//
//  DETALLES:
//
//    Dependiendo del sistema operativo, ejecuta un comando (como 'cls' o 'clear')
//    o envía una secuencia de escape para dejar la pantalla en blanco.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    system() o printf()
//
////////////////////////////////////////////////////////////////////////////////
void borrarPantalla (void)
{
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void limpiarPantalla (void)
//
//  USO:
//
//    Alias o función equivalente a borrarPantalla.
//
//  DETALLES:
//
//    Realiza la misma labor de limpieza visual de la terminal de texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    borrarPantalla()
//
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils)
//
//  USO:
//
//    Desplaza el cursor hacia abajo el número de filas indicado.
//
//  DETALLES:
//
//    A diferencia de un salto de línea común, esta función suele utilizarse
//    para mover el cursor de forma relativa a su posición actual.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que representa el número de filas a descender.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils)
//
//  USO:
//
//    Realiza saltos de línea verticales.
//
//  DETALLES:
//
//    Funciona de manera equivalente a imprimir múltiples caracteres '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que define la cantidad de saltos a realizar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    nuevaLinea()
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils)
//
//  USO:
//
//    Mueve la posición del cursor en el eje vertical (filas).
//
//  DETALLES:
//
//    Es una función de posicionamiento vertical relativo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que indica el desplazamiento en filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils)
//
//  USO:
//
//    Alias para el desplazamiento vertical del cursor.
//
//  DETALLES:
//
//    La 'V' hace referencia a "Vertical". Mueve el cursor nfils posiciones.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero con el número de filas a desplazar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    desplazarFils()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils)
//
//  USO:
//
//    Mueve el cursor en el eje Y (vertical).
//
//  DETALLES:
//
//    Utiliza la nomenclatura de coordenadas cartesianas donde Y es la vertical.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que indica la coordenada o incremento en Y.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    desplazarV()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas)
//
//  USO:
//
//    Genera un espacio de sangría o margen izquierdo.
//
//  DETALLES:
//
//    Desplaza el cursor a la derecha mediante espacios o tabulaciones.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Variable de tipo entero que indica el número de espacios de indentación.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols)
//
//  USO:
//
//    Mueve el cursor hacia la derecha el número de columnas especificado.
//
//  DETALLES:
//
//    A diferencia de la indentación simple, suele usarse para posicionamiento
//    relativo en la misma línea.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable de tipo entero que indica cuántas columnas avanzar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols)
//
//  USO:
//
//    Aplica un formato de tabulación horizontal.
//
//  DETALLES:
//
//    Efecto similar a la tecla TAB, desplazando el cursor un número ncols.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable de tipo entero que define el ancho de la tabulación.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    derecha()
//
////////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols)
//
//  USO:
//
//    Realiza un desplazamiento horizontal del cursor.
//
//  DETALLES:
//
//    Modifica la posición actual de la columna en la terminal.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable de tipo entero que indica el desplazamiento en columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols)
//
//  USO:
//
//    Mueve el cursor en el eje X (horizontal).
//
//  DETALLES:
//
//    Sigue la lógica de coordenadas cartesianas donde X es la horizontal.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable de tipo entero para el desplazamiento horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    desplazarCols()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols)
//
//  USO:
//
//    Alias para desplazamiento horizontal.
//
//  DETALLES:
//
//    La 'H' hace referencia a "Horizontal".
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable de tipo entero con el número de columnas a desplazar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    desplazarX()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols)
//
//  USO:
//
//    Ubica el cursor de la terminal en una coordenada específica de la pantalla.
//
//  DETALLES:
//
//    Es la función base para el control de la interfaz por consola. Permite
//    establecer dónde se escribirá el siguiente carácter, facilitando la
//    creación de menús, tablas o interfaces visuales organizadas.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que indica la fila (eje vertical) de destino.
//
//    ncols
//
//      Variable de tipo entero que indica la columna (eje horizontal) de destino.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Generalmente utiliza secuencias de escape ANSI para el movimiento.
//
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols)
//
//  USO:
//
//    Cambia la posición del cursor tanto en filas como en columnas.
//
//  DETALLES:
//
//    Se utiliza para saltar a un punto arbitrario de la pantalla de texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que indica la fila destino.
//
//    ncols
//
//      Variable de tipo entero que indica la columna destino.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
////////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarXY (int nfils, int ncols)
//
//  USO:
//
//    Mueve el cursor a coordenadas X e Y específicas.
//
//  DETALLES:
//
//    Equivalente a desplazar(), nombrando los ejes como en un plano.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero para la posición vertical.
//
//    ncols
//
//      Variable de tipo entero para la posición horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    desplazar()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax)
//
//  USO:
//
//    Genera una pausa en la ejecución de hasta un máximo de segundos.
//
//  DETALLES:
//
//    Utilizada para retardar procesos. El sufijo "max" suele sugerir que el
//    tiempo es el límite superior de la espera.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Variable de tipo entero que define el tiempo máximo de espera en segundos.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    esperarSegundos()
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax)
//
//  USO:
//
//    Genera una pausa breve de hasta un máximo de milisegundos.
//
//  DETALLES:
//
//    Utilizada en animaciones simples en consola o para dar fluidez visual
//    sin detener el programa por periodos largos.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Variable de tipo entero que indica el tope de milisegundos a esperar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    esperarMilisegundos()
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos)
//
//  USO:
//
//    Detiene la ejecución el tiempo exacto indicado en milisegundos.
//
//  DETALLES:
//
//    Funciona de manera idéntica a los retardos, sirviendo como alias
//    según la preferencia del programador.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable de tipo entero con la cantidad de tiempo a pausar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    esperarMilisegundos()
//
////////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos)
//
//  USO:
//
//    Pausa el flujo del programa durante una cantidad de segundos enteros.
//
//  DETALLES:
//
//    Implementación estándar de espera. Bloquea el proceso hasta que
//    transcurre el tiempo.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Variable de tipo entero que indica la duración de la pausa.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    sleep()
//
////////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos)
//
//  USO:
//
//    Pausa el flujo del programa durante una cantidad de milisegundos.
//
//  DETALLES:
//
//    Permite un control del tiempo mucho más preciso que la versión en segundos.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable de tipo entero que indica la duración de la pausa.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    usleep() o delay()
//
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void)
//
//  USO:
//
//    Detiene el programa hasta que el usuario realice una acción.
//
//  DETALLES:
//
//    Suele implementar un mensaje estándar de "Pulse una tecla para continuar".
//    Es útil para segmentar la ejecución del programa.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    esperarINTRO()
//
////////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols)
//
//  USO:
//
//    Realiza una pausa posicionando el mensaje en un lugar concreto.
//
//  DETALLES:
//
//    Mueve el cursor a la posición indicada antes de lanzar la instrucción
//    de pausa para mantener la estética de la interfaz.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que indica la fila donde se mostrará la pausa.
//
//    ncols
//
//      Variable de tipo entero que indica la columna donde se mostrará la pausa.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    pausa()
//
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Pausa personalizada con mensaje y posición configurables.
//
//  DETALLES:
//
//    Permite definir qué texto verá el usuario y si tras la pausa se debe
//    realizar un salto de línea.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres que contiene el mensaje de pausa personalizado.
//
//    nfils
//
//      Variable de tipo entero para la posición de la fila.
//
//    ncols
//
//      Variable de tipo entero para la posición de la columna.
//
//    nuevalinea
//
//      Variable booleana; si es true, añade un salto de línea tras la pausa.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    mostrar()
//    esperarINTRO()
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto (char msjtxt[])
//
//  USO:
//
//    Muestra una cadena de caracteres en la posición actual del cursor.
//
//  DETALLES:
//
//    Imprime el texto directamente sin modificar la posición previa del cursor.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Variable de tipo cadena de caracteres que contiene la información.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar (void)
//
//  USO:
//
//    Imprime un elemento visual (como una línea) para separar secciones.
//
//  DETALLES:
//
//    Ayuda a la legibilidad del contenido en la consola dividiendo bloques
//    de información.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void)
//
//  USO:
//
//    Inserta un salto de línea simple.
//
//  DETALLES:
//
//    Equivalente a imprimir el carácter especial '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[])
//
//  USO:
//
//    Envía un mensaje a la salida estándar.
//
//  DETALLES:
//
//    Alias o implementación común para la visualización de datos.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres con la información a visualizar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    texto()
//
////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje en unas coordenadas específicas de la pantalla.
//
//  DETALLES:
//
//    Combina el posicionamiento del cursor con la impresión de texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres con el texto.
//
//    nfils
//
//      Entero que indica la fila.
//
//    ncols
//
//      Entero que indica la columna.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    mostrar()
//
////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[])
//
//  USO:
//
//    Escribe una cadena de caracteres en la pantalla.
//
//  DETALLES:
//
//    Muestra el texto en la posición donde se encuentre el cursor.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Variable de tipo cadena que contiene el texto a escribir.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Escribe un texto en una ubicación específica de la pantalla.
//
//  DETALLES:
//
//    Sitúa el cursor en las coordenadas dadas antes de imprimir.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres con el contenido a mostrar.
//
//    nfils
//
//      Entero que indica la fila destino.
//
//    ncols
//
//      Entero que indica la columna destino.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    escribir()
//
////////////////////////////////////////////////////////////////////////////////

void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir (char msjtxt[])
//
//  USO:
//
//    Vuelca un mensaje de texto a la salida estándar.
//
//  DETALLES:
//
//    Envía la cadena de caracteres a la consola de forma directa.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Variable de tipo cadena con el mensaje informativo.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra texto formateado en una posición determinada.
//
//  DETALLES:
//
//    Realiza el salto a la coordenada (fila, columna) e imprime.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Texto que se desea visualizar.
//
//    nfils
//
//      Variable entera para la posición vertical.
//
//    ncols
//
//      Variable entera para la posición horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    imprimir()
//
////////////////////////////////////////////////////////////////////////////////

void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje informativo en pantalla.
//
//  DETALLES:
//
//    Ubica el cursor en nfils y ncols para mostrar el texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres que conforma el mensaje.
//
//    nfils
//
//      Fila donde se posicionará el inicio del mensaje.
//
//    ncols
//
//      Columna donde se posicionará el inicio del mensaje.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    mostrar()
//
////////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Muestra un mensaje con control de flujo de línea.
//
//  DETALLES:
//
//    Posiciona el texto y permite añadir un salto de línea opcional.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Contenido textual del mensaje.
//
//    nfils
//
//      Coordenada entera de la fila.
//
//    ncols
//
//      Coordenada entera de la columna.
//
//    nuevalinea
//
//      Booleano que indica si se debe saltar de línea tras el mensaje.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//    mostrar()
//    nuevaLinea()
//
////////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void)
//
//  USO:
//
//    Prepara la semilla para la generación de números aleatorios.
//
//  DETALLES:
//
//    Debe llamarse una sola vez al inicio del programa para asegurar que los
//    números generados posteriormente sean distintos en cada ejecución.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    srand()
//    time()
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite)
//
//  USO:
//
//    Calcula un número entero al azar entre 0 y el límite indicado.
//
//  DETALLES:
//
//    El valor devuelto suele ser mayor o igual a 0 y menor que el límite.
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      Variable entera que define el rango máximo de la generación.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa un valor entero generado aleatoriamente.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII (void)
//
//  USO:
//
//    Captura cualquier carácter de la tabla ASCII desde el teclado.
//
//  DETALLES:
//
//    Lee una pulsación de tecla sin realizar filtros previos.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor de tipo char que representa el carácter capturado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void)
//
//  USO:
//
//    Captura un único carácter alfabético válido.
//
//  DETALLES:
//
//    Filtra la entrada para asegurar que el carácter sea una letra.
//    Sólo acepta caracteres del estándar ASCII válidos.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor de tipo char representativo de la letra pulsada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//    vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Solicita un número entero que sea mayor o igual a cero.
//
//  DETALLES:
//
//    Valida la entrada y repite la petición si el número es negativo.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Texto descriptivo de la solicitud.
//
//    ncols
//
//      Posición de columna para el texto.
//
//    mostrarerror
//
//      Booleano que indica si debe mostrarse un mensaje de fallo.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor entero positivo validado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pedirEntero()
//    mensaje()
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
//
//  USO:
//
//    Solicita un entero dentro de un rango específico [min, max].
//
//  DETALLES:
//
//    Asegura que el valor esté comprendido entre los límites indicados.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Texto para la petición al usuario.
//
//    ncols
//
//      Columna de posicionamiento.
//
//    mostrarerror
//
//      Booleano para activar el aviso de error en pantalla.
//
//    min
//
//      Valor mínimo permitido.
//
//    max
//
//      Valor máximo permitido.
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero que cumple con el rango establecido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pedirEntero()
//    mensaje()
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
//
//  USO:
//
//    Solicita al usuario que introduzca una letra específica.
//
//  DETALLES:
//
//    Valida que el carácter coincida con el parámetro de referencia.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Texto de la petición.
//
//    ncols
//
//      Columna de posicionamiento.
//
//    mostrarerror
//
//      Booleano para activar el aviso de error.
//
//    letra
//
//      Carácter char que se espera recibir.
//
//  VALOR DE SALIDA:
//
//    Devuelve el valor ASCII de la letra validada (como entero).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//    validarLetraUnica()
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Solicita al usuario una respuesta de SÍ o NO (S/N).
//
//  DETALLES:
//
//    Ideal para preguntas de tipo "Desea salir?". Valida que el usuario solo
//    introduzca las opciones permitidas.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena con la pregunta de confirmación.
//
//    ncols
//
//      Entero para la posición horizontal del texto.
//
//    mostrarerror
//
//      Booleano que activa el mensaje de "Opción no válida" si el usuario falla.
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero (frecuentemente 1 para sí, 0 para no).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//    validarLetraConjunto()
//
////////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
//
//  USO:
//
//    Compara dos caracteres para ver si son iguales.
//
//  DETALLES:
//
//    Permite decidir si la comparación debe ignorar o no la diferencia entre
//    mayúsculas y minúsculas.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      Carácter de referencia.
//
//    dada
//
//      Carácter introducido por el usuario.
//
//    sensibleamayusculas
//
//      Booleano que define si 'A' es igual a 'a'.
//
//  VALOR DE SALIDA:
//
//    Devuelve un booleano (true si coinciden, false si no).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper() o tolower()
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Comprueba si un carácter pertenece a un grupo de caracteres permitidos.
//
//  DETALLES:
//
//    Verifica la existencia de la letra dentro del array de selección.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      Carácter de tipo char que se desea validar.
//
//    seleccion[]
//
//      Array de caracteres que contiene todas las opciones válidas.
//
//    sensibleamayusculas
//
//      Booleano que indica si se distingue entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor booleano (true si está en el conjunto, false si no).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    validarLetraUnica()
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char * cadenaOpcionesDisponibles (char entrada[])
//
//  USO:
//
//    Construye una cadena con las opciones que el usuario puede elegir.
//
//  DETALLES:
//
//    Formatea una lista de caracteres para mostrarla en el mensaje de error
//    o de petición (ej: "[S,N,O]").
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//
//      Array de caracteres con las opciones posibles.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero a la cadena de texto formateada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strcat()
//    sprintf()
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Solicita una letra que debe pertenecer a un conjunto de opciones dadas.
//
//  DETALLES:
//
//    Gestiona la petición y valida la entrada frente a una lista de caracteres.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      Cadena de caracteres con el texto de la petición para el usuario.
//
//    ncols
//
//      Variable entera que define la columna de posicionamiento del texto.
//
//    mostrarerror
//
//      Booleano que determina si se notifica al usuario una entrada inválida.
//
//    seleccion[]
//
//      Array de caracteres que contiene el conjunto de letras permitidas.
//
//    sensibleamayusculas
//
//      Booleano que indica si se debe diferenciar entre 'A' y 'a'.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor entero (código ASCII) de la letra seleccionada y validada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//    validarLetraConjunto()
//    mensaje()
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerTeclaInteractiva (void)
//
//  USO:
//
//    Captura de forma inmediata la pulsación de una tecla sin esperar al INTRO.
//
//  DETALLES:
//
//    Permite detectar teclas especiales (flechas, ESC, F1) para navegación.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero que representa el código de la tecla pulsada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getch() o kbhit()
//
////////////////////////////////////////////////////////////////////////////////

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
