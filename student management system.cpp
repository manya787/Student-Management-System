#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0; // to increment the index while storing data of students
int n = 0; // to count the total number of students in the class

struct sinfo // structure with variables to store info about the students
{
    char first_name[20];
    char last_name[20];
    int roll;
    int phy, math, sdf;
    float percentage;
} st[50]; // maximum number of students allowed in the class

void list_teacher() // function to print the name of teachers and the subjects taught by them
{
    FILE *fp;
    fp = fopen("teachers.txt", "r");
    while (!feof(fp))
    {
        char c = fgetc(fp);
        printf("%c", c);
    }
    printf("\n \n");
}

void add_student() // function to add the student in the class along with all their info
{
    printf("------------ ENTER THE DEATILS OF THE STUDENTS ------------\n");
    printf("             ---------------------------------             \n");
    printf("Enter the first name of the student\n");
    scanf("%s", st[i].first_name);
    printf("Enter the last name of the student\n");
    scanf("%s", st[i].last_name);
    printf("Enter the Roll Number\n");
    scanf("%d", &st[i].roll);
    printf("Enter the marks in Physics \n");
    scanf("%d", &st[i].phy);
    printf("Enter the marks in Maths \n");
    scanf("%d", &st[i].math);
    printf("Enter the marks in Sdf \n");
    scanf("%d", &st[i].sdf);
    i = i + 1; // incrementing the index
    n = n + 1; // changing the total number of the students in class
}

void find_rolll() // function to find a student using their roll number
{
    int x;
    printf("Enter the Roll Number of the student you want to find \n");
    scanf("%d", &x);
    printf("\n\n -------------------- \n\n");
    for (int j = 1; j <= n; j++)
    {
        if (x == st[j].roll)
        {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[j].first_name);
            printf("The Last name is %s\n", st[j].last_name);
            printf("The roll number is %d\n", st[j].roll);
            printf("The marks in Physics are %d\n", st[j].phy);
            printf("The marks in Mathematics are %d\n", st[j].math);
            printf("The marks in SDF are %d\n", st[j].sdf);
            break;
        }
    }
}

void find_firstName() // function to find a student using their first name
{
    char a[50];
    printf("Enter the First Name of the student\n");
    scanf("%s", a);
    printf("\n\n -------------------- \n\n");
    int c = 0;

    for (int j = 1; j <= i; j++)
    {
        if (!strcmp(st[j].first_name, a))
        {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[j].first_name);
            printf("The Last name is %s\n", st[j].last_name);
            printf("The Roll Number is %d\n ", st[j].roll);
            printf("The marks in Physics are %d\n", st[j].phy);
            printf("The marks in Mathematics are %d\n", st[j].math);
            printf("The marks in SDF are %d\n", st[j].sdf);
            c = 1;
        }
    }
    if (c != 1)
        printf("The First Name not Found\n");
}

void totalStudents() // function to print total number of students in the class and remaining seats in class
{
    printf("The total number of Student is %d\n", n);
    printf("Max no of students allowed is 50 \n");
    printf("You can have %d more students \n ", 50 - n);
}

void deleteStudents() // function to delete a student by their roll number
{
    int a;
    printf("Enter the Roll Number which you want to delete\n");
    printf("\n\n -------------------- \n\n");
    scanf("%d", &a);
    for (int j = 1; j <= n; j++)
    {
        if (a == st[j].roll)
        {
            for (int k = j; k < 49; k++)
                st[k] = st[k + 1];
            i--;
            n--;
        }
    }
    printf("The Roll Number is removed Successfully\n");
}

void updateStudents() // function to update the details of a student
{

    printf("Enter the roll number to update the entry : ");
    long int x;
    scanf("%ld", &x);
    for (int j = 1; j <= n; j++)
    {
        if (st[j].roll == x)
        {
            printf("1. First name\n"
                   "2. Last name\n"
                   "3. Roll no.\n"
                   "4. Physics\n"
                   "5. Chemistry\n"
                   "6. SDF\n");
            int z;
            scanf("%d", &z);
            printf("\n\n -------------------- \n\n");
            switch (z)
            {
            case 1:
                printf("Enter the new first name : \n");
                scanf("%s", st[j].first_name);
                break;
            case 2:
                printf("Enter the new last name : \n");
                scanf("%s", st[j].last_name);
                break;
            case 3:
                printf("Enter the new roll numnber : \n");
                scanf("%d", &st[j].roll);
                break;
            case 4:
                printf("Enter the new marks in Physics : \n");
                scanf("%d", &st[j].phy);
                break;
            case 5:
                printf("Enter the new marks in Mathematics \n");
                scanf(
                    "%d", &st[j].math);
                break;
            case 6:
                printf("Enter the new marks in SDF \n");
                scanf("%d", &st[j].sdf);
                break;
            }
            printf("UPDATED SUCCESSFULLY.\n");
        }
    }
}

void results()
{
    printf("Enter the roll number whose result you want to print \n ");
    int r;
    int a;
    scanf("%d", &r);
    printf("------------------------------------------------------------------------------------------\n");
    for (int k = 1; k < 20; k++)
    {
        if (k == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (r == st[j].roll)
                {
                    printf("                  The Students Details are                                             \n");
                    printf("                   The First name is %s                                                \n", st[j].first_name);
                    printf("                    The Last name is %s                                                 \n", st[j].last_name);
                    printf("                  The Roll Number is %d                                               \n", st[j].roll);
                    printf("                  The marks in Physics are %d                                          \n", st[j].phy);
                    printf("                   The marks in Mathematics are %d                                      \n", st[j].math);
                    printf("                   The marks in SDF are %d                                             \n", st[j].sdf);
                    printf("                    PERCENTAGE - %f                                                      \n", (st[j].phy + st[j].math + st[j].sdf) / 0.6);
                }
            }
        }
    }
    printf("------------------------------------------------------------------------------------------\n");
}

int main() // main execution
{
    printf("\n");
    printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *       Welcome      *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  * \n");
    printf("\t\t\t ******** THIS IS OUR STUDENT MANAGEMENT SYSTEM ******** \n");
    int choice, count;
    i = 1;
    while (1)
    {
        printf("\n\n\n ***************************** \n\n\n");
        printf("Choose what you want to do\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Roll Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Print the teachers \n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Students Details by Roll Number\n");
        printf("7. Update the Students Details by Roll Number\n");
        printf("8. Print the result ofa student\n");
        printf("9. To Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        printf("\n\n -------------------------- \n\n");
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            find_rolll();
            break;
        case 3:
            find_firstName();
            break;
        case 4:
            list_teacher();
            break;
        case 5:
            totalStudents();
            break;
        case 6:
            deleteStudents();
            break;
        case 7:
            updateStudents();
            break;
        case 8:
            results();
            break;
        case 9:
            printf(" ...... Thank you for using our program ......\n");
            printf("\n \n.............EXITING............\n");
            exit(0);
            break;
        }
    }
    return 0;
}