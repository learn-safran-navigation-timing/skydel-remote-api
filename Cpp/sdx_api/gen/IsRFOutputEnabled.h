#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the RF output is enabled or disabled for the specified satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID
    ///

    class IsRFOutputEnabled;
    typedef std::shared_ptr<IsRFOutputEnabled> IsRFOutputEnabledPtr;
    
    
    class IsRFOutputEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsRFOutputEnabled();

      IsRFOutputEnabled(const std::string& system, int svId);

      static IsRFOutputEnabledPtr create(const std::string& system, int svId);
      static IsRFOutputEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

