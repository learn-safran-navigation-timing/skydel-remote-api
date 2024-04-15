#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetCrossAuthenticatedSatellitesForSV.
    ///
    /// Name     Type      Description
    /// -------- --------- -------------------------------------------------------------------
    /// SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).
    /// SvIdList array int A list of the cross-authenticated satellites' SV IDs.
    ///

    class GetCrossAuthenticatedSatellitesForSVResult;
    typedef std::shared_ptr<GetCrossAuthenticatedSatellitesForSVResult> GetCrossAuthenticatedSatellitesForSVResultPtr;
    
    
    class GetCrossAuthenticatedSatellitesForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCrossAuthenticatedSatellitesForSVResult();

      GetCrossAuthenticatedSatellitesForSVResult(int svId, const std::vector<int>& svIdList);

      GetCrossAuthenticatedSatellitesForSVResult(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList);

      static GetCrossAuthenticatedSatellitesForSVResultPtr create(int svId, const std::vector<int>& svIdList);

      static GetCrossAuthenticatedSatellitesForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList);
      static GetCrossAuthenticatedSatellitesForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svIdList ****
      std::vector<int> svIdList() const;
      void setSvIdList(const std::vector<int>& svIdList);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetCrossAuthenticatedSatellitesForSVResult);
  }
}

