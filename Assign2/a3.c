#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

void allocate_block(int index_block[], int allocated_blocks[], int n, int block_number);
void deallocate_block(int index_block[], int allocated_blocks[], int n, int block_number);
void display_allocation(int index_block[], int allocated_blocks[], int n);

int main() {
    int n;
    printf("Enter the number of blocks on disk: ");
    scanf("%d", &n);

    int index_block[MAX_BLOCKS], allocated_blocks[MAX_BLOCKS];
    int choice, block_number;

    for (int i = 0; i < n; ++i) {
        index_block[i] = -1; // Initialize index block with -1 (indicating unallocated)
        allocated_blocks[i] = 0; // Initialize allocated_blocks with 0 (indicating unallocated)
    }

    while (1) {
        printf("\nIndexed File Allocation Method Simulation\n");
        printf("1. Allocate a block\n");
        printf("2. Deallocate a block\n");
        printf("3. Display allocated blocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter block number to allocate: ");
                scanf("%d", &block_number);
                allocate_block(index_block, allocated_blocks, n, block_number);
                break;
            case 2:
                printf("Enter block number to deallocate: ");
                scanf("%d", &block_number);
                deallocate_block(index_block, allocated_blocks, n, block_number);
                break;
            case 3:
                display_allocation(index_block, allocated_blocks, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void allocate_block(int index_block[], int allocated_blocks[], int n, int block_number) {
    if (allocated_blocks[block_number] == 1) {
        printf("Block %d is already allocated.\n", block_number);
        return;
    }

    int index;
    printf("Enter index block number for block %d: ", block_number);
    scanf("%d", &index);

    if (index_block[index] == -1) {
        index_block[index] = block_number;
        allocated_blocks[block_number] = 1;
        printf("Block %d allocated successfully.\n", block_number);
    } else {
        printf("Index block %d is already allocated.\n", index);
    }
}

void deallocate_block(int index_block[], int allocated_blocks[], int n, int block_number) {
    if (allocated_blocks[block_number] == 0) {
        printf("Block %d is not allocated.\n", block_number);
        return;
    }

    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (index_block[i] == block_number) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        index_block[index] = -1;
        allocated_blocks[block_number] = 0;
        printf("Block %d deallocated successfully.\n", block_number);
    } else {
        printf("Block %d is not indexed.\n", block_number);
    }
}

void display_allocation(int index_block[], int allocated_blocks[], int n) {
    printf("Block\tAllocated\tIndex Block\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%s\t\t%d\n", i, (allocated_blocks[i] == 1) ? "Yes" : "No", index_block[i]);
    }
}
