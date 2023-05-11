#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use SetQzssNavAlertFlagForSV.
    /// 
    /// Set QZSS NAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteNavAlertFlag;
    typedef std::shared_ptr<SetQzssSatelliteNavAlertFlag> SetQzssSatelliteNavAlertFlagPtr;
    
    
    class SetQzssSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteNavAlertFlag();

      SetQzssSatelliteNavAlertFlag(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssSatelliteNavAlertFlagPtr create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

