#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GLONASS satellite Almanac Unhealthy Flag Cn
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------
    /// SvId   int  The satellite's SV ID 1..24
    /// Health bool Status, false = Non-operability, true = Operability (Good)
    ///

    class SetGlonassAlmanacUnhealthyFlagForSV;
    typedef std::shared_ptr<SetGlonassAlmanacUnhealthyFlagForSV> SetGlonassAlmanacUnhealthyFlagForSVPtr;
    
    
    class SetGlonassAlmanacUnhealthyFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGlonassAlmanacUnhealthyFlagForSV();

      SetGlonassAlmanacUnhealthyFlagForSV(int svId, bool health);

      static SetGlonassAlmanacUnhealthyFlagForSVPtr create(int svId, bool health);
      static SetGlonassAlmanacUnhealthyFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    
  }
}

