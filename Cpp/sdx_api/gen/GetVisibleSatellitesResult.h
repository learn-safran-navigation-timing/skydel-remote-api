#pragma once

#include <memory>
#include "command_result.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVisibleSatellites
    ///
    /// Name Type      Description
    /// ---- --------- ----------------------------------------------
    /// Prns array int A list containing the visible satellites' PRNs
    ///

    class GetVisibleSatellitesResult;
    typedef std::shared_ptr<GetVisibleSatellitesResult> GetVisibleSatellitesResultPtr;
    
    
    class GetVisibleSatellitesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVisibleSatellitesResult();

      GetVisibleSatellitesResult(CommandBasePtr relatedCommand, const std::vector<int>& prns);
  
      static GetVisibleSatellitesResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& prns);
      static GetVisibleSatellitesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prns ****
      std::vector<int> prns() const;
      void setPrns(const std::vector<int>& prns);
    };
  }
}

