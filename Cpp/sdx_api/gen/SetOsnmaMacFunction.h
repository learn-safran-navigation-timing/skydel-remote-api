#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA MAC function.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------------------------------------------
    /// MacFunction string MAC function used to authenticate the navigation data. MAC functions are: "HMAC-SHA-256" and "CMAC-AES".
    ///                    Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.
    ///

    class SetOsnmaMacFunction;
    typedef std::shared_ptr<SetOsnmaMacFunction> SetOsnmaMacFunctionPtr;
    
    
    class SetOsnmaMacFunction : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetOsnmaMacFunction();

      SetOsnmaMacFunction(const std::string& macFunction);

      static SetOsnmaMacFunctionPtr create(const std::string& macFunction);
      static SetOsnmaMacFunctionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** macFunction ****
      std::string macFunction() const;
      void setMacFunction(const std::string& macFunction);
    };
    
  }
}

