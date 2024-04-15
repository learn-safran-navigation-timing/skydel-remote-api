#pragma once

#include <memory>
#include "command_base.h"

#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the list of satellites that are cross-authenticated by the specified satellite.
    ///
    /// Name     Type      Description
    /// -------- --------- -------------------------------------------------------------------
    /// SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).
    /// SvIdList array int A list of the cross-authenticated satellites' SV IDs.
    ///

    class SetCrossAuthenticatedSatellitesForSV;
    typedef std::shared_ptr<SetCrossAuthenticatedSatellitesForSV> SetCrossAuthenticatedSatellitesForSVPtr;
    
    
    class SetCrossAuthenticatedSatellitesForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetCrossAuthenticatedSatellitesForSV();

      SetCrossAuthenticatedSatellitesForSV(int svId, const std::vector<int>& svIdList);

      static SetCrossAuthenticatedSatellitesForSVPtr create(int svId, const std::vector<int>& svIdList);
      static SetCrossAuthenticatedSatellitesForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svIdList ****
      std::vector<int> svIdList() const;
      void setSvIdList(const std::vector<int>& svIdList);
    };
    
  }
}

