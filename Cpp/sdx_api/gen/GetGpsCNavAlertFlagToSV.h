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
    /// Get GPS CNAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsCNavAlertFlagToSV;
    typedef std::shared_ptr<GetGpsCNavAlertFlagToSV> GetGpsCNavAlertFlagToSVPtr;
    
    
    class GetGpsCNavAlertFlagToSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsCNavAlertFlagToSV();

      GetGpsCNavAlertFlagToSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsCNavAlertFlagToSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsCNavAlertFlagToSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

