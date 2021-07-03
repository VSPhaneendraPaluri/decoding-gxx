#include "GccPluginCallback.h"
#if 0
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "tree-pass.h"
#include "intl.h"
#include "diagnostic.h"
#endif

void GccPluginCallback::pluginStartParseFunction(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_START_PARSE_FUNCTION,  /* Called before parsing the body of a function. */" << std::endl;
  //tree fndef = (tree) gcc_data;
  //warning (0, G_("Start fndef %s"), IDENTIFIER_POINTER (DECL_NAME (fndef)));
}

void GccPluginCallback::pluginFinishParseFunction(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_FINISH_PARSE_FUNCTION, /* After finishing parsing a function. */" << std::endl;
}

void GccPluginCallback::pluginPassManagerSetup(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_PASS_MANAGER_SETUP,    /* To hook into pass manager.  */" << std::endl;
}

void GccPluginCallback::pluginFinishType(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_FINISH_TYPE,           /* After finishing parsing a type.  */" << std::endl;
}

void GccPluginCallback::pluginFinishDecl(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_FINISH_DECL,           /* After finishing parsing a declaration. */" << std::endl;
}

void GccPluginCallback::pluginFinishUnit(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_FINISH_UNIT,           /* Useful for summary processing.  */" << std::endl;
}

void GccPluginCallback::pluginPreGenericize(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_PRE_GENERICIZE,        /* Allows to see low level AST in C and C++ frontends.  */" << std::endl;
}

void GccPluginCallback::pluginFinish(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_FINISH,                /* Called before GCC exits.  */" << std::endl;
}

//  PLUGIN_INFO,                  /* Information about the plugin. */

void GccPluginCallback::pluginGccStart(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_GGC_START,             /* Called at start of GCC Garbage Collection. */" << std::endl;
}

void GccPluginCallback::pluginGccMarking(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_GGC_MARKING,           /* Extend the GGC marking. */" << std::endl;
}

void GccPluginCallback::pluginGccEnd(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_GGC_END,               /* Called at end of GGC. */" << std::endl;
}

#ifdef NO_CB_IMPL
void GccPluginCallback::pluginRegisterGccRoots(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_REGISTER_GGC_ROOTS,    /* Register an extra GGC root table. */" << std::endl;
}
#endif

void GccPluginCallback::pluginAttributes(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ATTRIBUTES,            /* Called during attribute registration */" << std::endl;
}

void GccPluginCallback::pluginStartUnit(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_START_UNIT,            /* Called before processing a translation unit. */" << std::endl;
}

void GccPluginCallback::pluginPragmas(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_PRAGMAS,               /* Called during pragma registration. */" << std::endl;
}

void GccPluginCallback::pluginAllPassesStart(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ALL_PASSES_START,      /* Called before first pass from all_passes. */" << std::endl;
}

void GccPluginCallback::pluginAllPassesEnd(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ALL_PASSES_END,        /* Called after last pass from all_passes.  */" << std::endl;
}
  
void GccPluginCallback::pluginAllIpaPassesStart(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ALL_IPA_PASSES_START,  /* Called before first ipa pass.  */" << std::endl;
}
  
void GccPluginCallback::pluginAllIpaPassesEnd(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ALL_IPA_PASSES_END,    /* Called after last ipa pass.  */" << std::endl;
}

void GccPluginCallback::pluginOverrideGate(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_OVERRIDE_GATE,         /* Allows to override pass gate decision for current_pass.  */" << std::endl;
}

void GccPluginCallback::pluginPassExecution(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_PASS_EXECUTION,        /* Called before executing a pass.  */" << std::endl;
}

void GccPluginCallback::pluginEarlyGimplePassesStart(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_EARLY_GIMPLE_PASSES_START,    /* Called before executing subpasses of a GIMPLE_PASS in execute_ipa_pass_list.  */" << std::endl;
}

void GccPluginCallback::pluginEarlyGimplePassesEnd(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_EARLY_GIMPLE_PASSES_END,      /* Called after executing subpasses of a GIMPLE_PASS in execute_ipa_pass_list.  */" << std::endl;
}

void GccPluginCallback::pluginNewPass(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_NEW_PASS,                     /* Called when a pass is first instantiated.  */" << std::endl;
}

void GccPluginCallback::pluginIncludeFile(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_INCLUDE_FILE,  \
   Called when a file is #include-d or given via the #line directive. \
   This could happen many times.  The event data is the included file path, \
   as a const char* pointer.  */" << std::endl;
}

void GccPluginCallback::pluginAnalyzerInit(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_ANALYZER_INIT,  \
  /* Called when -fanalyzer starts. The event data is an ana::plugin_analyzer_init_iface *.  */" << std::endl;
}

void GccPluginCallback::pluginEventFirstDynamic(void *gcc_data, void *user_data)
{
  std::cerr << "PLUGIN_EVENT_FIRST_DYNAMIC,          /* Dummy event used for indexing callback array.  */" << std::endl;
}
