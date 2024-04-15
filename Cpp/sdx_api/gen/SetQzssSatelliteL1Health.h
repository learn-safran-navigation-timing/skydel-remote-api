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
    /// Please note the command SetQzssSatelliteL1Health is deprecated since 21.3. You may use SetQzssL1HealthForSV.
    /// 
    /// Set QZSS L1 health (Health of L1C/A signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L1 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteL1Health;
    typedef std::shared_ptr<SetQzssSatelliteL1Health> SetQzssSatelliteL1HealthPtr;
    
    
    class SetQzssSatelliteL1Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssSatelliteL1Health();

      SetQzssSatelliteL1Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssSatelliteL1HealthPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssSatelliteL1HealthPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

