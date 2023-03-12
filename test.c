/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:10:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/12 16:51:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to add a node to the beginning of the linked list
void insertNode(struct Node **head, int data) {
    // Create a new node with the given data
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    
    // Set the next pointer of the new node to the current head of the list
    newNode->next = *head;
    
    // Update the head of the list to point to the new node
    *head = newNode;
}

// // Function to add a node to the end of the linked list
// void insertNode(struct Node **head, int data) {
//     // Create a new node with the given data
//     struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
    
//     // If the list is empty, make the new node the head of the list
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }
    
//     // Traverse the list to find the last node
//     struct Node *last = *head;
//     while (last->next != NULL) {
//         last = last->next;
//     }
    
//     // Add the new node to the end of the list
//     last->next = newNode;
// }

// Function to print the elements of the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node *head = NULL;
    
    // Insert some nodes into the list
    insertNode(&head, 3);
    insertNode(&head, 5);
    insertNode(&head, 7);
    
    // Print the elements of the list
    printList(head);
    
    return 0;
}
