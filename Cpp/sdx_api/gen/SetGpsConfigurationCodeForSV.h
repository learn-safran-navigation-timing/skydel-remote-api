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
    /// Set GPS SV configuration flag for one satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32
    /// SvConfig    int             SV Config 0..4
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsConfigurationCodeForSV;
    typedef std::shared_ptr<SetGpsConfigurationCodeForSV> SetGpsConfigurationCodeForSVPtr;
    
    
    class SetGpsConfigurationCodeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsConfigurationCodeForSV();

      SetGpsConfigurationCodeForSV(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName = {});

      static SetGpsConfigurationCodeForSVPtr create(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

