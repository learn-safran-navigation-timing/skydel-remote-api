#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssSatelliteL5Health is deprecated since 21.3. You may use GetQzssL5HealthForSV.
    /// 
    /// Get QZSS L5 health (Health of L5 signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssSatelliteL5Health;
    typedef std::shared_ptr<GetQzssSatelliteL5Health> GetQzssSatelliteL5HealthPtr;
    
    
    class GetQzssSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssSatelliteL5Health();

      GetQzssSatelliteL5Health(int svId);
  
      static GetQzssSatelliteL5HealthPtr create(int svId);
      static GetQzssSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

