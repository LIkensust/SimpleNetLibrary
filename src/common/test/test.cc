#include <iostream>
#include <pthread.h>
#include <thread>
#include "../Condition.h"
#include "../Mutex.h"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 
using namespace SNL;
using namespace std;

int condition_ = 0;
MutexLock mutex_;
Condition con_(mutex_);

void threadheadler() {
  for(int i=0;i<5;i++) {
    MutexLockGuard tmp(mutex_);
    condition_++; 
    sleep(1);
  }
  con_.notify();
}

void thread_fun() {
  MutexLockGuard tmp(mutex_);
  while(condition_<5)
  con_.wait();
}

int main()
{
  thread t1(threadheadler);
  thread t2(thread_fun);
  t1.join();
  t2.join();
  return 0;
}

