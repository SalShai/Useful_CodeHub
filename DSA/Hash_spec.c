#include "hash_op.c"

 int main()
 {
    int ch, reg, grade;
    char name[100];
   
    eleCount = 10;
    hashTable = (hash *) calloc(10, sizeof(hash));
    while (1) {
        printf("\n1. Insertion\t2. Deletion\n");
        printf("3. Searching\t4. Display\n5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("register number:");
            scanf("%d", &reg);
            getchar();
            printf("Name:");
            fgets(name, 100, stdin);
            name[strlen(name) - 1] = '\0';
            printf("grade:");
            scanf("%d", &grade);
            /*inserting new node to hash table */
            insertToHash(reg, name, grade);
            break;
 
        case 2:
            printf("Enter the register number:");
            scanf("%d", &reg);
            printf("Enter the grade:");
            scanf("%d", &grade);
            /* delete node with "reg" from hash table */
            deleteFromHash(reg,grade);
            break;
 
        case 3:
            printf("Enter the register number:");
            scanf("%d", &reg);
            printf("Enter the grade:");
            scanf("%d", &grade);
            searchInHash(reg,grade);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("U have entered wrong option!!\n");
            break;
        }
    }
    return 0;
}