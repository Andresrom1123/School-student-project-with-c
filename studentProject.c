#include <stdio.h>
#include <stdbool.h>

#define STUDENTS_NUMBER 20
#define LENGTH_MAX_NAME 50

typedef struct {
  int code;
  char name[LENGTH_MAX_NAME];
} Student;  

Student students[STUDENTS_NUMBER] = {
  {1, "Juan Vergara"},
  {2, "Maria Lopez"},
  {3, "Carlos Perez"},
  {4, "Ana Gomez"},
  {5, "Luis Torres"},
  {6, "Elena Martinez"},
  {7, "Pedro Ramirez"},
  {8, "Laura Fernandez"},
  {9, "Sofia Castro"},
  {10, "Miguel Herrera"},
  {11, "Camila Rojas"},
  {12, "Diego Morales"},
  {13, "Valentina Ruiz"},
  {14, "Andres Navarro"},
  {15, "Isabela Mendoza"},
  {16, "Julian Salazar"},
  {17, "Daniela Paredes"},
  {18, "Mateo Vargas"},
  {19, "Fernanda Leon"},
  {20, "Tomas Aguirre"}
};

bool isIntegervalue(int *integer) {
  char buffer[100];

  if (fgets(buffer, sizeof(buffer), stdin)) {
    return sscanf(buffer, "%d", integer) == 1;
  }

  return false;
}

void showOptionsMenu() {
  printf("0. Para salir del sistema\n");
  printf("1. Cargar los estudiantes\n");
  printf("2. Borrar un estudiante\n");
  printf("3. Agregar un estudiante\n");
  printf("4. Mostrar un estudiante\n");
  printf("5. Modificar un estudiante\n");
}

void showStudents() {
  for (int i = 0; i < STUDENTS_NUMBER; i++) {
    printf("Codigo: %d, Nombre: %s\n", students[i].code, students[i].name);
  }
}

int findStudentIndexByCode(int code) {
  int indexStudent = -1;
  int studentsSize = sizeof(students) / sizeof(students[0]);

  for (int i = 0; i < studentsSize - 1; i++) {
    if (students[i].code == code) {
      indexStudent = i;

      break;
    }
  }

  return indexStudent;
}

void deleteStudentByCode(int code) {
  int indexStudent = findStudentIndexByCode(code);

  if (indexStudent == -1) {
    printf("Codigo no encontrado, por favor ingresa un codigo valido.\n");
  } else {
    int studentsSize = sizeof(students) / sizeof(students[0]);

    for (int i = indexStudent; i < studentsSize - 1; i++) {
      students[i] = students[i + 1];
    }

    printf("Estudiante borrado...\n");
  }
}

int main() {
  int option;
  bool isStudentsSystemOpen = true;

  printf(
    "\n--- Bienvenido al sistema de estudiantes, se te presentan las siguientes opciones: ---\n"
  );
  showOptionsMenu();

  while(isStudentsSystemOpen) {
    printf("Pulsa (6) para ver el menu de opciones.\n");
    printf("Ingresa la opcion que deseas realizar: ");

    if (!isIntegervalue(&option)) {
      printf("Entrada invalida. Debes ingresar un numero entero.\n");

      continue;
    }

    switch (option) {
      case 0: isStudentsSystemOpen = false; break;
      case 1: showStudents(); break;
      case 2:
        int code;

        showStudents();
        printf("Escribe el codigo del estudiante que deseas borrar: ");

        if (isIntegervalue(&code)) {
          deleteStudentByCode(code);
        } else {
          printf("Entrada invalida. Debes ingresar numeros entero.\n");
        }

        break;
      case 3: printf("Opcion 3.\n"); break;
      case 4: 
        showStudents();
        printf("Escribe el codigo del estudiante que deseas buscar: ");

        if (isIntegervalue(&code)) {
          int index = findStudentIndexByCode(code);

          if (index == -1) {
            printf("El codigo del estudiante que ingresaste no existe.\n");
          } else {
            printf("Codigo: %d, Nombre: %s\n", students[index].code, students[index].name);
          }
        } else {
          printf("Entrada invalida. Debes ingresar numeros entero.\n");
        }
        break;
      case 5: printf("Opcion 5.\n"); break;
      case 6: showOptionsMenu(); break;
  
      default: printf("Opcion no encontrada.\n");
    }
  }

  return 0;
}
