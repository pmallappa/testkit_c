# TESTKIT - A Unit Test Framework in C


A QOM (Qemu Object Model) based, Unit Testing framework with following features

- Object Oriented Design (YES, in C)
- Using Minimal QOM
- Minimalistic MACRO support.
- Threaded
- TestCase support
- TestCase with Fixture support
- TestSuite support (collection of TestCase with/out Fixtures)

## Terminologies

### A Test Function

Denoted by TkFunc, is a single test
```c
TkError TkFunc(TkTest *tkt, void *data);
```

### A Test Case


### A Test Suite




# How To Build
----
SCons based build system. Just type scons in the toplevel directory

```sh
  $ export TESTKIT_C_DIR=/path/to/new/dir
  $ cd ${TESTKIT_C_DIR}
  $ git clone https://github.com/pmallappa/testkit_c.git
```

```sh
  $ scons
```

This will build a '.a' static library namely 'testkit_c.a'.
Link with test application

```sh
  $ gcc -o testapp ${TESTKIT_C_DIR}/build/testkit_c.a
```
