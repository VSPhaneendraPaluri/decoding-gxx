#include <iostream>

#include <gcc-plugin.h>
#include <plugin-version.h>

#include <tree-pass.h>
#include "cp/cp-tree.h"
#include "tree.h"

#include <set>
#include <vector>
#include <string>
#include <algorithm>

int plugin_is_GPL_compatible;
static int counter = 0;

std::set<tree> treeSet{};

bool compareSourceLine(tree t1, tree t2)
{
  return DECL_SOURCE_LOCATION(t1) < DECL_SOURCE_LOCATION(t2);
}

void traverse_tree_names(tree g_ns)
{
  // Presents us two things: names and namespaces
  cp_binding_level* level (NAMESPACE_LEVEL (g_ns));
  tree decl;
 
  for(decl = level->names; decl != NULL_TREE; decl = TREE_CHAIN(decl))
  {
    if (DECL_IS_BUILTIN(decl))
      continue;

    const char * name (IDENTIFIER_POINTER(DECL_NAME(decl)));
    /*
    The inclusion of headers brings in all built-ins that don't get excluded with the
    above DECL_IS_BUILTIN call.  Hence, using the below string comparison to filter
    out the irrelevant things
    */
    if (std::string(name).find(std::string("__")) != 0)
    {
      treeSet.insert(decl);
    }

    if (TREE_CODE(decl) == NAMESPACE_DECL)
    {
      traverse_tree_names(decl);
    }
  }
}

void print_tree_nodes()
{
  std::vector<tree> treeVector{};
  for (auto it = treeSet.begin(); it != treeSet.end(); ++it)
  {
    treeVector.push_back(*it);
  }
  std::sort(treeVector.begin(), treeVector.end(), compareSourceLine);

  for (auto it = treeVector.begin(); it != treeVector.end(); ++it)
  {
    counter++;
    tree decl = *it;
    
    const char * name (IDENTIFIER_POINTER(DECL_NAME(decl)));
    std::cerr << \
      "Index: " << counter << \
      " => " << DECL_SOURCE_FILE(decl) << ": " << DECL_SOURCE_LINE(decl) << \
      ", Name: " << name << \
      ", Tree Type: " << get_tree_code_name(TREE_CODE(decl));
      /*", Source File: " << DECL_SOURCE_FILE(decl) << \*/
      /*", Source Line: " << DECL_SOURCE_LINE(decl);*/

    //if (tree t = TREE_TYPE (decl))
    std::cerr << ", Tree Type: " << get_tree_code_name(TREE_CODE(TREE_TYPE(decl)));

    std::cerr << std::endl;
  }
}

static void preGenericizeCallback(void * gcc_data, void * user_data)
{
  std::cout << __PRETTY_FUNCTION__ << " function invoked by the compiler" << std::endl;
  
  //tree tree_obj = static_cast<tree>(gcc_data);
  counter = 0;
  traverse_tree_names(global_namespace);
  print_tree_nodes();
}


int plugin_init(struct plugin_name_args *plugin_info,
	        struct plugin_gcc_version *version)
{
  if (!plugin_default_version_check(version, &gcc_version))
  {
    std::cerr << "Plugin version incompatable with " << GCCPLUGIN_VERSION_MAJOR << ", " << GCCPLUGIN_VERSION_MINOR << std::endl;
    return 1;
  }

  std::cout << "Plugin is initialized ..." << std::endl;

  struct plugin_info userPluginInfo = {
    .version = "0.1",
    .help = "verbose\tThis demos PRE_GENERICIZE plugin event usage\n"
  };

  register_callback(plugin_info->base_name,
                    PLUGIN_INFO,
                    NULL,
                    static_cast<struct plugin_info *>(&userPluginInfo));

  struct register_pass_info pass_info;
  register_callback(plugin_info->base_name,
                    PLUGIN_PRE_GENERICIZE,
                    preGenericizeCallback,
                    NULL);

  std::cout << "Plugin callbacks registered successfully ..." << std::endl;

  return 0;
}
