/***************************************************************************//**
 * # License
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is Third Party Software licensed by Silicon Labs from a third party
 * and is governed by the sections of the MSLA applicable to Third Party
 * Software and the additional terms set forth below.
 *
 ******************************************************************************/
/*******************************************************************************
 * Copyright (c) 2009, 2013 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *    Ian Craggs - updates for the async client
 *    Ian Craggs - change size types from int to size_t
 *******************************************************************************/

#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

#include <stdlib.h> // for size_t definition

/*BE
defm defList(T)

def T concat Item
{
	at 4
	n32 ptr T concat Item suppress "next"
	at 0
	n32 ptr T concat Item suppress "prev"
	at 8
	n32 ptr T id2str(T)
}

def T concat List
{
	n32 ptr T concat Item suppress "first"
	n32 ptr T concat Item suppress "last"
	n32 ptr T concat Item suppress "current"
	n32 dec "count"
	n32 suppress "size"
}
endm

defList(INT)
defList(STRING)
defList(TMP)

BE*/

/**
 * Structure to hold all data for one list element
 */
typedef struct ListElementStruct
{
	struct ListElementStruct *prev, /**< pointer to previous list element */
							*next;	/**< pointer to next list element */
	void* content;					/**< pointer to element content */
} ListElement;


/**
 * Structure to hold all data for one list
 */
typedef struct
{
	ListElement *first,	/**< first element in the list */
				*last,	/**< last element in the list */
				*current;	/**< current element in the list, for iteration */
	int count;  /**< no of items */
	size_t size;  /**< heap storage used */
} List;

void ListZero(List*);
List* ListInitialize(void);

void ListAppend(List* aList, void* content, size_t size);
void ListAppendNoMalloc(List* aList, void* content, ListElement* newel, size_t size);
void ListInsert(List* aList, void* content, size_t size, ListElement* index);

int ListRemove(List* aList, void* content);
int ListRemoveItem(List* aList, void* content, int(*callback)(void*, void*));
void* ListDetachHead(List* aList);
int ListRemoveHead(List* aList);
void* ListPopTail(List* aList);

int ListDetach(List* aList, void* content);
int ListDetachItem(List* aList, void* content, int(*callback)(void*, void*));

void ListFree(List* aList);
void ListEmpty(List* aList);
void ListFreeNoContent(List* aList);

ListElement* ListNextElement(List* aList, ListElement** pos);
ListElement* ListPrevElement(List* aList, ListElement** pos);

ListElement* ListFind(List* aList, void* content);
ListElement* ListFindItem(List* aList, void* content, int(*callback)(void*, void*));

int intcompare(void* a, void* b);
int stringcompare(void* a, void* b);

#endif
