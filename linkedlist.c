#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  char *data;
} Node;

Node *head = NULL;

void printMenu () {
  printf("You have the following options:\n");
  printf("1. add a node to the list\n");
  printf("2. remove a node to the list\n");
  printf("3. insert a node to the list\n");
  printf("4. print list\n");
  printf("5. close program\n");
}

void printList() {
  Node *current = head;
  while(current != NULL) {
    if (current->next != NULL) {
      printf("%.100s->", current->data);
    } else {
      printf("%s", current->data);
    }

    current = current->next;
  }

  printf("\n");
  return;
}

char *inputData() {
  printf("Please enter a string: ");
  char *str = malloc(100 * sizeof(char));
  scanf("%s", str);
  return str;
}

Node *addNode (char *data) {
  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return NULL;
  }

  new->data = data;

  if (head != NULL) {
    new->next = head;
  }

  head = new;

  return head;
}

void removeNode (char data) {
  Node *prev = NULL;
  Node *current = head;

  while (current != NULL) {
    if (*current->data == data) {
      if (prev != NULL) {
        prev->next = current->next;
      } else {
        head = current->next;
      }

      current = NULL;
      break;
    } 

    prev = current;
    current = current->next;
  }

  return;
}

Node *insertNode (int pos, char *data) {
  Node *current = head;
  Node *new = malloc(sizeof(Node));
  new->data = data;

  int i = 0;
  while(current != NULL) {
    if (i == pos) {
      new->next = current->next;
      current->next = new;

      break;
    } else {
      current = current->next;
      i++;
    }
  }

  return new;
}

int main(int argc, char **argv) {
  int option = -1;

  while(option != 5) {
    printMenu();
    int num_received = scanf("%d", &option);

    if (num_received == 1 && option >= 1 && option <= 5) {
      switch(option) {
        char *data;
        int pos;
        case 1:
          data = inputData();
          addNode(data);
          break;
        case 2:
          data = inputData();
          removeNode(*data);
          break;
        case 3:
          data = inputData();
          printf("Please input a position: ");
          int pos_received = scanf("%d", &pos);
          if (pos_received == 1) {
            insertNode(pos, data);
          }
          break;
        case 4:
          // do nothing
          break;
        case 5:
          break;
      }

      printList();
    }
  }

  return 0;
}

