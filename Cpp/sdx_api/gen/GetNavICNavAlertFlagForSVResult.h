#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICNavAlertFlagForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.
    /// Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetNavICNavAlertFlagForSVResult> GetNavICNavAlertFlagForSVResultPtr;
    typedef GetNavICNavAlertFlagForSVResult GetNavICSatelliteNavAlertFlagResult;
    typedef std::shared_ptr<GetNavICSatelliteNavAlertFlagResult> GetNavICSatelliteNavAlertFlagResultPtr;
    
    class GetNavICNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNavICNavAlertFlagForSVResult();

      GetNavICNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      GetNavICNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICNavAlertFlagForSVResultPtr create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static GetNavICNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICNavAlertFlagForSVResult);
  }
}

