# Sistema de Análisis Clínico — IMMS

Proyecto final de la materia **Estructuras de Datos**.  
Sistema de gestión de historiales clínicos implementado con **listas simplemente enlazadas (LSEA)** en C++.

---

## Información general

| Campo | Valor |
|-------|-------|
| **Materia** | Estructuras de Datos |
| **Autores** | José Julián Flores Ramírez, Valery Ximena Oceguera de la Torre |
| **Fecha de inicio** | 15 de noviembre de 2025 |
| **Fecha de finalización** | 25 de noviembre de 2025 |
| **Lenguaje** | C++ |
| **Estructura principal** | Lista simplemente enlazada (nodos dinámicos con `struct`) |

---

## Estructura del proyecto

| Archivo | Descripción |
|---------|-------------|
| `IMMS.cpp` | Código fuente principal del sistema (menú, operaciones CRUD, validaciones, persistencia) |
| `historial_pacientes.txt` | Archivo de respaldo donde se guardan los registros de pacientes |
| `README.md` | Este documento |
| `ED Proyecto Final 2025B.pdf` | Documento del proyecto final (instrucciones/rúbrica) |

---

## Funcionalidades

1. **Agregar paciente** al inicio o al final de la lista.
2. **Mostrar historial** completo de pacientes.
3. **Filtrar registros** por:
   - Rango de costos (mínimo — máximo).
   - Rango de fechas (`DD/MM/AAAA` — `DD/MM/AAAA`).
   - Especialidad médica.
4. **Buscar** pacientes por:
   - Nombre exacto del paciente.
   - Nombre exacto del médico.
5. **Modificar datos** de un paciente existente (búsqueda por nombre).
6. **Eliminar paciente** por nombre (con confirmación).
7. **Ordenar pacientes** por costo de menor a mayor (usa `std::sort` + `std::vector`).
8. **Guardar / Recuperar** historial en archivo de texto (`historial_pacientes.txt`).

---

## Validaciones implementadas

- **Fecha**: formato `DD/MM/AAAA`, año entre 1900-2100, mes 1-12, días según el mes (incluye bisiestos).
- **Hora**: formato 24 horas `HH:MM`, horas 0-23, minutos 0-59.
- **Costo**: valores mayores a 0.
- **Rangos**: el límite inferior debe ser menor o igual que el superior (costos y fechas).

---

## Estructura de datos

```cpp
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
    AnalisiClinico *apNext;   // enlace al siguiente nodo
};
```

La lista es **simple** (cada nodo apunta solo al siguiente), **abierta** (termina en `NULL`) y utiliza **memoria dinámica** (`new` / `free`).

---

## Librerías utilizadas

| Librería | Uso |
|----------|-----|
| `<iostream>` | Entrada/salida por consola |
| `<fstream>` | Lectura/escritura del archivo de respaldo |
| `<iomanip>` | Formato de decimales (`setprecision(2)`) |
| `<algorithm>` | Ordenamiento (`std::sort`) |
| `<vector>` | Contenedor auxiliar para reordenar nodos |
| `<conio.h>`, `<cstdlib>`, `<cstring>` | Utilidades del sistema y manejo de cadenas |

---

## Compilación y ejecución

> El programa está diseñado para compiladores compatibles con **Windows** (usa `system("CLS")`, `system("pause")` y `<conio.h>`).

```bash
g++ IMMS.cpp -o IMMS.exe
IMMS.exe
```

O con cualquier IDE que soporte C++ (Visual Studio Code, Dev-C++, Code::Blocks, etc.).

---

## Ejemplo de datos guardados

El archivo `historial_pacientes.txt` almacena registros con el siguiente formato:

```
Nombre del paciente: [nombre]
Nombre del medico: [medico]
Especialidad: [especialidad]
Fecha: DD/MM/AAAA
Hora: HH:MM
Diagnostico: [...]
...
Costo: 4500.00
============================================
```

---

## Notas

- Se debe ingresar el **nombre exacto** del paciente para buscar, modificar o eliminar.
- La persistencia es en **texto plano** (no binaria), por lo que el archivo puede leerse/editarse manualmente.
- El ordenamiento por costo se realiza sobre la lista en memoria y **no se guarda automáticamente** en disco; para conservar el orden ejecuta la opción de guardar después de ordenar.

---

*Proyecto académico — Estructuras de Datos, 4° Semestre.*
