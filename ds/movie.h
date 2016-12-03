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
 영화의 이름 등을 초기화합니다
 > arguments
  mv: 초기화할 movie 포인터
  name: 영화 이름

 > return value
  초기화에 성공했다면 mv를 반환합니다
  실패했다면 NULL을 반환합니다


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
 해당 스케쥴의 상영 시작시간, 종료시간, 상영관 번호, 좌석 등을 초기화합니다.

 > arguments
  t: 초기화할 스케쥴 포인터
  mv: 상영할 영화
  st: 스케쥴 시작 시간
 > return value
  초기화에 성공했다면 t를 반환합니다
  실패했다면 NULL을 반환합니다


@author

*/
schedule* schedule_init(schedule** t, movie* mv, int st);

/*
schedule* schedule_insert(schedule* head, schedule* t);
 맨 뒤에 다음 스케쥴을 삽입합니다.

 > arguments
  head: 스케쥴을 삽입할 리스트의 head
  schedule: 삽입할 스케쥴

 > return value
  삽입에 성공했다면 t를 반환합니다
  실패했다면 NULL을 반환합니다


@author

*/
schedule* schedule_insert(schedule* head, schedule* t);