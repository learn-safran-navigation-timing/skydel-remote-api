#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use GetQzssNavAlertFlagForSV.
    /// 
    /// Get QZSS NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssSatelliteNavAlertFlag;
    typedef std::shared_ptr<GetQzssSatelliteNavAlertFlag> GetQzssSatelliteNavAlertFlagPtr;
    
    
    class GetQzssSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssSatelliteNavAlertFlag();

      GetQzssSatelliteNavAlertFlag(int svId);
  
      static GetQzssSatelliteNavAlertFlagPtr create(int svId);
      static GetQzssSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

