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
    /// Please note the command SetQzssSatelliteL2Health is deprecated since 21.3. You may use SetQzssL2HealthForSV.
    /// 
    /// Set QZSS L2 health (Health of L2C signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L2 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteL2Health;
    typedef std::shared_ptr<SetQzssSatelliteL2Health> SetQzssSatelliteL2HealthPtr;
    
    
    class SetQzssSatelliteL2Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssSatelliteL2Health();

      SetQzssSatelliteL2Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssSatelliteL2HealthPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssSatelliteL2HealthPtr dynamicCast(CommandBasePtr ptr);
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

