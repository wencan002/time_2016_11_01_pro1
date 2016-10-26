#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<hiredis.h>
#include"make_log.h"
#include"redis_op.h"

#define REIDS_TEST_MODULE "test"
#define REIDS_TEST_PROC "redis_test"

int  main(int argc,char *argv[])
{
	 redisContext *redis_conn=NULL;
	 int  ret=0;
	 
	 redis_conn=rop_connectdb_nopwd("127.0.0.1","6379");
	 if(redis_conn==NULL)
	 {
	 	LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"conn  err");
	 	exit(1);
	 }
   
   
   ret=rop_set_string(redis_conn,"hello","world");
   if(ret==-1)
   {
   	LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"set %s %s error","hello","world");
   	exit(1);
   } 
    LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"set %s %s succ","hello","world");
   	
   //判断key值是否存在
   ret=rop_is_key_exist(redis_conn,"hello");  
   if(ret==-1)
   {
   	LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"func rop_is_key_exist  err");
   	exit(1);
   }
   if(ret==0)
    {
     	LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"key %s not exist ","hello");
        exit(1);
     }
        
    LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"key %s is  exist ","hello");
    
   //自封装函数get  string
    ret=rop_get_string(redis_conn,"hello");  
   if(ret==-1)
   {
   	LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"get %s %s error","hello","world");
   	exit(1);
    }
     
   LOG(REIDS_TEST_MODULE,REIDS_TEST_PROC,"get %s %s succ","hello","world");

  	rop_disconnect(redis_conn);
  	
  	
  	return  0;
  }
