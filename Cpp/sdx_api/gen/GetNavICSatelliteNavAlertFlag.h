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
    /// Please note the command GetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use GetNavICNavAlertFlagForSV.
    /// 
    /// Get NavIC NAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICSatelliteNavAlertFlag;
    typedef std::shared_ptr<GetNavICSatelliteNavAlertFlag> GetNavICSatelliteNavAlertFlagPtr;
    
    
    class GetNavICSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICSatelliteNavAlertFlag();

      GetNavICSatelliteNavAlertFlag(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICSatelliteNavAlertFlagPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetNavICSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

