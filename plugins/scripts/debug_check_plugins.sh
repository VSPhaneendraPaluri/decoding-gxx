#!/bin/bash`


#echo ""
#echo ""
#echo "Checking dummy_plugin plugin ..."
#cd ${GXX_PLUGINSDIR}/build/dummy_plugin
#${GXX_INSTALLDIR}/bin/g++ -fplugin=./libDummyGxxPlugin.so -c -x c++ /dev/null -o /dev/null

echo ""
echo ""
echo "Checking basic_plugin plugin ..."
cd ${GXX_PLUGINSDIR}/build/basic_plugin
${GXX_INSTALLDIR}/bin/g++ -fplugin=./libBasicGxxPlugin.so -c -x c++ /dev/null -o /dev/null
