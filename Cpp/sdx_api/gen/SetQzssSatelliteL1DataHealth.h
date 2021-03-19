#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use SetQzssL1DataHealthForSV.
    /// 
    /// Set QZSS L1 C/A nav data health
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health int  Data health 0..7
    ///

    class SetQzssSatelliteL1DataHealth;
    typedef std::shared_ptr<SetQzssSatelliteL1DataHealth> SetQzssSatelliteL1DataHealthPtr;
    
    
    class SetQzssSatelliteL1DataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteL1DataHealth();

      SetQzssSatelliteL1DataHealth(int svId, int health);
  
      static SetQzssSatelliteL1DataHealthPtr create(int svId, int health);
      static SetQzssSatelliteL1DataHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

