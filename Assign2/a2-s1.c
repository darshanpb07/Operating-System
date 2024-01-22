#include <stdio.h>

int main() {
    int n, num_files, i, start_block, length;
    char file_name[20];

    printf("Enter the number of blocks in the disk: ");
    scanf("%d", &n);

    int blocks[n];

    for (i = 0; i < n; i++) {
        blocks[i] = 0; // initialize all blocks to be empty
    }

    while (1) {
        printf("\n1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Display disk status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("\nEnter the name of the file: ");
                scanf("%s", file_name);
                printf("Enter the starting block number: ");
                scanf("%d", &start_block);
                printf("Enter the length of the file: ");
                scanf("%d", &length);

                if (start_block + length > n) {
                    printf("File allocation failed: not enough space\n");
                } else {
                    for (i = start_block; i < start_block + length; i++) {
                        if (blocks[i] != 0) {
                            printf("File allocation failed: block %d is already allocated\n", i);
                            break;
                        }
                    }

                    if (i == start_block + length) { // all blocks are free
                        for (i = start_block; i < start_block + length; i++) {
                            blocks[i] = 1;
                        }

                        printf("File %s created successfully\n", file_name);
                    }
                }

                break;
            case 2:
                printf("\nEnter the name of the file: ");
                scanf("%s", file_name);
                printf("Enter the starting block number: ");
                scanf("%d", &start_block);
                printf("Enter the length of the file: ");
                scanf("%d", &length);

                for (i = start_block; i < start_block + length; i++) {
                    if (blocks[i] == 0) {
                        printf("File deletion failed: block %d is not allocated\n", i);
                        break;
                    }
                }

                if (i == start_block + length) { // all blocks are allocated
                    for (i = start_block; i < start_block + length; i++) {
                        blocks[i] = 0;
                    }

                    printf("File %s deleted successfully\n", file_name);
                }

                break;
            case 3:
                printf("\nDisk status:\n");
                for (i = 0; i < n; i++) {
                    if (blocks[i] == 0) {
                        printf("Block %d: Free\n", i);
                    } else {
                        printf("Block %d: Allocated\n", i);
                    }
                }

                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
