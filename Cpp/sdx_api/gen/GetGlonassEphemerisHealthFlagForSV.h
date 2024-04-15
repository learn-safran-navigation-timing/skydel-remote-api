#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GLONASS satellite Ephemeris Health Flag Bn(ln)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------------
    /// SvId int  The satellite's SV ID 1..24
    ///

    class GetGlonassEphemerisHealthFlagForSV;
    typedef std::shared_ptr<GetGlonassEphemerisHealthFlagForSV> GetGlonassEphemerisHealthFlagForSVPtr;
    
    
    class GetGlonassEphemerisHealthFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGlonassEphemerisHealthFlagForSV();

      GetGlonassEphemerisHealthFlagForSV(int svId);

      static GetGlonassEphemerisHealthFlagForSVPtr create(int svId);
      static GetGlonassEphemerisHealthFlagForSVPtr dynamicCast(CommandBasePtr ptr);
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

