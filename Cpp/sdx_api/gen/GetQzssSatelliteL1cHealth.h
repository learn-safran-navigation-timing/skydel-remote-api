#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssSatelliteL1cHealth is deprecated since 21.3. You may use GetQzssL1cHealthForSV.
    /// 
    /// Get QZSS L1C health (Health of L1C signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssSatelliteL1cHealth;
    typedef std::shared_ptr<GetQzssSatelliteL1cHealth> GetQzssSatelliteL1cHealthPtr;
    
    
    class GetQzssSatelliteL1cHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssSatelliteL1cHealth();

      GetQzssSatelliteL1cHealth(int svId);
  
      static GetQzssSatelliteL1cHealthPtr create(int svId);
      static GetQzssSatelliteL1cHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

