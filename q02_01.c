// 12S23026 - Arif M. Doloksaribu
// 12S23051 - Theresia Silaban

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"


int main(int _argc, char **_argv)
{
    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    struct student_t *student = malloc(100 * sizeof(struct student_t));
    int i = 0;
    int in = 0;
    int hn = 0;
    char masukan[100], *argument, *token;
    int h = 0;

    while (1) {
        fgets(masukan, 100, stdin);
        masukan[strcspn(masukan, "\n")] = 0;
        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "dorm-print-all") == 0) {
            print_dorms(dorm, h);
            continue;
        }
        else if (strcmp(masukan, "student-print-all") == 0) {
            print_stu(student, i);
            continue;
        }
        argument = strtok(masukan, "#");
        if (strcmp(argument, "dorm-add") == 0) {
            token = strtok(NULL, "#");
            strcpy(dorm[h].name, token);
            token = strtok(NULL, "#");
            dorm[h].capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                dorm[h].gender = GENDER_MALE;
            } else {
                dorm[h].gender = GENDER_FEMALE;
            }
            
            dorm[h] = create_dorm(dorm[h].name, dorm[h].capacity, dorm[h].gender);

            h++;
        }
         else if (strcmp(argument, "student-add") == 0){
            token = strtok(NULL, "#");
            strcpy(student[i].id, token);
            token = strtok(NULL, "#");
            strcpy(student[i].name, token);
            token = strtok(NULL, "#");
            strcpy(student[i].year, token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                 student[i].gender = GENDER_MALE;
            } else {
                student[i].gender = GENDER_FEMALE;
            }
             student[i] = create_student(student[i].id, student[i].name, student[i].year, student[i].gender);

            i++;
    }
    else if(strcmp(argument, "assign-student")==0){
        token = strtok(NULL,"#");
        strcpy(student[in].id, token);

        token = strtok(NULL,"#");
        strcpy(dorm[hn].name, token);
        if(student[in].id == student[i].id){
                i = in;
                in++;
        }
           if(dorm[hn].name == dorm[h].name){
            h = hn;
            hn++;
            }
        assign_student(student, dorm, in, hn);
    }

        else if(strcmp(argument,"student-print-all-detail")==0){
            void(*pf)(struct student_t *_student, int size);
            pf = student_print_all_detail;
            pf(student, i);
        }
        else if(strcmp(argument,"dorm-print-all-detail")==0){
            void(*pf)(struct dorm_t *_dorm, int size);
            pf = dorm_print_all_detail;
            pf(dorm, h);
        }
    }       
    return 0;
}
  
