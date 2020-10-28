
#pragma once

#include <stdio.h>
#include <pthread.h>
//��װһ��������������������Ϊ״̬
typedef struct condition
{
	pthread_mutex_t pmutex;
	pthread_cond_t pcond;
}condition_t;

//��״̬�Ĳ�������
int condition_init(condition_t* cond);
int condition_lock(condition_t* cond);
int condition_unlock(condition_t* cond);
int condition_wait(condition_t* cond);
int condition_timedwait(condition_t* cond, const struct timespec* abstime);
int condition_signal(condition_t* cond);
int condition_broadcast(condition_t* cond);
int condition_destroy(condition_t* cond);







//
//
//
//
//���÷���
//
//
//void* mytask1(void* arg)
//{
//	printf("thread %ld is working on task %d\n", (long)pthread_self(), *(int*)arg);
//	sleep(1);
//	free(arg);
//	return NULL;
//}
//void* mytask2(void* arg)
//{
//	printf("thread %ld is working on task %d\n", (long)pthread_self(), *(int*)arg);
//	sleep(1);
//	free(arg);
//	return NULL;
//}
//void* mytask(void* arg)
//{
//	printf("thread %ld is working on task %d\n", (long)pthread_self(), *(int*)arg);
//	sleep(1);
//	free(arg);
//	return NULL;
//}
//int main(int argc, const char* argv[]) {
//	threadpool_t pool;
//	//��ʼ���̳߳أ���������߳�
//	threadpool_init(&pool, 3);
//	int i = 1;
//	int* arg = (int*)malloc(sizeof(int));
//	*arg = i;
//	threadpool_add_task(&pool, mytask1, arg);
//	arg = (int*)malloc(sizeof(int));
//	i = 2;
//	*arg = i;
//	threadpool_add_task(&pool, mytask1, arg);
//	//    for(i=0; i < 10; i++)
//	//       {
//	//           int *arg = (int*)malloc(sizeof(int));
//	//           *arg = i;
//	//           threadpool_add_task(&pool, mytask, arg);
//	//
//	//       }
//	threadpool_destroy(&pool);
//	return 0;
//	return 0;
//}

