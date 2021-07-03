#include <iostream>

class GccPluginCallback
{
  public:

    /*
      The prototype for a plugin callback function.
      gcc_data  - event-specific data provided by GCC
      user_data - plugin-specific data provided by the plug-in.
    
      typedef void (*plugin_callback_func)(void *gcc_data, void *user_data);
    */
    static void pluginStartParseFunction(void *gcc_data, void *user_data);
    static void pluginFinishParseFunction(void *gcc_data, void *user_data);
    static void pluginPassManagerSetup(void *gcc_data, void *user_data);
    static void pluginFinishType(void *gcc_data, void *user_data);
    static void pluginFinishDecl(void *gcc_data, void *user_data);
    static void pluginFinishUnit(void *gcc_data, void *user_data);
    static void pluginPreGenericize(void *gcc_data, void *user_data);
    static void pluginFinish(void *gcc_data, void *user_data);
    static void pluginGccStart(void *gcc_data, void *user_data);
    static void pluginGccMarking(void *gcc_data, void *user_data);
    static void pluginGccEnd(void *gcc_data, void *user_data);
#ifdef NO_CB_IMPL
    static void pluginRegisterGccRoots(void *gcc_data, void *user_data); // No callback
#endif
    static void pluginAttributes(void *gcc_data, void *user_data);
    static void pluginStartUnit(void *gcc_data, void *user_data);
    static void pluginPragmas(void *gcc_data, void *user_data);
    static void pluginAllPassesStart(void *gcc_data, void *user_data);
    static void pluginAllPassesEnd(void *gcc_data, void *user_data);
    static void pluginAllIpaPassesStart(void *gcc_data, void *user_data);
    static void pluginAllIpaPassesEnd(void *gcc_data, void *user_data);
    static void pluginOverrideGate(void *gcc_data, void *user_data);
    static void pluginPassExecution(void *gcc_data, void *user_data);
    static void pluginEarlyGimplePassesStart(void *gcc_data, void *user_data);
    static void pluginEarlyGimplePassesEnd(void *gcc_data, void *user_data);
    static void pluginNewPass(void *gcc_data, void *user_data);
    static void pluginIncludeFile(void *gcc_data, void *user_data);
    static void pluginAnalyzerInit(void *gcc_data, void *user_data);
    static void pluginEventFirstDynamic(void *gcc_data, void *user_data);
};