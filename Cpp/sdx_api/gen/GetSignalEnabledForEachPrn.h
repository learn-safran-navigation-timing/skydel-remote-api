#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSignalEnabledForEachPrn is deprecated since 21.3. You may use IsSignalEnabledForEachSV.
    /// 
    /// Tells if the signal is enabled or disabled for each satellite. See GetSignalEnabledForEachPrn description for allowed signals.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Signal string Signal key - see command description for possible values
    ///

    class GetSignalEnabledForEachPrn;
    typedef std::shared_ptr<GetSignalEnabledForEachPrn> GetSignalEnabledForEachPrnPtr;
    
    
    class GetSignalEnabledForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSignalEnabledForEachPrn();

      GetSignalEnabledForEachPrn(const std::string& signal);
  
      static GetSignalEnabledForEachPrnPtr create(const std::string& signal);
      static GetSignalEnabledForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

