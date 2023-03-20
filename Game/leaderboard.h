// RPS Pro: leaderboard.h
// Contains the definitions of the Leaderboard module's functions
// and data structures
//
// Module managed by Michelle Novar

#ifndef RPS_PRO_GAME_LEADERBOARD_H
#define RPS_PRO_GAME_LEADERBOARD_H

#include "authentication.h"

typedef struct leaderboardNode {
	USER* data;
	struct leaderboardNode* next;
} LEADERBOARD_NODE;

typedef struct leaderboard {
	struct leaderBoardNode* firstNode;
} LEADERBOARD;

#endif




//// build these 
//struct Node {
//    int data;
//    struct Node* next;
//};

// This function prints contents of linked list starting
// from the given node
void printList(struct leaderboardNode* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Driver's code
//int main()
//{
    struct leaderboardNode* head = NULL;
    struct leaderboardNode* second = NULL;
    struct leaderboardNode* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct leaderboardNode*)malloc(sizeof(struct leaderboardNode));
    second = (struct leaderboardNode*)malloc(sizeof(struct leaderboardNode));
    third = (struct leaderboardNode*)malloc(sizeof(struct leaderboardNode));

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    // Function call
    printList(head);

  /*  return 0;
}*/
