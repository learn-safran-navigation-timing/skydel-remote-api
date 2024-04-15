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
    /// Please note the command SetQzssSatelliteL5Health is deprecated since 21.3. You may use SetQzssL5HealthForSV.
    /// 
    /// Set QZSS L5 health (Health of L5 signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L5 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteL5Health;
    typedef std::shared_ptr<SetQzssSatelliteL5Health> SetQzssSatelliteL5HealthPtr;
    
    
    class SetQzssSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssSatelliteL5Health();

      SetQzssSatelliteL5Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssSatelliteL5HealthPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
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

