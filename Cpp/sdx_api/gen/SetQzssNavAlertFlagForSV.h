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
    /// Set QZSS NAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssNavAlertFlagForSV;
    typedef std::shared_ptr<SetQzssNavAlertFlagForSV> SetQzssNavAlertFlagForSVPtr;
    
    
    class SetQzssNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssNavAlertFlagForSV();

      SetQzssNavAlertFlagForSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssNavAlertFlagForSVPtr create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

