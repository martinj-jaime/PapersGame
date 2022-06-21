
#define TAM 41              // dimension global para strings
#define CANT_INMIGRANTES 31 // dimension del arreglo de inmigrantes
#define FECHA_JUEGO 1860
#define historial "historial.bin"
#define USER "users.bin"

/** Usuarios **/
typedef struct {
    char nombre[TAM];
    char password[TAM];
} stUsuarios;

/** Permiso: subcampo **/
typedef struct {
    char nombre[TAM];
    char apellido[TAM];
    int dni;
    char proposito[TAM];
    int duracion;
} stPermiso;

/** Inmigrante **/
typedef struct {
    int visado;
    int infiltrado;

    char nombre[TAM];
    char apellido[TAM];
    int dni;
    int edad;
    int diaNacimineto;
    int mesNacimineto;
    int anoNacimineto;
    char zona[TAM];
    int vencimientoDNI;
    char genero;

    stPermiso permiso;
} stInmigrante;

/** Resumen de la partida **/
typedef struct {
    char usuario[TAM];
    int fecha[TAM];
    int totalInmigrantes;
    int totalInfiltrados;
    int infiltradosAcertados;
    int infiltradosFallidos;
} stResumenPartida;



