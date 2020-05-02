---
layout: post
title: Setup InsfraStructure To Write Plugins
date: 2019-12-14 13:19 +0530
---

Hello Guys, welcome to this hands-on tutorial on how to get started creating a dummy G++ Plugin.

Currently, while I'm jotting down this post, the version that I've started to experiment writing G++ Plugins is with 9.2.0. Plugins support was introduced into GCC version 4.5.0 onwards.  Plugins allow gcc/gxx and it eco-system developers to introduce new features to the users.  Plugins once written in a way that is in agreement with the GCC guidelines, it gets loaded as a shared object file (.so).  The plugins are generally written in a way that they make use of the gcc-plugin interfaces (callbacks rather) to intervene in various phases of the compilation process.

Actually, there is not a very clean interface available to get to all the (internal) details of the GCC.  Hence, one needs to spend time and dive deep down to understand the GCC framework better.


# Why ONLY PLUGINs to decode GCC ?
Well, as mentioned earlier too, there are some good amount of documentations made available by the GNU team itself, and other organizations too (GNU being a open-source project).  For instance,
- [GCC Wiki](https://gcc.gnu.org/wiki/HomePage)
- [GNU Online Docs](https://gcc.gnu.org/onlinedocs/gccint)
and many more ...

IMHO, it is always good to start-off with a use-case that checks a feature set provided by some implementation.  This way, one gets to hit various parts of the framework.  


# What is the goal ?
To create a simple G++ plugin that once integrated properly, shall do nothing but would report something like "PVS Dummy Plugin Successful".  The successful execution of this dummy plugin would prove that the basic infra-structure required for extending the plugin to fit to various use-cases is already ready.


# Exercise Some Caution !!
NOTE:  It is always recommended to not to directly work on the system installed GCC since, things could easily go awkward if any issue occurs.  Hence, users are recommended to download GCC for original GCC downloads webpage, store it locally and make edits to it.  Remember, don't let the build artifacts get installed in the system space.

Just a reminder:
GCC version 4.5.0: Plugins feature was introduced
GCC version 4.7.0: Once could write both C and C++-based plugins
GCC version 4.8.0: Plugins could be written onlly C++ way !

Always better to have a local version of GCC built that is configured to generate build artifacts locally.


# Steps to Getting Started
#### Setup and export paths to few sources that would be used later by other scripts
  ```
  export GXX_SRCDIR=${HOME}/sources/gxx/svn-sources/gcc
  export GXX_BUILDDIR=${GXX_SRCDIR}/../gxx-build
  export GXX_INSTALLDIR=${HOME}/MyInstalls/gxx/gcc-install
  export GXX_PLUGINDIR=${HOME}/MyWorks/01_plugins/01_gxx
 
  echo "GXX Sources Directory ------ ${GXX_SRCDIR}"
  echo "GXX Build Directory -------- ${GXX_BUILDDIR}"
  echo "GXX Install Directory ------ ${GXX_INSTALLDIR}"
  echo "GXX Plugins Directory ------ ${GXX_PLUGINDIR}"
 ```
#### Download, Build and Install GCC
  ```
   1 # Download / Checkout GCC from original repository
   2 mkdir -p ${GXX_SRCDIR}
   3 svn checkout svn://gcc.gnu.org/svn/gcc/trunk ${GXX_SRCDIR}
   4 cd ${GXX_SRCDIR}
   5 ./contrib/download_prerequisites
   6
   7 # Configure and Build GCC
   8 mkdir -p ${GXX_BUILDDIR}
   9 cd ${GXX_BUILDDIR}
  10
  11 mkdir -p ${GXX_INSTALLDIR}
  12 SED=sed
  13 ${GXX_SRCDIR}/configure --prefix=${GXX_INSTALLDIR} --enable-languages=c,c++ --disable-multilib --disable-bootstrap --with-system-zlib
  14 make -j$(getconf _NPROCESSORS_ONLN)
  15
  16 # Install GCC
  17 make install
  ```

#### Sstart with an Empty Plugin
  I've named the plugin - 'DummyGxxPlugin.cpp'.
  I've tried to make use of CMake build generator to get my C++-based plugins get built.
  Below is the content of the CMakeList file.
  ```
    1 cmake_minimum_required(VERSION 3.10)
    2
    3 set(PLUGIN_NAME dummyGxxPlugin)
    4 project(${PLUGIN_NAME})
    5
    6 set(CMAKE_CXX_STANDARD 14)
    7 set(COMPILE_TIME_FLAGS
    8  -std=c++14
    9  -Wall
   10  -fno-rtti
   11  )
   12 set(LINK_TIME_FLAGS
   13  -fPIC
   14  )
   15
   16 set(SOURCES
   17   DummyGxxPlugin.cpp
   18   )
   19
   20 add_library(${PROJECT_NAME} SHARED ${SOURCES})
   21
   22 target_compile_options(${PROJECT_NAME}
   23   PRIVATE
   24   ${COMPILE_TIME_FLAGS}
   25   )
   26 target_link_libraries(${PROJECT_NAME}
   27   PRIVATE
   28   ${LINK_TIME_FLAGS}
   29   )
  ```
  Alternaltively, you can get this from [here]({{ site.repository-path }}{{ site.baseurl }}/blob/{{ site.branch }}/plugins/00_dummy_plugin/CMakeLists.txt).

#### Build the Plugin (currently just an empty file)
  The plugin gets built as a SHARED OBJECT
  ```
  1 cd ${GXX_PLUGINSDIR}
  2
  3 cmake -G "Unix Makefiles" .
  4 make
  ```

  Woohoo !  The plugin (??) is built !
  ~~~
  total 44
  drwxrwxrwx 1 pvs pvs  4096 Dec 14 07:26 .
  drwxrwxrwx 1 pvs pvs  4096 Dec 14 12:45 ..
  -rw-rw-rw- 1 pvs pvs 12761 Dec 14 07:25 CMakeCache.txt
  -drwxrwxrwx 1 pvs pvs  4096 Dec 14 07:26 CMakeFiles
  -rw-rw-rw- 1 pvs pvs  5142 Dec 14 07:26 Makefile
  -rw-rw-rw- 1 pvs pvs  1532 Dec 14 07:25 cmake_install.cmake
  -rwxrwxrwx 1 pvs pvs  8256 Dec 14 07:26 libdummyGxxPlugin.so
  ~~~

  Wait, how to confirm whether the infra-structure setup works or not ?

#### Sanity Check of the SetUp
  Try driving the locally installed G++ binaries by providing the built plugin as a command line argument along with few other required arguments
  ```
  ${GXX_INSTALLDIR}/bin/g++ -fplugin=./libdummyGxxPlugin.so -c -x c++ /dev/null -o /dev/null
  ```
  The execution of the above command should report something like this
  ~~~
  cc1plus: fatal error: plugin ./libdummyGxxPlugin.so is not licensed under a GPL-compatible license ./libdummyGxxPlugin.so: undefined symbol: plugin_is_GPL_compatible
  compilation terminated.
  ~~~
  Yes, that is expected, since our plugin is just an empty file for now.
  But, this proves one is good to proceed further and unfold the next beauties of GXX.

  To begin with writing very basic G++ plugin, go over to my next post.