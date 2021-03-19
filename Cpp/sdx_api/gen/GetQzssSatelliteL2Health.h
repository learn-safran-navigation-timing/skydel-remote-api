#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssSatelliteL2Health is deprecated since 21.3. You may use GetQzssL2HealthForSV.
    /// 
    /// Get QZSS L2 health (Health of L2C signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssSatelliteL2Health;
    typedef std::shared_ptr<GetQzssSatelliteL2Health> GetQzssSatelliteL2HealthPtr;
    
    
    class GetQzssSatelliteL2Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssSatelliteL2Health();

      GetQzssSatelliteL2Health(int svId);
  
      static GetQzssSatelliteL2HealthPtr create(int svId);
      static GetQzssSatelliteL2HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

