#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaMacFunction.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------------------------------------------
    /// MacFunction string MAC function used to authenticate the navigation data. MAC functions are: "HMAC-SHA-256" and "CMAC-AES".
    ///                    Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.
    ///

    class GetOsnmaMacFunctionResult;
    typedef std::shared_ptr<GetOsnmaMacFunctionResult> GetOsnmaMacFunctionResultPtr;
    
    
    class GetOsnmaMacFunctionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaMacFunctionResult();

      GetOsnmaMacFunctionResult(const std::string& macFunction);

      GetOsnmaMacFunctionResult(CommandBasePtr relatedCommand, const std::string& macFunction);

      static GetOsnmaMacFunctionResultPtr create(const std::string& macFunction);

      static GetOsnmaMacFunctionResultPtr create(CommandBasePtr relatedCommand, const std::string& macFunction);
      static GetOsnmaMacFunctionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** macFunction ****
      std::string macFunction() const;
      void setMacFunction(const std::string& macFunction);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaMacFunctionResult);
  }
}

