#pragma once

const int SEATS_MAX = 250;
const bool AVAILABLE = true;
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
movie* movie_init(movie** mv, char* name);

typedef struct schedule_
{
	movie* movie;
	int starting_time;
	int ending_time;
	bool seats[SEATS_MAX];

	schedule_* prev_movie;
	schedule_* next_movie;
} schedule;

/*
schedule* schedule_init(schedule* t, movie* mv, int st);
 �ش� �������� �� ���۽ð�, ����ð�, �󿵰� ��ȣ, �¼� ���� �ʱ�ȭ�մϴ�.

 > arguments
  t: �ʱ�ȭ�� ������ ������
  mv: ���� ��ȭ
  st: ������ ���� �ð�
 > return value
  �ʱ�ȭ�� �����ߴٸ� t�� ��ȯ�մϴ�
  �����ߴٸ� NULL�� ��ȯ�մϴ�


@author

*/
schedule* schedule_init(schedule** t, movie* mv, int st);

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