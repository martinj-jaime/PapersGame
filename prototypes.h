
#include "inmigrante.h"

/** RANDOM **/
void randomizarInmigrantes      (stInmigrante inmigrantes[], int cantInmigrantes);
int random_dni                  ();
// int edad                     (stInmigrante inmigrante[], int i);
int random_dia                  ();
int random_mes                  ();
int random_ano                  ();
int random_vencimiento          ();
char random_genero              ();
void random_zona                (stInmigrante inmigrante[], int i);
void random_nombre              (stInmigrante inmigrante[], int i);
void random_apellido            (stInmigrante inmigrante[], int i);
void random_proposito           (stInmigrante inmigrantes[], int i);
void random_duracion            (stInmigrante inmigrantes[], int i);

/** MENU **/
int Menu                        (int * cantInmigrantes, stInmigrante inmigrantes[]);
void goY                        (int y);
void Logo                       ();
void SelectCantInmigrantes      (int * cantInmigrantes);
void Historial                  ();
void mostrarHistorial           (stResumenPartida resumen);


/** PRINCIPAL **/
void InmigrantesRestantes       (int validos, int i);
void MostrarDNIyPermiso         (stInmigrante inmigrantes[], int i);
void Principal                  (stInmigrante inmigrantes[], int validos);
void mostrar_tarjetas           (stInmigrante inmigrantes[], int validos);
void validarDejarPasar          (char dejarPasar[]);
void inputDejarPasar            (char dejarPasar[]);


/** RESUMEN **/
int cantidadInfiltrados         (stInmigrante inmigrantes[], int validos);
int cantidadAcertados           (stInmigrante inmigrantes[], int validos);
int cantidadFallidos            (stInmigrante inmigrantes[], int validos);
void date                       (stResumenPartida *resumen);

/** USUARIOS **/

void iniciarSesion              (stUsuarios * user);
void login                      (FILE * archi, stUsuarios * user);
void registrarse                (FILE * archi, stUsuarios * user);
int buscarUser                  (char name[]);

/** VALIDACIONES **/
void controlString              (char x[]);










