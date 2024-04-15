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
    /// Result of GetOsnmaTeslaHashFunction.
    ///
    /// Name         Type   Description
    /// ------------ ------ -------------------------------------------------------------------------------------
    /// HashFunction string Hash function used for the TESLA chain. Hash functions are: "SHA-256" and "SHA3-256".
    ///

    class GetOsnmaTeslaHashFunctionResult;
    typedef std::shared_ptr<GetOsnmaTeslaHashFunctionResult> GetOsnmaTeslaHashFunctionResultPtr;
    
    
    class GetOsnmaTeslaHashFunctionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaTeslaHashFunctionResult();

      GetOsnmaTeslaHashFunctionResult(const std::string& hashFunction);

      GetOsnmaTeslaHashFunctionResult(CommandBasePtr relatedCommand, const std::string& hashFunction);

      static GetOsnmaTeslaHashFunctionResultPtr create(const std::string& hashFunction);

      static GetOsnmaTeslaHashFunctionResultPtr create(CommandBasePtr relatedCommand, const std::string& hashFunction);
      static GetOsnmaTeslaHashFunctionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** hashFunction ****
      std::string hashFunction() const;
      void setHashFunction(const std::string& hashFunction);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTeslaHashFunctionResult);
  }
}

