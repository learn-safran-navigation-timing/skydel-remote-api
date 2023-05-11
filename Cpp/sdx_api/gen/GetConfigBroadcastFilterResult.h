#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/ConfigFilter.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConfigBroadcastFilter.
    ///
    /// Name   Type               Description
    /// ------ ------------------ ------------------------------------------------------------------------------
    /// Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.
    ///

    class GetConfigBroadcastFilterResult;
    typedef std::shared_ptr<GetConfigBroadcastFilterResult> GetConfigBroadcastFilterResultPtr;
    
    
    class GetConfigBroadcastFilterResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetConfigBroadcastFilterResult();

      GetConfigBroadcastFilterResult(const std::vector<Sdx::ConfigFilter>& filter);

      GetConfigBroadcastFilterResult(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter);

      static GetConfigBroadcastFilterResultPtr create(const std::vector<Sdx::ConfigFilter>& filter);

      static GetConfigBroadcastFilterResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter);
      static GetConfigBroadcastFilterResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** filter ****
      std::vector<Sdx::ConfigFilter> filter() const;
      void setFilter(const std::vector<Sdx::ConfigFilter>& filter);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetConfigBroadcastFilterResult);
  }
}

