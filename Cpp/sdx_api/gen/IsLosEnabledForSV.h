#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID
    ///

    class IsLosEnabledForSV;
    typedef std::shared_ptr<IsLosEnabledForSV> IsLosEnabledForSVPtr;
    
    
    class IsLosEnabledForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLosEnabledForSV();

      IsLosEnabledForSV(const std::string& system, int svId);

      static IsLosEnabledForSVPtr create(const std::string& system, int svId);
      static IsLosEnabledForSVPtr dynamicCast(CommandBasePtr ptr);
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

