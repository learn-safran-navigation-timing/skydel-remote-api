#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ephemeris reference time for a SBAS satellite.
    ///
    /// Name Type Description
    /// ---- ---- ----------------------
    /// SvId int  The satellite's SV ID.
    ///

    class GetSbasEphemerisReferenceTimeForSV;
    typedef std::shared_ptr<GetSbasEphemerisReferenceTimeForSV> GetSbasEphemerisReferenceTimeForSVPtr;
    
    
    class GetSbasEphemerisReferenceTimeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasEphemerisReferenceTimeForSV();

      GetSbasEphemerisReferenceTimeForSV(int svId);

      static GetSbasEphemerisReferenceTimeForSVPtr create(int svId);
      static GetSbasEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr);
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

