#ifndef _GCD_H_
#define _GCD_H_

typedef uint64_t (gcd_f)(uint64_t, uint64_t);

uint64_t gcd64(uint64_t, uint64_t);
uint64_t gcd64_use_builtin_ctz(uint64_t, uint64_t);

#endif /* _GCD_H_ */
