// This file is part of the SV-Benchmarks collection of verification tasks:
// https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks
//
// SPDX-FileCopyrightText: 2001-2016 Daniel Kroening, Computer Science
// Department, University of Oxford SPDX-FileCopyrightText: 2001-2016 Edmund
// Clarke, Computer Science Department, Carnegie Mellon University
// SPDX-FileCopyrightText: 2014-2021 The SV-Benchmarks Community
//
// SPDX-License-Identifier: LicenseRef-BSD-4-Clause-Attribution-Kroening-Clarke

extern void abort(void);

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
  ((void)sizeof((0) ? 1 : 0), __extension__({
     if (0)
       ;
     else
       __assert_fail("0", "square_5.c", 7, __extension__ __PRETTY_FUNCTION__);
   }));
}
extern void abort(void);
void assume_abort_if_not(int cond) {
  if (!cond) {
    abort();
  }
}
extern float __VERIFIER_nondet_float(void);
int main() {
  float IN = __VERIFIER_nondet_float();
  assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

  float x = IN;

  float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x -
                 0.0390625f * x * x * x * x;

  if (!(result >= 0.0f && result < 1.3985f)) {
    reach_error();
  }

  return 0;
}