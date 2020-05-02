#!/bin/bash

# Download / Checkout GCC from original repository
mkdir -p ${GXX_SRCDIR}
svn checkout svn://gcc.gnu.org/svn/gcc/trunk ${GXX_SRCDIR}
cd ${GXX_SRCDIR}
./contrib/download_prerequisites

# Configure and Build GCC
mkdir -p ${GXX_BUILDDIR}
cd ${GXX_BUILDDIR}

mkdir -p ${GXX_INSTALLDIR}
SED=sed
${GXX_SRCDIR}/configure --prefix=${GXX_INSTALLDIR} --enable-languages=c,c++ --disable-multilib --disable-bootstrap --with-system-zlib
make -j$(getconf _NPROCESSORS_ONLN)

# Install GCC
make install

