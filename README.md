libgo for Unikraft
=============================

This is a port of libgo for Unikraft as an external library. You will
need the following external libraries to make it work:

+ newlib
+ compiler-rt
+ libunwind
+ libcxx
+ libcxxabi
+ pthread-embedded
+ gcc
+ lwip
+ libucontext

When adding the library in the dependency list, please make sure that
gcc comes before libgo, e.g.:

```
...$(UK_LIBS)/gcc:$(UK_LIBS)/libgo:...
```

Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main unikraft repository.
