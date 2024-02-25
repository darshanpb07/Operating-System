#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list allocation
struct Node {
    int block_number;
    struct Node* next;
};

// Disk structure
struct Disk {
    int num_blocks;
    char** blocks; // For storing file names or NULL if block is free
    struct Node** linked_blocks; // For storing linked list of blocks allocated to a file
};

// Function to initialize disk
struct Disk* initializeDisk(int num_blocks) {
    struct Disk* disk = (struct Disk*)malloc(sizeof(struct Disk));
    disk->num_blocks = num_blocks;

    disk->blocks = (char**)malloc(num_blocks * sizeof(char*));
    disk->linked_blocks = (struct Node**)malloc(num_blocks * sizeof(struct Node*));

    // Initialize all blocks as free initially
    for (int i = 0; i < num_blocks; ++i) {
        disk->blocks[i] = NULL;
        disk->linked_blocks[i] = NULL;
    }

    return disk;
}

// Function to allocate blocks to a file
void allocateFile(struct Disk* disk, char* file_name, int num_blocks) {
    int start_block = -1;
    for (int i = 0; i < disk->num_blocks; ++i) {
        if (disk->blocks[i] == NULL) {
            start_block = i;
            break;
        }
    }

    if (start_block == -1 || start_block + num_blocks > disk->num_blocks) {
        printf("Error: Not enough space available to allocate file.\n");
        return;
    }

    struct Node* current_block = NULL;
    for (int i = 0; i < num_blocks; ++i) {
        disk->blocks[start_block + i] = file_name;
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->block_number = start_block + i;
        new_node->next = NULL;

        if (current_block == NULL) {
            disk->linked_blocks[start_block] = new_node;
            current_block = new_node;
        } else {
            current_block->next = new_node;
            current_block = new_node;
        }
    }

    printf("File '%s' allocated starting from block %d.\n", file_name, start_block);
}

// Function to free blocks allocated to a file
void freeBlocks(struct Disk* disk, int start_block) {
    struct Node* current_block = disk->linked_blocks[start_block];
    while (current_block != NULL) {
        int block_number = current_block->block_number;
        disk->blocks[block_number] = NULL;
        struct Node* temp = current_block;
        current_block = current_block->next;
        free(temp);
    }
    disk->linked_blocks[start_block] = NULL;
    printf("Blocks allocated to the file starting from block %d freed.\n", start_block);
}

// Function to display disk status
void displayDiskStatus(struct Disk* disk) {
    printf("Disk Status:\n");
    for (int i = 0; i < disk->num_blocks; ++i) {
        if (disk->blocks[i] == NULL) {
            printf("Block %d: Free\n", i);
        } else {
            printf("Block %d: Allocated to '%s'\n", i, disk->blocks[i]);
        }
    }
}

// Main function
int main() {
    int num_blocks;
    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &num_blocks);

    struct Disk* disk = initializeDisk(num_blocks);

    int choice;
    while (true) {
        printf("\nMenu:\n");
        printf("1. Allocate file\n");
        printf("2. Free file\n");
        printf("3. Display disk status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char file_name[50];
                int num_blocks;
                printf("Enter the name of the file: ");
                scanf("%s", file_name);
                printf("Enter the number of blocks needed for the file: ");
                scanf("%d", &num_blocks);
                allocateFile(disk, file_name, num_blocks);
                break;
            }
            case 2: {
                int start_block;
                printf("Enter the starting block of the file to free: ");
                scanf("%d", &start_block);
                freeBlocks(disk, start_block);
                break;
            }
            case 3: {
                displayDiskStatus(disk);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
