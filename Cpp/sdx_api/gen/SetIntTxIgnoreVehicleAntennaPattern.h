#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetIntTxIgnoreVehicleAntennaPattern is deprecated since 20.2. You may use SetIntTxIgnoreRxAntennaPatterns.
    /// 
    /// Set whether a dynamic transmitter should ignore the vehicle's antenna patterns (gain and phase).
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------
    /// Ignore bool   If true, the vehicle's antenna patterns (gain and phase) will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnoreVehicleAntennaPattern;
    typedef std::shared_ptr<SetIntTxIgnoreVehicleAntennaPattern> SetIntTxIgnoreVehicleAntennaPatternPtr;
    
    
    class SetIntTxIgnoreVehicleAntennaPattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxIgnoreVehicleAntennaPattern();

      SetIntTxIgnoreVehicleAntennaPattern(bool ignore, const std::string& id);

      static SetIntTxIgnoreVehicleAntennaPatternPtr create(bool ignore, const std::string& id);
      static SetIntTxIgnoreVehicleAntennaPatternPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

