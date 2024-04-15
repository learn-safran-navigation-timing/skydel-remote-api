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
    /// Get GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsL1HealthForSV;
    typedef std::shared_ptr<GetGpsL1HealthForSV> GetGpsL1HealthForSVPtr;
    
    
    class GetGpsL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsL1HealthForSV();

      GetGpsL1HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsL1HealthForSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

