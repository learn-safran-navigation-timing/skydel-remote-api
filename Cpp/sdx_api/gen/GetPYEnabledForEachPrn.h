#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetPYEnabledForEachPrn is deprecated since 21.3. You may use IsPYCodeEnabledForEachSV.
    /// 
    /// Tells if the P(Y)-Code is enabled or disabled for each satellite. See GetPYEnabledForEachPrn description for allowed signals.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Signal string Signal key - see command description for possible values
    ///

    class GetPYEnabledForEachPrn;
    typedef std::shared_ptr<GetPYEnabledForEachPrn> GetPYEnabledForEachPrnPtr;
    
    
    class GetPYEnabledForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPYEnabledForEachPrn();

      GetPYEnabledForEachPrn(const std::string& signal);
  
      static GetPYEnabledForEachPrnPtr create(const std::string& signal);
      static GetPYEnabledForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

