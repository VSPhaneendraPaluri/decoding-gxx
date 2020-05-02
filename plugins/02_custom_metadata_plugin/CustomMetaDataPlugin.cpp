#include <iostream>
#include <string>

#include "PluginMetaData.h"
#include <plugin-version.h>

int plugin_is_GPL_compatible;


int plugin_init(struct plugin_name_args *plugin_info,
	        struct plugin_gcc_version *version)
{
 PluginMetaData pluginMetaData_;

 if (plugin_info == nullptr)
 {
   std::cerr << "Plugin Info struct pointer is NULL" << std::endl;
   return -1;
 }
 
 {
  std::cout << "============ Plugin Information =============" << std::endl;
  std::cout << "Base Name (without extension): " << plugin_info->base_name << std::endl;
  std::cout << "Full Name                    : " << plugin_info->full_name << std::endl;
  std::cout << "Number of arguments          : " << plugin_info->argc << std::endl;
  for (int32_t index = 0; index < plugin_info->argc; index++)
  {
    std::cout << "Plugin KVP[" << std::dec << "] - Key  : " << plugin_info->argv[index].key << std::endl;
    std::cout << "Plugin KVP[" << std::dec << "] - Value: " << plugin_info->argv[index].value << std::endl;
  }
  //std::cout << "Plugin version string        : " << plugin_info->version << std::endl;
  //std::cout << "Plugin help string           : " << plugin_info->help << std::endl;
  std::cout << "=============================================" << std::endl;
 }
 {
   std::cout << "================== 'plugin_gcc_version' struct information ============" << std::endl;
   std::cout << "basever     : " << version->basever << std::endl;
   std::cout << "datestamp   : " << version->datestamp << std::endl;
   std::cout << "devphase    : " << version->devphase << std::endl;
   std::cout << "revision    : " << version->revision << std::endl;
   std::cout << "configuration_arguments     : " << version->configuration_arguments << std::endl;
   std::cout << "=======================================================================" << std::endl;
 }

 if (strncmp(version->basever, pluginMetaData_.defaultPluginVersionInfo_.basever, strlen("10.0")))
 {
   std::cerr << "Plugin default version check for (7.4) failed." << std::endl;
   return -1;
 }
 
 return 0;
}
