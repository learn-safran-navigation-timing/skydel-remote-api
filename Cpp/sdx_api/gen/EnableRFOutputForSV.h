#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) RF output for specified satellite. Use SV ID 0 to enabled/disable all satellites.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    The satellite's SV ID
    /// Enabled bool   RF is enabled when value is True
    ///

    class EnableRFOutputForSV;
    typedef std::shared_ptr<EnableRFOutputForSV> EnableRFOutputForSVPtr;
    
    
    class EnableRFOutputForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableRFOutputForSV();

      EnableRFOutputForSV(const std::string& system, int svId, bool enabled);

      static EnableRFOutputForSVPtr create(const std::string& system, int svId, bool enabled);
      static EnableRFOutputForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

