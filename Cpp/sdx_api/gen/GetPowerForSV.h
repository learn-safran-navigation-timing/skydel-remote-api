#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetPowerForSV is deprecated since 22.7. You may use GetAllPowerForSV.
    /// 
    /// Get the power offset for specified satellite SV ID.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------
    /// System string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The Satellite SV ID
    ///

    class GetPowerForSV;
    typedef std::shared_ptr<GetPowerForSV> GetPowerForSVPtr;
    
    
    class GetPowerForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetPowerForSV();

      GetPowerForSV(const std::string& system, int svId);

      static GetPowerForSVPtr create(const std::string& system, int svId);
      static GetPowerForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

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

