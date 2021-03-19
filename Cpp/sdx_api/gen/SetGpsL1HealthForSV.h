#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L1 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsL1HealthForSV;
    typedef std::shared_ptr<SetGpsL1HealthForSV> SetGpsL1HealthForSVPtr;
    
    
    class SetGpsL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsL1HealthForSV();

      SetGpsL1HealthForSV(int svId, bool health);
  
      static SetGpsL1HealthForSVPtr create(int svId, bool health);
      static SetGpsL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

