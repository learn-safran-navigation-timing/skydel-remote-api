#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS L5 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L5 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsL5HealthForSV;
    typedef std::shared_ptr<SetGpsL5HealthForSV> SetGpsL5HealthForSVPtr;
    
    
    class SetGpsL5HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsL5HealthForSV();

      SetGpsL5HealthForSV(int svId, bool health);
  
      static SetGpsL5HealthForSVPtr create(int svId, bool health);
      static SetGpsL5HealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

