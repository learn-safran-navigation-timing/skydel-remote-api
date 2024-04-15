#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Disable all multipath for the specified satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId   int    The satellite's SV ID
    /// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
    ///

    class RemoveAllMultipathForSV;
    typedef std::shared_ptr<RemoveAllMultipathForSV> RemoveAllMultipathForSVPtr;
    
    
    class RemoveAllMultipathForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllMultipathForSV();

      RemoveAllMultipathForSV(const std::string& system, int svId, bool reset);

      static RemoveAllMultipathForSVPtr create(const std::string& system, int svId, bool reset);
      static RemoveAllMultipathForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** reset ****
      bool reset() const;
      void setReset(bool reset);
    };
    
  }
}

