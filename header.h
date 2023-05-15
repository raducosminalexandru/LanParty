#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define NUMBER_OF_TASKS 5
#define NAMES_LENGHT 80
#define WINNER_TEAMS 8
#define SEMI_FINAL 2

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};

struct PlayerArray{
    struct Player player;
    struct PlayerArray *next;
};

typedef struct PlayerArray PlayerArray;

struct Team{
    char *name;
    int numberOfPlayers;
    float team_points;
    PlayerArray *Players;
    struct Team *nextTeam;
};

typedef struct Team Team;

typedef struct TeamsQueue{
    Team *firstTeam,*secondTeam;
} Match;

struct Element{
    Match* Teams;
    struct Element* next;
};

typedef struct Element Element;

struct Q{
    Element *front,*rear;
};

typedef struct Q Queue;


struct StackElement{
    Team* StackTeam;
    struct StackElement* next;
};

typedef struct StackElement StackNode;

struct TreeNode{
    int height;
    Team* TeamNode;
    struct TreeNode *left,*right;
};

typedef struct TreeNode TreeNode;


void Task1(char** argv, Team** TeamList);
void Task2(Team** TeamList, char** argv);
void Task3(Team* TeamList, char** argv,Queue** WinnersTeams);
void Task4(Queue* WinnersTeam, Team** TeamWinners,TreeNode** root, char** argv);


void PrintList(Team* TeamList, FILE* output);
float MedianCalculator(Team* TeamMedian);
int PowOf2(int numberOfTeams);
void RemoveTeam(Team** TeamHead, Team* TeamToDelete);
Team* copyTeam(Team* source, Team* destination);


Queue* createQueue();
void enQueue(Queue*q, Team* firstTeam, Team* secondTeam);
Match* deQueue(Queue*q);
int isEmpty(Queue*q);
void deleteQueue(Queue*q);
Queue* CreateQueue(Queue* q, Team* TeamList);
void PrintQueue(Queue* q, FILE* output);
void PrintMatches(Queue* q, FILE* output);
void CalculatePoints(Queue *q);
Queue* newQueue(Queue* q);
void QueueToList(Queue* q, Team** TeamListt);

Team* top(StackNode *top);
void push(StackNode**top, Team* v);
Team* pop(StackNode**top);
int isEmptyStack(StackNode*top);
void deleteStack(StackNode**top);
void deleteStack(StackNode**top);
void CreateStacks(Queue* q, StackNode** Winners, StackNode** Losers);
void PrintStack(StackNode**top, FILE* output);
void recreateQueueFromWinnersStack(Queue** q, StackNode* winnersStack);

TreeNode* newNode(Team* TeamToAdd);
TreeNode* insert(TreeNode* node, Team* TeamToAdd);
void PrintBST(TreeNode* root, FILE* output);
