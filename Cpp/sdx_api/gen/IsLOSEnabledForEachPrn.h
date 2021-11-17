#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsLOSEnabledForEachPrn is deprecated since 21.3. You may use IsLOSEnabledForEachSV.
    /// 
    /// Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class IsLOSEnabledForEachPrn;
    typedef std::shared_ptr<IsLOSEnabledForEachPrn> IsLOSEnabledForEachPrnPtr;
    
    
    class IsLOSEnabledForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLOSEnabledForEachPrn();

      IsLOSEnabledForEachPrn(const std::string& system);
  
      static IsLOSEnabledForEachPrnPtr create(const std::string& system);
      static IsLOSEnabledForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

