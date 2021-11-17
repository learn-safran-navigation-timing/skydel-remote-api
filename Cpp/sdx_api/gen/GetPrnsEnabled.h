#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetPrnsEnabled is deprecated since 21.3. You may use IsEachSVEnabled.
    /// 
    /// Get  enabled or disabled satellites for this constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------------------------------------------------------------------------------------------
    /// System string The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetPrnsEnabled;
    typedef std::shared_ptr<GetPrnsEnabled> GetPrnsEnabledPtr;
    
    
    class GetPrnsEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPrnsEnabled();

      GetPrnsEnabled(const std::string& system);
  
      static GetPrnsEnabledPtr create(const std::string& system);
      static GetPrnsEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

