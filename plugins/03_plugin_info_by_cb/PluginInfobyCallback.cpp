#include <iostream>
#include <string>

// #define NO_CB_IMPL

#include <gcc-plugin.h>
#include <plugin-version.h>

// Contains information required by PLUGIN_PASS_MANAGER_SETUP plugin
#include "tree-pass.h"

#include "GccPluginCallback.h"

int plugin_is_GPL_compatible;


int plugin_init(struct plugin_name_args *plugin_info,
	        struct plugin_gcc_version *version)
{
  if (!plugin_default_version_check(version, &gcc_version))
  {
    std::cerr << "Plugin version incompatable with " << GCCPLUGIN_VERSION_MAJOR << ", " << GCCPLUGIN_VERSION_MINOR << std::endl;
    return 1;
  }

  /*
    plugin.def file provides 'enum plugin_event' enumeration that lists callback events that the plugin can register to
    The plugin can register using a function call registration for 'register_callback'
    Function arguments:
    1. char *name: plugin name
    2. int event: event code from above (enum plugin_event)
    3. plugin_callback_func callback: function handler upon invoking of event by GCC
    4. void *user_data: plugin specific data
  */

  std::cout << "Plugin is initialized ..." << std::endl;

  struct plugin_info userPluginInfo = {
    .version = "0.1",
    .help = "verbose\tThis is the verbose log\n"
  };
  
  register_callback(plugin_info->base_name,
                    PLUGIN_START_PARSE_FUNCTION,
                    GccPluginCallback::pluginStartParseFunction,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_FINISH_PARSE_FUNCTION,
                    GccPluginCallback::pluginFinishParseFunction,
                    NULL);

#ifdef NO_CB_IMPL
  struct register_pass_info pass_info;
  register_callback(plugin_info->base_name,
                    PLUGIN_PASS_MANAGER_SETUP,
                    NULL,
                    static_cast<void *>(&pass_info));
#endif

  register_callback(plugin_info->base_name,
                    PLUGIN_FINISH_TYPE,
                    GccPluginCallback::pluginFinishType,
                    NULL);
  
  register_callback(plugin_info->base_name,
                    PLUGIN_FINISH_DECL,
                    GccPluginCallback::pluginFinishDecl,
                    NULL);
  
  register_callback(plugin_info->base_name,
                    PLUGIN_FINISH_UNIT,
                    GccPluginCallback::pluginFinishUnit,
                    NULL);
  
  register_callback(plugin_info->base_name,
                    PLUGIN_PRE_GENERICIZE,
                    GccPluginCallback::pluginPreGenericize,
                    NULL);
  
  register_callback(plugin_info->base_name,
                    PLUGIN_FINISH,
                    GccPluginCallback::pluginFinish,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_GGC_START,
                    GccPluginCallback::pluginGccStart,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_GGC_MARKING,
                    GccPluginCallback::pluginGccMarking,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_GGC_END,
                    GccPluginCallback::pluginGccEnd,
                    NULL);

  struct ggc_root_tab gcc_root;
  register_callback(plugin_info->base_name,
                    PLUGIN_REGISTER_GGC_ROOTS,
                    NULL,
                    static_cast<ggc_root_tab *>(&gcc_root));

  register_callback(plugin_info->base_name,
                    PLUGIN_ATTRIBUTES,
                    GccPluginCallback::pluginAttributes,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_START_UNIT,
                    GccPluginCallback::pluginStartUnit,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_PRAGMAS,
                    GccPluginCallback::pluginPragmas,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_ALL_PASSES_START,
                    GccPluginCallback::pluginAllPassesStart,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_ALL_PASSES_END,
                    GccPluginCallback::pluginAllPassesEnd,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_ALL_IPA_PASSES_START,
                    GccPluginCallback::pluginAllIpaPassesStart,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_ALL_IPA_PASSES_END,
                    GccPluginCallback::pluginAllIpaPassesEnd,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_OVERRIDE_GATE,
                    GccPluginCallback::pluginOverrideGate,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_PASS_EXECUTION,
                    GccPluginCallback::pluginPassExecution,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_EARLY_GIMPLE_PASSES_START,
                    GccPluginCallback::pluginEarlyGimplePassesStart,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_EARLY_GIMPLE_PASSES_END,
                    GccPluginCallback::pluginEarlyGimplePassesEnd,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_NEW_PASS,
                    GccPluginCallback::pluginNewPass,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_INCLUDE_FILE,
                    GccPluginCallback::pluginIncludeFile,
                    NULL);

#ifdef NO_CB_IMPL
  register_callback(plugin_info->base_name,
                    PLUGIN_ANALYZER_INIT,
                    GccPluginCallback::pluginAnalyzerInit,
                    NULL);

  register_callback(plugin_info->base_name,
                    PLUGIN_EVENT_FIRST_DYNAMIC,
                    GccPluginCallback::pluginEventFirstDynamic,
                    NULL);
#endif

  std::cout << "Plugin callback registrations are completed successfully ..." << std::endl;

  return 0;
}
