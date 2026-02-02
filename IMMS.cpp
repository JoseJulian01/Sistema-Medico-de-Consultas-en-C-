/*
LSEA lISTAS SIMPLES ENCADEADAS
OBSERVACIONES:
- NO SE PUEDE ACCEDER A UN ELEMENTO DE LA LISTA SIN PASAR POR LOS ANTERIORES
- NO SE PUEDE ACCEDER A UN ELEMENTO DE LA LISTA SIN PASAR POR LOS POSTERIORES
- NO SE PUEDE ACCEDER A UN ELEMENTO DE LA LISTA SIN PASAR POR LOS ANTERIORES
- Simple= Apunta a 1 nodo
- Abiertas= Se acaban en NULL
- Fecha de inicio del proyecto : 15-11-2025
- Fecha de finalización del proyecto : 25-11-2025
- Autores: José Julián Flores Ramirez Y Valery Ximena Oceguera de la Torre
- Proyecto: IMMS
- Objetivo: Análisis clinico de los pacientes del hospital IMMS
*/
//:)

// Validaciones de datos

// Formato de fecha correcta DD/MM/AAAA
// Formato de hora (24 horas) correcto HH:MM
// Costos validos > 0
// Filtro de rango de fechas DD/MM/AAAA - DD/MM/AAAA

// Librerias
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <fstream> // agregado para ofstream/ifstream en la funcion de guardar y recuperar archivo
#include <iomanip> // necesario para setprecision y fixed para imprimir costos con dos decimales
#include <iostream>
#include <stdlib.h>

// Librerias nuevas utilizadas
#include <algorithm>
#include <vector>
// Funcionamiento de las librerias:
//  algorithm: Proporciona algoritmos estándar para operaciones comunes como
//  búsqueda, ordenamiento, etc.
//  vector: Implementa un contenedor dinámico que permite almacenar una
//  colección de elementos.

// Funciones agregadas al sistema:
//  sort: Ordena los elementos de un rango en orden ascendente.
//  lambda: Permite definir funciones anónimas (funciones sin nombre) que pueden
//  ser usadas como parámetros de algoritmos. begin: Devuelve un iterador al
//  primer elemento del rango. end: Devuelve un iterador al final del rango.
//  const: Indica que la función no modificará los datos de la lista.

using namespace std;

// TDA´s
struct AnalisiClinico {
  char NombrePaciente[50];
  char NombreMedico[50];
  char Especialidad[50];
  char Fecha[20];
  char Hora[20];
  char Diagnostico[100];
  char Tratamiento[100];
  char Medicamentos[100];
  char Observaciones[100];
  char Resultados[100];
  char Conclusiones[100];
  char Recomendaciones[100];
  float costo;
  // Apuntar al siguiente nodo
  AnalisiClinico *apNext;
};

// Apuntador a mi lista(Variable Global)
AnalisiClinico *apLista = NULL;

// Prototipos de funciones (Operaciones)

// Menu de opciones
void menu(void);
// Pedir los datos
void capturarDatos(AnalisiClinico *nuevo);
// Agregar un nuevo paciente al inicio de la lista
void agregar_inicio(void);
// Agregar un nuevo paciente al final de la lista
void agregar_final(void);
// Mostrar historial de pacientes
void mostrar_historial(void);
// Filtrar pacientes por costos
void filtrar_costos(void);
// Filtrar pacientes por fecha
void filtrar_fecha(void);
// Filtrar pacientes por Especialidad
void filtrar_especialidad(void);
// Modificar un campo en especifico de un paciente
void modificarPaciente(void);
// Buscar un paciente por nombre
void buscar_nombre(void);
// Buscar pacientes por el Medico
void buscar_medico(void);
// Guardar los datos en la lista en un archivo de texto (respaldo)
void guardar_archivo(void);
// Recuperar los datos del archivo de texto (respaldo) y mostrarlos en la
// pantalla
void recuperar_archivo(void);
// Eliminar un paciente por nombre
void eliminar_paciente(void);
// Ordenar pacientes por costo (de menor a mayor)
void ordenar_por_costo(void);

// Funcion principal
int main(void) {

  menu();
  return 0;
}

//---------------------------------------------------Implementacion de
// funciones--------------------------------------------------//

// Menu de opciones
void menu(void) {
  system("CLS");
  int opc; //Variable opcion para el Switch

  cout << "         _ _ _ _ _ _ _ _ _        " << endl;
  cout << "         |     IMMS      |         " << endl;
  cout << "         |     +   +     |         " << endl;
  cout << "         |   +       +   |         " << endl;
  cout << "         |     +   +     |         " << endl;
  cout << "         |_ _ _ _ _ _ _ _|         " << endl;
  cout << "          |   [     ]   |           " << endl;
  cout << "          |   [     ]   |           " << endl;
  cout << "          |   [     ]   |           " << endl;
  cout << "          |___[_____]___|           " << endl;
  cout << "        BIENVENIDO AL SISTEMA      " << endl;
  cout << endl;
  cout << endl;
  system("pause");
  system("CLS");
  do {
    cout << "Ingrese la opcion deseada: ";

    cout << "\n";
    cout << "===MENU DE OPCIONES===" << endl;
    cout << "1. Agregar un nuevo paciente al inicio de la lista" << endl;
    cout << "2. Agregar un nuevo paciente al final de la lista" << endl;
    cout << "3. Mostrar historial de pacientes" << endl;
    cout << "4. Filtrar pacientes por costos" << endl;
    cout << "5. Filtrar pacientes por fecha" << endl;
    cout << "6. Filtrar pacientes por Especialidad" << endl;
    cout << "7. Buscar un paciente por nombre" << endl;
    cout << "8. Buscar pacientes por el Medico" << endl;
    cout << "9. Modificar datos del paciente" << endl;
    cout
        << "10. Guardar los datos en la lista en un archivo de texto (respaldo)"
        << endl;
    cout << "11. Recuperar los datos del archivo de texto (respaldo) y "
            "mostrarlos en la pantalla"
         << endl;
    cout << "12. Eliminar un paciente por nombre" << endl;
    cout << "13. Ordenar pacientes por costo (de menor a mayor)" << endl;
    cout << "0. Salir del programa" << endl;
    cin >> opc;
    switch (opc) {
    case 1:
      agregar_inicio();
      break;
    case 2:
      agregar_final();
      break;
    case 3:
      mostrar_historial();
      break;
    case 4:
      filtrar_costos();
      break;
    case 5:
      filtrar_fecha();
      break;
    case 6:
      filtrar_especialidad();
      break;
    case 7:
      buscar_nombre();
      break;
    case 8:
      buscar_medico();
      break;
    case 9:
      modificarPaciente();
      break;
    case 10:
      guardar_archivo();
      break;
    case 11:
      recuperar_archivo();
      break;
    case 12:
      eliminar_paciente();
      break;
    case 13:
      ordenar_por_costo();
      break;
    case 0:
      cout << "Saliendo del programa..." << endl;
      break;
    default:
      cout << "Opcion invalida, intente de nuevo" << endl;
      break;
    } // fin switch
    system("pause");
    system("CLS");
  } while (opc != 0); // fin do while

} // fin menu

// Funcion para capturar los datos del paciente
void capturarDatos(AnalisiClinico *nuevo) {
  cout << "Ingrese el nombre del paciente: ";

  cin.getline(nuevo->NombrePaciente, 50);

  cout << "Ingrese el nombre del medico: ";
  cin.getline(nuevo->NombreMedico, 50);

  cout << "Ingrese la especialidad: ";
  cin.getline(nuevo->Especialidad, 50);

  // Pedir Fecha
  bool fecha_valida = false;
  do {
    cout << "Ingrese la fecha (DD/MM/AAAA): "; // Validación de fecha
    cin.getline(nuevo->Fecha, 20);

    int d, m, a;
    if (sscanf(nuevo->Fecha, "%d/%d/%d", &d, &m, &a) == 3) {
      if (a >= 1900 && a <= 2100 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
        // Validar días tomando en cuenta el mes y años bisiestos
        int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // Año bisiesto
        if (m == 2 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)))
          dias_mes[1] = 29;
        if (d <= dias_mes[m - 1])
          fecha_valida = true;
        else
          cout << "Día inválido para el mes ingresado. Intente de nuevo.\n";

      } else {
        cout << "Fecha fuera de rango. Intente de nuevo.\n";
      }

    } else {
      cout << "Formato inválido. Use DD/MM/AAAA. Intente de nuevo.\n";
    }
  } while (!fecha_valida);

  // Pedir hora
  bool hora_valida = false;
  char hora_ingresada[20];
  do {
    cout << "Ingrese la hora (HH:MM): ";
    cin.getline(hora_ingresada, 20);

    int h, m;
    if (sscanf(hora_ingresada, "%d:%d", &h, &m) ==
        2) { // Validar la hora con el formato 24 horas
      if (h >= 0 && h <= 23 && m >= 0 && m <= 59) {
        hora_valida = true;
        strcpy(nuevo->Hora, hora_ingresada);
      } else {
        cout << "Hora fuera de rango. Intente de nuevo.\n";
      }
    } else {
      cout << "Formato inválido. Use HH:MM. Intente de nuevo.\n";
    }

  } while (!hora_valida);

  cout << "Ingrese el diagnostico: ";
  cin.getline(nuevo->Diagnostico, 100);

  cout << "Ingrese el tratamiento: ";
  cin.getline(nuevo->Tratamiento, 100);

  cout << "Ingrese los medicamentos: ";
  cin.getline(nuevo->Medicamentos, 100);

  cout << "Ingrese las observaciones: ";
  cin.getline(nuevo->Observaciones, 100);

  cout << "Ingrese los resultados: ";
  cin.getline(nuevo->Resultados, 100);

  cout << "Ingrese las conclusiones: ";
  cin.getline(nuevo->Conclusiones, 100);

  cout << "Ingrese las recomendaciones: ";
  cin.getline(nuevo->Recomendaciones, 100);

  cout << "Ingrese el costo: ";
  cin >> nuevo->costo;
  if (nuevo->costo <= 0) {
    cout << "El costo no puede ser 0" << endl;
  }
  cin.ignore(); // Limpiar buffer por si se vuelve a pedir getline después
}

// Función para agregar al inicio de la lista
void agregar_inicio(void) {
  system("CLS");
  // Declaracion de variables
  AnalisiClinico *nuevo;
  nuevo = new AnalisiClinico;
  cin.ignore(); // Limpiar buffer antes de capturar datos
  capturarDatos(nuevo);

  // Apuntar al siguiente nodo
  nuevo->apNext = apLista;
  // Asignar el nuevo nodo a la lista
  apLista = nuevo;
  // Mensaje de confirmacion
  cout << "Paciente agregado al inicio de la lista" << endl;
  system("pause");
  system("CLS");
}

// Función para agregar al final de la lista
void agregar_final(void) {
  AnalisiClinico *nuevo;
  nuevo = new AnalisiClinico;
  cin.ignore(); // Limpiar buffer antes de capturar datos
  capturarDatos(nuevo);

  // Verificar si la lista esta vacia
  if (apLista == NULL) {
    // Si la lista esta vacia, el nuevo nodo es el primero
    apLista = nuevo;
    nuevo->apNext = NULL;
  } else {
    // Si la lista no esta vacia, el nuevo nodo se agrega al final
    AnalisiClinico *aux = apLista;
    while (aux->apNext != NULL) {
      aux = aux->apNext;
    }
    aux->apNext = nuevo;
    nuevo->apNext = NULL;
  }
  // Mensaje de confirmacion
  cout << "Paciente agregado al final de la lista" << endl;
  system("pause");
  system("CLS");
}

// Mostrar historial de pacientes
void mostrar_historial(void) {
  system("CLS");
  // Declaracion de variables
  AnalisiClinico *aux = apLista;
  while (aux != NULL) {
    cout << "=================HISTORIAL===========================\n";
    cout << "Nombre del paciente: " << aux->NombrePaciente << endl;
    cout << "Nombre del medico: " << aux->NombreMedico << endl;
    cout << "Especialidad: " << aux->Especialidad << endl;
    cout << "Fecha: " << aux->Fecha << endl;
    cout << "Hora: " << aux->Hora << endl;
    cout << "Diagnostico: " << aux->Diagnostico << endl;
    cout << "Tratamiento: " << aux->Tratamiento << endl;
    cout << "Medicamentos: " << aux->Medicamentos << endl;
    cout << "Observaciones: " << aux->Observaciones << endl;
    cout << "Resultados: " << aux->Resultados << endl;
    cout << "Conclusiones: " << aux->Conclusiones << endl;
    cout << "Recomendaciones: " << aux->Recomendaciones << endl;
    cout << "Costo: " << aux->costo << endl;
    cout << "============================================\n";
    aux = aux->apNext; // Avanzar al siguiente nodo
  }
  if (apLista == NULL) {
    cout << "No hay pacientes en el historial." << endl;
    return;
  }
  system("pause");
  system("CLS");
} // fin mostrar_historial

// Filtrar pacientes por  rango de costos
void filtrar_costos(void) {
  system("CLS");
  // Declaración de variables
  float rangoMin, rangoMax;
  bool encontrado = false;

  // Caso A) Lista vacía
  if (apLista == NULL) {
    cout << "==La lista está vacía==" << endl;
    return;
  }

  // Consultar el rango de costos (validación correcta, el mínimo debe ser
  // menor que el máximo)
  do {
    cout << "--Ingrese el menor rango de costo que desea obtener--" << endl;
    cin >> rangoMin;
    cout << "--Ingrese el máximo rango de costo que desea obtener--" << endl;
    cin >> rangoMax;
    if (rangoMin >= rangoMax) {
      cout << "El costo mínimo debe ser menor que el costo máximo. Intente "
              "nuevamente."
           << endl;
    }
  } while (rangoMin >= rangoMax);

  // Apuntador que recorre la lista
  AnalisiClinico *aux = apLista;

  // Caso B) Lista con uno o más nodos
  while (aux != NULL) {
    if (aux->costo >= rangoMin && aux->costo <= rangoMax) {
      encontrado = true;
      cout << "Clientes con el rango de costos de Análisis: \n";
      cout << "============================================\n";
      cout << "Nombre del paciente: " << aux->NombrePaciente << endl;
      cout << "Nombre del medico: " << aux->NombreMedico << endl;
      cout << "Especialidad: " << aux->Especialidad << endl;
      cout << "Fecha: " << aux->Fecha << endl;
      cout << "Hora: " << aux->Hora << endl;
      cout << "Diagnostico: " << aux->Diagnostico << endl;
      cout << "Tratamiento: " << aux->Tratamiento << endl;
      cout << "Medicamentos: " << aux->Medicamentos << endl;
      cout << "Observaciones: " << aux->Observaciones << endl;
      cout << "Resultados: " << aux->Resultados << endl;
      cout << "Conclusiones: " << aux->Conclusiones << endl;
      cout << "Recomendaciones: " << aux->Recomendaciones << endl;
      cout << "Costo: " << aux->costo << endl;
      cout << "============================================\n";
    }
    aux = aux->apNext; // Avanzar al siguiente nodo
  }
  if (encontrado == false) {
    cout << "No se encontraron pacientes en el rango de costos especificado."
         << endl;
  }
  system("pause");
} // fin filtrar_costos

// Función auxiliar para convertir fecha DD/MM/AAAA a entero AAAAMMDD
long fechaAEntero(char *fecha) {
  int d, m, a;
  if (sscanf(fecha, "%d/%d/%d", &d, &m, &a) == 3) {
    return a * 10000 + m * 100 + d;
  }
  return 0;
}

// Filtrar pacientes por fecha
void filtrar_fecha(void) {
  system("CLS");

  // Declaración de variables
  char fechaInicio[20];
  char fechaFin[20];
  bool encontrado = false;

  // Caso A) Lista vacía
  if (apLista == NULL) {
    cout << "==La lista está vacía==" << endl;
    return;
  }

  // Consultar el rango de fechas
  bool fechaValida = false;
  do {
    cout << "--Ingrese la fecha de inicio (DD/MM/AAAA)--" << endl;
    cin.ignore(); // Limpiar buffer antes de la entrada de texto
    cin.getline(fechaInicio, 20);

    // Validación básica de formato (longitud y posiciones de '/')
    if (strlen(fechaInicio) == 10 && fechaInicio[2] == '/' &&
        fechaInicio[5] == '/') {
      fechaValida = true;
    } else {
      cout << "Formato de fecha inválido. Intente nuevamente (DD/MM/AAAA)."
           << endl;
    }
  } while (!fechaValida);

  fechaValida = false;
  do {
    cout << "--Ingrese la fecha de fin (DD/MM/AAAA)--" << endl;
    cin.getline(fechaFin, 20);

    // Validación básica de formato (longitud y posiciones de '/')
    if (strlen(fechaFin) == 10 && fechaFin[2] == '/' && fechaFin[5] == '/') {
      // Ahora valida que fechaInicio <= fechaFin usando la funcion auxiliar
      if (fechaAEntero(fechaInicio) > fechaAEntero(fechaFin)) {
        cout << "La fecha de fin debe ser igual o posterior a la fecha de "
                "inicio. Intente nuevamente."
             << endl;
      } else {
        fechaValida = true;
      }
    } else {
      cout << "Formato de fecha inválido. Intente nuevamente (DD/MM/AAAA)."
           << endl;
    }
  } while (!fechaValida);

  // Apuntador que recorre la lista
  AnalisiClinico *aux = apLista;

  // Caso B) Lista con uno o más nodos
  while (aux != NULL) {
    long fActual = fechaAEntero(aux->Fecha);
    long fInicio = fechaAEntero(fechaInicio);
    long fFin = fechaAEntero(fechaFin);

    if (fActual >= fInicio && fActual <= fFin) {
      encontrado = true;
      cout << "Clientes con el rango de fechas de Análisis: \n";
      cout << "============================================\n";
      cout << "Nombre del paciente: " << aux->NombrePaciente << endl;
      cout << "Nombre del medico: " << aux->NombreMedico << endl;
      cout << "Especialidad: " << aux->Especialidad << endl;
      cout << "Fecha: " << aux->Fecha << endl;
      cout << "Hora: " << aux->Hora << endl;
      cout << "Diagnostico: " << aux->Diagnostico << endl;
      cout << "Tratamiento: " << aux->Tratamiento << endl;
      cout << "Medicamentos: " << aux->Medicamentos << endl;
      cout << "Observaciones: " << aux->Observaciones << endl;
      cout << "Resultados: " << aux->Resultados << endl;
      cout << "Conclusiones: " << aux->Conclusiones << endl;
      cout << "Recomendaciones: " << aux->Recomendaciones << endl;
      cout << "Costo: " << aux->costo << endl;
      cout << "============================================\n";
    }
    aux = aux->apNext; // Avanzar al siguiente nodo
  }
  if (encontrado == false) {
    cout << "No se encontraron pacientes en el rango de fechas especificado."
         << endl;
  } // fin if
  system("pause");
} // fin filtrar_fecha

// Filtrar pacientes por Especialidad
void filtrar_especialidad(void) {
  system("CLS");

  // Declaración de variables
  char especialidadBuscar[50];
  bool encontrado = false;
  // Caso A) Lista vacía
  if (apLista == NULL) {
    cout << "==La lista está vacía==" << endl;
    return;
  }
  // Consultar la especialidad a buscar
  cout << "--Ingrese la especialidad que desea buscar--" << endl;
  cin.ignore(); // Limpiar buffer antes de la entrada de texto
  cin.getline(especialidadBuscar, 50);
  // Apuntador que recorre la lista
  AnalisiClinico *aux = apLista;
  // Caso B) Lista con uno o más nodos
  while (aux != NULL) {
    if (strcmp(aux->Especialidad, especialidadBuscar) == 0) {
      encontrado = true;
      cout << "Clientes con la especialidad de :" << especialidadBuscar << "\n";
      cout << "============================================\n";
      cout << "Nombre del paciente: " << aux->NombrePaciente << endl;
      cout << "Nombre del medico: " << aux->NombreMedico << endl;
      cout << "Especialidad: " << aux->Especialidad << endl;
      cout << "Fecha: " << aux->Fecha << endl;
      cout << "Hora: " << aux->Hora << endl;
      cout << "Diagnostico: " << aux->Diagnostico << endl;
      cout << "Tratamiento: " << aux->Tratamiento << endl;
      cout << "Medicamentos: " << aux->Medicamentos << endl;
      cout << "Observaciones: " << aux->Observaciones << endl;
      cout << "Resultados: " << aux->Resultados << endl;
      cout << "Conclusiones: " << aux->Conclusiones << endl;
      cout << "Recomendaciones: " << aux->Recomendaciones << endl;
      cout << "Costo: " << aux->costo << endl;
      cout << "============================================\n";
    }
    aux = aux->apNext; // Avanzar al siguiente nodo
  } // fin while
  if (encontrado == false) {
    cout << "No se encontraron pacientes con la especialidad especificada."
         << endl;
  } // fin if
  system("pause");
} // fin filtrar_especialidad

// Buscar un paciente por nombre
void buscar_nombre(void) {
  // 1)     Declarar un apuntador auxiliar
  AnalisiClinico *apCopia = apLista; // Apuntador que recorre la lista
  // Caso A) Lista vacia
  if (apLista == NULL) {
    cout << "==La lista esta vacia==" << endl;
    return;
  } // if
  // Consultar nombre del paciente a mostrar
  char nombreBuscar[50];
  cout << "Ingresa el nombre del paciente a buscar" << endl;
  cin.ignore(); // Limpiar buffer
  cin.getline(nombreBuscar, 50, '\n');
  // Caso B) Lista con uno o más nodos
  cout << "La direccion de la memoria empieza en: ->" << apLista->apNext
       << endl;
  cout << "Este nodo esta en la direccion de memoria: ->" << apCopia << endl;
  bool encontrado = false;
  do {
    if (strcmp(apCopia->NombrePaciente, nombreBuscar) == 0) {
      encontrado = true;
      cout << "Paciente encontrado." << endl;
      cout << "\n";
      cout << "===DATOS DEL PACIENTE===" << endl;
      cout << "Nombre del paciente: " << apCopia->NombrePaciente << endl;
      cout << "Nombre del medico: " << apCopia->NombreMedico << endl;
      cout << "Especialidad: " << apCopia->Especialidad << endl;
      cout << "Fecha: " << apCopia->Fecha << endl;
      cout << "Hora: " << apCopia->Hora << endl;
      cout << "Diagnostico: " << apCopia->Diagnostico << endl;
      cout << "Tratamiento: " << apCopia->Tratamiento << endl;
      cout << "Medicamentos: " << apCopia->Medicamentos << endl;
      cout << "Observaciones: " << apCopia->Observaciones << endl;
      cout << "Resultados: " << apCopia->Resultados << endl;
      cout << "Conclusiones: " << apCopia->Conclusiones << endl;
      cout << "Recomendaciones: " << apCopia->Recomendaciones << endl;
      cout << "Costo: " << apCopia->costo << endl;
      cout << "Direccion de memoria del nodo: ->" << apCopia->apNext << endl;

      // Mover el apuntador al siguiente nodo
      apCopia = apCopia->apNext; // Avanzar al siguiente nodo
    } // fin IF
    else {
      apCopia = apCopia->apNext; // Avanzar al siguiente nodo
    } // fin else
  } while (apCopia != NULL);
  if (!encontrado)
    cout << "Paciente con nombre " << nombreBuscar << " No fue localizado."
         << endl;
  system("pause");
} // fin buscar_nombre

// Buscar pacientes por el Medico
void buscar_medico(void) {

  // 1)     Declarar un apuntador auxiliar
  AnalisiClinico *apCopia = apLista; // Apuntador que recorre la lista
  // Caso A) Lista vacia
  if (apLista == NULL) {
    cout << "==La lista esta vacia==" << endl;
    return;
  } // if
  // Consultar nombre del medico a mostrar
  char medicoBuscar[50];
  cin.ignore();
  cout << "Ingresa el nombre del medico a buscar" << endl;
  cin.getline(medicoBuscar, 50, '\n');
  // Caso B) Lista con uno o más nodos
  cout << "La direccion de la memoria empieza en: ->" << apLista->apNext
       << endl;
  cout << "Este nodo esta en la direccion de memoria: ->" << apCopia << endl;
  bool encontrado = false;
  do {
    if (strcmp(apCopia->NombreMedico, medicoBuscar) == 0) {
      encontrado = true;
      cout << "Paciente(s) atendido(s) por el medico encontrado." << endl;

      cout << "\n";
      cout << "===DATOS DEL PACIENTE===" << endl;
      cout << "Nombre del paciente: " << apCopia->NombrePaciente << endl;
      cout << "Nombre del medico: " << apCopia->NombreMedico << endl;
      cout << "Especialidad: " << apCopia->Especialidad << endl;
      cout << "Fecha: " << apCopia->Fecha << endl;
      cout << "Hora: " << apCopia->Hora << endl;
      cout << "Diagnostico: " << apCopia->Diagnostico << endl;
      cout << "Tratamiento: " << apCopia->Tratamiento << endl;
      cout << "Medicamentos: " << apCopia->Medicamentos << endl;
      cout << "Observaciones: " << apCopia->Observaciones << endl;
      cout << "Resultados: " << apCopia->Resultados << endl;
      cout << "Conclusiones: " << apCopia->Conclusiones << endl;
      cout << "Recomendaciones: " << apCopia->Recomendaciones << endl;
      cout << "Costo: " << apCopia->costo << endl;
      cout << "Direccion de memoria del nodo: ->" << apCopia->apNext << endl;

      // Mover el apuntador al siguiente nodo
      apCopia = apCopia->apNext; // Avanzar al siguiente nodo
    } // fin IF
    else {
      apCopia = apCopia->apNext; // Avanzar al siguiente nodo
    } // fin else
  } while (apCopia != NULL);
  if (!encontrado)
    cout << "No se encontraron pacientes atendidos por el medico "
         << medicoBuscar << "." << endl;
  system("pause");
  system("cls");
} // fin buscar_medico

void modificarPaciente() {
  // 1)     Declarar un apuntador auxiliar
  AnalisiClinico *apCopia = apLista; // Apuntador que recorre la lista
  // Caso A) Lista vacia
  if (apLista == NULL) {
    cout << "==La lista esta vacia==" << endl;
    return;
  } // if
  // Consultar nombre del paciente a modificar
  char nombreModificar[50];
  cout << "Ingresa el nombre del paciente a modificar" << endl;
  cout << "Tome en cuenta que tiene que ser el mismo nombre exactamente para "
          "localizarlo."
       << endl;
  cout << "De no ser asi, no se podra localizar." << endl;
  cout << "\n Nombre:";
  cin.ignore(); // Limpiar buffer
  cin.getline(nombreModificar, 50, '\n');
  // Caso B) Lista con uno o más nodos
  bool encontrado = false;
  do {
    if (strcmp(apCopia->NombrePaciente, nombreModificar) == 0) {
      encontrado = true;
      cout << "Paciente encontrado." << endl;
      cout << "-   -Ingrese los nuevos datos del paciente:-   -" << endl;
      capturarDatos(apCopia); // Reutilizar la función para capturar datos
      cout << "Datos del paciente modificados correctamente." << endl;
      system("pause");
      return; // Salir después de modificar
    } // fin IF
    else {
      apCopia = apCopia->apNext; // Avanzar al siguiente nodo
    } // fin else
  } while (apCopia != NULL);
  if (!encontrado)
    cout << "Paciente con nombre " << nombreModificar << " No fue localizado."
         << endl;
  system("pause");
}

// Guardar los datos en la lista en un archivo de texto (respaldo)
void guardar_archivo(void) {
  AnalisiClinico *aux = apLista;
  // 2) Crear un DESCRIPTOR de archivo
  ofstream apArchivo;

  cout << "Guardando historial en historial_pacientes.txt" << endl;

  // 3) Crear y Abrir archivo
  apArchivo.open("historial_pacientes.txt", ios_base::out);

  // 4) Validar el descriptor del archivo
  if (!apArchivo) {
    cout << "Problema al abrir archivo --> historial_pacientes.txt" << endl;
    return;
  }

  // 5) Guardar los datos en el archivo
  while (aux != NULL) {
    apArchivo << "Nombre del paciente: " << aux->NombrePaciente << '\n';
    apArchivo << "Nombre del medico: " << aux->NombreMedico << '\n';
    apArchivo << "Especialidad: " << aux->Especialidad << '\n';
    apArchivo << "Fecha: " << aux->Fecha << '\n';
    apArchivo << "Hora: " << aux->Hora << '\n';
    apArchivo << "Diagnostico: " << aux->Diagnostico << '\n';
    apArchivo << "Tratamiento: " << aux->Tratamiento << '\n';
    apArchivo << "Medicamentos: " << aux->Medicamentos << '\n';
    apArchivo << "Observaciones: " << aux->Observaciones << '\n';
    apArchivo << "Resultados: " << aux->Resultados << '\n';
    apArchivo << "Conclusiones: " << aux->Conclusiones << '\n';
    apArchivo << "Recomendaciones: " << aux->Recomendaciones << '\n';
    apArchivo << "Costo: " << fixed << setprecision(2) << aux->costo << '\n';
    apArchivo << "============================================" << '\n';
    aux = aux->apNext;
  }

  // 6) Cerrar el archivo
  apArchivo.close();

  cout << "Datos guardados en historial_pacientes.txt correctamente." << endl;
  system("pause");
} // fin guardar_archivo

// Recuperar los datos del archivo de texto (respaldo) y mostrarlos en la
// pantalla
void recuperar_archivo(void) {
  // 2) Crear un DESCRIPTOR de archivo de lectura
  ifstream apArchivo;
  string linea;

  cout << "Leyendo historial desde historial_pacientes.txt" << endl;

  // 3) Abrir archivo
  apArchivo.open("historial_pacientes.txt", ios_base::in);

  // 4) Validar descriptor
  if (!apArchivo) {
    cout << "Problema al abrir archivo --> historial_pacientes.txt" << endl;
    return;
  }

  // 5) Leer y mostrar contenido
  cout << "===Historial de Pacientes desde archivo===" << endl;
  while (std::getline(apArchivo, linea)) {
    cout << linea << endl;
  }

  // 6) Cerrar archivo
  apArchivo.close();
  system("pause");
} // fin recuperar_archivo

// Eliminar un paciente por nombre
void eliminar_paciente(void) {
  // 1)     Declarar un apuntador auxiliar
  AnalisiClinico *apBorrar = apLista; // Apuntador que recorre la lista
  AnalisiClinico *apAnterior = NULL;  // Apuntador al nodo anterior

  // variable de opcción para eliminar al paciente
  int opc;

  // Caso A) Lista vacia
  if (apLista == NULL) {
    cout << "==La lista esta vacia==" << endl;
    return;
  } // if

  // Consultar nombre del paciente a eliminar
  char nombreEliminar[50];
  cout << "Ingresa el nombre del paciente a eliminar" << endl;
  cin.ignore(); // Limpiar buffer
  cin.getline(nombreEliminar, 50, '\n');
  // cin.ignore(); // Eliminado

  // Caso B) Lista con uno o más nodos
  bool encontrado = false;
  while (apBorrar != NULL) {
    if (strcmp(apBorrar->NombrePaciente, nombreEliminar) == 0) {
      encontrado = true;
      cout << "Paciente encontrado." << endl;
      cout << "Estas seguro que quieres eliminarlo?" << endl;
      cout << "Si: 1" << endl;
      cout << "No: 0" << endl;
      cin >> opc;
      if (opc == 0) {
        system("pause");
        return;
      }
      // Si es el primer nodo
      if (apAnterior == NULL) {
        apLista =
            apBorrar->apNext; // Mover el inicio de la lista al siguiente nodo
      } else {
        apAnterior->apNext = apBorrar->apNext; // Saltar el nodo a eliminar
      }
      if (opc == 1) {
        free(apBorrar); // Liberar memoria
        cout << "Paciente eliminado correctamente." << endl;
      }
      system("pause");
      return;
    } // fin IF
    apAnterior = apBorrar;       // Mover el anterior al actual
    apBorrar = apBorrar->apNext; // Avanzar al siguiente nodo
  } // fin while
  if (!encontrado)
    cout << "Paciente con nombre " << nombreEliminar << " No fue localizado."
         << endl;
  system("pause");
} // fin eliminar_paciente

// Ordenar pacientes por costo (de menor a mayor)
// Función comparadora para ordenar por costo (de menor a mayor)
bool compararCosto(const AnalisiClinico *a, const AnalisiClinico *b) {
  return a->costo < b->costo;
}

// Ordenar pacientes por costo (de menor a mayor)
// Utilizando std::sort de la librería <algorithm> y std::vector
void ordenar_por_costo(void) {
  // Caso: Lista vacía o con un solo elemento
  if (apLista == NULL || apLista->apNext == NULL) {
    cout << "No hay suficientes pacientes para ordenar." << endl;
    system("pause");
    return;
  }

  // 1. Construir un vector de punteros a los nodos para evitar copiar apNext
  std::vector<AnalisiClinico *> nodos;
  AnalisiClinico *aux = apLista;
  while (aux != NULL) {
    nodos.push_back(aux);
    aux = aux->apNext;
  }

  // 2. Ordenar el vector de punteros por costo
  std::sort(nodos.begin(), nodos.end(), compararCosto);

  // 3. Reenlazar la lista según el orden en el vector
  apLista = nodos[0];
  for (size_t i = 0; i + 1 < nodos.size(); ++i) {
    nodos[i]->apNext = nodos[i + 1];
  }
  nodos.back()->apNext = NULL; // último nodo apunta a NULL

  cout << "La lista ha sido ordenada por costo (de menor a mayor)." << endl;
  system("pause");
} // fin ordenar_por_costo

// Fin del programa
