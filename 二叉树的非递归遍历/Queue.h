#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>	
#include<stdbool.h>


//前置声明,声明外部的自定义类型不需要extern
struct BinaryTree;
typedef struct BinaryTree* QDataType;

//typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode*next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode*head;
	QueueNode*tail;
}Queue;

void QueueInit(Queue*pq);
void QueueDestroy(Queue*pq);

void QueuePush(Queue*pq, QDataType X);
void QueuePop(Queue*pq);
QDataType QueueFront(Queue*pq);
QDataType QueueBack(Queue*pq);
bool QueueEmpty(Queue*pq);
int QueueSize(Queue*pq);