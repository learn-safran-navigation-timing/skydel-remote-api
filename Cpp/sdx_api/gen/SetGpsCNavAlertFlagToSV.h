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
    /// Set GPS CNAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// Alert       bool            GPS CNAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsCNavAlertFlagToSV;
    typedef std::shared_ptr<SetGpsCNavAlertFlagToSV> SetGpsCNavAlertFlagToSVPtr;
    
    
    class SetGpsCNavAlertFlagToSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsCNavAlertFlagToSV();

      SetGpsCNavAlertFlagToSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static SetGpsCNavAlertFlagToSVPtr create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsCNavAlertFlagToSVPtr dynamicCast(CommandBasePtr ptr);
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

