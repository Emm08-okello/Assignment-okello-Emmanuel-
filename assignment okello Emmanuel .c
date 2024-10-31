name ; /*okello Emmanuel otieno 
registration number;PA107/G/22022/24
course ; computer systems engineering*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

void writeStudentsToFile(const char *filename, struct Student *students, int count) {
    FILE *file = fopen("/storage/emulated/0/android c kemboi/c file3.bin", "w+"); 
    
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(students, sizeof(struct Student), count, file); 
    fclose(file);
}

void readStudentsFromFile(const char *filename, struct Student *students, int count) {
    FILE *file = fopen("/storage/emulated/0/android c kemboi/c file3.bin","w+"); 
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    fread(students, sizeof(struct Student), count, file); 
    fclose(file);
}

int main() {
    int n;

    
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student)); 

    
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    const char *filename = "students.dat";
    
    
    writeStudentsToFile(filename, students, n);
    
    
    struct Student *readStudents = malloc(n * sizeof(struct Student));
    
    
    readStudentsFromFile(filename, readStudents, n);
    
    
    printf("\nStudents read from file:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", readStudents[i].name, readStudents[i].marks);
    }
// kemboi
    
    free(students);
    free(readStudents);

    return 0;
}
