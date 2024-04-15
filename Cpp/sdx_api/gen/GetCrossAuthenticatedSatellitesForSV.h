#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the list of satellites that are cross-authenticated by the specified satellite.
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------------
    /// SvId int  The satellite's SV ID (use 0 to apply on all Galileo's satellites).
    ///

    class GetCrossAuthenticatedSatellitesForSV;
    typedef std::shared_ptr<GetCrossAuthenticatedSatellitesForSV> GetCrossAuthenticatedSatellitesForSVPtr;
    
    
    class GetCrossAuthenticatedSatellitesForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCrossAuthenticatedSatellitesForSV();

      GetCrossAuthenticatedSatellitesForSV(int svId);

      static GetCrossAuthenticatedSatellitesForSVPtr create(int svId);
      static GetCrossAuthenticatedSatellitesForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

