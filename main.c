#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "make_log.h"

int main(int argc, char *argv[])
{
    LOG("111", "222", "nihao");
    LOG("222", "222", "世界");
    LOG("333", "333", "tianchao");

	return 0;
}
