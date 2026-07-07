#include <stdio.h>
#include <stdlib.h>
int flag1 = 0, flag2 = 0, n, i, elm, pos;
void creation(int*);
void display(int*);
void insertion(int*);
void deletion(int*);
void search(int*);

int main() {
    int ch, *a;

show:
    printf("\n");
    printf("1.Creation \n");
    printf("2.Display \n");
    printf("3.Insertion \n");
    printf("4.Deletion \n");
    printf("5.Search \n");
    printf("6.Exit \n");
    printf("Select ur choice \n");
    scanf("%d", &ch);

    if (flag1 == 0 && ch >= 2 && ch <= 5) {
        printf("List is empty\n");
    } else {
        switch (ch) {
            case 1:
                printf("Enter the range: ");
                scanf("%d", &n);
                a = (int*)malloc(n * sizeof(int));
                creation(a);
                flag1 = 1;
                break;
            case 2:
                display(a);
                break;
            case 3:
                insertion(a);
                break;
            case 4:
                deletion(a);
                break;
            case 5:
                search(a);
                break;
            case 6:
                printf("Exiting the program.\n");
                if (flag1 == 1) {
                    free(a); 
                }
                exit(0);
            default:
                printf("Invalid choice \n");
        }
    }
    goto show;
    
    return 0;
}

void creation(int *a) {
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("List was created Successfully \n");
}

void insertion(int *a) {
    printf("Enter the pos to insert \n");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("%d is out of range\n", pos);
    } else {
        printf("Enter the elem to insert\n");
        scanf("%d", &elm);
        
        // Shifting elements to the right
        for (i = n; i > pos - 1; i--) {
            a[i] = a[i - 1];
        }
        a[pos - 1] = elm;
        n++;
        printf("%d is inserted successfully \n", elm);
    }
}

void deletion(int *a) {
    printf("Enter the elm to delete \n");
    scanf("%d", &elm);
    
    flag2 = 0;
    for (i = 0; i < n; i++) {
        if (elm == a[i]) {
            pos = i + 1;
            flag2 = 1;
            break;
        }
    }

    if (flag2 == 0) {
        printf("%d not found\n", elm);
    } else {
        // Shifting elements to the left
        for (i = pos - 1; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
        printf("%d was removed successfully\n", elm);

        if (n == 0) {
            flag1 = 0;
            free(a);
        }
    }
}

void display(int *a) {
    printf("List is \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void search(int *a) {
    flag2 = 0;
    printf("Enter the elm to search \n");
    scanf("%d", &elm);
    
    for (i = 0; i < n; i++) {
        if (elm == a[i]) {
            printf("%d found at pos %d\n", elm, i + 1);
            flag2 = 1;
            break;
        }
    }

    if (flag2 == 0) {
        printf("%d not found\n", elm);
    }
}



OUTPUT
1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
1
Enter the range: 4
Enter 4 elements: 1 2 3 4
List was created Successfully 

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
4 
Enter the elm to delete 
2
2 was removed successfully

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
3
Enter the pos to insert 
3 9
Enter the elem to insert
9 is inserted successfully 

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
5
Enter the elm to search 
2
2 not found

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
5
Enter the elm to search 
1
1 found at pos 1

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
2
List is 
1	3	9	4	

1.Creation 
2.Display 
3.Insertion 
4.Deletion 
5.Search 
6.Exit 
Select ur choice 
6
Exiting the program.
