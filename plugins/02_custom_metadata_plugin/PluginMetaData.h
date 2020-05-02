#pragma once

#include <stdint.h>
#include <gcc-plugin.h>

struct PluginMetaData
{
  static constexpr  struct plugin_info defaultPluginInfo_ =
  {
    .version = "1",
    .help    = "type -h or --help",
  };

  static constexpr struct plugin_gcc_version defaultPluginVersionInfo_ =
  {
   .basever = "9.9",
  };
};

