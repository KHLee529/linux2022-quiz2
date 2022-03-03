#ifndef _UTIL_H_
#define _UTIL_H_

time_t diff(struct timespec t1, struct timespec t2)
{
    return (t2.tv_nsec - t1.tv_nsec) + (t2.tv_sec - t1.tv_sec) * 1000000000;
}
#endif /* _UTIL_H_ */
