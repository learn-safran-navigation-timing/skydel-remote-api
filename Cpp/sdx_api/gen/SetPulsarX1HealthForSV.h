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
    /// Set PULSAR X1 health (Health of X1 Signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.
    /// Health      bool            X1 health, false = Signal not operational, true = Signal operational
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetPulsarX1HealthForSV;
    typedef std::shared_ptr<SetPulsarX1HealthForSV> SetPulsarX1HealthForSVPtr;
    
    
    class SetPulsarX1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPulsarX1HealthForSV();

      SetPulsarX1HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static SetPulsarX1HealthForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static SetPulsarX1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

