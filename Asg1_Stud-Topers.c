#include <stdio.h>

#define MAX_STUDENTS 100
#define NUM_SUBJECTS 5

struct Student {
    int id;
    char name[50];
    int marks[NUM_SUBJECTS];
    float average;
};
void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name); 

        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
        calculateAverage(&s[i]);
    }
}

void calculateAverage(struct Student *s) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += s->marks[i];
    }
    s->average = total / (float)NUM_SUBJECTS;
}
void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;
    float highestAvg = s[0].average;

    for (int i = 1; i < n; i++) {
        if (s[i].average > highestAvg) {
            highestAvg = s[i].average;
            topperIndex = i;
        }
    }

    printf("\nTopper Student:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Marks: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d ", s[topperIndex].marks[j]);
    }
    printf("\nAverage: %.2f\n", s[topperIndex].average);
}

int main() {
    int n = 5;
    struct Student students[MAX_STUDENTS];
    inputStudents(students, n);
    displayTopper(students, n);
    return 0;
}
