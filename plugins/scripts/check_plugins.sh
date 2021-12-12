#!/bin/bash

echo ""
echo "===================================================="
echo "               RUNNING PLUGIN #$1                   "
echo "===================================================="
echo ""

if [ $1 == 0 ]
then
echo ""
echo ""
echo "Checking 00_dummy_plugin plugin ..."
cd ${GXX_PLUGINSDIR}/build/01_dummy_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib00_DummyGxxPlugin.so -c -x c++ /dev/null -o /dev/null
fi

if [ $1 == 1 ]
then
echo ""
echo ""
echo "Checking 01_basic_plugin plugin ..."
cd ${GXX_PLUGINSDIR}/build/01_basic_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib01_BasicGxxPlugin.so -c -x c++ /dev/null -o /dev/null
fi

if [ $1 == 2 ]
then
echo ""
echo ""
echo "Checking 02_custom_metadata_plugin ..."
cd ${GXX_PLUGINSDIR}/build/02_custom_metadata_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib02_CustomMetaDataPlugin.so -c -x c++ /dev/null -o /dev/null
fi

if [ $1 == 3 ]
then
echo ""
echo ""
echo "Checking 03_plugin_info_by_cb plugin ..."
cd ${GXX_PLUGINSDIR}/build/03_plugin_info_by_cb
echo "NOTE: ===> G++ is just the front-end for the Compiler.  It is just a driver but not the compiler"
${GXX_INSTALLDIR}/bin/../libexec/gcc/x86_64-pc-linux-gnu/10.0.0/cc1 -fplugin=./lib03_PluginInfobyCb.so --help
echo ""
echo "Now, trying to validate the functions called by the plugin"
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib03_PluginInfobyCb.so -c ${GXX_PLUGINSDIR}/test_files/TestFile.cpp -o /dev/null
fi

if [ $1 == 4 ]
then
echo ""
echo ""
echo "Checking 04_cxx_ast plugin ..."
cd ${GXX_PLUGINSDIR}/build/04_cxx_ast
echo "Now, trying to validate the functions called by the plugin"
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib04_CxxAst.so -c ${GXX_PLUGINSDIR}/test_files/TestFile.cpp -o /dev/null
#${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib04_CxxAst.so -c ${GXX_PLUGINSDIR}/test_files/ExceptionHandler.h -o /dev/null
fi
