#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS L2 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L2 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsL2HealthForSV;
    typedef std::shared_ptr<SetGpsL2HealthForSV> SetGpsL2HealthForSVPtr;
    
    
    class SetGpsL2HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsL2HealthForSV();

      SetGpsL2HealthForSV(int svId, bool health);
  
      static SetGpsL2HealthForSVPtr create(int svId, bool health);
      static SetGpsL2HealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

