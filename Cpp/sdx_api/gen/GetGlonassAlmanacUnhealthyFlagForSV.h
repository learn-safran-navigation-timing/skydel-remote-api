#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GLONASS satellite Almanac Unhealthy Flag Cn
    ///
    /// Name Type Description
    /// ---- ---- ---------------------------
    /// SvId int  The satellite's SV ID 1..24
    ///

    class GetGlonassAlmanacUnhealthyFlagForSV;
    typedef std::shared_ptr<GetGlonassAlmanacUnhealthyFlagForSV> GetGlonassAlmanacUnhealthyFlagForSVPtr;
    
    
    class GetGlonassAlmanacUnhealthyFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassAlmanacUnhealthyFlagForSV();

      GetGlonassAlmanacUnhealthyFlagForSV(int svId);

      static GetGlonassAlmanacUnhealthyFlagForSVPtr create(int svId);
      static GetGlonassAlmanacUnhealthyFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

