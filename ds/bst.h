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
  root: �˻��� ������ Ʈ���� ��Ʈ
  target_rid: �˻��� Ű ��

 > return value
  ��ġ�ϴ� ��尡 �ִٸ� �� ����� �����͸� ��ȯ�մϴ�.
  ���ٸ� NULL�� ��ȯ�մϴ�.


@author

*/
bst_node* bst_search(bst_node* root, int target_rid);
bst_node* bst_search_with_parent(bst_node* root, int target_rid, bst_node** parent);

/*
int bst_insert(bst_node** root, bst_node* t);
 > arguments
  root: ������ ������ Ʈ���� ��Ʈ
  t: ������ ���

 > return value
  ���Կ� �����ߴٸ� 0�� �ƴ� ���� ��ȯ�մϴ�.
  �����ߴٸ� 0�� ��ȯ�մϴ�.


@author

*/
int bst_insert(bst_node** root, bst_node* t);

/*
int bst_delete(bst_node* root, int target_rid);
 > arguments
  root: ������ ������ Ʈ���� ��Ʈ
  target_rid: ������ ����� rid��

 > return value
  ������ �����ߴٸ� 0�� �ƴ� ���� ��ȯ�մϴ�.
  �����ߴٸ� 0�� ��ȯ�մϴ�.


@author

*/
int bst_delete(bst_node** root, int target_rid);

/*
void bst_print(bst_node** root);
 > arguments
  root: ����� Ʈ���� ��Ʈ

 > return value
  none

@author

*/
void bst_print(bst_node* root);

/*
int bst_hasChild(bst_node* t)
 ��尡 �ڽ��� �ִ��� Ȯ���մϴ�.
 > arguments
  t: Ÿ�� ���

 > return value
  �ڽ��� ��

*/
int bst_hasChild(bst_node* t);