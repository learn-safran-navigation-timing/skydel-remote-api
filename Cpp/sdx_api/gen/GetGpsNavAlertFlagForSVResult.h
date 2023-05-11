#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsNavAlertFlagForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// Alert       bool            GPS NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetGpsNavAlertFlagForSVResult> GetGpsNavAlertFlagForSVResultPtr;
    
    
    class GetGpsNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsNavAlertFlagForSVResult();

      GetGpsNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsNavAlertFlagForSVResultPtr create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGpsNavAlertFlagForSVResult);
  }
}

