#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteL1Health is deprecated since 21.3. You may use SetQzssL1HealthForSV.
    /// 
    /// Set QZSS L1 health (Health of L1C/A signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L1 health, false = signal OK, true = signal bad
    ///

    class SetQzssSatelliteL1Health;
    typedef std::shared_ptr<SetQzssSatelliteL1Health> SetQzssSatelliteL1HealthPtr;
    
    
    class SetQzssSatelliteL1Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteL1Health();

      SetQzssSatelliteL1Health(int svId, bool health);
  
      static SetQzssSatelliteL1HealthPtr create(int svId, bool health);
      static SetQzssSatelliteL1HealthPtr dynamicCast(CommandBasePtr ptr);
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

