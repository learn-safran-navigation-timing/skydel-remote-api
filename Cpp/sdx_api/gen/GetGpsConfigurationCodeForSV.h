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


      GetGpsConfigurationCodeForSV();

      GetGpsConfigurationCodeForSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationCodeForSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr);
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

