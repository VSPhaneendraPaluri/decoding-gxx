#!/bin/bash

echo "Root source directory for current build : ${GXX_PLUGINSDIR}"

echo "Performing out-of-source build for the plugins solution ..."

echo "Creating build directory ..."
cd ${GXX_PLUGINSDIR}
mkdir -p build || exit 1
cd build

cmake -G "Unix Makefiles" ../
cmake --build . --config --

#echo "Checking plugins now ..."
#bash check_plugins.sh

