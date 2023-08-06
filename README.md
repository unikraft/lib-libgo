libgo for Unikraft
=============================

This is a port of libgo for Unikraft as an external library. You will
need the following external libraries to make it work:

+ compiler-rt
+ libunwind
+ libgo
+ musl
+ lwip

Please note that the listed order is important, in particular
compiler-rt before libgo and musl, e.g.:

```
...$(UK_LIBS)/compiler-rt:$(UK_LIBS)/libunwind:$(UK_LIBS)/libgo:$(UK_LIBS)/musl:$(UK_LIBS)/lwip...

```

Currently, you need to use GCC 12 along with gccgo >= 12.
Only the x86 architecture is supported for the moment.
If using QEMU, the `-cpu host` option must be passed as an argument, because the default CPU cannot handle 1GB pages.

Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main unikraft repository.
