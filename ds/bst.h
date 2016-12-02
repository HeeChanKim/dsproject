#pragma once
#include "movie.h"

typedef struct bst_node_
{
	int rid; // reservation id
	schedule* schedule;

	bst_node_* left;
	bst_node_* right;
} bst_node;

/*
bst_node* bst_search(bst_node* root, int target_rid) 
 > arguments
  root: 검색을 실행할 트리의 루트
  target_rid: 검색할 키 값

 > return value
  일치하는 노드가 있다면 그 노드의 포인터를 반환합니다.
  없다면 NULL을 반환합니다.


@author

*/
bst_node* bst_search(bst_node* root, int target_rid);
bst_node* bst_search_with_parent(bst_node* root, int target_rid, bst_node** parent);

/*
int bst_insert(bst_node** root, bst_node* t);
 > arguments
  root: 삽입을 실행할 트리의 루트
  t: 삽입할 노드

 > return value
  삽입에 성공했다면 0이 아닌 수를 반환합니다.
  실패했다면 0을 반환합니다.


@author

*/
int bst_insert(bst_node** root, bst_node* t);

/*
int bst_delete(bst_node* root, int target_rid);
 > arguments
  root: 삭제를 실행할 트리의 루트
  target_rid: 삭제할 노드의 rid값

 > return value
  삭제에 성공했다면 0이 아닌 수를 반환합니다.
  실패했다면 0을 반환합니다.


@author

*/
int bst_delete(bst_node** root, int target_rid);

/*
void bst_print(bst_node** root);
 > arguments
  root: 출력할 트리의 루트

 > return value
  none

@author

*/
void bst_print(bst_node* root);

/*
int bst_hasChild(bst_node* t)
 노드가 자식이 있는지 확인합니다.
 > arguments
  t: 타겟 노드

 > return value
  자식의 수

*/
int bst_hasChild(bst_node* t);