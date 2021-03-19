#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICSatelliteL5Health is deprecated since 21.3. You may use SetNavICL5HealthForSV.
    /// 
    /// Set NavIC L5 health (Health of L5 signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..14
    /// Health bool L5 health, false = signal OK, true = signal bad
    ///

    class SetNavICSatelliteL5Health;
    typedef std::shared_ptr<SetNavICSatelliteL5Health> SetNavICSatelliteL5HealthPtr;
    
    
    class SetNavICSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICSatelliteL5Health();

      SetNavICSatelliteL5Health(int svId, bool health);
  
      static SetNavICSatelliteL5HealthPtr create(int svId, bool health);
      static SetNavICSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
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

