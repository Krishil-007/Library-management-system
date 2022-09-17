
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int rent = 10;

struct issueNode
{
    char rollNo[10];
    char studentName[20];
    char department[15];
    char issueDate[10];
    int days;
    char title[20];
    struct issueNode *pre, *next;
} *issueHead = NULL, *issueEnd = NULL;
struct node
{
    char title[20];
    char author[20];
    int price;
    int quantity;
    struct node *pre, *next;
} * head[6] = {NULL, NULL, NULL, NULL, NULL, NULL}, *temp[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

void defaultadd()
{
    head[1] = (struct node *)malloc(sizeof(struct node));
    temp[1] = (struct node *)malloc(sizeof(struct node));
    //Computer Department
    strcpy(head[1]->title, "JAVA");
    strcpy(head[1]->author, "Balaguruswamy");
    head[1]->price = 600;
    head[1]->quantity = 2;

    strcpy(temp[1]->title, "Complete JAVA");
    strcpy(temp[1]->author, "Herbert Schildt");
    temp[1]->price = 800;
    temp[1]->quantity = 2;
    head[1]->next = temp[1];
    head[1]->pre = NULL;
    temp[1]->pre = head[1];
    temp[1]->next = NULL;

    head[2] = (struct node *)malloc(sizeof(struct node));
    temp[2] = (struct node *)malloc(sizeof(struct node));
    //Chemical Department
    strcpy(head[2]->title, "Organic Chemistry");
    strcpy(head[2]->author, "Arun Bahl");
    head[2]->price = 900;
    head[2]->quantity = 2;

    strcpy(temp[2]->title, "Physical Chemistry");
    strcpy(temp[2]->author, "S. Chand");
    temp[2]->price = 800;
    temp[2]->quantity = 1;
    head[2]->next = temp[2];
    head[2]->pre = NULL;
    temp[2]->pre = head[2];
    temp[2]->next = NULL;

    head[3] = (struct node *)malloc(sizeof(struct node));
    temp[3] = (struct node *)malloc(sizeof(struct node));
    //Mechanical Department
    strcpy(head[3]->title, "Fluid Mechanics");
    strcpy(head[3]->author, "Shiv Kumar");
    head[3]->price = 700;
    head[3]->quantity = 1;

    strcpy(temp[3]->title, "Material Science");
    strcpy(temp[3]->author, "WD Callister");
    temp[3]->price = 800;
    temp[3]->quantity = 2;
    head[3]->next = temp[3];
    head[3]->pre = NULL;
    temp[3]->pre = head[3];
    temp[3]->next = NULL;

    head[4] = (struct node *)malloc(sizeof(struct node));
    temp[4] = (struct node *)malloc(sizeof(struct node));
    //Civil Department
    strcpy(head[4]->title, "Surveying");
    strcpy(head[4]->author, "S K Duggal");
    head[4]->price = 500;
    head[4]->quantity = 2;
    head[4]->pre = NULL;
    head[4]->next = NULL;
    temp[4] = head[4];

    head[5] = (struct node *)malloc(sizeof(struct node));
    temp[5] = (struct node *)malloc(sizeof(struct node));
    //Electrical Department
    strcpy(head[5]->title, "Basic Electrical");
    strcpy(head[5]->author, "V K Mehta");
    head[5]->price = 600;
    head[5]->quantity = 1;
    head[5]->pre = NULL;
    head[5]->next = NULL;
    temp[5] = head[5];

    head[6] = (struct node *)malloc(sizeof(struct node));
    temp[6] = (struct node *)malloc(sizeof(struct node));
    //Electronics Department
    strcpy(head[6]->title, "Basic Electronics");
    strcpy(head[6]->author, "D P Kothari");
    head[6]->price = 400;
    head[6]->quantity = 2;
    head[6]->pre = NULL;
    head[6]->next = NULL;
    temp[6] = head[6];
}

void changeRent(int newRent)
{
    rent = newRent;
    printf("Rent changed successfully\n");
}

void addRecord(struct node *x, int k)
{
    char info[100];
    int d;
    struct issueNode *new = (struct issueNode *)malloc(sizeof(struct issueNode));
    printf("\n  Enter the Roll Number of the student : ");
    fflush(stdin);
    gets(info);
    while (info[0] == '\0')
    {
        printf("\n  Please enter roll number, it is mandatory.");
        printf("\n  Enter roll number of the book: ");
        fflush(stdin);
        gets(info);
    }
    strcpy(new->rollNo, info);
    printf("\n  Enter the Name of the student : ");
    fflush(stdin);
    gets(info);
    while (info[0] == '\0')
    {
        printf("\n  Please enter Name of the student, it is mandatory.");
        printf("\n  Enter Name of the Student: ");
        fflush(stdin);
        gets(info);
    }
    strcpy(new->studentName, info);
    printf("\n  Enter the Issue Date (DD\\MM\\YYYY) for book : ");
    fflush(stdin);
    gets(info);
    while (info[0] == '\0')
    {
        printf("\n  Please enter a valid date, it is mandatory : ");
        fflush(stdin);
        gets(info);
    }
    strcpy(new->issueDate, info);
    strcpy(new->title, x->title);
    printf("\n  Enter the number of days : ");
    scanf("%d", &d);
    while (d < 0)
    {
        printf("\n  Please enter valid number of days : ");
        scanf("%d", d);
    }
    new->days = d;
    switch (k)
    {
    case 1:
        strcpy(new->department, "Computer");
        break;
    case 2:
        strcpy(new->department, "Chemical");
        break;
    case 3:
        strcpy(new->department, "Mechanical");
        break;
    case 4:
        strcpy(new->department, "Civil");
        break;
    case 5:
        strcpy(new->department, "Electrical");
        break;
    case 6:
        strcpy(new->department, "Electronics");
        break;
    default:
        break;
    }

    if (issueHead == NULL)
    {
        new->pre = NULL;
        new->next = NULL;
        issueHead = issueEnd = new;
    }
    else
    {
        new->next = NULL;
        new->pre = issueEnd;
        issueEnd->next = new;
        issueEnd = new;
    }
    printf("\nThank you for issuing the book\n\nThe Book is issued by ");
    puts(new->studentName);
    printf("\nYou need to pay %d Rupees", ((new->days) * rent));
}
void deleteRecord(char book[], char rn[])
{
    struct issueNode *t, *t1, *t2;
    t = issueHead;
    if (issueHead == issueEnd && strcmp(rn, t->rollNo) == 0 && strcmp(book, t->title) == 0)
    {
        issueHead = issueEnd = NULL;
        return;
    }
    else if (strcmp(rn, issueHead->rollNo) == 0 && strcmp(book, issueHead->title) == 0)
    {
        issueHead = issueHead->next;
        issueHead->pre = NULL;
        return;
    }
    else if (strcmp(rn, issueEnd->rollNo) == 0 && strcmp(book, issueEnd->title) == 0)
    {
        issueEnd = issueEnd->pre;
        issueEnd->next = NULL;
        return;
    }
    else
    {
        t = issueHead->next;
        while (t != NULL)
        {
            if (strcmp(rn, t->rollNo) == 0 && strcmp(book, t->title) == 0)
            {
                t1 = t->pre;
                t2 = t->next;
                t1->next = t2;
                t2->pre = t1;
                break;
            }
            else
            {
                t = t->next;
            }
        }
    }
    return;
}

struct node *searchbook(int i, char arr[])
{
    struct node *t = head[i];
    if (t == NULL)
    {
        return NULL;
    }
    int flag = 0;
    while (t != NULL)
    {
        if (strcmp(t->title, arr) == 0)
        {
            flag = 1;
            break;
        }
        else
        {
            t = t->next;
        }
    }
    if (flag == 1)
    {
        return t;
    }
    else
    {
        return NULL;
    }
}
void addbook(int i)
{
    struct node *p;
    struct node *t;
    char info[20], aut[20], k = ' ';
    int q, pri, data;
    printf("\n  Enter title of the book : ");
    fflush(stdin);
    gets(info);
    while (info[0] == '\0')
    {
        printf("\n  Please enter title, it is mandatory : ");
        fflush(stdin);
        gets(info);
    }
    p = searchbook(i, info);
    if (p != NULL)
    {
        printf("\n  Book already exists in the library.");
        printf("\n  Enter new price of this book : ");
        scanf("%d", &pri);
        printf("\n  Enter new quantity of this book : ");
        scanf("%d", &q);
        p->price = pri;
        p->quantity = q;
    }
    else
    {
        printf("\n  Enter author of this book : ");
        fflush(stdin);
        gets(aut);
        while (aut[0] == '\0')
        {
            printf("\n  Please enter author of this book, it is mandatory : ");
            fflush(stdin);
            gets(aut);
        }
        printf("\n  Enter price of this book : ");
        scanf("%d", &pri);
        printf("\n  Enter quantity of this book : ");
        scanf("%d", &data);
        while (data == 0)
        {
            printf("\n  Please enter quantity of this book, it is mandatory.");
            printf("\n  Enter quantity of the book: ");
            scanf("%d", &data);
        }
        struct node *fnode;
        if (head[i] == NULL)
        {
            head[i] = (struct node *)malloc(sizeof(struct node));
            strcpy(head[i]->title, info);
            strcpy(head[i]->author, aut);
            head[i]->price = pri;
            head[i]->quantity = data;
            head[i]->next = NULL;
            head[i]->pre = NULL;
            temp[i] = head[i];
        }
        else
        {
            fnode = (struct node *)malloc(sizeof(struct node));
            strcpy(fnode->title, info);
            strcpy(fnode->author, aut);
            fnode->price = pri;
            fnode->quantity = data;
            fnode->next = NULL;
            fnode->pre = temp[i];
            temp[i]->next = fnode;
            temp[i] = fnode;
        }
        printf("\n  Book is inserted successfully!!\n");
    }
    return;
}
char *Date(char a[])
{
    static char b[12];
    for (int i = 0; i < 12; i++)
    {
        if (i == 11)
        {
            b[i] = '|';
        }
        else
        {
            b[i] = 32;
        }
    }
    for (int i = 1, j = 0; a[j] != '\0'; i++, j++)
    {

        b[i] = a[j];
    }

    return b;
}
char *setRollNo(char a[])
{

    static char b[12];
    for (int i = 0; i < 12; i++)
    {
        if (i == 0)
        {
            b[i] = '|';
        }
        if (i == 11)
        {
            b[i] = '|';
        }
        else
        {
            b[i] = 32;
        }
    }
    for (int i = 1, j = 0; a[j] != '\0'; i++, j++)
    {

        b[i] = a[j];
    }

    return b;
}
char *setName(char a[])
{
    static char b[20];
    for (int i = 0; i < 20; i++)
    {
        if (i == 19)
        {
            b[i] = '|';
        }
        else
        {
            b[i] = 32;
        }
    }
    for (int i = 1, j = 0; a[j] != '\0'; i++, j++)
    {
        b[i] = a[j];
    }
    return b;
}
char *setDepartment(char a[])
{
    static char b[15];
    for (int i = 0; i < 15; i++)
    {
        if (i == 14)
        {
            b[i] = '|';
        }
        else
        {
            b[i] = 32;
        }
    }
    for (int i = 1, j = 0; a[j] != '\0'; i++, j++)
    {
        b[i] = a[j];
    }
    return b;
}
void arrayPrinter(char *p, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%c", p[i]);
    }
}
void display(int i)
{
    struct node *t;
    t = head[i];
    if (t == NULL)
    {
        printf("-------------------------------------");
        printf("\n  No books have been added yet!!\n");
        printf("-------------------------------------\n");
        return;
    }
    printf("\n-----------------------------------------------------------------------\n");
    printf("|");
    char a[20] = "BOOK'S TITLE";
    char *p = setName(a);
    arrayPrinter(p, 19);
    strcpy(a, "AUTHOR");
    p = setName(a);
    arrayPrinter(p, 19);
    strcpy(a, "PRICE");
    p = setDepartment(a);
    arrayPrinter(p, 14);
    strcpy(a, "QUANTITY");
    p = setDepartment(a);
    arrayPrinter(p, 14);
    printf("\n-----------------------------------------------------------------------");
    while (t != NULL)
    {
        printf("\n");
        printf("|");
        p = setName(t->title);
        arrayPrinter(p, 19);
        p = setName(t->author);
        arrayPrinter(p, 19);
        char b[15];
        sprintf(b, "%ld", t->price);
        p = setDepartment(b);
        arrayPrinter(p, 14);
        sprintf(b, "%ld", t->quantity);
        p = setDepartment(b);
        arrayPrinter(p, 14);
        if (t->next == NULL)
        {
            printf("\n-----------------------------------------------------------------------");
        }
        t = t->next;
    }
}
void displayRecord()
{
    struct issueNode *m;
    m = issueHead;
    if (m == NULL)
    {
        printf("-----------------------------------");
        printf("\n  No books have been Issued yet!!\n");
        printf("-----------------------------------");
        return;
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("|");
    char r[20] = "ROLL NO";
    char *y = setRollNo(r);
    arrayPrinter(y, 11);
    strcpy(r, "STUDENT NAME");
    y = setName(r);
    arrayPrinter(y, 19);
    strcpy(r, "TITLE");
    y = setName(r);
    arrayPrinter(y, 19);
    strcpy(r, "Department");
    y = setDepartment(r);
    arrayPrinter(y, 14);
    strcpy(r, "DATE");
    y = Date(r);
    arrayPrinter(y, 11);
    printf("\n--------------------------------------------------------------------------------\n");
    while (m != NULL)
    {
        printf("|");
        strcpy(r, m->rollNo);
        y = setRollNo(r);
        arrayPrinter(y, 11);

        strcpy(r, m->studentName);
        y = setName(r);
        arrayPrinter(y, 19);

        strcpy(r, m->title);
        y = setName(r);
        arrayPrinter(y, 19);

        strcpy(r, m->department);
        y = setDepartment(r);
        arrayPrinter(y, 14);

        strcpy(r, m->issueDate);
        y = Date(r);
        arrayPrinter(y, 11);
        printf("\n");
        if (m->next == NULL)
        {
            printf("--------------------------------------------------------------------------------\n");
        }
        m = m->next;
    }
}
void deletebook(int i, char a[])
{
    struct node *t, *t1, *t2;
    int flag;
    t = head[i];
    if (t == NULL)
    {
        return;
    }
    if (t == head[i] && strcmp(a, t->title) == 0)
    {
        head[i] = head[i]->next;
        flag++;
    }
    else
    {
        t = head[i]->next;
        for (; t != NULL;)
        {
            if (strcmp(a, t->title) == 0)
            {
                if (t->next == NULL)
                {
                    t1 = t->pre;
                    t1->next = NULL;
                    flag++;
                    temp[i] = t1;
                }
                else
                {
                    t1 = t->pre;
                    t2 = t->next;
                    t1->next = t2;
                    t2->pre = t1;
                    flag++;
                }
                break;
            }
            else
            {
                t = t->next;
            }
        }
    }
    if (flag == 0)
    {
        printf("\n  Sorry, Book is currently not available\n");
    }
    else
    {
        printf("\n  Book is successfully deleted!!\n");
    }
}
void issuebook(int i, char a[])
{
    struct node *p;
    p = searchbook(i, a);
    if (p == NULL)
    {
        printf("\n  Book is not available ");
        return;
    }
    if (p->quantity == 0)
    {
        printf("\n  Sorry,Book is currently not available ");
        return;
    }
    else
    {
        addRecord(p, i);
        p->quantity = (p->quantity) - 1;
        return;
    }
}
void returnbook(int i, char a[])
{
    struct node *p;
    p = searchbook(i, a);
    p->quantity = (p->quantity) + 1;
    printf("\n  Book is returned by you is : %s and now %d books are available.\n", a, p->quantity);
    return;
}

void Departmentlist()
{
    printf("\n  Here's a list of all departments");
    printf("\n  1. Computer");
    printf("\n  2. Chemical");
    printf("\n  3. Mechanical");
    printf("\n  4. Civil");
    printf("\n  5. Electrical");
    printf("\n  6. Electronics");
}
void welcome()
{
    printf("\n***************************************************************************************************************");
    printf("\n*                                                                                                             *");
    printf("\n*                                       WELCOME TO LIBRARY MANAGEMENT                                         *");
    printf("\n*                                                                                                             *");
    printf("\n***************************************************************************************************************");
    printf("\n\n");
}
void showMenu()
{
    printf("\n***************************************************************************************************************");
    printf("\n**                                                 MAIN MENU                                                 **");
    printf("\n***************************************************************************************************************");
    printf("\n**\t\t\t  1.   Add book                                                                      **");
    printf("\n**\t\t\t  2.   Delete book details                                                           **");
    printf("\n**\t\t\t  3.   View books of any particular department                                       **");
    printf("\n**\t\t\t  4.   View all books                                                                **");
    printf("\n**\t\t\t  5.   Search book details.                                                          **");
    printf("\n**\t\t\t  6.   Issue a Book.                                                                 **");
    printf("\n**\t\t\t  7.   Return a Book.                                                                **");
    printf("\n**\t\t\t  8.   Display Issued Book Record.                                                   **");
    printf("\n**\t\t\t  9.   Change Rent                                                                   **");
    printf("\n**\t\t\t  10.  Exit                                                                          **");
    printf("\n***************************************************************************************************************");
    printf("\n\t\t\t---->> Enter your choice :");
}
int main()
{
    int c, d, k = 1, flag, newRent;
    char title[20], rn1[20];
    struct node *p;
    welcome();
    defaultadd();
    do
    {
        showMenu();
        fflush(stdin);
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            Departmentlist();
            printf("\n  Enter the department number : ");
            scanf("%d", &d);
            addbook(d);
            break;
        case 2:
            Departmentlist();
            printf("\n  Enter department number whose book details you want to delete : ");
            scanf("%d", &d);
            display(d);
            printf("\n  Enter the title of book you want to delete : ");
            fflush(stdin);
            gets(title);
            deletebook(d, title);
            break;
        case 3:
            Departmentlist();
            printf("\n  Enter the department number to view books of any particular department: ");
            scanf("%d", &d);
            display(d);
            break;
        case 4:
            printf("------------------------------------\n");
            printf("  Here's a list of all departments\n");
            printf("------------------------------------\n");
            printf("\n  --->Department of Computer\n");
            display(1);
            printf("\n  --->Department of Chemical\n");
            display(2);
            printf("\n  --->Department of Mechanical\n");
            display(3);
            printf("\n  --->Department of Civil\n");
            display(4);
            printf("\n  --->Department of Electrical\n");
            display(5);
            printf("\n  --->Department of Electronics\n");
            display(6);
            break;
        case 5:
            Departmentlist();
            printf("\n  Enter the department number to search books from any particular department: ");
            scanf("%d", &d);
            printf("\n  Enter the title of book you want to search : ");
            fflush(stdin);
            gets(title);
            p = searchbook(d, title);
            if (p == NULL)
            {
                printf("\n  Sorry, Book is currently not available.\n");
            }
            else
            {
                printf("\n  Book's title : %s   Author : %s   Price : %d   Quantity : %d\n", p->title, p->author, p->price, p->quantity);
            }
            break;
        case 6:
            Departmentlist();
            printf("\n  Enter the department number to issue books from any particular department: ");
            scanf("%d", &d);
            display(d);
            if (head[d] != NULL)
            {
                printf("\n  Enter the title of the book you want to issue : ");
                fflush(stdin);
                gets(title);
                issuebook(d, title);
            }
            break;
        case 7:
            Departmentlist();
            printf("\n  Enter the department number to return book from any particular department: ");
            scanf("%d", &d);
            printf("\n  Enter title of the book you want to return : ");
            fflush(stdin);
            gets(title);
            printf("\n  Enter your Roll Number : ");
            gets(rn1);
            p = searchbook(d, title);
            if (p == NULL)
            {
                printf("\n  This book is not owned by Library\n");
            }
            else
            {
                returnbook(d, title);
                deleteRecord(title, rn1);
            }
            break;
        case 8:
            displayRecord();
            break;

        case 9:
            printf("Enter the new value of rent\n");
            scanf("%d", &newRent);
            changeRent(newRent);
            break;
        case 10:
            return 0;
            break;
        default:
            printf("\n  Invalid choice.\n");
            break;
        }
    } while (k == 1);
}