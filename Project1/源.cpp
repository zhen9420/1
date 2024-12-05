#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000  // ���ڴ��С
#define REQUEST_COUNT 5   // �ڴ�������

// ������з����ṹ��
typedef struct FreeBlock {
    int start;              // ������ʼ��ַ
    int size;               // ������С
    struct FreeBlock* next; // ��һ�����з���
} FreeBlock;

// ��ʼ�����з���
FreeBlock* initialize_memory() {
    FreeBlock* block = (FreeBlock*)malloc(sizeof(FreeBlock));
    block->start = 0;
    block->size = MEMORY_SIZE;
    block->next = NULL;
    return block;
}

// ��ʾ���з������
void display_memory(FreeBlock* head) {
    FreeBlock* current = head;
    printf("��ǰ���з�����\n");
    while (current) {
        printf("��ʼ��ַ: %d, ��С: %d\n", current->start, current->size);
        current = current->next;
    }
    printf("\n");
}

// �״���Ӧ�㷨
void first_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * prev = NULL;

    while (current) {
        if (current->size >= request_size) {
            printf("���� %d �ֽڵ���ַ %d (�״���Ӧ)\n", request_size, current->start);
            current->start += request_size;
            current->size -= request_size;

            if (current->size == 0) { // ������з�������ȫ����
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    *head = current->next;
                }
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("�޷����� %d �ֽ� (�״���Ӧ)\n", request_size);
}

// �����Ӧ�㷨
void best_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * best = NULL, * prev = NULL, * best_prev = NULL;

    while (current) {
        if (current->size >= request_size && (!best || current->size < best->size)) {
            best = current;
            best_prev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (best) {
        printf("���� %d �ֽڵ���ַ %d (�����Ӧ)\n", request_size, best->start);
        best->start += request_size;
        best->size -= request_size;

        if (best->size == 0) {
            if (best_prev) {
                best_prev->next = best->next;
            }
            else {
                *head = best->next;
            }
            free(best);
        }
    }
    else {
        printf("�޷����� %d �ֽ� (�����Ӧ)\n", request_size);
    }
}

// ���Ӧ�㷨
void worst_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * worst = NULL, * prev = NULL, * worst_prev = NULL;

    while (current) {
        if (current->size >= request_size && (!worst || current->size > worst->size)) {
            worst = current;
            worst_prev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (worst) {
        printf("���� %d �ֽڵ���ַ %d (���Ӧ)\n", request_size, worst->start);
        worst->start += request_size;
        worst->size -= request_size;

        if (worst->size == 0) {
            if (worst_prev) {
                worst_prev->next = worst->next;
            }
            else {
                *head = worst->next;
            }
            free(worst);
        }
    }
    else {
        printf("�޷����� %d �ֽ� (���Ӧ)\n", request_size);
    }
}

// ������
int main() {
    int requests[REQUEST_COUNT] = { 200, 300, 100, 50, 250 }; // �ڴ�����
    FreeBlock* memory = initialize_memory();

    printf("�״���Ӧ�㷨:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        first_fit(&memory, requests[i]);
        display_memory(memory);
    }

    memory = initialize_memory();
    printf("�����Ӧ�㷨:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        best_fit(&memory, requests[i]);
        display_memory(memory);
    }

    memory = initialize_memory();
    printf("���Ӧ�㷨:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        worst_fit(&memory, requests[i]);
        display_memory(memory);
    }

    return 0;
}
