#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetRFEnabledForEachPrn is deprecated since 21.3. You may use IsRFOutputEnabledForEachSV.
    /// 
    /// Tells if the RF is enabled or disabled for each satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetRFEnabledForEachPrn;
    typedef std::shared_ptr<GetRFEnabledForEachPrn> GetRFEnabledForEachPrnPtr;
    
    
    class GetRFEnabledForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetRFEnabledForEachPrn();

      GetRFEnabledForEachPrn(const std::string& system);
  
      static GetRFEnabledForEachPrnPtr create(const std::string& system);
      static GetRFEnabledForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

