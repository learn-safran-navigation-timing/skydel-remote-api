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
    /// Get GPS Anti-Spoofing Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsAntiSpoofingFlagForSV;
    typedef std::shared_ptr<GetGpsAntiSpoofingFlagForSV> GetGpsAntiSpoofingFlagForSVPtr;
    
    
    class GetGpsAntiSpoofingFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsAntiSpoofingFlagForSV();

      GetGpsAntiSpoofingFlagForSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsAntiSpoofingFlagForSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsAntiSpoofingFlagForSVPtr dynamicCast(CommandBasePtr ptr);
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

