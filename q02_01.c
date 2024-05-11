// 12S23026 - Arif M. Doloksaribu
// 12S23051 - Theresia Silaban

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[100];
    int year;
    char gender[10];
    char dorm[100];
} Student;

typedef struct {
    char name[100];
    int capacity;
    char gender[10];
    int occupied;
} Dorm;

void emptyDorm(Dorm dorm[], int n, char dormName[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dorm[i].name, dormName) == 0) {
            dorm[i].occupied = 0;
            break;
        }
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s|%s|%d|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender, students[i].dorm);
    }
}

void printDorms(Dorm dorm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s|%d|%s|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].gender, dorm[i].occupied);
    }
}

int main() {
    const int MAX_STUDENTS = 100;
    const int MAX_DORMS = 100;

    Student students[MAX_STUDENTS];
    Dorm dorms[MAX_DORMS];
    int studentCount = 0;
    int dormCount = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        char *command = strtok(input, "#");
        if (strcmp(command, "student-add") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *yearStr = strtok(NULL, "#");
            int year = atoi(yearStr);
            char *gender = strtok(NULL, "#");

            strcpy(students[studentCount].id, id);
            strcpy(students[studentCount].name, name);
            students[studentCount].year = year;
            strcpy(students[studentCount].gender, gender);
            strcpy(students[studentCount].dorm, "unassigned");
            studentCount++;
        } else if (strcmp(command, "dorm-add") == 0) {
            char *name = strtok(NULL, "#");
            char *capacityStr = strtok(NULL, "#");
            int capacity = atoi(capacityStr);
            char *gender = strtok(NULL, "#");

            strcpy(dorms[dormCount].name, name);
            dorms[dormCount].capacity = capacity;
            strcpy(dorms[dormCount].gender, gender);
            dorms[dormCount].occupied = 0;
            dormCount++;
        } else if (strcmp(command, "assign-student") == 0) {
            char *id = strtok(NULL, "#");
            char *dormName = strtok(NULL, "#");

            for (int i = 0; i < studentCount; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    strcpy(students[i].dorm, dormName);
                    break;
                }
            }

            for (int i = 0; i < dormCount; i++) {
                if (strcmp(dorms[i].name, dormName) == 0) {
                    dorms[i].occupied++;
                    break;
                }
            }
        } else if (strcmp(command, "dorm-empty") == 0) {
            char *dormName = strtok(NULL, "#");

            emptyDorm(dorms, dormCount, dormName);

            for (int i = 0; i < studentCount; i++) {
                if (strcmp(students[i].dorm, dormName) == 0) {
                    strcpy(students[i].dorm, "unassigned");
                }
            }
        } else if (strcmp(command, "student-print-all-detail\n") == 0) {
            printStudents(students, studentCount);
        } else if (strcmp(command, "dorm-print-all-detail\n") == 0) {
            printDorms(dorms, dormCount);
        }
    }

    return 0;
}
