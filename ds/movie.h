#pragma once

const int SEATS_MAX = 250;

typedef struct movie_
{
	char* name;
	int running_time; // in minutes
} movie;

/*
movie* movie_init(movie* mv, char* name);
 ��ȭ�� �̸� ���� �ʱ�ȭ�մϴ�
 > arguments
  mv: �ʱ�ȭ�� movie ������
  name: ��ȭ �̸�

 > return value
  �ʱ�ȭ�� �����ߴٸ� mv�� ��ȯ�մϴ�
  �����ߴٸ� NULL�� ��ȯ�մϴ�


@author

*/
movie* movie_init(movie* mv, char* name);

typedef struct schedule_
{
	movie* movie;
	int starting_time;
	int ending_time;
	int room_number;
	bool seats[SEATS_MAX];

	schedule_* next_movie;
} schedule;

/*
schedule* schedule_init(schedule* t, movie* mv, int rn);
 �ش� �������� �� ���۽ð�, ����ð�, �󿵰� ��ȣ, �¼� ���� �ʱ�ȭ�մϴ�.

 > arguments
  t: �ʱ�ȭ�� ������ ������
  mv: ���� ��ȭ
  rn: �󿵰� ��ȣ

 > return value
  �ʱ�ȭ�� �����ߴٸ� t�� ��ȯ�մϴ�
  �����ߴٸ� NULL�� ��ȯ�մϴ�


@author

*/
schedule* schedule_init(schedule* t, movie* mv, int rn);

/*
schedule* schedule_insert(schedule* head, schedule* t);
 �� �ڿ� ���� �������� �����մϴ�.

 > arguments
  head: �������� ������ ����Ʈ�� head
  schedule: ������ ������

 > return value
  ���Կ� �����ߴٸ� t�� ��ȯ�մϴ�
  �����ߴٸ� NULL�� ��ȯ�մϴ�


@author

*/
schedule* schedule_insert(schedule* head, schedule* t);

/*
int schedule_delete(schedule* head, schedule* t);
 > arguments
  head: �������� ������ ����Ʈ�� head
  schedule: ������ ������

 > return value
  ������ �����ߴٸ� 0 �̿��� ���ڸ� ��ȯ�մϴ�
  �����ߴٸ� 0�� ��ȯ�մϴ�


@author

*/
int schedule_delete(schedule* head, schedule* t);