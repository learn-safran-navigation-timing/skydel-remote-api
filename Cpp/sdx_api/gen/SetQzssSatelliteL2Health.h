#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteL2Health is deprecated since 21.3. You may use SetQzssL2HealthForSV.
    /// 
    /// Set QZSS L2 health (Health of L2C signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L2 health, false = signal OK, true = signal bad
    ///

    class SetQzssSatelliteL2Health;
    typedef std::shared_ptr<SetQzssSatelliteL2Health> SetQzssSatelliteL2HealthPtr;
    
    
    class SetQzssSatelliteL2Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteL2Health();

      SetQzssSatelliteL2Health(int svId, bool health);
  
      static SetQzssSatelliteL2HealthPtr create(int svId, bool health);
      static SetQzssSatelliteL2HealthPtr dynamicCast(CommandBasePtr ptr);
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

