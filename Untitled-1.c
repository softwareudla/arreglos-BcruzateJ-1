#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 20
#define MAX_MATERIAS 6
#define TAM_NOMBRE 50
#define TAM_MATERIA 50

int main() {
    char estudiantes[MAX_ESTUDIANTES][TAM_NOMBRE];
    char materias[MAX_MATERIAS][TAM_MATERIA];
    int nEstudiantes, nMaterias;
    float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
    int opcion;

    printf("Ingrese el numero de estudiantes (max 20): ");
    scanf("%d", &nEstudiantes);
    while (nEstudiantes < 0 || nEstudiantes > MAX_ESTUDIANTES) {
        printf("Valor invalido. Ingrese entre 0 y 20: ");
        scanf("%d", &nEstudiantes);
    }

    getchar();

    for (int i = 0; i < nEstudiantes; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i], TAM_NOMBRE, stdin);
        estudiantes[i][strcspn(estudiantes[i], "\n")] = '\0';
    }

    printf("Ingrese el numero de materias (max 6): ");
    scanf("%d", &nMaterias);
    while (nMaterias < 0 || nMaterias > MAX_MATERIAS) {
        printf("Valor invalido. Ingrese entre 0 y 6: ");
        scanf("%d", &nMaterias);
    }
    getchar(); 

    for (int i = 0; i < nMaterias; i++) {
        printf("Nombre de la materia %d: ", i + 1);
        fgets(materias[i], TAM_MATERIA, stdin);
        materias[i][strcspn(materias[i], "\n")] = '\0';
    }

    for (int i = 0; i < nEstudiantes; i++) {
        printf("\nIngrese las notas para %s:\n", estudiantes[i]);
        for (int j = 0; j < nMaterias; j++) {
            float nota;
            do {
                printf("Nota en %s (0 a 10): ", materias[j]);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("Nota invalida. Debe estar entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            notas[i][j] = nota;
        }
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Mostrar notas\n");
        printf("2. Cambiar una nota\n");
        printf("3. Eliminar un estudiante\n");
        printf("4. Eliminar una nota especifica\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\n%-20s", "Estudiante");
            for (int j = 0; j < nMaterias; j++) {
                printf("%-15s", materias[j]);
            }
            printf("\n");
            for (int i = 0; i < 20 + 15 * nMaterias; i++) printf("-");
            printf("\n");
            for (int i = 0; i < nEstudiantes; i++) {
                printf("%-20s", estudiantes[i]);
                for (int j = 0; j < nMaterias; j++) {
                    printf("%-15.2f", notas[i][j]);
                }
                printf("\n");
            }
        } else if (opcion == 2) {
            int est, mat;
            float nuevaNota;
            printf("Ingrese el numero del estudiante (1 a %d): ", nEstudiantes);
            scanf("%d", &est);
            printf("Ingrese el numero de la materia (1 a %d): ", nMaterias);
            scanf("%d", &mat);
            if (est >= 1 && est <= nEstudiantes && mat >= 1 && mat <= nMaterias) {
                printf("Nota actual: %.2f\n", notas[est-1][mat-1]);
                printf("Ingrese la nueva nota (0 a 10): ");
                scanf("%f", &nuevaNota);
                if (nuevaNota >= 0 && nuevaNota <= 10) {
                    notas[est-1][mat-1] = nuevaNota;
                    printf("Nota actualizada correctamente.\n");
                } else {
                    printf("Nota invalida.\n");
                }
            } else {
                printf("Estudiante o materia invalida.\n");
            }
        } else if (opcion == 3) {
            int est;
            printf("Ingrese el numero del estudiante a eliminar (1 a %d): ", nEstudiantes);
            scanf("%d", &est);
            if (est >= 1 && est <= nEstudiantes) {
                strcpy(estudiantes[est - 1], "ELIMINADO");
                for (int j = 0; j < nMaterias; j++) {
                    notas[est - 1][j] = 0;
                }
                printf("Estudiante eliminado.\n");
            } else {
                printf("Numero invalido.\n");
            }
        } else if (opcion == 4) {
            int est, mat;
            printf("Ingrese el numero del estudiante (1 a %d): ", nEstudiantes);
            scanf("%d", &est);
            printf("Ingrese el numero de la materia (1 a %d): ", nMaterias);
            scanf("%d", &mat);
            if (est >= 1 && est <= nEstudiantes && mat >= 1 && mat <= nMaterias) {
                notas[est - 1][mat - 1] = 0;
                printf("Nota eliminada (puesta en 0).\n");
            } else {
                printf("Posicion invalida.\n");
            }
        } else if (opcion == 5) {
            printf("Saliendo del programa.\n");
        } else {
            printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}