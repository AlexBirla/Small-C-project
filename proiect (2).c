#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int indexStudent=0;

struct Student
{
    int id;
    char first_name[100];
    char last_name[100];
    int grade1;
    int grade2;
    int grade3;
};
void console_menu()
{
    printf("Welcome to the online catalogue. Please select one of the options\n");
    printf("  1. Add a student to the catalogue.\n");
    printf("  2. Show detalis of all students.\n");
    printf("  3. Search a student by his first name.\n");
    printf("  4. Compute the mean of a student's grades.\n");
    printf("  5. Compute the mean of all students.\n");
    printf("  6. Exit.\n");
}
int verify_empty_file(FILE* in_file)
{
    int size;
    in_file =fopen("db.txt","r");

    if( in_file== NULL)
        return 0;

    fseek(in_file,0, SEEK_END);
    size= ftell (in_file);
    return size;
    fclose(in_file);
}
void add_to_file( FILE* out_file, struct Student *input)
{

    out_file=fopen("db.txt","a");
    if (out_file == NULL)
    {
        fprintf(stderr,"We have an error opening the file\n");//stderr writes the console_menu message or error message
        exit(1);
    }
    else
        fprintf(out_file,"%d, %s, %s, %d, %d, %d;\n", input->id, input->first_name, input->last_name, input->grade1, input->grade2, input->grade3);

    if(fwrite != 0)
        printf("Student was added succesfully !\n");
    else
        printf("Error writing file !\n");
    fclose(out_file);

}
struct Student add_student(struct Student* STD)
{
    char choice,line[1024];
    FILE * fptr;
    fptr=fopen("db.txt","r");
    if(verify_empty_file(fptr)==2)
    {
        STD->id=1;
    }
    else
    {
        if(fptr)
        {
            while( fgets(line,1024,fptr)!=NULL)
            {
                //search for the last line
            }
            char nr[10];
            for (int i = 0; i < strlen(line) && line[i] != ','; i++)
                nr[i] = line[i];
            STD->id=atoi(nr)+1;

            fclose(fptr);
        }
    }

    printf("Please complete the following:\n ");
    printf("1. Enter the student's first name: ");
    scanf("%c",&choice);
    scanf("%[^\n]", STD->first_name); //will read all characters until you reach \n
    printf("\n");
    printf("2. Enter the student's last name: ");
    scanf("%c",&choice);
    scanf("%[^\n]", STD->last_name);
    printf("\n");
    printf("3. Grade 1: ");
    scanf("%c",&choice);
    scanf("%d", &STD->grade1);
    printf("\n");
    printf("4. Grade 2: ");
    scanf("%c",&choice);
    scanf("%d", &STD->grade2);
    printf("\n");
    printf("5. Grade 3: ");
    scanf("%c",&choice);
    scanf("%d", &STD->grade3);
    printf("\n");
    indexStudent++;
    return *STD;
    fclose(fptr);
}
void details_student( FILE* in_file)
{
    int k;
    char l[10000],*pt;

    in_file=fopen("db.txt", "r");

    if(verify_empty_file(in_file)==2)
    {
        printf("No student was added yet ");
        return;
    }

    while( fgets(l, sizeof l, in_file))
    {
        k=0;
        pt=strtok(l,",;");
        while(pt)
        {
            if(k==0)
                printf("ID:          %s\n", pt);
            else if(k == 1)
                printf("First Name: %s\n", pt);
            else if(k == 2)
                printf("Last name:  %s\n", pt);
            else if(k == 3)
                printf("ADS grade:                %s\n", pt);
            else if(k == 4)
                printf("Programming II grade:     %s\n", pt);
            else if(k == 5)
                printf("FLAT grade:               %s\n\n", pt);
            pt = strtok(NULL, ",;");
            k++;

        }
    }
    fclose(in_file);
}

void search_by_last_name(FILE* in_file)
{
    int ok=0, contor=0,k=0;
    char lname[40],*pt,c,l[10000];
    in_file=fopen("db.txt", "r");
    if(verify_empty_file(in_file)==2)
    {
        printf("The file is empty ");
        return;
    }
    scanf("%c",&c);// we clear the buffer so we will have the correct input
    printf("Enter the last name you are looking for: ");
    scanf("%[^\n]",&lname);
    while(fgets(l,sizeof l,in_file))
        if(strstr(l,lname))
        {
            ok=1;
            k++;
            int k=0,*pt;
            pt=strtok(l,",;");
            while(pt)
            {
                if(k==0)
                    printf("ID:          %s\n", pt);
                else if(k == 1)
                    printf("First Name: %s\n", pt);
                else if(k == 2)
                    printf("Last name:  %s\n", pt);
                else if(k == 3)
                    printf("ADS grade:               %s\n", pt);
                else if(k == 4)
                    printf("Programming II grade:    %s\n", pt);
                else if(k == 5)
                    printf("FLAT grade:              %s\n\n", pt);
                pt = strtok(NULL, ",;");
                k++;

            }
        }
        else
            strcpy(&l,"");

    if(ok==0)
    {
        printf("We couldn't find the student you are looking for!\n ");
    }
    fclose(in_file);
}
void edit(FILE* in_file)
{
    int ok=0, contor=0,k=0;
    char lname[40],*pt,c,l[10000];
    in_file=fopen("db.txt", "r");
    if(verify_empty_file(in_file)==2)
    {
        printf("The file is empty ");
        return;
    }
    scanf("%c",&c);// we clear the buffer so we will have the correct input
    printf("Enter the last name you are looking for: ");
    scanf("%[^\n]",&lname);
    while(fgets(l,sizeof l,in_file))
        if(strstr(l,lname))
        {
            ok=1;
            k++;
            int k=0,*pt;
            pt=strtok(l,",;");
            while(pt)
            {
                if(k==0)
                    printf("ID:          %s\n", pt);
                else if(k == 1)
                    printf("First Name: %s\n", pt);
                else if(k == 2)
                    printf("Last name:  %s\n", pt);
                else if(k == 3)
                    printf("Grade 1:    %s\n", pt);
                else if(k == 4)
                    printf("Grade 2:    %s\n", pt);
                else if(k == 5)
                    printf("Grade 3:    %s\n\n", pt);
                pt = strtok(NULL, ",;");
                k++;

            }
        }
        else
            strcpy(&l,"");

    if(ok==0)
    {
        printf("We couldn't find the student you are looking for!\n ");
    }
    fclose(in_file);
}
void calculate_mean(FILE* in_file)
{
    int ok=0, contor=0,k=0;
    char *pt,c,l[10000],ID[3];
    in_file=fopen("db.txt", "r");
    if(verify_empty_file(in_file)==2)
    {
        printf("The file is empty ");
        return;
    }
    scanf("%c",&c);
    printf("Enter the student ID you want to compute the mean for: ");
    scanf("%s",&ID);
    int mean=0;
    while(fgets(l,sizeof l,in_file))
    {


        ok=1;
        int k=0,*pt;
        pt=strtok(l,",;");
        if(strcmp(l,ID)==0)
        {
            while(pt)
            {
                if(k==0)
                    printf("ID:          %s\n", pt);
                else if(k == 1)
                    printf("First Name: %s\n", pt);
                else if(k == 2)
                    printf("Last name:  %s\n", pt);
                else if(k == 3)
                    mean+=atoi(pt);
                else if(k == 4)
                    mean+=atoi(pt);
                else if(k == 5)
                    mean+=atoi(pt);
                pt = strtok(NULL, ",;");
                k++;

            }
            float mean2;
            mean2=(float)mean/3;
            printf("Mean:  %.2f\n", mean2);
            if(mean2>5)
                printf("Passed\n");
            else
                printf("Failed\n");
        }
        else
            strcpy(&l,"");
    }
    if(ok==0)
    {
        printf("We couldn't find the student you are looking for!\n ");
    }
    fclose(in_file);
}
void calculate_mean2(FILE* in_file)
{
    int ok=0, contor=0,k=0;
    char *pt,c,l[10000],ID[3];
    in_file=fopen("db.txt", "r");
    if(verify_empty_file(in_file)==2)
    {
        printf("The file is empty ");
        return;
    }
    scanf("%c",&c);
    int mean=0,aux;
    while(fgets(l,sizeof l,in_file))
    {
        ok=1;
        int k=0,*pt=malloc(sizeof(char)*100);
        pt=strtok(l,",;");
        while(pt)
        {
            if(k==0)
                aux=atoi(pt);
            else if(k == 3)
                mean+=atoi(pt);
            else if(k == 4)
                mean+=atoi(pt);
            else if(k == 5)
                mean+=atoi(pt);
            pt = strtok(NULL, ",;");
            k++;

        }

    }
    float mean2;
    mean2=(float)mean/(aux*3);
    printf("The mean of all the students is %.2f", mean2);
    fclose(in_file);
}

int main()
{
    int ch;
    struct Student input;
    FILE* out_file;
    console_menu();

    printf("Please select one of the options: ");
    scanf("%d", &ch);
    while (ch!=6)
    {
        if (ch==1)
        {
            add_student(&input);
            add_to_file(out_file, &input);
            printf("\n");
            console_menu();
            printf("\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
        else if (ch==2)
        {
            details_student(out_file);
            printf("\n");
            console_menu();
            printf("\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
        else if (ch==3)
        {
            search_by_last_name(out_file);
            printf("\n");
            console_menu();
            printf("\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
        else if (ch==4)
        {
            calculate_mean(out_file);
            printf("\n");
            console_menu();
            printf("\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
        else if (ch==5)
        {
            calculate_mean2(out_file);
            printf("\n");
            console_menu();
            printf("\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
        else
        {
            printf("Invalid choice!\nPlease select one of the options: ");
            scanf("%d", &ch);
        }
    }

    return 0;
}




