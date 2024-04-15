#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GpsASFlag.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsAntiSpoofingFlagForSV.
    ///
    /// Name         Type            Description
    /// ------------ --------------- -------------------------------------------------------------------------------------------
    /// SvId         int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// AntiSpoofing GpsASFlag       GPS Anti-Spoofing Flag.
    /// DataSetName  optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsAntiSpoofingFlagForSVResult;
    typedef std::shared_ptr<GetGpsAntiSpoofingFlagForSVResult> GetGpsAntiSpoofingFlagForSVResultPtr;
    
    
    class GetGpsAntiSpoofingFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsAntiSpoofingFlagForSVResult();

      GetGpsAntiSpoofingFlagForSVResult(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsAntiSpoofingFlagForSVResultPtr create(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsAntiSpoofingFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsAntiSpoofingFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsAntiSpoofingFlagForSVResult);
  }
}

