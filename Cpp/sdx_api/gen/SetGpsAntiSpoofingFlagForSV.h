#pragma once

#include <memory>
#include "command_base.h"

#include "gen/GpsASFlag.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS Anti-Spoofing Flag
    ///
    /// Name         Type            Description
    /// ------------ --------------- -------------------------------------------------------------------------------------------
    /// SvId         int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// AntiSpoofing GpsASFlag       GPS Anti-Spoofing Flag.
    /// DataSetName  optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsAntiSpoofingFlagForSV;
    typedef std::shared_ptr<SetGpsAntiSpoofingFlagForSV> SetGpsAntiSpoofingFlagForSVPtr;
    
    
    class SetGpsAntiSpoofingFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsAntiSpoofingFlagForSV();

      SetGpsAntiSpoofingFlagForSV(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {});

      static SetGpsAntiSpoofingFlagForSVPtr create(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {});
      static SetGpsAntiSpoofingFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

