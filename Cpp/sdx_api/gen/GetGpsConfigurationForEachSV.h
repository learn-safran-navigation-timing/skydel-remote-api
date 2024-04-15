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
    /// Get GPS SV configuration flag for each SVs
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsConfigurationForEachSV;
    typedef std::shared_ptr<GetGpsConfigurationForEachSV> GetGpsConfigurationForEachSVPtr;
    
    
    class GetGpsConfigurationForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsConfigurationForEachSV(const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationForEachSVPtr create(const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsConfigurationForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

