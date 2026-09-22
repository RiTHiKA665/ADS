#include <stdio.h>
#include <string.h>
#define MAX 20
char undoStack[MAX][15];
char redoStack[MAX][15];
int undoTop = -1;
int redoTop = -1;
/* Push into Undo Stack */
void PushUndo(char operation[])
{
    if (undoTop == MAX - 1)
    {
    	printf("Stack Overflows");
    	return;
	}
        undoTop++;
        strcpy(undoStack[undoTop], operation);
}
/* Push into Redo Stack */
void PushRedo(char operation[])
{
    if (redoTop == MAX - 1)
    {
    	printf("Stack Overflows");
    	return;
	}
        redoTop++;
        strcpy(redoStack[redoTop], operation);
}
/* Undo operation */
void PopUndo()
{
    if (undoTop == -1)
    {
        printf("Nothing to Undo!\n");
        return;
    }
    printf("Undo: %s\n", undoStack[undoTop]);
    PushRedo(undoStack[undoTop]);
    undoTop--;}
/* Redo operation */
void PopRedo()
{
    if (redoTop == -1)
    {
        printf("Nothing to Redo!\n");
        return;
    }
    printf("Redo: %s\n", redoStack[redoTop]);
    PushUndo(redoStack[redoTop]);
    redoTop--;
}
int main()
{
    int i,choice;
    char operation[50];
    while (1)
    {
        printf("\n--- UNDO REDO MENU ---\n");
        printf("1. Perform Operation\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");
		printf("Update list:\n");
		for(i=0;i<=undoTop;i++)
		 printf("%s, ",undoStack[i]);

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter operation: ");
                scanf(" %[^\n]", operation);
			redoTop=-1; //reset redo stack
                PushUndo(operation);
                break;
            case 2:
                PopUndo();   break;
            case 3:
                PopRedo();   break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
