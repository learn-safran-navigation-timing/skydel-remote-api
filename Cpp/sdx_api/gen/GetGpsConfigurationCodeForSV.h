#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS SV configuration flag for one satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsConfigurationCodeForSV;
    typedef std::shared_ptr<GetGpsConfigurationCodeForSV> GetGpsConfigurationCodeForSVPtr;
    
    
    class GetGpsConfigurationCodeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsConfigurationCodeForSV();

      GetGpsConfigurationCodeForSV(int svId, const std::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationCodeForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {});
      static GetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

