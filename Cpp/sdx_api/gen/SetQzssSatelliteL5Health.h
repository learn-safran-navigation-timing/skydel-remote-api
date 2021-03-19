#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteL5Health is deprecated since 21.3. You may use SetQzssL5HealthForSV.
    /// 
    /// Set QZSS L5 health (Health of L5 signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L5 health, false = signal OK, true = signal bad
    ///

    class SetQzssSatelliteL5Health;
    typedef std::shared_ptr<SetQzssSatelliteL5Health> SetQzssSatelliteL5HealthPtr;
    
    
    class SetQzssSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteL5Health();

      SetQzssSatelliteL5Health(int svId, bool health);
  
      static SetQzssSatelliteL5HealthPtr create(int svId, bool health);
      static SetQzssSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
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

