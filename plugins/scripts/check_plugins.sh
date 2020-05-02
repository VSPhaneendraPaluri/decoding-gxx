#!/bin/bash`


echo ""
echo ""
echo "Checking 00_dummy_plugin plugin ..."
cd ${GXX_PLUGINSDIR}/build/01_dummy_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib00_DummyGxxPlugin.so -c -x c++ /dev/null -o /dev/null

echo ""
echo ""
echo "Checking 01_basic_plugin plugin ..."
cd ${GXX_PLUGINSDIR}/build/01_basic_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib01_BasicGxxPlugin.so -c -x c++ /dev/null -o /dev/null

echo ""
echo ""
echo "Checking 02_custom_metadata_plugin ..."
cd ${GXX_PLUGINSDIR}/build/02_custom_metadata_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./lib02_CustomMetaDataPlugin.so -c -x c++ /dev/null -o /dev/null
