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
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
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


      RemoveAllMultipathForSV();

      RemoveAllMultipathForSV(const std::string& system, int svId, bool reset);

      static RemoveAllMultipathForSVPtr create(const std::string& system, int svId, bool reset);
      static RemoveAllMultipathForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

