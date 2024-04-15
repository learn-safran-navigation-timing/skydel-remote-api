#pragma once

#include <memory>
#include "command_base.h"

#include "gen/ConfigFilter.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the filter for configuration broadcast.
    ///
    /// Name   Type               Description
    /// ------ ------------------ ------------------------------------------------------------------------------
    /// Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.
    ///

    class SetConfigBroadcastFilter;
    typedef std::shared_ptr<SetConfigBroadcastFilter> SetConfigBroadcastFilterPtr;
    
    
    class SetConfigBroadcastFilter : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetConfigBroadcastFilter();

      SetConfigBroadcastFilter(const std::vector<Sdx::ConfigFilter>& filter);

      static SetConfigBroadcastFilterPtr create(const std::vector<Sdx::ConfigFilter>& filter);
      static SetConfigBroadcastFilterPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** filter ****
      std::vector<Sdx::ConfigFilter> filter() const;
      void setFilter(const std::vector<Sdx::ConfigFilter>& filter);
    };
    
  }
}

