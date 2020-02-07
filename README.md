libgo for Unikraft
=============================

This is a port of libgo for Unikraft as an external library. You will
need the following external libraries to make it work:

+ gcc
+ libgo
+ pthread-embedded
+ lwip
+ compiler-rt
+ libcxx
+ libcxxabi
+ libunwind
+ libucontext
+ newlib

Please note that the listed order is important, in particular
gcc before libgo, e.g.:

```
...$(UK_LIBS)/gcc:$(UK_LIBS)/libgo:$(UK_LIBS)/pthread-embedded...

```

Currently, you need to assign at least 512 MB of RAM to the guest.

Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main unikraft repository.
