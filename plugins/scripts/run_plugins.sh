#!/bin/bash

echo "Root source directory for current build : ${GXX_PLUGINSDIR}"

echo "Executing user requested plugin: $1"

cd ${GXX_PLUGINSDIR}/build

ctest . -v

